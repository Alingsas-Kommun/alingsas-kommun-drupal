<?php
/**
 * @file
 * alingsasintra_bulletin.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function alingsasintra_bulletin_default_fe_block_settings() {
  $export = array();

  $export['version'] = '1.0';

  // Theme independent visibility settings.
  $export['visibility'] = array(
    'alingsasintra_demo-bulletin_board' => array(
      'delta' => 'bulletin_board',
      'module' => 'alingsasintra_demo',
    ),
    'menu-menu-anslagstavlan' => array(
      'delta' => 'menu-anslagstavlan',
      'module' => 'menu',
    ),
  );

  // alingsasintra
  $theme = array();

  $theme['alingsasintra_demo-bulletin_board'] = array(
    'module' => 'alingsasintra_demo',
    'delta' => 'bulletin_board',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '-18',
    'region' => 'sidebar_third',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '1',
  );

  $theme['menu-menu-anslagstavlan'] = array(
    'module' => 'menu',
    'delta' => 'menu-anslagstavlan',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '-15',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'anslagstavlan
anslagstavlan/*
node/add/advert',
    'title' => '<none>',
    'cache' => -1,
  );

  $export['theme']['alingsasintra'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export['theme'][$theme_key]);
    }
  }
  return $export;
}
