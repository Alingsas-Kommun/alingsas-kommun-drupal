<?php
/**
 * @file
 * alingsasintra_booking_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function alingsasintra_booking_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['alingsasintra_booking-booking_info'] = array(
    'cache' => '1',
    'custom' => '0',
    'delta' => 'booking_info',
    'module' => 'alingsasintra_booking',
    'node_types' => array(),
    'pages' => 'booking/*
kalender/*',
    'roles' => array(),
    'themes' => array(
      'alingsasintra' => array(
        'region' => 'sidebar_second',
        'status' => '1',
        'theme' => 'alingsasintra',
        'weight' => '-18',
      ),
    ),
    'title' => '',
    'visibility' => '1',
  );

  $export['facetapi-lBHu7tUsjqIqJm8f4UgLKwmV0sAOSxJo'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'lBHu7tUsjqIqJm8f4UgLKwmV0sAOSxJo',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => 'events
events/*
events-by-organization
events-by-organization/*',
    'roles' => array(),
    'themes' => array(
      'alingsasintra' => array(
        'region' => 'sidebar_second',
        'status' => '1',
        'theme' => 'alingsasintra',
        'weight' => '-23',
      ),
    ),
    'title' => 'Filtrera Förvaltning/Avdelning',
    'visibility' => '1',
  );

  return $export;
}
