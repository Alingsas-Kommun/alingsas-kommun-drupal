<?php
/**
 * @file
 * alingsasintra_search_nodes.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function alingsasintra_search_nodes_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer search_api.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'search_api',
  );

  return $permissions;
}
