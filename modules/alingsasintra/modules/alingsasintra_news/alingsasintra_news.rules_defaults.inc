<?php
/**
 * @file
 * alingsasintra_news.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function alingsasintra_news_default_rules_configuration() {
  $items = array();
  $items['rules_publish_news'] = entity_import('rules_config', '{ "rules_publish_news" : {
      "LABEL" : "Publish news",
      "PLUGIN" : "rule set",
      "TAGS" : [ "news" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "Nod", "type" : "node" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "news" : "news" } } } },
              { "NOT node_is_promoted" : { "node" : [ "node" ] } }
            ],
            "DO" : [ { "node_promote" : { "node" : [ "node" ] } } ],
            "LABEL" : "Publish news rule"
          }
        }
      ]
    }
  }');
  $items['rules_publish_news_rule'] = entity_import('rules_config', '{ "rules_publish_news_rule" : {
      "LABEL" : "Publish news rule",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "news" ],
      "REQUIRES" : [ "rules", "rules_scheduler" ],
      "ON" : [ "node_insert", "node_update" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "news" : "news" } } } }
      ],
      "DO" : [
        { "schedule" : {
            "component" : "rules_publish_news",
            "date" : [ "node:field-publishduration:value" ],
            "identifier" : "publish [node:nid]",
            "param_node" : [ "node" ]
          }
        }
      ]
    }
  }');
  $items['rules_reset_publish_news_schedule'] = entity_import('rules_config', '{ "rules_reset_publish_news_schedule" : {
      "LABEL" : "Reset publish news schedule",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "news" ],
      "REQUIRES" : [ "rules", "rules_scheduler" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_publishdate" } },
        { "data_is_empty" : { "data" : [ "node:field-publishdate" ] } }
      ],
      "DO" : [
        { "schedule_delete" : { "component" : "rules_publish_news", "task" : "publish [node:nid]" } }
      ]
    }
  }');
  $items['rules_reset_unpublish_news_schedule'] = entity_import('rules_config', '{ "rules_reset_unpublish_news_schedule" : {
      "LABEL" : "Reset unpublish news schedule",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "news" ],
      "REQUIRES" : [ "rules", "rules_scheduler" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_unpublishdate" } },
        { "data_is_empty" : { "data" : [ "node:field-unpublishdate" ] } }
      ],
      "DO" : [
        { "schedule_delete" : { "component" : "rules_unpublish_news", "task" : "unpublish [node:nid]" } }
      ]
    }
  }');
  $items['rules_unpublish_news'] = entity_import('rules_config', '{ "rules_unpublish_news" : {
      "LABEL" : "Unpublish news",
      "PLUGIN" : "rule set",
      "TAGS" : [ "news" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "Nod", "type" : "node" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "news" : "news" } } } },
              { "node_is_promoted" : { "node" : [ "node" ] } }
            ],
            "DO" : [ { "node_unpromote" : { "node" : [ "node" ] } } ],
            "LABEL" : "Unpublish news rule"
          }
        }
      ]
    }
  }');
  $items['rules_unpublish_news_rule'] = entity_import('rules_config', '{ "rules_unpublish_news_rule" : {
      "LABEL" : "Unpublish news rule",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "news" ],
      "REQUIRES" : [ "rules", "rules_scheduler" ],
      "ON" : [ "node_insert", "node_update" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "news" : "news" } } } }
      ],
      "DO" : [
        { "schedule" : {
            "component" : "rules_unpublish_news",
            "date" : [ "node:field-publishduration:value2" ],
            "identifier" : "unpublish [node:nid]",
            "param_node" : [ "node" ]
          }
        }
      ]
    }
  }');
  return $items;
}
