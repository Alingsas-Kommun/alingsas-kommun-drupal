<?php
/**
 * @file
 * alingsasintra_booking_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function alingsasintra_booking_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facetapi:block_cache:search_api@event_index';
  $strongarm->value = -1;
  $export['facetapi:block_cache:search_api@event_index'] = $strongarm;

  return $export;
}
