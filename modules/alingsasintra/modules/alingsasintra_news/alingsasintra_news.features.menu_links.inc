<?php
/**
 * @file
 * alingsasintra_news.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function alingsasintra_news_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-nyheter:nyheter
  $menu_links['menu-nyheter:nyheter'] = array(
    'menu_name' => 'menu-nyheter',
    'link_path' => 'nyheter',
    'router_path' => 'nyheter',
    'link_title' => 'Visa alla nyheter',
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
  t('Visa alla nyheter');


  return $menu_links;
}
