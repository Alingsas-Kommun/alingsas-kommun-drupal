<?php
/**
 * @file
 * alingsasintra_user_profile.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function alingsasintra_user_profile_default_fe_block_settings() {
  $export = array();

  $export['version'] = '1.0';

  // Theme independent visibility settings.
  $export['visibility'] = array(
    'menu-menu-personal-menu' => array(
      'delta' => 'menu-personal-menu',
      'module' => 'menu',
    ),
    'menu_block-2' => array(
      'delta' => '2',
      'module' => 'menu_block',
    ),
  );

  // alingsasintra
  $theme = array();

  $theme['menu-menu-personal-menu'] = array(
    'module' => 'menu',
    'delta' => 'menu-personal-menu',
    'theme' => 'alingsasintra',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['menu_block-2'] = array(
    'module' => 'menu_block',
    'delta' => '2',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '-16',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user
user/*
my/content
mina-nyheter
all-content',
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
