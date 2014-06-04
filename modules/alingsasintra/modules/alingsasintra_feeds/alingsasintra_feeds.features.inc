<?php
/**
 * @file
 * alingsasintra_feeds.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function alingsasintra_feeds_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function alingsasintra_feeds_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function alingsasintra_feeds_node_info() {
  $items = array(
    'aditrorecruit_job_import' => array(
      'name' => t('Aditrorecruit Job import'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'alingsas_job' => array(
      'name' => t('Jobb'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Arbetsbeskrivning'),
      'help' => '',
    ),
  );
  return $items;
}
