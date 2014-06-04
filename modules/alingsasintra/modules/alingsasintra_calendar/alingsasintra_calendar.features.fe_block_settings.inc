<?php
/**
 * @file
 * alingsasintra_calendar.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function alingsasintra_calendar_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu-menu-kalender'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'menu-kalender',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => 'events
events-by-organization
kalender/*
node/add/event',
    'roles' => array(),
    'themes' => array(
      'alingsasintra' => array(
        'region' => 'sidebar_second',
        'status' => '1',
        'theme' => 'alingsasintra',
        'weight' => '-28',
      ),
    ),
    'title' => '<none>',
    'visibility' => '1',
  );

  return $export;
}
