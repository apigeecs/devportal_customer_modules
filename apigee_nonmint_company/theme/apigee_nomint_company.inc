<?php

function apigee_nomint_company_developer_companies(&$variables) {
    global $user;
    $companies = $variables['companies'];
    drupal_add_css(drupal_get_path('module', 'apigee_company') . '/css/apigee_company.css', 'file');

    $rows = array();
    $row_link_options = array(
        'attributes' => array(
            'class' => array('btn', 'btn-default', 'leave-company-btn'),
        ),
    );

    foreach ($companies as $company) {
        $leave_link = l(t('Leave'), 'api_company/company/developer/leave/' . $company->name, $row_link_options);
        // If the current developer is the owner of the company then don't show
        // the leave link.
        if ($company->attributes['ADMIN_EMAIL'] == $user->mail) {
            $leave_link = t("Owner");
        }

        // @TODO: This URL should be modified by monetization module.
        $company_link_options = array('query' => array('destination' => 'api_company/company/developers'));
        $company_cell = l($company->displayName, 'api_company/company/switch/' . $company->name, $company_link_options);

        $rows[] = array(
            'data' => array(
                'company' => array(
                    'data' => $company_cell,
                ),
                'leave' => array(
                    'data' => $leave_link,
                ),
            ),
        );
    }

    $header = array(
        'company' => array(
            'data' => t('Companies'),
            'colspan' => 2,
        ),
    );
    $attributes = array(
        'class' => array('apigee-company-tables', 'developers-company-list'),
    );

    $output = theme('table', array(
        'header' => $header,
        'rows' => $rows,
        'attributes' => $attributes,
        'empty' => t('You are not a member of any companies.'),
    ));
    if (user_access('manage company users')) {
        $output .= '<div class="create-company-container">';
        $link_options = array(
            'attributes' => array(
                'class' => array('btn', 'btn-default', 'create-company-btn'),
            ),
        );
        $output .= l(t('Create company'), "api_company/developer/company/add", $link_options);
        $output .= '</div>';
    }
    return $output;
}