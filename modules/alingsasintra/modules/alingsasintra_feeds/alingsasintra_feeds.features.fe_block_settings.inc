<?php
/**
 * @file
 * alingsasintra_feeds.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function alingsasintra_feeds_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu-menu-jobb'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'menu-jobb',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'alingsasintra' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'alingsasintra',
        'weight' => '-17',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  return $export;
}
