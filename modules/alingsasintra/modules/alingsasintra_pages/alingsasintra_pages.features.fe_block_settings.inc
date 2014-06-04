<?php
/**
 * @file
 * alingsasintra_pages.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function alingsasintra_pages_default_fe_block_settings() {
  $export = array();

  $export['version'] = '1.0';

  // Theme independent visibility settings.
  $export['visibility'] = array(
    'menu_block-1' => array(
      'delta' => '1',
      'module' => 'menu_block',
    ),
  );

  // alingsasintra
  $theme = array();

  $theme['menu_block-1'] = array(
    'module' => 'menu_block',
    'delta' => '1',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '-24',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '<front>
node/*/edit',
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
