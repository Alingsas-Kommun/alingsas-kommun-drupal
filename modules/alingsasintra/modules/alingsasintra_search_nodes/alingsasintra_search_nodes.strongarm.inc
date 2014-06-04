<?php
/**
 * @file
 * alingsasintra_search_nodes.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function alingsasintra_search_nodes_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facetapi:block_cache:search_api@default_node_index';
  $strongarm->value = -1;
  $export['facetapi:block_cache:search_api@default_node_index'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facetapi:block_cache:search_api@user_index';
  $strongarm->value = -1;
  $export['facetapi:block_cache:search_api@user_index'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_facets_search_ids';
  $strongarm->value = array(
    'default_node_index' => array(
      'search_api_views:search_nodes:search_nodes' => 'search_api_views:search_nodes:search_nodes',
      'search_api_views:all_nodes_by_search_api:page' => 'search_api_views:all_nodes_by_search_api:page',
      'search_api_views:all_nodes_by_search_api:search_api_views_facets_block_1' => 'search_api_views:all_nodes_by_search_api:search_api_views_facets_block_1',
      'search_api_views:all_nodes_by_search_api:page_1' => 'search_api_views:all_nodes_by_search_api:page_1',
      'search_api_views:search_users:search_nodes' => 'search_api_views:search_users:search_nodes',
    ),
    'user_index' => array(
      'search_api_views:search_users:page' => 'search_api_views:search_users:page',
      'search_api_views:search_users:search_user_list' => 'search_api_views:search_users:search_user_list',
    ),
  );
  $export['search_api_facets_search_ids'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_block_hashes';
  $strongarm->value = array(
    'fbbddbe6816f8b2aad14f56cc599b801' => 'nyheter-news_common_organisation',
    '2b3d7a238ebf9db160c4aaa925d5a9f4' => 'personalized_content-block_my_news',
  );
  $export['views_block_hashes'] = $strongarm;

  return $export;
}
