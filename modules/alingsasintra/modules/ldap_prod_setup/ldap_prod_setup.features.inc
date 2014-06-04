<?php
/**
 * @file
 * ldap_prod_setup.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ldap_prod_setup_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ldap_authorization" && $api == "ldap_authorization") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "ldap_query" && $api == "ldap_query") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "ldap_servers" && $api == "ldap_servers") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
