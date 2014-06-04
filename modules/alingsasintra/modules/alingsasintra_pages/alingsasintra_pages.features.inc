<?php
/**
 * @file
 * alingsasintra_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function alingsasintra_pages_ctools_plugin_api() {
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
 * Implements hook_image_default_styles().
 */
function alingsasintra_pages_image_default_styles() {
  $styles = array();

  // Exported image style: teaser.
  $styles['teaser'] = array(
    'name' => 'teaser',
    'effects' => array(
      3 => array(
        'label' => 'Skala och beskär',
        'help' => 'Skala och beskär kommer att bibehålla proportionerna i den ursprungliga bilden, därefter beskära det större måttet. Detta är mest användbart för att skapa perfekta kvadratiska miniatyrbilder utan att tänja ut bilden.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '259',
          'height' => '160',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function alingsasintra_pages_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Sida'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Rubrik'),
      'help' => '',
    ),
    'teaser' => array(
      'name' => t('Puff'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}
