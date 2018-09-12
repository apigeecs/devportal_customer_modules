<?php
/**
 * @file
 * ApigeeNonMintCompanyInvitation.inc
 */

/**
 * Controller class for Company Invitation
 *
 * Class ApigeeNonMintCompanyInvitation
 */
class ApigeeNonMintCompanyInvitation extends ApigeeCompanyInvitationController{
  
  /**
   * {@inheritdoc}
   */
  public function load($ids = array(), $conditions = array()) {
    if (isset($conditions['companyId'])) {
      $conditions['company_id'] = $conditions['companyId'];
      unset($conditions['companyId']);
    }
    if (isset($conditions['developerId'])) {
      $conditions['developer_id'] = $conditions['developerId'];
      unset($conditions['developerId']);
    }
    $entities = entity_load('company_invitation_non_mint', empty($ids)? FALSE : $ids , $conditions);
    $new_entities = [];
    foreach($entities as $id=>$entity){
      $new_entities[$id] = new ApigeeCompanyInvitationEntity($entity);
    }
    return $new_entities;
  }
  
  /**
   * {@inheritdoc}
   */
  public function save($entity) {
    $company = entity_load_single('apigee_company', $entity->companyId);
    $exists = FALSE;
    foreach ($company->developers as $role => $developers) {
      if (in_array($entity->developerId, $developers)) {
        drupal_set_message("Developer already exists in this company.", 'error');
        $exists = TRUE;
        break;
      }
    }
    if (!$exists) {
      $config = devconnect_default_org_config();
      $entity->company_id = $entity->companyId;
      $entity->developer_id = $entity->developerId;
      $entity->org = $config->orgName;
      if ($entity->is_new) {
        $entity->state  = "PENDING";
      }
      $_user = user_load_by_mail($entity->sourceDeveloperEmail);
      $entity->source_developer = $_user->uid;
      $entity->invitation_type = $entity->type;
      $entity->type = 'company_invitation_non_mint';
      $entity = (object) ((array) $entity);
      return entity_save('company_invitation_non_mint', $entity);
    }
  }
  
  /**
   * {@inheritdoc}
   */
  public function delete($ids) {
    return entity_delete_multiple('company_invitation_non_mint', $ids);
  }
}
