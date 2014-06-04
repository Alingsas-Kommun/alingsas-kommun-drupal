<?php
/**
 * @file
 * alingsasintra_calendar.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function alingsasintra_calendar_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-kalender:events
  $menu_links['menu-kalender:events'] = array(
    'menu_name' => 'menu-kalender',
    'link_path' => 'events',
    'router_path' => 'events',
    'link_title' => 'Gemensamma aktiviteter och kurser',
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
    'weight' => '-49',
  );
  // Exported menu link: menu-kalender:events-by-organization
  $menu_links['menu-kalender:events-by-organization'] = array(
    'menu_name' => 'menu-kalender',
    'link_path' => 'events-by-organization',
    'router_path' => 'events-by-organization',
    'link_title' => 'Förvaltningens aktiviteter och kurser',
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
    'weight' => '-48',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Förvaltningens aktiviteter och kurser');
  t('Gemensamma aktiviteter och kurser');


  return $menu_links;
}
