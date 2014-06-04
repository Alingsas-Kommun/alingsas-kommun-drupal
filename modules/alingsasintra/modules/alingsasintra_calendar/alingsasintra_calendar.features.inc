<?php
/**
 * @file
 * alingsasintra_calendar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function alingsasintra_calendar_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function alingsasintra_calendar_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function alingsasintra_calendar_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Aktivitet/kurs'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}
