<?php
/**
 * @file
 * ldap_prod_setup.ldap_query.inc
 */

/**
 * Implements hook_default_ldap_query().
 */
function ldap_prod_setup_default_ldap_query() {
  $export = array();

  $qid = new stdClass();
  $qid->disabled = FALSE; /* Edit this to true to make a default qid disabled initially */
  $qid->api_version = 1;
  $qid->qid = 'ldap_users';
  $qid->name = 'LDAP Users';
  $qid->sid = 'ldap_prod';
  $qid->status = TRUE;
  $qid->base_dn_str = '';
  $qid->filter = '';
  $qid->attributes_str = 'title,pidJobCode';
  $qid->sizelimit = 0;
  $qid->timelimit = 0;
  $qid->deref = FALSE;
  $qid->scope = TRUE;
  $export['ldap_users'] = $qid;

  return $export;
}
