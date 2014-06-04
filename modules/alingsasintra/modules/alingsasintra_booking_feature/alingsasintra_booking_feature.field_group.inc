<?php
/**
 * @file
 * alingsasintra_booking_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function alingsasintra_booking_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_booking|node|event|form';
  $field_group->group_name = 'group_booking';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bokning',
    'weight' => '8',
    'children' => array(
      0 => 'field_bookable',
      1 => 'field_max_participants',
      2 => 'field_event_additional_info',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Bokning',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_booking|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_external_information|node|event|form';
  $field_group->group_name = 'group_external_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Relaterad information',
    'weight' => '9',
    'children' => array(
      0 => 'field_event_related_information',
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
  $export['group_external_information|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_information|node|event|form';
  $field_group->group_name = 'group_general_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Allmän Information',
    'weight' => '10',
    'children' => array(
      0 => 'field_event_general_information',
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
  $export['group_general_information|node|event|form'] = $field_group;

  return $export;
}
