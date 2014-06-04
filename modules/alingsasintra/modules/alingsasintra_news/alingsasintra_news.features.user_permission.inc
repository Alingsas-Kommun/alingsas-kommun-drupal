<?php
/**
 * @file
 * alingsasintra_news.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function alingsasintra_news_user_default_permissions() {
  $permissions = array();

  // Exported permission: create news content.
  $permissions['create news content'] = array(
    'name' => 'create news content',
    'roles' => array(
      0 => 'administrator',
      1 => 'central redaktör',
      2 => 'publicist',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any news content.
  $permissions['delete any news content'] = array(
    'name' => 'delete any news content',
    'roles' => array(
      0 => 'administrator',
      1 => 'central redaktör',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own news content.
  $permissions['delete own news content'] = array(
    'name' => 'delete own news content',
    'roles' => array(
      0 => 'administrator',
      1 => 'central redaktör',
      2 => 'publicist',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any news content.
  $permissions['edit any news content'] = array(
    'name' => 'edit any news content',
    'roles' => array(
      0 => 'administrator',
      1 => 'central redaktör',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own news content.
  $permissions['edit own news content'] = array(
    'name' => 'edit own news content',
    'roles' => array(
      0 => 'administrator',
      1 => 'central redaktör',
      2 => 'publicist',
      3 => 'publicist +',
    ),
    'module' => 'node',
  );

  // Exported permission: enter news revision log entry.
  $permissions['enter news revision log entry'] = array(
    'name' => 'enter news revision log entry',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override news authored by option.
  $permissions['override news authored by option'] = array(
    'name' => 'override news authored by option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override news authored on option.
  $permissions['override news authored on option'] = array(
    'name' => 'override news authored on option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override news promote to front page option.
  $permissions['override news promote to front page option'] = array(
    'name' => 'override news promote to front page option',
    'roles' => array(
      0 => 'administrator',
      1 => 'central redaktör',
      2 => 'publicist',
      3 => 'publicist +',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override news published option.
  $permissions['override news published option'] = array(
    'name' => 'override news published option',
    'roles' => array(
      0 => 'administrator',
      1 => 'central redaktör',
      2 => 'publicist',
      3 => 'publicist +',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override news revision option.
  $permissions['override news revision option'] = array(
    'name' => 'override news revision option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override news sticky option.
  $permissions['override news sticky option'] = array(
    'name' => 'override news sticky option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  return $permissions;
}
