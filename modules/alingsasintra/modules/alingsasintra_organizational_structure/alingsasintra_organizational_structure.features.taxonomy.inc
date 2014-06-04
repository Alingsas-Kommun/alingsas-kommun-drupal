<?php
/**
 * @file
 * alingsasintra_organizational_structure.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function alingsasintra_organizational_structure_taxonomy_default_vocabularies() {
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
