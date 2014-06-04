<?php

/**
 * Connector to  REST-services of Alfresco
 * must implement:
 * - setUser()
 * - setUrl()
 */

class AlfrescoConnector {

  private $url;
  private $user;
  private $requesttype;
  private $connection;
  public $request;
  private $response;
  private $data = false;
  private $error = '';
  private $header_options = array();
  private $host;

  public function __construct($host = false, $user = false) {
    $this->setRequesttype('GET');
    if($host) {
      $this->setHost($host);
    }
    if($user) {
      $this->setUser($user);
    }
    $this->connection = curl_init();
  }

  public function __destruct() {
    if($this->connection) {
      curl_close($this->connection);
    }
  }

  public function setRequesttype($type) {
    if(in_array($type, array('GET', 'POST', 'PUT', 'DELETE'))) {
      $this->requesttype = $type;
    }
    else {
      throw new Exception('This is an unknown requesttype.');
    }
    return $this;
  }

  public function setHost($host) {
    if(strpos($host, 'http://') === 0 || strpos($host, 'https://') === 0) {
      $this->host = $host;
      $this->request = $this->host.$this->url;
    }
    else {
      throw new Exception('The given url has no protocol defined.');
    }
    return $this;
  }

  public function setUrl($url) {
    $this->url = $url;
    $this->request = $this->host.$this->url;
    return $this;
  }

  public function setUser($user) {
    if(is_string($user)) {
      $this->user = $user;
    }
    elseif (is_object($user)) {
      $this->user = $user->name;
    }
    return $this;
  }

  public function getUser() {
    return $this->user;
  }

  public function setData($data) {
    $this->data = $data;
    return $this;
  }

  public function getResponse() {
    return $this->response;
  }

  public function getError() {
    return $this->error;
  }

  private function GET() {
    curl_setopt($this->connection, CURLOPT_CUSTOMREQUEST, 'GET');
    $http_query = $this->data ? $this->data : null;
    if($http_query) {
      if(is_array($http_query)) {
        $http_query = http_build_query($http_query);
      }
      else {
        $http_query = urlencode($http_query);
      }
      $this->request .= (strpos($this->url, '?') ? '&' : '?').$http_query;
    }
  }

  private function POST() {
    curl_setopt($this->connection, CURLOPT_CUSTOMREQUEST, 'POST');
    curl_setopt($this->connection, CURLOPT_POST, TRUE);
    $http_data = $this->data ? $this->data : null;
    if(is_array($http_data)) {
      $http_data = http_build_query($http_data);
    }
    if($http_data) {
      curl_setopt($this->connection, CURLOPT_POSTFIELDS, $http_data);
      $this->header_options[] = 'Content-Length: ' . strlen($http_data);
      if(json_decode($http_data) != NULL) {
        $this->header_options[] = 'Content-Type: application/json';
      }
      else {
        $this->header_options[] = 'Content-Type: application/cmisquery+xml';
      }
    }
    $this->header_options[] = 'Content-Type: application/cmisquery+xml';
  }

  private function PUT() {
    curl_setopt($this->connection, CURLOPT_CUSTOMREQUEST, 'POST');
  }

  private function DELETE() {
    curl_setopt($this->connection, CURLOPT_CUSTOMREQUEST, 'GET');
  }

  public function execute() {

    curl_setopt($this->connection, CURLOPT_HTTP_VERSION, CURLOPT_HTTP_VERSION_1_0);
    $requesttype = $this->requesttype;
    $this->$requesttype();

    if(!$this->request) {
      $this->error = 'No host or url defined.';
      return false;
    }
    else {
      curl_setopt($this->connection, CURLOPT_URL, $this->request);
    }

    if($this->user) {
      $this->header_options[] = 'X-Alfresco-Remote-User: '.$this->user;
    }

    $authentication = variable_get('alingsasintra_alfresco_cmis_user', false);
    if($authentication) {
      curl_setopt($this->connection, CURLOPT_USERPWD, $authentication);
    }

    curl_setopt($this->connection, CURLOPT_HTTPHEADER, $this->header_options);
    curl_setopt($this->connection, CURLOPT_FOLLOWLOCATION, true);
    curl_setopt($this->connection, CURLOPT_RETURNTRANSFER, true);

    $this->error = '';

    $result = curl_exec($this->connection);
    if($_GET['DEBUG']) {
      echo "\nConnection:".print_r(curl_getinfo($this->connection), TRUE);
      echo "\nData:".$this->data;
      echo "\nResult:".$result;
      echo "\n\n";
    }
    if($result !== false) {
      $this->response = $result;
      return true;
    }
    $this->error = curl_error($this->connection);
    return false;
  }

