<?php

function devconnect_nonmint_company_entity_info() {
  $info = array(
    'company_invitation_non_mint' => array(
      'label' => t('Company Invitation (Non-Mint)'),
      'controller class' => 'NonMintCompanyInvitationController',
      'fieldable' => FALSE,
      'module' => 'devconnect_nonmint_company',
      'access callback' => TRUE,
      'entity keys' => array(
        'id' => 'appId',
        'name' => 'name',
      ),
    ),
  );
  return $info;

}