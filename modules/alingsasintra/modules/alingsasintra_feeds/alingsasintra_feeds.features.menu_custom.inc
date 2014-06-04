<?php
/**
 * @file
 * alingsasintra_feeds.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function alingsasintra_feeds_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-jobb.
  $menus['menu-jobb'] = array(
    'menu_name' => 'menu-jobb',
    'title' => 'Jobb',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Jobb');


  return $menus;
}
