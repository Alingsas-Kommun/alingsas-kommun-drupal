<?php
/**
 * @file
 * alingsasintra_organizational_structure.ldap_query.inc
 */

/**
 * Implements hook_default_ldap_query().
 */
function alingsasintra_organizational_structure_default_ldap_query() {
  $export = array();

  $qid = new stdClass();
  $qid->disabled = FALSE; /* Edit this to true to make a default qid disabled initially */
  $qid->api_version = 1;
  $qid->qid = 'ldap_group_hierarchy';
  $qid->name = 'LDAP groups';
  $qid->sid = 'ldap_prod';
  $qid->status = TRUE;
  $qid->base_dn_str = 'ou=Organizational-Structure,ou=Groups,o=Alingsas';
  $qid->filter = '(description=*)';
  $qid->attributes_str = 'cn,description,pidParentDN';
  $qid->sizelimit = 0;
  $qid->timelimit = 0;
  $qid->deref = FALSE;
  $qid->scope = TRUE;
  $export['ldap_group_hierarchy'] = $qid;

  return $export;
}
