<?php
/**
 * @file
 * ldap_prod_setup.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ldap_prod_setup_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|user|user|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Kontaktinformation',
    'weight' => '4',
    'children' => array(
      0 => 'field_ou',
      1 => 'field_organizational_structure',
      2 => 'field_user_email',
      3 => 'field_user_phone',
      4 => 'field_user_mobile',
      5 => 'field_user_fax',
      6 => 'field_user_address',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_contact|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_contact|user|user|default';
  $field_group->group_name = 'group_user_contact';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Kontaktinformation',
    'weight' => '2',
    'children' => array(
      0 => 'field_ou',
      1 => 'field_user_email',
      2 => 'field_user_phone',
      3 => 'field_user_mobile',
      4 => 'field_user_fax',
      5 => 'field_user_address',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_user_contact|user|user|default'] = $field_group;

  return $export;
}
