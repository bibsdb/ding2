<?php

/**
 * @file
 * Ding user provider example.
 */

/**
 * Provider authenticate callback.
 */
function connie_user_authenticate($name, $pass) {
  $res = array(
    'success' => FALSE,
  );

  // We log in users if the four last letters in the name matches the password
  // or if the username matched our list of created users.
  if (drupal_substr($name, -4) == $pass ||
      !empty($_SESSION['connie_created_users'][$name])) {
    $res['success'] = TRUE;
    if (preg_match('/blocked/', $name)) {
      $res['success'] = FALSE;
      $res['messages'][] = t("Sorry, you're blocked");
    }

    $res['creds'] = array(
      'name' => $name,
      'pass' => $pass,
    );

    $res['user'] = array(
      'mail' => $name . '@example.com',
      'data' => array(
        'display_name' => drupal_ucfirst($name),
      ),
    );

    // This is how we pass data from here (where the profile2 profile
    // might not yet exist) to the profile_init callback.
    $res['private']['branch'] = 'aby';
  }

  return $res;
}

/**
 * Test that credentials is still valid.
 *
 * If this function is not defined, it is assumed that having credentials
 * available is enough.
 */
function connie_user_is_authenticated($creds) {
  return (isset($creds['name']) && isset($creds['pass']));
}

/**
 * Update user account.
 *
 * Update email and/or pincode for user.
 *
 * @param object $account
 *   User.
 * @param array $changes
 *   An array with 'mail' and/or 'pass' keys.
 *
 * @returns array
 *   An array, optionally with new 'creds' which will be cached.
 */
function connie_user_account_update($account, array $changes) {
  $result = array();
  $creds = ding_user_get_creds($account);
  $res = connie_client_invoke('update_userinfo', $creds['name'], $creds['pass'], $changes);
  if ($res !== TRUE) {
    // Call failed, throw exception.
    if (is_string($res)) {
      $exception_message = t('Update userinfo failed, message: @message', array('@message' => $res));
    }
    else {
      $exception_message = t('Update userinfo failed.');
    }
    throw new Exception($exception_message);
  }

  if (isset($changes['pass'])) {
    // Set new password.
    $creds['pass'] = $changes['pass'];
    // Update creds.
    $result['creds'] = $creds;

    // Update user status cache.
    _connie_user_status($creds, TRUE);
  }
  return $result;
}

/**
 * Create a user.
 *
 * @param string $cpr
 *   The CPR number for the user.
 * @param string $pin_code
 *   The password for the user.
 * @param string $name
 *   The name of the user.
 * @param string $mail
 *   The user email address.
 * @param string $branch_id
 *   The id for the branch which should be the users preferred branch.
 */
function connie_user_create($cpr, $pin_code, $name, $mail, $branch_id) {
  if (empty($_SESSION['connie_created_users'])) {
    $_SESSION['connie_created_users'] = array();
  }
  // Remember which users that have created so they can be logged in afterwards.
  $_SESSION['connie_created_users'][$cpr] = func_get_args();
}

/**
 * Testing function, shouldn't be implemented in provider implementations.
 *
 * @todo: move testing code to use another existing function.
 */
function connie_user_test() {
  ding_user_get_creds(NULL);

  return "Wolla!";
}
