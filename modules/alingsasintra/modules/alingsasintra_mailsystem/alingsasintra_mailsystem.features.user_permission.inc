<?php
/**
 * @file
 * alingsasintra_mailsystem.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function alingsasintra_mailsystem_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer mailsystem.
  $permissions['administer mailsystem'] = array(
    'name' => 'administer mailsystem',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'mailsystem',
  );

  // Exported permission: administer smtp module.
  $permissions['administer smtp module'] = array(
    'name' => 'administer smtp module',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'smtp',
  );

  return $permissions;
}
