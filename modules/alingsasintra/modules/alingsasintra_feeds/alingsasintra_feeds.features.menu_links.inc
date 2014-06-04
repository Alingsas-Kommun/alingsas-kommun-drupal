<?php
/**
 * @file
 * alingsasintra_feeds.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function alingsasintra_feeds_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-jobb:jobb
  $menu_links['menu-jobb:jobb'] = array(
    'menu_name' => 'menu-jobb',
    'link_path' => 'jobb',
    'router_path' => 'jobb',
    'link_title' => 'Visa alla jobb',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Visa alla jobb');


  return $menu_links;
}
