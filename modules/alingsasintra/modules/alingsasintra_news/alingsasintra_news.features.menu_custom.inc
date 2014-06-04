<?php
/**
 * @file
 * alingsasintra_news.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function alingsasintra_news_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-nyheter.
  $menus['menu-nyheter'] = array(
    'menu_name' => 'menu-nyheter',
    'title' => 'Nyheter',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Nyheter');


  return $menus;
}
