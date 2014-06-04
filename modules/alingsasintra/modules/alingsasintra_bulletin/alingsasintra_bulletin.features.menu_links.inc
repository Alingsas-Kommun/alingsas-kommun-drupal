<?php
/**
 * @file
 * alingsasintra_bulletin.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function alingsasintra_bulletin_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-anslagstavlan:anslagstavlan
  $menu_links['menu-anslagstavlan:anslagstavlan'] = array(
    'menu_name' => 'menu-anslagstavlan',
    'link_path' => 'anslagstavlan',
    'router_path' => 'anslagstavlan',
    'link_title' => 'Visa alla',
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
  t('Visa alla');


  return $menu_links;
}
