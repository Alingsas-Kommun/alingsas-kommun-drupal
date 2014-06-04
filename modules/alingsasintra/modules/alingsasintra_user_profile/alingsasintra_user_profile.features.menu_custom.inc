<?php
/**
 * @file
 * alingsasintra_user_profile.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function alingsasintra_user_profile_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-personal-menu.
  $menus['menu-personal-menu'] = array(
    'menu_name' => 'menu-personal-menu',
    'title' => 'Personal Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Personal Menu');


  return $menus;
}
