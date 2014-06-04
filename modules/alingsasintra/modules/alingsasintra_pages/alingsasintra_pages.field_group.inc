<?php
/**
 * @file
 * alingsasintra_pages.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function alingsasintra_pages_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contactperson|node|page|form';
  $field_group->group_name = 'group_contactperson';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Kontakt',
    'weight' => '7',
    'children' => array(
      0 => 'field_contact_name',
      1 => 'field_contact_email',
      2 => 'field_contact_user',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Kontakt',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Välj antingen Kontaktperson eller skriv in Enhet och E-post nedan',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_contactperson|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_external_information|node|page|form';
  $field_group->group_name = 'group_external_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Relaterad information',
    'weight' => '5',
    'children' => array(
      0 => 'field_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Relaterad information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_external_information|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_information|node|page|form';
  $field_group->group_name = 'group_general_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Allmän Information',
    'weight' => '6',
    'children' => array(
      0 => 'field_general_information',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Allmän Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_general_information|node|page|form'] = $field_group;

  return $export;
}
