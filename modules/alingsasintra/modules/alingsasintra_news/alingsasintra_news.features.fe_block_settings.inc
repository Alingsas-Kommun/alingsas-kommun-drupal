<?php
/**
 * @file
 * alingsasintra_news.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function alingsasintra_news_default_fe_block_settings() {
  $export = array();

  $export['version'] = '1.0';

  // Theme independent visibility settings.
  $export['visibility'] = array(
    'alingsasintra-news_subnav' => array(
      'delta' => 'news_subnav',
      'module' => 'alingsasintra',
    ),
    'menu-menu-nyheter' => array(
      'delta' => 'menu-nyheter',
      'module' => 'menu',
    ),
    'views-2b3d7a238ebf9db160c4aaa925d5a9f4' => array(
      'delta' => '2b3d7a238ebf9db160c4aaa925d5a9f4',
      'module' => 'views',
    ),
    'views-fbbddbe6816f8b2aad14f56cc599b801' => array(
      'delta' => 'fbbddbe6816f8b2aad14f56cc599b801',
      'module' => 'views',
    ),
    'views-news_per_page-news_per_page' => array(
      'delta' => 'news_per_page-news_per_page',
      'module' => 'views',
      'node_type' => array(
        'page' => TRUE,
      ),
    ),
    'views-nyheter-block_common' => array(
      'delta' => 'nyheter-block_common',
      'module' => 'views',
    ),
  );

  // alingsasintra
  $theme = array();

  $theme['alingsasintra-news_subnav'] = array(
    'module' => 'alingsasintra',
    'delta' => 'news_subnav',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '-13',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'nyheter/*
verktyg/*',
    'title' => '',
    'cache' => '1',
  );

  $theme['menu-menu-nyheter'] = array(
    'module' => 'menu',
    'delta' => 'menu-nyheter',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '-12',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'nyheter
nyheter-term/*',
    'title' => '<none>',
    'cache' => -1,
  );

  $theme['views-2b3d7a238ebf9db160c4aaa925d5a9f4'] = array(
    'module' => 'views',
    'delta' => '2b3d7a238ebf9db160c4aaa925d5a9f4',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '0',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '<none>',
    'cache' => -1,
  );

  $theme['views-fbbddbe6816f8b2aad14f56cc599b801'] = array(
    'module' => 'views',
    'delta' => 'fbbddbe6816f8b2aad14f56cc599b801',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '0',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'content/nyhetsarkiv',
    'title' => '<none>',
    'cache' => -1,
  );

  $theme['views-news_per_page-news_per_page'] = array(
    'module' => 'views',
    'delta' => 'news_per_page-news_per_page',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '0',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'content/*',
    'title' => '<none>',
    'cache' => -1,
  );

  $theme['views-nyheter-block_common'] = array(
    'module' => 'views',
    'delta' => 'nyheter-block_common',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '-21',
    'region' => 'sidebar_second',
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
