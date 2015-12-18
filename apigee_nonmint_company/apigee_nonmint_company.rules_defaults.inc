<?php
/**
 * @file
 * apigee_nonmint_company.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function apigee_nonmint_company_default_rules_configuration() {
  $items = array();
  $items['rules_notify_developer_on_being_added_to_the_company'] = entity_import('rules_config', '{ "rules_notify_developer_on_being_added_to_the_company" : {
      "LABEL" : "Notify Developer on being added to the Company",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "eck" ],
      "ON" : { "company_invitation_non_mint_insert" : [] },
      "DO" : [
        { "mail" : {
            "to" : [ "company-invitation-non-mint:developer-id" ],
            "subject" : "You have been added to a new Company",
            "message" : "Hello,\\r\\n\\r\\nYou have been added to a new company on [site:url].\\r\\nTo accept the invite to join this company please visit  [site:url]api_company\\/companies\\/list\\r\\n\\r\\nYou will need to create an account on this site to be able to accept the invitation.\\r\\n\\r\\nThanks,\\r\\n[site:name]\\r\\n",
            "language" : [ "company-invitation-non-mint:type" ]
          }
        }
      ]
    }
  }');
  return $items;
}
