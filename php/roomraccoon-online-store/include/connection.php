<?php

require_once('configuration.php');
//require('fnc.php');
//require_once('init.php');

$db_connection = new mysqli($db_host, $db_user, $db_pass,$db_name);

if ($db_connection->connect_error) {
  die("Connection failed: " . $db_connection->connect_error);
}

?>