  public function debug() {
    $dump = print_r(curl_getinfo($this->connection), TRUE);
    $dump .= print_r($this->data, TRUE);
    $dump .= print_r($this->response, TRUE);
    return $dump;
  }

}

class AlfrescoEntityManager {

  private $connection;
  private $public_host = false;
  private $unit_of_work = array();
  private $repository = array();
  public $search_count_all = 0;
  public $search_pages = 0;
  public $items_per_page = 0;

  public function __construct($connector) {
    module_load_include('php', 'cmis_common', '/lib/cmis_repository_wrapper');
    $this->connection = $connector;
  }

  public function __call($method, $args) {
    //some lazy loading here?
    throw new Exception($func." is not defined!");
  }

  public function setPublicHost($public_host) {
    $this->public_host = $public_host;
    return $this;
  }

  /**
   * @param string $id
   * @return AlfrescoRepository
   */
  public function getRepository($id = false) {
    if(!$id) $id = 'default';
    if(!$this->repository[$id]) {
      $this->repository[$id] = new AlfrescoRepository($this);
    }
    return $this->repository[$id];
  }

  public function getMydocuments() {
    if(!$this->repository['_my_documents']) {
      $this->repository['_my_documents'] = new AlfrescoRepository();
      $this->connection->setRequesttype('GET')->setUrl('/share/proxy/alfresco/slingshot/doclib/doclist/documents/node/alfresco/sites/home?max=50&filter=recentlyModifiedByMe');
      if($this->connection->execute()) {
        $docs = json_decode($this->connection->getResponse(), TRUE);
        var_dump($this->connection->getResponse()); exit;
        foreach($docs as $item) {
          $item = new AlfrescoDocument($item);
          $this->repository['_my_documents']->add($item);
        }
      }
      else {
        print $this->connection->getError(); exit;
      }
    }
    return $this->repository['_my_documents']->sort();
  }

  public function getMytasks() {
    if(!$this->repository['_my_tasks']) {
      $this->repository['_my_tasks'] = new AlfrescoRepository();
      $this->connection->setRequesttype('GET')->setUrl('/alfresco/wcs/api/task-instances');
      if($this->connection->execute()) {
        $tasks = json_decode($this->connection->getResponse(), TRUE);
        if(isset($tasks['data']) && count($tasks['data'])) {
          foreach($tasks['data'] as $item) {
            $item = new AlfrescoNode($item);
            $this->repository['_my_tasks']->add($item);
          }
        }
      }
      else {
        print $this->connection->getError(); exit;
      }
    }
    return $this->repository['_my_tasks']->sort();
  }

  public function getMyactivities() {
    if(!$this->repository['_my_activities']) {
      $this->repository['_my_activities'] = new AlfrescoRepository();
      $this->connection->setRequesttype('GET')->setUrl('/alfresco/wcs/api/activities/feed/user?format=json');
      if($this->connection->execute()) {
        $activities = json_decode($this->connection->getResponse(), TRUE);
        if(isset($activities) && count($activities)) {
          foreach($activities as $item) {
            $item['activitySummary'] = json_decode($item['activitySummary'], TRUE);
            $item = new AlfrescoNode($item);
            $this->repository['_my_activities']->add($item);
          }
        }
      }
      else {
        print $this->connection->getError(); exit;
      }
    }
    return $this->repository['_my_activities'];
  }


