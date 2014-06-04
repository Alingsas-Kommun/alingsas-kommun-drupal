<?php
/**
 * @file
 * alingsasintra_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function alingsasintra_news_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
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
function alingsasintra_news_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function alingsasintra_news_node_info() {
  $items = array(
    'news' => array(
      'name' => t('Nyhet'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}
