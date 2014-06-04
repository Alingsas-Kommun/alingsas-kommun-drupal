<?php
/**
 * @file
 * alingsasintra_blocks.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function alingsasintra_blocks_default_fe_block_settings() {
  $export = array();

  $export['version'] = '1.0';

  // Theme independent visibility settings.
  $export['visibility'] = array(
    'alingsasintra-back_subnav' => array(
      'delta' => 'back_subnav',
      'module' => 'alingsasintra',
    ),
    'alingsasintra-local_tasks' => array(
      'delta' => 'local_tasks',
      'module' => 'alingsasintra',
    ),
    'alingsasintra_bookmarks-sidebar_bookmarks' => array(
      'delta' => 'sidebar_bookmarks',
      'module' => 'alingsasintra_bookmarks',
    ),
    'alingsasintra_demo-open_jobs' => array(
      'delta' => 'open_jobs',
      'module' => 'alingsasintra_demo',
    ),
    'alingsasintra_demo-sidebar_user' => array(
      'delta' => 'sidebar_user',
      'module' => 'alingsasintra_demo',
    ),
    'system-main' => array(
      'delta' => 'main',
      'module' => 'system',
    ),
    'system-user-menu' => array(
      'delta' => 'user-menu',
      'module' => 'system',
    ),
  );

  // alingsasintra
  $theme = array();

  $theme['alingsasintra-back_subnav'] = array(
    'module' => 'alingsasintra',
    'delta' => 'back_subnav',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '-23',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/add
node/add/*
node/*/edit
kalender
kalender/*
anslagstavlan
anslagstavlan/*
nyheter
nyheter-term
nyheter-term/*
notification
notification/*
sok-anvandare
sok
node/*/submission/*
comment/reply
comment/reply/*
jobb
jobb/*
node/*/import
node/*/delete-items
node/*/unlock
node/*/log',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['alingsasintra-local_tasks'] = array(
    'module' => 'alingsasintra',
    'delta' => 'local_tasks',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '-22',
    'region' => 'sidebar_third',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['alingsasintra_bookmarks-sidebar_bookmarks'] = array(
    'module' => 'alingsasintra_bookmarks',
    'delta' => 'sidebar_bookmarks',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '-20',
    'region' => 'sidebar_third',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['alingsasintra_demo-open_jobs'] = array(
    'module' => 'alingsasintra_demo',
    'delta' => 'open_jobs',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '-19',
    'region' => 'sidebar_third',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '1',
  );

  $theme['alingsasintra_demo-sidebar_user'] = array(
    'module' => 'alingsasintra_demo',
    'delta' => 'sidebar_user',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '-21',
    'region' => 'sidebar_third',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['system-main'] = array(
    'module' => 'system',
    'delta' => 'main',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '-17',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['system-user-menu'] = array(
    'module' => 'system',
    'delta' => 'user-menu',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '-23',
    'region' => 'sidebar_third',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
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
