<?php
/**
 * @file
 * alingsasintra_organizational_structure.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function alingsasintra_organizational_structure_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ldap_query" && $api == "ldap_query") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
