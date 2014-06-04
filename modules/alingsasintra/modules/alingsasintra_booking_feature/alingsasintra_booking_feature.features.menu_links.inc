<?php
/**
 * @file
 * alingsasintra_booking_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function alingsasintra_booking_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-kalender:booking/mybookings
  $menu_links['menu-kalender:booking/mybookings'] = array(
    'menu_name' => 'menu-kalender',
    'link_path' => 'booking/mybookings',
    'router_path' => 'booking/mybookings',
    'link_title' => 'Mina bokade aktiviteter och kurser',
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
  // Exported menu link: menu-kalender:booking/mymanagedevents
  $menu_links['menu-kalender:booking/mymanagedevents'] = array(
    'menu_name' => 'menu-kalender',
    'link_path' => 'booking/mymanagedevents',
    'router_path' => 'booking/mymanagedevents',
    'link_title' => 'Mina skapade aktiviteter och kurser',
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
  t('Mina bokade aktiviteter och kurser');
  t('Mina skapade aktiviteter och kurser');


  return $menu_links;
}
