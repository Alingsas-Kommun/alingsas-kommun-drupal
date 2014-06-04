<?php
/**
 * @file
 * ldap_prod_setup.ldap_servers.inc
 */

/**
 * Implements hook_default_ldap_servers().
 */
function ldap_prod_setup_default_ldap_servers() {
  $export = array();

  $ldap_servers_conf = new stdClass();
  $ldap_servers_conf->disabled = FALSE; /* Edit this to true to make a default ldap_servers_conf disabled initially */
  $ldap_servers_conf->api_version = 1;
  $ldap_servers_conf->sid = 'ldap_prod';
  $ldap_servers_conf->name = 'LDAP prod server';
  $ldap_servers_conf->status = TRUE;
  $ldap_servers_conf->ldap_type = 'default';
  $ldap_servers_conf->address = '';
  $ldap_servers_conf->port = 389;
  $ldap_servers_conf->tls = FALSE;
  $ldap_servers_conf->bind_method = TRUE;
  $ldap_servers_conf->binddn = '';
  $ldap_servers_conf->bindpw = '';
  $ldap_servers_conf->basedn = array(
    0 => 'ou=Users,o=Alingsas',
    1 => 'ou=Groups,o=Alingsas',
  );
  $ldap_servers_conf->user_attr = 'uid';
  $ldap_servers_conf->account_name_attr = '';
  $ldap_servers_conf->mail_attr = '';
  $ldap_servers_conf->mail_template = '';
  $ldap_servers_conf->unique_persistent_attr = '';
  $ldap_servers_conf->unique_persistent_attr_binary = FALSE;
  $ldap_servers_conf->user_dn_expression = '';
  $ldap_servers_conf->ldap_to_drupal_user = '';
  $ldap_servers_conf->testing_drupal_username = '';
  $ldap_servers_conf->testingDrupalUserDn = '';
  $ldap_servers_conf->groupFunctionalityUnused = FALSE;
  $ldap_servers_conf->group_object_category = 'groupofnames';
  $ldap_servers_conf->groupNested = FALSE;
  $ldap_servers_conf->groupUserMembershipsAttrExists = FALSE;
  $ldap_servers_conf->groupUserMembershipsAttr = '';
  $ldap_servers_conf->groupMembershipsAttr = 'member';
  $ldap_servers_conf->groupMembershipsAttrMatchingUserAttr = 'dn';
  $ldap_servers_conf->groupDeriveFromDn = FALSE;
  $ldap_servers_conf->groupDeriveFromDnAttr = '';
  $ldap_servers_conf->groupTestGroupDn = '';
  $ldap_servers_conf->groupTestGroupDnWriteable = '';
  $ldap_servers_conf->search_pagination = FALSE;
  $ldap_servers_conf->search_page_size = 1000;
  $ldap_servers_conf->weight = 0;
  $export['ldap_prod'] = $ldap_servers_conf;

  return $export;
}
