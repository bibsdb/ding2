core = 7.x
api = 2

; Projects
projects[ding_base][type] = "module"
projects[ding_base][download][type] = "git"
projects[ding_base][download][url] = "git@github.com:ding2tal/ding_base.git"
projects[ding_base][download][branch] = "development"

projects[ting_reference][type] = "module"
projects[ting_reference][download][type] = "git"
projects[ting_reference][download][url] = "git@github.com:ding2tal/ting_reference.git"
projects[ting_reference][download][branch] = "development"

projects[cache_actions][subdir] = "contrib"
projects[cache_actions][version] = "2.0-alpha5"

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.4"
projects[ctools][patch][0] = "http://drupal.org/files/ctools-n1925018-12.patch"

projects[features][subdir] = "contrib"
projects[features][version] = "2.0-beta2"

projects[features_extra][subdir] = "contrib"
projects[features_extra][version] = "1.0-beta1"

projects[field_group][subdir] = "contrib"
projects[field_group][version] = "1.1"

projects[og][subdir] = "contrib"
projects[og][version] = "2.5"

# This version of og menu contains patches from ding2tal.
projects[og_menu][type] = "module"
projects[og_menu][subdir] = "contrib"
projects[og_menu][download][type] = "git"
projects[og_menu][download][url] = "http://git.drupal.org/project/og_menu.git"
projects[og_menu][download][revision] = "4c1d8dd4c18dc25df12f5e7fabd4dde52dd286f0"
projects[og_menu][patch][0] = "http://drupal.org/files/issues/option_to_hide_create_menu-2139819-2.patch"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0"

projects[media][type] = "module"
projects[media][subdir] = "contrib"
projects[media][download][type] = "git"
projects[media][download][url] = "http://git.drupal.org/project/media.git"
projects[media][download][revision] = "c3cda2b"

projects[file_entity][subdir] = "contrib"
projects[file_entity][version] = "2.0-alpha2"

projects[menu_block][type] = "module"
projects[menu_block][subdir] = "contrib"
projects[menu_block][download][type] = "git"
projects[menu_block][download][url] = "http://git.drupal.org/project/menu_block.git"
projects[menu_block][download][revision] = "32ab1cf08b729c93302455d67dd05f64ad2fc056"
projects[menu_block][patch][0] = "http://drupal.org/files/menu_block-ctools-693302-96.patch"

projects[views_bulk_operations][subdir] = "contrib"
projects[views_bulk_operations][version] = "3.1"
