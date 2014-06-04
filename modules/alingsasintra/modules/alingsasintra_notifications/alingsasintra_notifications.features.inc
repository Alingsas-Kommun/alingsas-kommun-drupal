<?php
/**
 * @file
 * alingsasintra_notifications.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function alingsasintra_notifications_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function alingsasintra_notifications_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function alingsasintra_notifications_node_info() {
  $items = array(
    'notification' => array(
      'name' => t('Informationsmeddelande'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Rubrik'),
      'help' => '',
    ),
  );
  return $items;
}
