<?php
/**
 * @file
 * alingsasintra_bulletin.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function alingsasintra_bulletin_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-anslagstavlan.
  $menus['menu-anslagstavlan'] = array(
    'menu_name' => 'menu-anslagstavlan',
    'title' => 'Anslagstavlan',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Anslagstavlan');


  return $menus;
}
