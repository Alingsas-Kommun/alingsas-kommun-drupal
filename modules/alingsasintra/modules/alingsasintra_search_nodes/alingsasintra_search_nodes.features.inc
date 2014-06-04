<?php
/**
 * @file
 * alingsasintra_search_nodes.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function alingsasintra_search_nodes_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function alingsasintra_search_nodes_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function alingsasintra_search_nodes_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "local_db_search",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_node_status" : { "status" : 1, "weight" : "-50", "settings" : [] },
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-49",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "advert" : "advert",
              "event" : "event",
              "alingsas_job" : "alingsas_job",
              "news" : "news",
              "page" : "page",
              "verktyg" : "verktyg"
            }
          }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "-48", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "-47",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : {
          "status" : 1,
          "weight" : "-46",
          "settings" : { "mode" : "search_result_teaser" }
        },
        "search_api_alter_add_url" : { "status" : 1, "weight" : "-45", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "-44", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "-43", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "type" : true,
              "title" : true,
              "field_introduction" : true,
              "field_contact_name" : true,
              "field_jf_departmentdesc" : true,
              "field_jf_qualifications" : true,
              "field_jf_employmenttype_nam" : true,
              "field_jf_employmenttype_des" : true,
              "field_jf_employmentgrade_na" : true,
              "field_jf_employmentgrade_de" : true,
              "field_jf_salarytype" : true,
              "field_jf_salarytype_desc" : true,
              "field_jf_workshift" : true,
              "field_jf_workshift_desc" : true,
              "field_jf_additionalinfo" : true,
              "body:value" : true,
              "field_url:title" : true,
              "field_organizational_structure:name" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "field_introduction" : true, "body:value" : true },
            "title" : 1,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_introduction" : true,
              "field_contact_name" : true,
              "field_jf_departmentdesc" : true,
              "field_jf_qualifications" : true,
              "field_jf_employmenttype_nam" : true,
              "field_jf_employmenttype_des" : true,
              "field_jf_employmentgrade_na" : true,
              "field_jf_employmentgrade_de" : true,
              "field_jf_salarytype" : true,
              "field_jf_salarytype_desc" : true,
              "field_jf_workshift" : true,
              "field_jf_workshift_desc" : true,
              "field_jf_additionalinfo" : true,
              "body:value" : true,
              "field_organizational_structure:name" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      },
      "fields" : {
        "type" : { "type" : "string" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "status" : { "type" : "boolean" },
        "promote" : { "type" : "boolean" },
        "created" : { "type" : "date" },
        "changed" : { "type" : "date" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "comment_count" : { "type" : "integer" },
        "field_organizational_structure" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_introduction" : { "type" : "text", "boost" : "3.0" },
        "field_contact_name" : { "type" : "text" },
        "field_contact_user" : { "type" : "integer", "entity_type" : "user" },
        "field_jf_departmentdesc" : { "type" : "text" },
        "field_jf_qualifications" : { "type" : "text" },
        "field_jf_employmenttype_nam" : { "type" : "text" },
        "field_jf_employmenttype_des" : { "type" : "text" },
        "field_jf_employmentgrade_na" : { "type" : "text" },
        "field_jf_employmentgrade_de" : { "type" : "text" },
        "field_jf_salarytype" : { "type" : "text" },
        "field_jf_salarytype_desc" : { "type" : "text" },
        "field_jf_workshift" : { "type" : "text" },
        "field_jf_workshift_desc" : { "type" : "text" },
        "field_jf_additionalinfo" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "search_api_url" : { "type" : "uri" },
        "search_api_viewed" : { "type" : "text" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "body:value" : { "type" : "text" },
        "field_url:title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_url:url" : { "type" : "list\\u003Curi\\u003E" },
        "field_organizational_structure:name" : { "type" : "list\\u003Cstring\\u003E" }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  $items['user_index'] = entity_import('search_api_index', '{
    "name" : "user_index",
    "machine_name" : "user_index",
    "description" : null,
    "server" : "local_db_search",
    "item_type" : "user",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "uid" : { "type" : "integer" },
        "name" : { "type" : "text" },
        "field_firstname" : { "type" : "text", "boost" : "5.0" },
        "field_lastname" : { "type" : "text", "boost" : "5.0" },
        "field_ou" : { "type" : "text" },
        "field_user_title" : { "type" : "text" },
        "field_user_email" : { "type" : "text" },
        "field_user_phone" : { "type" : "text" },
        "field_user_mobile" : { "type" : "text" },
        "field_user_fax" : { "type" : "text" },
        "field_user_address" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "field_organizational_structure:name" : { "type" : "list\\u003Cstring\\u003E" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "name" : true,
              "field_firstname" : true,
              "field_lastname" : true,
              "field_ou" : true,
              "field_user_title" : true,
              "field_user_email" : true,
              "field_user_phone" : true,
              "field_user_mobile" : true,
              "field_user_fax" : true,
              "field_user_address" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "name" : true,
              "field_firstname" : true,
              "field_lastname" : true,
              "field_ou" : true,
              "field_user_title" : true,
              "field_user_email" : true,
              "field_user_phone" : true,
              "field_user_mobile" : true,
              "field_user_fax" : true,
              "field_user_address" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "name" : true,
              "field_firstname" : true,
              "field_lastname" : true,
              "field_ou" : true,
              "field_user_title" : true,
              "field_user_email" : true,
              "field_user_phone" : true,
              "field_user_mobile" : true,
              "field_user_fax" : true,
              "field_user_address" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "name" : true,
              "field_firstname" : true,
              "field_lastname" : true,
              "field_ou" : true,
              "field_user_title" : true,
              "field_user_email" : true,
              "field_user_phone" : true,
              "field_user_mobile" : true,
              "field_user_fax" : true,
              "field_user_address" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function alingsasintra_search_nodes_default_search_api_server() {
  $items = array();
  $items['local_db_search'] = entity_import('search_api_server', '{
    "name" : "Local DB search",
    "machine_name" : "local_db_search",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "3",
      "indexes" : {
        "default_node_index" : {
          "type" : {
            "table" : "search_api_db_default_node_index_type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_default_node_index_title",
            "type" : "text",
            "boost" : "5.0"
          },
          "promote" : {
            "table" : "search_api_db_default_node_index_promote",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_default_node_index_created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_default_node_index_changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_default_node_index_author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "comment_count" : {
            "table" : "search_api_db_default_node_index_comment_count",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_default_node_index_search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_default_node_index_body_value",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_organizational_structure" : {
            "table" : "search_api_db_default_node_index_field_organizational_structure",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_organizational_structure:name" : {
            "table" : "search_api_db_default_node_index_field_organizational_structu_1",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_default_node_index_status",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "field_introduction" : {
            "table" : "search_api_db_default_node_index_field_introduction",
            "type" : "text",
            "boost" : "3.0"
          },
          "field_contact_name" : {
            "table" : "search_api_db_default_node_index_field_contact_name",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_contact_user" : {
            "table" : "search_api_db_default_node_index_field_contact_user",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_url" : {
            "table" : "search_api_db_default_node_index_search_api_url",
            "type" : "uri",
            "boost" : "1.0"
          },
          "search_api_viewed" : {
            "table" : "search_api_db_default_node_index_search_api_viewed",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_access_node" : {
            "table" : "search_api_db_default_node_index_search_api_access_node",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_url:title" : {
            "table" : "search_api_db_default_node_index_field_url_title",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_url:url" : {
            "table" : "search_api_db_default_node_index_field_url_url",
            "type" : "list\\u003Curi\\u003E",
            "boost" : "1.0"
          },
          "field_jf_departmentdesc" : {
            "table" : "search_api_db_default_node_index_field_jf_departmentdesc",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_jf_qualifications" : {
            "table" : "search_api_db_default_node_index_field_jf_qualifications",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_jf_employmenttype_nam" : {
            "table" : "search_api_db_default_node_index_field_jf_employmenttype_nam",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_jf_employmenttype_des" : {
            "table" : "search_api_db_default_node_index_field_jf_employmenttype_des",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_jf_employmentgrade_na" : {
            "table" : "search_api_db_default_node_index_field_jf_employmentgrade_na",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_jf_employmentgrade_de" : {
            "table" : "search_api_db_default_node_index_field_jf_employmentgrade_de",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_jf_salarytype" : {
            "table" : "search_api_db_default_node_index_field_jf_salarytype",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_jf_salarytype_desc" : {
            "table" : "search_api_db_default_node_index_field_jf_salarytype_desc",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_jf_workshift" : {
            "table" : "search_api_db_default_node_index_field_jf_workshift",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_jf_workshift_desc" : {
            "table" : "search_api_db_default_node_index_field_jf_workshift_desc",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_jf_additionalinfo" : {
            "table" : "search_api_db_default_node_index_field_jf_additionalinfo",
            "type" : "text",
            "boost" : "1.0"
          }
        },
        "user_index" : {
          "name" : {
            "table" : "search_api_db_user_index_name",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_firstname" : {
            "table" : "search_api_db_user_index_field_firstname",
            "type" : "text",
            "boost" : "5.0"
          },
          "field_lastname" : {
            "table" : "search_api_db_user_index_field_lastname",
            "type" : "text",
            "boost" : "5.0"
          },
          "field_ou" : {
            "table" : "search_api_db_user_index_field_ou",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_title" : {
            "table" : "search_api_db_user_index_field_user_title",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_email" : {
            "table" : "search_api_db_user_index_field_user_email",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_phone" : {
            "table" : "search_api_db_user_index_field_user_phone",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_mobile" : {
            "table" : "search_api_db_user_index_field_user_mobile",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_fax" : {
            "table" : "search_api_db_user_index_field_user_fax",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_address" : {
            "table" : "search_api_db_user_index_field_user_address",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_user_index_search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_organizational_structure:name" : {
            "table" : "search_api_db_user_index_field_organizational_structure_name",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "uid" : {
            "table" : "search_api_db_user_index_uid",
            "type" : "integer",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1"
  }');
  return $items;
}
