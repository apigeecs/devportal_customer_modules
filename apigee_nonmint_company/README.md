Apigee nonmint module is used for providing company features for non-monit orgs. Eg: creating a company, registering Apps under the company name, inviting developer etc.

 
 ## **How to install the module**
In order to use this module:
1. Clone / download this repo.
2. Place devportal_customer_modules/apigee_nonmint_company/ inside <your_site_repo>/sites/all/modules/custom/
3. Push the changes back to <your_site_repo> (only for on-cloud)
4. Log in to your dev portal with admin credentials
5. Goto {your_portal_site}/admin/modules
6. enable apigee_nonmint_company module, and save the changes.
7. goto {your_portal_site}/admin/structure/block and assign "Switch Company" block to a region and save the changes.

You should now able to find the "Switch Company" block in the region assigned.

## **How to use the module**

**Add a new company** 
This feature is available for only Company Administrator role on the developer portal 
1. Goto "switch company" block and select "manage companies" from the drop down"
2.  Select "create company" option 
3. Provide a name for the company and Save.
4.  A new company will be created and can be seen in "switch company" dropdown.

 **Invite Developers** 
 This feature is available for only Company Administrator role on the developer portal
 1. Goto Manage companies.
 2. Select the company name for which developer need to be invited.
 3. provide the email address of the developer and send the invite.
 4. Once the developer registers with the same email_Id, the developer can find the invites in the "switch company" block and once the invitation is accepted, the developer is added to the company, and can find the company in its list.

**Create Apps**
 This feature is available for only Developer role on the developer portal.
 1. Goto "my apps"
 2. provide app details
 3. select the product
 4. enter company name under which the app needs to be created, and save the changes.




