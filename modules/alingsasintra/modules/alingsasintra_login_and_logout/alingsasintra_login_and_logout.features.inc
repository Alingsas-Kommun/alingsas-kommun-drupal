<?php
/**
 * @file
 * alingsasintra_login_and_logout.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function alingsasintra_login_and_logout_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
