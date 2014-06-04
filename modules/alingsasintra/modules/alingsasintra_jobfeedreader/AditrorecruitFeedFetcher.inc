<?php
/**
 * Fetches data via HTTP.
 */
class AditrorecruitFeedFetcher extends FeedsFetcher {

  /**
   * Implements FeedsFetcher::fetch().
   */
  public function fetch(FeedsSource $source) {
    $source_config = $source->getConfigFor($this);

    return new AditrorecruitFeedsResult($source_config['source'], $source->feed_nid);
  }

  /**
   * Clear caches.
   */
  public function clear(FeedsSource $source) {
    $source_config = $source->getConfigFor($this);
    $url = $source_config['source'];
    feeds_include_library('http_request.inc', 'http_request');
    http_request_clear_cache($url);
  }

  /**
   * Implements FeedsFetcher::request().
   */
  public function request($feed_nid = 0) {
    feeds_dbg($_GET);
    @feeds_dbg(file_get_contents('php://input'));

      try {
        feeds_source($this->id, $feed_nid)->existing()->import();
      }
      catch (Exception $e) {
        // In case of an error, respond with a 503 Service (temporary) unavailable.
        header('HTTP/1.1 503 "Not Found"', NULL, 503);
        exit();
      }

    // Will generate the default 200 response.
    header('HTTP/1.1 200 "OK"', NULL, 200);
    exit();
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    return array(
    );
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = array();
    return $form;
  }

  /**
   * Expose source form.
   */
  public function sourceForm($source_config) {
    $form = array();
    $form['source'] = array(
      '#type' => 'textfield',
      '#title' => t('URL'),
      '#description' => t('Enter a feed URL.'),
      '#default_value' => isset($source_config['source']) ? $source_config['source'] : '',
      '#maxlength' => NULL,
      '#required' => TRUE,
    );
    return $form;
  }

  /**
   * Override parent::sourceFormValidate().
   */
  public function sourceFormValidate(&$values) {
    if (!feeds_valid_url($values['source'], TRUE)) {
      $form_key = 'feeds][' . get_class($this) . '][source';
      form_set_error($form_key, t('The URL %source is invalid.', array('%source' => $values['source'])));
    }
  }

}

/**
 * Definition of the import batch object created on the fetching stage by
 * FeedsHTTPFetcher.
 */
class AditrorecruitFeedsResult extends FeedsFetcherResult {
  protected $url;
  protected $file_path;

  /**
   * Constructor.
   */
  public function __construct($url = NULL, $feed_nid) {
    $this->url = $url;
    parent::__construct('', $feed_nid);
  }

  /**
   * Implementation of FeedsImportBatch::getRaw();
   */
  public function getRaw() {
    $xml = "<!--?xml version=\"1.0\" encoding=\"utf-8\"?-->\n<Assignmentlist>\n";
    feeds_include_library('http_request.inc', 'http_request');
    $result = http_request_get($this->url);
    if (!in_array($result->code, array(200, 201, 202, 203, 204, 205, 206))) {
      throw new Exception(t('Download of @url failed with code !code.', array('@url' => $this->url, '!code' => $result->code)));
    }
    preg_match_all("/<Guid>(.*)<\/Guid>/U", $result->data, $items);
    $item_url = str_replace('AssignmentList', 'AssignmentItem', $this->url);
    foreach($items[1] as $item) {
      $result = http_request_get($item_url.'&guidAssignment='.$item);
      if (!in_array($result->code, array(200, 201, 202, 203, 204, 205, 206))) {
        continue;
      }
      else {
        $str = str_replace('<?xml version="1.0" encoding="utf-8"?>', '', $result->data);
        $xml .= $str;
      }
    }
    //drupal_set_message('<pre>'.$xml.'</pre>');
    $xml .= "\n</Assignmentlist>";
    return $xml;
  }
}
