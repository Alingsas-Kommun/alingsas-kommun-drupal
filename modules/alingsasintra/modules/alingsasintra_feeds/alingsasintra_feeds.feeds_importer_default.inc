<?php
/**
 * @file
 * alingsasintra_feeds.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function alingsasintra_feeds_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'aditrorecruit_importer';
  $feeds_importer->config = array(
    'name' => 'Aditrorecruit Importer',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'AditrorecruitFeedFetcher',
      'config' => array(),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'Guid',
          'xpathparser:1' => 'Localization/AssignmentLoc/AssignmentTitle',
          'xpathparser:2' => 'Localization/AssignmentLoc/WorkDescr',
          'xpathparser:3' => 'Localization/AssignmentLoc/DepartmentDescr',
          'xpathparser:4' => 'Localization/AssignmentLoc/Qualifications',
          'xpathparser:5' => 'Localization/AssignmentLoc/EmploymentType/Name',
          'xpathparser:6' => 'Localization/AssignmentLoc/EmploymentType/Descr',
          'xpathparser:7' => 'Localization/AssignmentLoc/EmploymentDuration/Name',
          'xpathparser:8' => 'Localization/AssignmentLoc/EmploymentDuration/Descr',
          'xpathparser:9' => 'EmploymentStartDate',
          'xpathparser:10' => 'ApplicationEndDate',
          'xpathparser:11' => 'RefNo',
          'xpathparser:12' => 'ApplicationMethods/ApplicationMethod[1]/ValueXml/web/url',
          'xpathparser:13' => 'Localization/AssignmentLoc/SalaryType/Name',
          'xpathparser:14' => 'Localization/AssignmentLoc/SalaryType/Descr',
          'xpathparser:15' => 'NumberOfJobs',
          'xpathparser:16' => 'Localization/AssignmentLoc/WorkShift/Name',
          'xpathparser:17' => 'Localization/AssignmentLoc/WorkShift/Descr',
          'xpathparser:18' => 'ContactPersons/ContactPerson[1]/ContactName',
          'xpathparser:19' => 'ContactPersons/ContactPerson[1]/Title',
          'xpathparser:20' => 'ContactPersons/ContactPerson[1]/Telephone',
          'xpathparser:21' => 'ContactPersons/ContactPerson[1]/Email',
          'xpathparser:22' => 'ContactPersons/ContactPerson[2]/ContactName',
          'xpathparser:23' => 'ContactPersons/ContactPerson[2]/Title',
          'xpathparser:24' => 'ContactPersons/ContactPerson[2]/Telephone',
          'xpathparser:25' => 'ContactPersons/ContactPerson[2]/Email',
          'xpathparser:26' => 'Localization/AssignmentLoc/AdditionalInfo',
          'xpathparser:27' => 'PublishStartDate',
          'xpathparser:28' => 'PublishEndDate',
          'xpathparser:29' => 'Departments/Department[2]/Name',
          'xpathparser:30' => 'EmploymentEndDate',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
          'xpathparser:13' => 0,
          'xpathparser:14' => 0,
          'xpathparser:15' => 0,
          'xpathparser:16' => 0,
          'xpathparser:17' => 0,
          'xpathparser:18' => 0,
          'xpathparser:19' => 0,
          'xpathparser:20' => 0,
          'xpathparser:21' => 0,
          'xpathparser:22' => 0,
          'xpathparser:23' => 0,
          'xpathparser:24' => 0,
          'xpathparser:25' => 0,
          'xpathparser:26' => 0,
          'xpathparser:27' => 0,
          'xpathparser:28' => 0,
          'xpathparser:29' => 0,
          'xpathparser:30' => 0,
        ),
        'context' => '/Assignmentlist/AssignmentDetails/Assignment',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
            'xpathparser:13' => 0,
            'xpathparser:14' => 0,
            'xpathparser:15' => 0,
            'xpathparser:16' => 0,
            'xpathparser:17' => 0,
            'xpathparser:18' => 0,
            'xpathparser:19' => 0,
            'xpathparser:20' => 0,
            'xpathparser:21' => 0,
            'xpathparser:22' => 0,
            'xpathparser:23' => 0,
            'xpathparser:24' => 0,
            'xpathparser:25' => 0,
            'xpathparser:26' => 0,
            'xpathparser:27' => 0,
            'xpathparser:28' => 0,
            'xpathparser:29' => 0,
            'xpathparser:30' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'body',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_jf_departmentdesc',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_jf_qualifications',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_jf_employmenttype_nam',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_jf_employmenttype_des',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_jf_employmentgrade_na',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_jf_employmentgrade_de',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_jf_employmentstartdate:start',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_jf_applicationenddate:start',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_jf_referencenumber',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_jf_applicationmethods:url',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_jf_salarytype',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'xpathparser:14',
            'target' => 'field_jf_salarytype_desc',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'xpathparser:15',
            'target' => 'field_jf_numberofjobs',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'xpathparser:16',
            'target' => 'field_jf_workshift',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'xpathparser:17',
            'target' => 'field_jf_workshift_desc',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'xpathparser:18',
            'target' => 'field_jf_contact1_name',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'xpathparser:19',
            'target' => 'field_jf_contact1_title',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'xpathparser:20',
            'target' => 'field_jf_contact1_phone',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'xpathparser:21',
            'target' => 'field_jf_contact1_email',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'xpathparser:22',
            'target' => 'field_jf_contact2_name',
            'unique' => FALSE,
          ),
          23 => array(
            'source' => 'xpathparser:23',
            'target' => 'field_jf_contact2_title',
            'unique' => FALSE,
          ),
          24 => array(
            'source' => 'xpathparser:24',
            'target' => 'field_jf_contact2_phone',
            'unique' => FALSE,
          ),
          25 => array(
            'source' => 'xpathparser:25',
            'target' => 'field_jf_contact2_email',
            'unique' => FALSE,
          ),
          26 => array(
            'source' => 'xpathparser:26',
            'target' => 'field_jf_additionalinfo',
            'unique' => FALSE,
          ),
          27 => array(
            'source' => 'xpathparser:27',
            'target' => 'field_jf_publishdate:start',
            'unique' => FALSE,
          ),
          28 => array(
            'source' => 'xpathparser:28',
            'target' => 'field_jf_publishdate:end',
            'unique' => FALSE,
          ),
          29 => array(
            'source' => 'xpathparser:29',
            'target' => 'field_jf_department',
            'unique' => FALSE,
          ),
          30 => array(
            'source' => 'xpathparser:30',
            'target' => 'field_jf_employmentenddate:start',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'alingsas_job',
      ),
    ),
    'content_type' => 'aditrorecruit_job_import',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['aditrorecruit_importer'] = $feeds_importer;

  return $export;
}
