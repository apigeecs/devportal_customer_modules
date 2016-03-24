<?php

function apigee_nonmint_company_developer_companies(&$variables) {
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


/**
 * Returns HTML for the company context switcher.
 *
 * @param array $variables
 *   An associative array containing:
 *   - company_list: An array containing the company attributes, indexed by
 *     company id. Each element of the array has the following keys:
 *     - "id": The company's unique id.
 *     - "display_name": The company's display name.
 *     - 'url': The URL to call in order to switch to that company.
 *     Here's an example:
 *
 * @code
 *     $company_list = array(
 *       'apigee' => array(
 *         'id' => 'apigee',
 *         'display_name' => 'Apigee Corporation',
 *         'url' => 'api_company/company/switch/apigee',
 *       ),
 *     );
 * @endcode
 *
 * @return string
 *   HTML for the table switcher.
 */
function apigee_nonmint_company_switcher($variables) {
  $company_links = array();
  $company_list = &$variables['company_list'];
  foreach($company_list as $i => $company){
    if($company['name'] == null){
      $developer_company = $company;
      unset($company_list[$i]);
    }
  }
  uasort($variables['company_list'], function($a,$b){
    return strncmp(trim($a['display_name']),trim($b['display_name']),128);
  });

  $context = apigee_company_get_current_context_company();
  $path = current_path();
  $apps_path = drupal_match_path($path, implode("\n", array("user/*/apps", "user/*/apps/*", "user/*/app-detail/*")));
  $manage_path = drupal_match_path($path, implode("\n", array('api_company/company/developers', 'api_company/companies/list', "api_company/developer/company/add")));
  $links[] = array(
    'title' => "My Apps (Individual)",
    'href' => $developer_company['url'],
    'query' => array("destination" => 'user/me/apps'),
    'attributes' => array(
      'title' => $company['display_name'],
      'class' => array(
        'developer-apps ' . ($context == NULL && $apps_path? " active ": ""),
      ),
    ),
  );
  // Create link for each company.
  foreach ($variables['company_list'] as $company) {
    $links["company_apps"][] = array(
      'title' => $company['display_name'],
      'href' => $company['url'],
      'query' => array("destination" => 'user/me/apps'),
      'attributes' => array(
        'title' => $company['display_name'],
        'class' => array(
          'company-app-' . $company['name'] . ($context->name == $company['name'] && $apps_path? " active " : ""),
        ),
      ),
    );
    $links["manage_companies"][] = array(
      'title' => $company['display_name'],
      'href' => $company['url'],
      'query' => array("destination" => 'api_company/company/developers'),
      'attributes' => array(
        'title' => $company['display_name'],
        'class' => array(
          'manage-company-' . $company['name'] . ($context->name == $company['name'] && $manage_path? " active " : ""),
        ),
      ),
    );
  }
  $links["company_apps"] = array(
    'title' => "<span>Company Apps (Team)</span>" . theme('links', array('links' => $links["company_apps"])),
    'html' => TRUE,
  );
  $links["manage_companies"] = array(
    'title' => l('Manage Companies / Invitations',
        'api_company/company/switch/',
        array(
          'query' => array('destination' => 'api_company/companies/list'),
           'attributes' => array(
             'class' => array('manage-companies '. ($context == NULL && $manage_path ? " active ": ""))
           ),
          )
        ) . theme('links', array('links' => $links["manage_companies"])),
    'html' => TRUE,
  );
  return theme('links', array('links' => $links));
}