  public function getSites() {
    if(!$this->repository['_my_sites']) {
      $this->repository['_my_sites'] = new AlfrescoRepository();
      $this->connection->setRequesttype('GET')->setUrl('/alfresco/wcs/api/people/' . $this->connection->getUser() . '/sites?roles=user&size=100');
      if($this->connection->execute()) {
        $sites = json_decode($this->connection->getResponse(), TRUE);
        //fetch favourites
        $this->connection->setRequesttype('GET')->setUrl('/alfresco/wcs/api/people/' . $this->connection->getUser() . '/preferences?pf=org.alfresco.share.sites');
        if($this->connection->execute()) {
          $favourites = json_decode($this->connection->getResponse());
          $items = array();
          foreach($favourites->org->alfresco->share->sites->favourites as $key => $value) {
            if($value == true) {
              $items[] = $key;
            }
          }
        }

        foreach($sites as $item) {
          $item = new AlfrescoSite($item);
          $item->setHref($this->public_host.'/share/page/site/'.$item->shortName.'/dashboard');
          if(in_array($item->shortName, $items)) {
            $item->setFavourite(TRUE);
          }
          $this->repository['_my_sites']->add($item);
        }
      }
      else {
        print $this->connection->getError(); exit;
      }
    }
    return $this->repository['_my_sites']->sort();
  }

  public function getChildren($object) {
    $result = array();
    if($object) {
      //get children
      $this->connection->setRequesttype('GET')->setUrl('/alfresco/cmisatom/'.variable_get('alingsasintra_alfresco_cmis_endpoint','').'/children?id=workspace://SpacesStore/'.$object->getId());

      if($this->connection->execute()) {
        $xmldata = $this->connection->getResponse();
        $objects = CMISRepositoryWrapper::extractObjectFeed($xmldata);
        if($object instanceof AlfrescoSite) {
          //it's a site - fetch documentlibrary
          $this->connection->setRequesttype('GET')->setUrl('/alfresco/cmisatom/'.variable_get('alingsasintra_alfresco_cmis_endpoint','').'/children?id=workspace://SpacesStore/'.basename($objects->objectList[0]->properties['cmis:objectId']));
          $this->connection->execute();
          $xmldata = $this->connection->getResponse();
          $objects = CMISRepositoryWrapper::extractObjectFeed($xmldata);
        }

        foreach($objects->objectList as $entry) {
          $item = null;
          if($entry->properties['cmis:baseTypeId'] == 'cmis:folder') {
            $item = new AlfrescoFolder($this->_mapCmisProperties($entry->properties));
            $item->setType('folder');
          }
          elseif($entry->properties['cmis:baseTypeId'] == 'cmis:document') {
            $item = new AlfrescoDocument($this->_mapCmisProperties($entry->properties));
            $item->setHref($this->public_host.'/share/proxy/alfresco/api/node/content/workspace/SpacesStore/'.$item->getId().'/'.$item->name);
            $item->setType('document');
          }
          if($item) {
            $item->setRepository($object->getRepository());
            $result[] = $item;
          }
        }
        return $result;
      }
      else {
        return($this->connection->getError());
      }
    }
  }

  public function fetchNode($id) {
    if($id) {
      //get properties
      $this->connection->setRequesttype('GET')->setUrl('/alfresco/cmisatom/'.variable_get('alingsasintra_alfresco_cmis_endpoint','').'/id?id=workspace://SpacesStore/'.$id);

      if($this->connection->execute()) {
        $xmldata = $this->connection->getResponse();
        $object = CMISRepositoryWrapper::extractObject($xmldata);
        if($object->properties['cmis:objectTypeId'] == 'F:st:site') {
          $item = new AlfrescoSite($this->_mapCmisProperties($object->properties));
        }
        elseif($object->properties['cmis:baseTypeId'] == 'cmis:folder') {
          $item = new AlfrescoFolder($this->_mapCmisProperties($object->properties));
        }
        elseif($object->properties['cmis:baseTypeId'] == 'cmis:document') {
          $item = new AlfrescoDocument($this->_mapCmisProperties($object->properties));
          $item->setHref($this->public_host.'/share/proxy/alfresco/api/node/content/workspace/SpacesStore/'.$item->getId().'/'.$item->name.'?a=true');
        }
        return $item;
      }
      else {
        return($this->connection->getError());
      }
    }
  }

