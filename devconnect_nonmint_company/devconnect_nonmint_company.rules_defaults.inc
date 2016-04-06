<?php
/**
 * @file
 * apigee_nonmint_company.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */

function devconnect_nonmint_company_default_rules_configuration() {

  $email_message = <<< EOM
Hello,

You have been added to a new company on [site:url].
To accept the invitation to join this company, please visit [site:url]api_company\/companies\/list

You will need to create an account on this site to be able to accept the invitation.

Thanks,

[site:name]
EOM;

  $config = [
    'rules_notify_developer_on_being_added_to_a_company' => [
      'LABEL' => 'Notify Developer on being added to a company',
      'PLUGIN' => 'reaction rule',
      'OWNER' => 'rules',
      'REQUIRES' => [ 'rules', 'apigee_company' ],
      'ON' => [ 'apigee_company_invitation_insert' => [] ],
      'DO' => [
        [
          'mail' => [
            'to' => '[apigee-company-invitation:developerId]',
            'subject' => 'You have been added to a new Company',
            'message' => trim($email_message),
            'language' => ['site:current-page:language']
          ]
        ]
      ]
    ]
  ];
  $entity = entity_import('rules_config', $config);
  return array('rules_notify_developer_on_being_added_to_a_company' => $entity);
}
