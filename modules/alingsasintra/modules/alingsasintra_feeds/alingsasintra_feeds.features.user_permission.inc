<?php
/**
 * @file
 * alingsasintra_feeds.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function alingsasintra_feeds_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer feeds.
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: clear aditrorecruit_importer feeds.
  $permissions['clear aditrorecruit_importer feeds'] = array(
    'name' => 'clear aditrorecruit_importer feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: create aditrorecruit_job_import content.
  $permissions['create aditrorecruit_job_import content'] = array(
    'name' => 'create aditrorecruit_job_import content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create alingsas_job content.
  $permissions['create alingsas_job content'] = array(
    'name' => 'create alingsas_job content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any aditrorecruit_job_import content.
  $permissions['delete any aditrorecruit_job_import content'] = array(
    'name' => 'delete any aditrorecruit_job_import content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any alingsas_job content.
  $permissions['delete any alingsas_job content'] = array(
    'name' => 'delete any alingsas_job content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own aditrorecruit_job_import content.
  $permissions['delete own aditrorecruit_job_import content'] = array(
    'name' => 'delete own aditrorecruit_job_import content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own alingsas_job content.
  $permissions['delete own alingsas_job content'] = array(
    'name' => 'delete own alingsas_job content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any aditrorecruit_job_import content.
  $permissions['edit any aditrorecruit_job_import content'] = array(
    'name' => 'edit any aditrorecruit_job_import content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any alingsas_job content.
  $permissions['edit any alingsas_job content'] = array(
    'name' => 'edit any alingsas_job content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own aditrorecruit_job_import content.
  $permissions['edit own aditrorecruit_job_import content'] = array(
    'name' => 'edit own aditrorecruit_job_import content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own alingsas_job content.
  $permissions['edit own alingsas_job content'] = array(
    'name' => 'edit own alingsas_job content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: enter aditrorecruit_job_import revision log entry.
  $permissions['enter aditrorecruit_job_import revision log entry'] = array(
    'name' => 'enter aditrorecruit_job_import revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: enter alingsas_job revision log entry.
  $permissions['enter alingsas_job revision log entry'] = array(
    'name' => 'enter alingsas_job revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: import aditrorecruit_importer feeds.
  $permissions['import aditrorecruit_importer feeds'] = array(
    'name' => 'import aditrorecruit_importer feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: override aditrorecruit_job_import authored by option.
  $permissions['override aditrorecruit_job_import authored by option'] = array(
    'name' => 'override aditrorecruit_job_import authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: override aditrorecruit_job_import authored on option.
  $permissions['override aditrorecruit_job_import authored on option'] = array(
    'name' => 'override aditrorecruit_job_import authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: override aditrorecruit_job_import promote to front page option.
  $permissions['override aditrorecruit_job_import promote to front page option'] = array(
    'name' => 'override aditrorecruit_job_import promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: override aditrorecruit_job_import published option.
  $permissions['override aditrorecruit_job_import published option'] = array(
    'name' => 'override aditrorecruit_job_import published option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: override aditrorecruit_job_import revision option.
  $permissions['override aditrorecruit_job_import revision option'] = array(
    'name' => 'override aditrorecruit_job_import revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: override aditrorecruit_job_import sticky option.
  $permissions['override aditrorecruit_job_import sticky option'] = array(
    'name' => 'override aditrorecruit_job_import sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: override alingsas_job authored by option.
  $permissions['override alingsas_job authored by option'] = array(
    'name' => 'override alingsas_job authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: override alingsas_job authored on option.
  $permissions['override alingsas_job authored on option'] = array(
    'name' => 'override alingsas_job authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: override alingsas_job promote to front page option.
  $permissions['override alingsas_job promote to front page option'] = array(
    'name' => 'override alingsas_job promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: override alingsas_job published option.
  $permissions['override alingsas_job published option'] = array(
    'name' => 'override alingsas_job published option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: override alingsas_job revision option.
  $permissions['override alingsas_job revision option'] = array(
    'name' => 'override alingsas_job revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: override alingsas_job sticky option.
  $permissions['override alingsas_job sticky option'] = array(
    'name' => 'override alingsas_job sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: unlock aditrorecruit_importer feeds.
  $permissions['unlock aditrorecruit_importer feeds'] = array(
    'name' => 'unlock aditrorecruit_importer feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  return $permissions;
}
