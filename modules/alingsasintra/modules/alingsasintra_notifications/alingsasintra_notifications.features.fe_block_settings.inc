<?php
/**
 * @file
 * alingsasintra_notifications.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function alingsasintra_notifications_default_fe_block_settings() {
  $export = array();

  $export['version'] = '1.0';

  // Theme independent visibility settings.
  $export['visibility'] = array(
    'views-notifications-block' => array(
      'delta' => 'notifications-block',
      'module' => 'views',
    ),
    'views-notifications-block_1' => array(
      'delta' => 'notifications-block_1',
      'module' => 'views',
    ),
  );

  // alingsasintra
  $theme = array();

  $theme['views-notifications-block'] = array(
    'module' => 'views',
    'delta' => 'notifications-block',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '-23',
    'region' => 'notification_area',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '<none>',
    'cache' => -1,
  );

  $theme['views-notifications-block_1'] = array(
    'module' => 'views',
    'delta' => 'notifications-block_1',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '-21',
    'region' => 'notification_area',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '<front>',
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
