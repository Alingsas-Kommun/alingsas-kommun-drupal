<?php
/**
 * @file
 * alingsasintra_news.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function alingsasintra_news_taxonomy_default_vocabularies() {
  return array(
    'organizational_structure' => array(
      'name' => 'Organisation Struktur',
      'machine_name' => 'organizational_structure',
      'description' => '',
      'hierarchy' => '1',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
