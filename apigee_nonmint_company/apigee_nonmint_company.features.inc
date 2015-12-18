<?php
/**
 * @file
 * apigee_nonmint_company.features.inc
 */

/**
 * Implements hook_eck_entity_type_info().
 */
function apigee_nonmint_company_eck_entity_type_info() {
  $items = array(
    'company_invitation_non_mint' => array(
      'name' => 'company_invitation_non_mint',
      'label' => 'Company Invitation Non-Mint',
      'properties' => array(
        'company_id' => array(
          'label' => 'Company Id',
          'type' => 'text',
          'behavior' => '',
        ),
        'created_at' => array(
          'label' => 'Created At',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'developer_id' => array(
          'label' => 'Developer Id',
          'type' => 'text',
          'behavior' => '',
        ),
        'lastmodified_at' => array(
          'label' => 'Last Modified',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
        'org' => array(
          'label' => 'Org',
          'type' => 'text',
          'behavior' => '',
        ),
        'requestor' => array(
          'label' => 'Requestor',
          'type' => 'text',
          'behavior' => 'author',
        ),
        'state' => array(
          'label' => 'State',
          'type' => 'text',
          'behavior' => '',
        ),
      ),
    ),
  );
  return $items;
}
