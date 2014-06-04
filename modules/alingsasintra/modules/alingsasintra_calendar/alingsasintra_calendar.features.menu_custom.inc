<?php
/**
 * @file
 * alingsasintra_calendar.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function alingsasintra_calendar_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-kalender.
  $menus['menu-kalender'] = array(
    'menu_name' => 'menu-kalender',
    'title' => 'Kalender',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Kalender');


  return $menus;
}