  public function search($q, $type = null, $page = 0) {
    $repositories = false;
    if(strlen($q) > 0) {
      $settings = variable_get('alingsasintra_alfresco_search', false);
      foreach($settings as $key=>$value) {
        if($value['type'] == $type) {
          $repositories = $value;
          break;
        }
      }

      if($repositories) {
          $query =  "SELECT D.cmis:objectTypeId, D.cmis:objectId, D.cmis:name, D.cmis:lastModifiedBy,D.cmis:lastModificationDate,A.akdm:documentNumber,A.akdm:documentStatus,A.akdm:documentSecrecy, T.cm:title, T.cm:description, SCORE() SEARCH_SCORE ";
          $query .= "FROM akdm:document D ";
          $query .= "JOIN akdm:commonAspect AS A ON D.cmis:objectId = A.cmis:objectId ";
          $query .= "JOIN cm:titled AS T ON D.cmis:objectId = T.cmis:objectId ";
          $query .= "WHERE ";
          if($q) {
            $query .= "(D.cmis:name LIKE '%".$q."%' OR CONTAINS(D,'".$q."')) AND ";
          }
          $query .= "A.akdm:documentStatus='Färdigt dokument' ";
          $query .= "AND A.akdm:documentSecrecy='Offentligt' ";
          $query .= "AND D.cmis:objectTypeId NOT LIKE 'D:akdm:byggredadocument' ";
          $query .= "AND (IN_TREE(D, 'workspace://SpacesStore/".($repositories['global'] ? $repositories['global'] : "29a512ae-81e3-4b55-b5cc-b8bd7abfab8d")."') "; //Gemensamma regler rutiner etc., denna skall alltid vara med
          //Narrow down the search to specific folders, the IN_TREE function takes a node ref of a folder to use as base
          //Include all following lines when no restriction is set on förvaltning, when restricting by förvaltning, include only one of them:
          if($_GET['org'] && $repositories['endpoints'][$_GET['org']]) {
            $query .= "OR IN_TREE(D, 'workspace://SpacesStore/".$repositories['endpoints'][$_GET['org']]."') ";
          }
          else {
            foreach($repositories['endpoints'] as $key => $value) {
              $query .= "OR IN_TREE(D, 'workspace://SpacesStore/".$value."') ";
            }
          }
          $query .= ") ";
          $query .= "ORDER BY SEARCH_SCORE ASC, D.cmis:name ASC";
      } else {
          $query =  "SELECT D.cmis:objectTypeId, D.cmis:objectId, D.cmis:name, D.cmis:lastModifiedBy,D.cmis:lastModificationDate,A.akdm:documentNumber,A.akdm:documentStatus,A.akdm:documentSecrecy, T.cm:title, T.cm:description, SCORE() SEARCH_SCORE ";
          $query .= "FROM akdm:document D ";
          $query .= "JOIN akdm:commonAspect AS A ON D.cmis:objectId = A.cmis:objectId ";
          $query .= "JOIN cm:titled AS T ON D.cmis:objectId = T.cmis:objectId ";
          $query .= "WHERE ";
          if($q) {
            $query .= "(D.cmis:name LIKE '%".$q."%' OR CONTAINS(D,'".$q."')) AND ";
          }
          $query .= "A.akdm:documentStatus='Färdigt dokument' ";
          $query .= "AND A.akdm:documentStatus='Färdigt dokument' ";
          $query .= "AND A.akdm:documentSecrecy='Offentligt' ";
          $query .= "AND D.cmis:objectTypeId NOT LIKE 'D:akdm:byggredadocument' ";
          $query .= "ORDER BY SEARCH_SCORE ASC, D.cmis:name ASC";
      }

      $maxitems = variable_get('alingsasintra_alfresco_search_maxitems', 30);
      $skipcount = $page*$maxitems;
      $cmis_query = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>'."\n";
      $cmis_query .=<<<EOL
<cmis:query xmlns:cmis="http://docs.oasis-open.org/ns/cmis/core/200908/"
xmlns:cmism="http://docs.oasis-open.org/ns/cmis/messaging/200908/"
xmlns:atom="http://www.w3.org/2005/Atom"
xmlns:app="http://www.w3.org/2007/app"
xmlns:cmisra="http://docs.oasisopen.org/ns/cmis/restatom/200908/">
<cmis:statement>{$query}</cmis:statement>
<cmis:maxItems>{$maxitems}</cmis:maxItems>
<cmis:skipCount>{$skipcount}</cmis:skipCount>
</cmis:query>
EOL;
      $this->connection->setData($cmis_query);
      $this->connection->setRequesttype('POST')->setUrl('/alfresco/cmisatom/'.variable_get('alingsasintra_alfresco_cmis_endpoint','').'/query');
      if($this->connection->execute()) {
        $xmldata = $this->connection->getResponse();
        $this->search_count_all = CMISRepositoryWrapper::doXQuery($xmldata, 'opensearch:totalResults');
        $this->search_count_all = $this->search_count_all ? $this->search_count_all->item(0)->nodeValue : 0;
        if($this->search_count_all > $maxitems) {
          $this->search_pages = ceil($this->search_count_all/$maxitems);
        }
        $objects = CMISRepositoryWrapper::extractObjectFeed($xmldata);
        foreach($objects->objectList as $entry) {
          $item = new AlfrescoDocument($this->_mapCmisProperties($entry->properties));
          $item->setHref($this->public_host.'/share/proxy/alfresco/api/node/content/workspace/SpacesStore/'.$item->getId().'/'.$item->name.'?a=true');
          $item->setType('document');
          $this->getRepository()->add($item);
        }
        return $this->getRepository();
      }
      else {
        drupal_set_message($this->connection->getError(), 'error');
        return $this->getRepository();
      }
    }
    else {
      drupal_set_message(t('The search term has to be at least one character.'), 'error');
      return $this->getRepository();
    }
  }

