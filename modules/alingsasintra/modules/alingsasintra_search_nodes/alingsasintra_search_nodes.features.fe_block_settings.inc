<?php
/**
 * @file
 * alingsasintra_search_nodes.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function alingsasintra_search_nodes_default_fe_block_settings() {
  $export = array();

  $export['version'] = '1.0';

  // Theme independent visibility settings.
  $export['visibility'] = array(
    'alingsasintra-custom_search' => array(
      'delta' => 'custom_search',
      'module' => 'alingsasintra',
    ),
    'facetapi-7bELpP1cJH7QkQqHRXco2ZnHOSFsS1Cw' => array(
      'delta' => '7bELpP1cJH7QkQqHRXco2ZnHOSFsS1Cw',
      'module' => 'facetapi',
    ),
    'facetapi-v74101ZrMqMit5DtbE3fkcfpyfoXjwr9' => array(
      'delta' => 'v74101ZrMqMit5DtbE3fkcfpyfoXjwr9',
      'module' => 'facetapi',
    ),
    'facetapi-zIH8EsYFkvWKeMtTZTGLEm1GrYlAarmk' => array(
      'delta' => 'zIH8EsYFkvWKeMtTZTGLEm1GrYlAarmk',
      'module' => 'facetapi',
    ),
  );

  // alingsasintra
  $theme = array();

  $theme['alingsasintra-custom_search'] = array(
    'module' => 'alingsasintra',
    'delta' => 'custom_search',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '-12',
    'region' => 'header_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['facetapi-7bELpP1cJH7QkQqHRXco2ZnHOSFsS1Cw'] = array(
    'module' => 'facetapi',
    'delta' => '7bELpP1cJH7QkQqHRXco2ZnHOSFsS1Cw',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '-16',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'sok-anvandare',
    'title' => 'Filtrera Förvaltning/Avdelning',
    'cache' => -1,
  );

  $theme['facetapi-v74101ZrMqMit5DtbE3fkcfpyfoXjwr9'] = array(
    'module' => 'facetapi',
    'delta' => 'v74101ZrMqMit5DtbE3fkcfpyfoXjwr9',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '-17',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'sok
sok/*
nyheter/sok',
    'title' => 'Filtrera Förvaltning/Avdelning',
    'cache' => -1,
  );

  $theme['facetapi-zIH8EsYFkvWKeMtTZTGLEm1GrYlAarmk'] = array(
    'module' => 'facetapi',
    'delta' => 'zIH8EsYFkvWKeMtTZTGLEm1GrYlAarmk',
    'theme' => 'alingsasintra',
    'status' => '1',
    'weight' => '-18',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'sok
sok/*',
    'title' => 'Filtrera Innehållstyp',
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
