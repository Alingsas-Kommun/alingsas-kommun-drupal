<?php
/**
 * @file
 * alingsasintra_bulletin.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function alingsasintra_bulletin_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function alingsasintra_bulletin_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function alingsasintra_bulletin_node_info() {
  $items = array(
    'advert' => array(
      'name' => t('Annons'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Rubrik'),
      'help' => '',
    ),
  );
  return $items;
}