  public function _mapCmisProperties($cmis) {
    $result = array();
    foreach($cmis as $key => $value) {
      if($key == '') continue;
      $result[$key] = $value;
      switch ($key) {
        case 'cmis:objectId':
          $result['node'] = $value;
          break;
        case 'cmis:name':
          $result['name'] = $value;
          break;
        case 'cmis:path':
          $result['path'] = $value;
          break;
        case 'cm:title':
          $result['title'] = $value;
          break;
        case 'cm:description':
          $result['description'] = $value;
          break;
        case 'cmis:lastModificationDate':
          $result['date'] = strtotime($value);
          break;
        case 'cmis:lastModifiedBy':
          $result['author'] = $value;
          break;
        case 'akdm:documentSecrecy':
          if($value == 'Sekretessbelagt') $result['private'] = TRUE;
          break;
      }
    }
    return $result;
  }

  public function persist($item) {
    if($item->hasChanged()) {
      $this->unit_of_work[$item->shortName] = $item;
    }
    return $this;
  }

  public function flush() {
    $error = array();
    foreach($this->unit_of_work as $item) {
      //only favourite_status for now
      $this->connection->setRequesttype('POST')->setUrl('/alfresco/wcs/api/people/' . $this->connection->getUser() . '/preferences');
      $data = '{"org":{"alfresco":{"share":{"sites":{"favourites":{"'.$item->shortName.'":'.($item->getFavourite() ? 'true' : 'false').'}}}}}}';
      $this->connection->setData($data);
      if(!$this->connection->execute()) {
        $error[] = $this->connection->getError();
      }
    }
    if(count($error) > 0) {
      return FALSE;
    }
    return TRUE;
  }

}

class AlfrescoRepository implements ArrayAccess, Iterator, Countable
{
	private $container = array();
	private $id = false;
	private $_em = false;

	public function __construct($_em) {
	  $this->_em = $_em;
	}

	public function add($item) {
	  $item->setRepository($this);
	  $this->container[] = $item;
	  return $this;
	}

	public function sort() {
	  usort($this->container, function($a, $b) {
	    return strcasecmp($a->title, $b->title);
	  });
	  return $this;
	}

	public function findByShortName($name) {
	  foreach($this->container as $item) {
	    if($item->shortName == $name) {
	      return $item;
	    }
	  }
	  return false;
	}

