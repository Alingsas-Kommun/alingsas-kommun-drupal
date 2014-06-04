<?php
/**
 * @file
 * alingsasintra_texteditor.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function alingsasintra_texteditor_user_default_permissions() {
  $permissions = array();

  // Exported permission: allow CKFinder file uploads.
  $permissions['allow CKFinder file uploads'] = array(
    'name' => 'allow CKFinder file uploads',
    'roles' => array(
      0 => 'administrator',
      1 => 'central redaktör',
      2 => 'publicist',
      3 => 'publicist +',
    ),
    'module' => 'ckeditor',
  );

  // Exported permission: use text format html.
  $permissions['use text format html'] = array(
    'name' => 'use text format html',
    'roles' => array(
      0 => 'administrator',
      1 => 'central redaktör',
      2 => 'personal',
      3 => 'publicist',
      4 => 'publicist +',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
