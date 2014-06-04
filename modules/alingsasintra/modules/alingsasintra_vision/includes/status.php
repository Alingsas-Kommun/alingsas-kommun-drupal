<style>

    td {
        padding: 3px;
    }

    thead td {
        background: #ccc;
        font-weight: bold;
    }
    
    .hv {
        color: #600;
        font-style: italic;
    }
    
    .hv td {
        padding-left: 2em;
    }

</style>

<form method="get">

    <p>Search data: &nbsp;
        First name <input type="text" name="first" value="<?= $_GET['first'] ?>">
        Last name <input type="text" name="last" value="<?= $_GET['last'] ?>">
        <input type="submit">
    </p>

</form>

<?php

/*

    Small script to demonstrate connecting, authentication and searching with the
    Vision 80/20 Connector Service.
    
    WARNING: This script completely trusts remote values. If you code something yourself,
    remember to mangle and strip and htmlencode everything. :)

*/

$ms = microtime(true);

# -----
# Customize these settings below

$hostname  = 'host';        # Hostname for the Vision 80/20 Connector service
$extension = '';            # Telephone extension
$password  = '';            # Password to use

# -----

require_once 'IP.php';                    # Definitions for IP communication
require_once 'ConnectorSearchResult.php'; # Encapsulates search results
require_once 'ConnectorPacket.php';       # Encapsulates packets
require_once 'Connector.php';             # Main class for communication

# Function to check the result of a transaction
function check_result(ConnectorPacket $packet)
{
    if ($packet == null)
        die("Communication error: No reply received");
    else if ($packet->failed())
        die("Communication error: {$packet->errno} {$packet->errtext}");
}

# Just prettify the output, replacing the different separators with letters easier to recognize
function mangle($s)
{
    $s = str_replace(CONNECTOR_STX, '<', $s);
    $s = str_replace(CONNECTOR_ETX, '>', $s);
    $s = str_replace(CONNECTOR_SEP, '|', $s);
    $s = str_replace(CONNECTOR_SUB, '||', $s);
    $s = str_replace(CONNECTOR_SSB, '[', $s);
    $s = str_replace(CONNECTOR_ESB, ']', $s);
    $s = str_replace(CONNECTOR_ISUB, '/', $s);
    
    return $s;
}



# New instance of Connector required ----------

$conn = new Connector();


# Connect to the Vision 80/20 connector service ----------

if (!$conn->connect($hostname))
    die("Couldn't connect to service on host $hostname");

echo "<p>Connected to $hostname ...</p>";


# Try to request a new session ----------

check_result($conn->req_s());       # REQ-S requests a new session identifier. This session ID
                                    # is stored in $conn->session and must always be included.
                                    # It can be used across connections if necessary - so you
                                    # may use the same ID over several HTTP requests. Storing the 
                                    # session identifier in $_SESSION[] is a good idea.

echo "<p>Got session, it is {$conn->session} ...</p>";


# Try to login ----------

$result = $conn->auth($extension, $password);  # Login using extension and password
check_result($result);

echo "<p>We are logged in, my name is " . $result->get(FLD_NAMN) . "</p>";
                                        # The AUTH reply always contains more data, like user name
                                        # and other cool stuff. Run print_r() on the result to
                                        # see all the juicy details.

                                        
# Create a new search object - search for all users called Anna ----------

$packet = new ConnectorPacket(          # There is no predefined function for searching, so
                                        # we create our own packet for this.
    'SEARCH',                           # Command code = SEARCH
    array(
        FLD_SESSION => $conn->session,  # Always include the session!
    )
);

if ($_GET['first'] != '')
    $packet->add(FLD_SEARCHFLD, '1,' . $_GET['first']);
if ($_GET['last'] != '')
    $packet->add(FLD_SEARCHFLD, '2,' . $_GET['last']);

$conn->send($packet);                   # Send our carefully crafted packet.
$reply = $conn->read();                 # Receive reply and check it.
check_result($reply);

$result = new ConnectorSearchResult($reply);
$result->dumpToTable();

                                        
# Okay, now shut down gracefully ----------

$conn->end();                           # End logs out and destroys the session. $conn->session
                                        # should now be empty.
$conn->disconnect();                    # And disconnect, to be a good citizen.

$ms = round((microtime(true) - $ms) * 1000);
echo "<p>The end. Total run time = $ms ms</p>";