	public function findById($id) {
	  foreach($this->container as $item) {
	    if($item->id == $id) {
	      return $item;
	    }
	  }

	  $item = $this->_em->fetchNode($id);
	  $this->add($item);
	  return $item;
	}

	public function findFavourites() {
	  $result = array();
	  foreach($this->container as $item) {
	    if($item->getFavourite()) {
	      $result[] = $item;
	    }
	  }
	  return $result;
	}

	public function getEntityManager() {
	  return $this->_em;
	}

	/*
	* to use ArrayAccess
	*/
	public function offsetSet($offset,$value)
	{
		if ($offset == "")
		{
			$this->container[] = $value;
		}
		else
		{
			$this->container[$offset] = $value;
		}
	}

	/*
	* to use ArrayAccess
	*/
	public function offsetExists($offset)
	{
		return isset($this->container[$offset]);
	}

	/*
	* to use ArrayAccess
	*/
	public function offsetUnset($offset)
	{
		unset($this->container[$offset]);
	}

	/*
	* to use ArrayAccess
	*/
	public function offsetGet($offset)
	{
		return isset($this->container[$offset]) ? $this->container[$offset] : null;
	}

	/*
	* to use Iterator
	*/
	public function rewind()
	{
		reset($this->container);
	}

	/*
	* to use Iterator
	*/
	public function current()
	{
		return current($this->container);
	}

	/*
	* to use Iterator
	*/
	public function key()
	{
		return key($this->container);
	}

	/*
	* to use Iterator
	*/
	public function next()
	{
		return next($this->container);
	}

	/*
	* to use Iterator
	*/
	public function valid()
	{
		return $this->current() !== false;
	}

	/*
	* to use Countable
	*/
	public function count()
	{
		return count($this->container);
	}

}

class AlfrescoSite extends AlfrescoNode {

  private $favourite = NULL;
  private $children = FALSE;

  public function setFavourite($favourite) {
    if($this->favourite !== $favourite) {
      $this->setChanged(TRUE);
      $this->favourite = $favourite;
    }
    return $this;
  }

  public function getFavourite() {
    return $this->favourite;
  }

  public function getChildren() {
    if($this->children === FALSE) {
      $this->children = $this->getRepository()->getEntityManager()->getChildren($this);
    }
    return $this->children;
  }

  public function setChildren() {
    if($this->children === FALSE) {
      $this->children = $this->getRepository()->getEntityManager()->getChildren($this);
    }
    return $this->children;
  }

}

class AlfrescoDocument extends AlfrescoNode {

}

class AlfrescoFolder extends AlfrescoNode {

  private $children = FALSE;

  public function getChildren() {
    if($this->children === FALSE) {
      $this->children = $this->getRepository()->getEntityManager()->getChildren($this);
    }
    return $this->children;
  }

}

class AlfrescoNode {

  private $repository = FALSE;
  private $has_changed = FALSE;
  public $id = FALSE;
  public $description = FALSE;
  public $type = FALSE;
  public $href;
  public $private = FALSE;
  //let's run the variables dynamically for now

  public function __construct($parameters = array()) {
    if (count($parameters)) {
      foreach($parameters as $key => $value) {
        $this->$key = $value;
        if($key == 'node' && $value) {
          $this->id = basename($value);
          if(strpos($this->id, ';')) {
            $this->id = array_shift(split(';', $this->id));
          }
        }
        if($key == 'visibility' && $value == 'PRIVATE') {
          $this->private = TRUE;
        }
      }
    }
  }

  public function getId() {
    return $this->id;
  }

  public function setDescription($description) {
    $this->description = $description;
    return $this;
  }

  public function setType($type) {
    $this->type = $type;
    return $this;
  }

  public function setHref($href) {
    $this->href = $href;
    return $this;
  }

  public function getHref($href) {
    if($this->isPrivate()) {
      return '';
    }
    return $this->href;
  }

  public function setRepository($repository) {
    $this->repository = $repository;
    return $this;
  }

  public function getRepository() {
    return $this->repository;
  }

  public function setChanged($val) {
    $this->has_changed = $val;
    return $this;
  }

  public function hasChanged($val = null) {
    return $this->has_changed;
  }

  public function isPrivate() {
    return $this->private;
  }

}
