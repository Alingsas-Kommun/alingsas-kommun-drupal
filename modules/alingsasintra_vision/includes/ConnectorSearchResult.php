<?php

/**
 *  @package Connector
 */

/**
 *  ConnectorSearchResult encapsulates and formats a search result
 */
class ConnectorSearchResult
{
    public $searchCount   = 0;
    public $fields        = array();
    public $records       = array();

    // Constructor

    public function __construct(ConnectorPacket $packet)
    {
        if ($packet->command != 'SEARCH')
            die("ConnectorSearchResult: Packet is not a search result");

        foreach($packet->fields as $f)
        {
            $field = substr($f, 0, 3);
            $data = substr($f, 4);

            switch($field)
            {
                case FLD_SEARCH_COUNT:
                    $this->parseSearchCount($data);
                    break;

                case FLD_SHOWFLD:
                    $this->parseShowFld($data);
                    break;

                case FLD_FIELDS:
                    $this->parseFields($data);
                    break;

                case FLD_FIELDSWIDTH:
                    $this->parseFieldsWidth($data);
                    break;

                case FLD_HEADERS:
                    $this->parseHeaders($data);
                    break;

                case FLD_SEARCHREC:
                    $this->parseSearchRec($data);
                    break;

                case FLD_SEARCHHV:
                    $this->parseSearchHv($data);
                    break;

                case FLD_HV_GROUP:
                    $this->parseHvGroup($data);
                    break;

                default:
                    echo "$field = " . mangle($data) . "\r\n";
                    break;
            }
        }
    }

    // Protected methods

    protected function updateFieldCount($len)
    {
        while (count($this->fields) < $len)
            $this->fields[] = array();
    }

    protected function parseSearchCount($data)
    {
        $this->searchCount = (int)$data;
    }

    protected function parseShowFld($data)
    {
        $x = explode(CONNECTOR_SUB, $data);
        $this->updateFieldCount(count($x));

        for($i=0; $i<count($x); $i++)
            $this->fields[$i]['visible'] = $x[$i];
    }

    protected function parseFields($data)
    {
        $x = explode(CONNECTOR_SUB, $data);
        $this->updateFieldCount(count($x));

        for($i=0; $i<count($x); $i++)
            $this->fields[$i]['field'] = $x[$i];
    }

    protected function parseFieldsWidth($data)
    {
        $x = explode(CONNECTOR_SUB, $data);
        $this->updateFieldCount(count($x));

        for($i=0; $i<count($x); $i++)
            $this->fields[$i]['width'] = $x[$i];
    }

    protected function parseHeaders($data)
    {
        $x = explode(CONNECTOR_SUB, $data);
        $this->updateFieldCount(count($x));

        for($i=0; $i<count($x); $i++)
            $this->fields[$i]['header'] = $x[$i];
    }

    protected function parseSearchRec($data)
    {
        $this->records[] = explode(CONNECTOR_SUB, $data);
    }

    protected function parseSearchHv($data)
    {
        $last = count($this->records) - 1;
        if ($last < 0)
            return;

        $x = explode(CONNECTOR_SUB, $data);
        $this->records[$last]['hv'][] = array(
            'start'    => $x[0],
            'stop'     => $x[1],
            'tel'      => $x[2],
            'text'     => $x[3],
            'orsid'    => $x[4],
            'orstext'  => $x[5],
            'status'   => $x[6],
            'hvnr'     => $x[7],
            'tillg'    => $x[8],
            'vem'      => $x[10],
            'tel_text' => $x[11]
        );
    }

    protected function parseHvGroup($data)
    {
        $last = count($this->records) - 1;
        if ($last < 0)
            return;

        $this->records[$last]['hvGroup'] = $data;
    }

    // Public methods

    public static function dumpDate($date)
    {
        // Reformat 20081231090000 -> 2008-12-31 09:00

        return substr($date, 0, 4) . '-' .
               substr($date, 4, 2) . '-' .
               substr($date, 6, 2) . ' ' .
               substr($date, 8, 2) . ':' .
               substr($date, 10, 2);
    }

    public function dumpToTable()
    {
        $visibleFields = array();
        $visibleCount = 0;

        // Check which fields should be displayed or not
        for($i=0; $i<count($this->fields); $i++)
            if ($this->fields[$i]['visible'] == 'J')
                $visibleFields[] = $i;
        $visibleCount = count($visibleFields);

        echo "<table cellspacing='0'>";

        // Dump table header
        echo "<thead><tr>";
        foreach($visibleFields as $i)
            echo "<td>" . $this->fields[$i]['header'] . "</td>";
        echo "</tr></thead>";

        foreach($this->records as $rec)
        {
            echo "<tr>";
            foreach($visibleFields as $i)
                echo "<td>" . $rec[$i] . "</td>";
            echo "<tr>";

            if (array_key_exists('hv', $rec))
                foreach($rec['hv'] as $hv)
                {
                    echo "<tr class='hv'><td colspan=\"$visibleCount\">";

                    $hv_from = self::dumpDate($hv['start']);
                    $hv_to   = self::dumpDate($hv['stop']);
                    $hv_ors  = $hv['orstext'];

                    echo "$hv_ors ($hv_from - $hv_to)";

                    echo "</td></tr>";
                }

            if (array_key_exists('hvGroup', $rec))
            {
                $hv_return = self::dumpDate($rec['hvGroup']);
                echo "<tr class='hv'><td colspan=\"$visibleCount\">Returns on $hv_return</td></tr>";
            }
        }

        echo "</table>";
    }
}
