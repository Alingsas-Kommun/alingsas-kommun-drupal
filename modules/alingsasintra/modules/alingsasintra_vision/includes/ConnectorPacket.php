<?php

/**
 *  @package Connector
 */

/**
 *  ConnectorPacket handles a single connector transaction and encodes/decodes data.
 */
class ConnectorPacket
{
    public $command = "";
    public $fields = array();
    public $errno = 0;
    public $errtext = "";

    public function __construct($command = null, array $fields = null)
    {
        if ($command != null)
            $this->command = $command;

        if ($fields != null)
        {
            foreach($fields as $k => $v)
                $this->fields[] = "$k=$v";
        }
    }

    public static function decode($packet)
    {
        if ($packet == "" || $packet[0] != CONNECTOR_STX || $packet[strlen($packet)-1] != CONNECTOR_ETX)
            return null;

        $packet = substr($packet, 1, strlen($packet) - 2);
        $x = explode(CONNECTOR_SEP, $packet);

        $result = new ConnectorPacket();
        $result->command = array_shift($x);
        $result->fields = $x;

        if ($result->command == "ERR")
        {
            $result->errno = $result->fields[0];
            $result->errtext = $result->fields[1];
        }

        return $result;
    }

    public function success()
    {
        return $this->errno == 0;
    }

    public function failed()
    {
        return $this->errno != 0;
    }

    public function get($code)
    {
        $code = $code . "=";
        $len = strlen($code);

        foreach($this->fields as $field)
            if (substr($field, 0, $len) == $code)
                return substr($field, $len);

        return "";
    }

    public function add($code, $data)
    {
        $this->fields[] = $code . "=" . $data;
    }

    public function packet()
    {
        if ($this->command == "")
            return "";

        return
            CONNECTOR_STX .
            $this->command .
            (count($this->fields) > 0 ? CONNECTOR_SEP . implode(CONNECTOR_SEP, $this->fields) : "") .
            CONNECTOR_ETX;
    }
}
