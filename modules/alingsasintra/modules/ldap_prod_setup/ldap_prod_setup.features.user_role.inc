<?php
/**
 * @file
 * ldap_prod_setup.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ldap_prod_setup_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '6',
  );

  // Exported role: central redaktör.
  $roles['central redaktör'] = array(
    'name' => 'central redaktör',
    'weight' => '5',
  );

  // Exported role: personal.
  $roles['personal'] = array(
    'name' => 'personal',
    'weight' => '2',
  );

  // Exported role: publicist.
  $roles['publicist'] = array(
    'name' => 'publicist',
    'weight' => '3',
  );

  // Exported role: publicist +.
  $roles['publicist +'] = array(
    'name' => 'publicist +',
    'weight' => '4',
  );

  return $roles;
}
