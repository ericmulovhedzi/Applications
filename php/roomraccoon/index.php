<?php
ini_set('display_errors', '1');
ini_set('display_startup_errors', '1');
error_reporting(E_ALL);

include("include/connection.php");

$_TITLE = "Roomraccoon PHP Test Sample | ";$_DESCRIPTION = $_KEYWORDS ="";

if(!isset($_GET['p'])) {$_GET['p'] = 'home';}

?>
<!-- Copyright: 2021 -->
<!DOCTYPE html >
<html xmlns="http://www.w3.org/1999/xhtml"  xml:lang="en" lang="en">
<head> 
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
		
	<title><?php echo $_TITLE; ?></title>
	<meta name="description" content="<?php echo $_DESCRIPTION; ?>" />
	
	<meta http-equiv="Content-Security-Policy" content="upgrade-insecure-requests">
		
	<meta name="keywords" content="construction, manufacturing" />
	<meta name="distribution" content="global" /> 
	<meta name="robots" content="follow, all" /> 
	<meta name="language" content="en, sv" /> 

	<meta name="geo.country" content="RSA" />
	<meta name="geo.region" content="za" /> 
	<meta name="geo.placename" content="Cape Town, South Africa" />
	<meta name="geo.position" content="28.02358,-26.041052" />

	<meta name="DC.Title" content="<?php echo $_TITLE; ?>" />
	<meta name="DC.Description" content="<?php echo $_DESCRIPTION; ?>" /> 
	<meta name="DC.Creator" content="Roomraccoon" /> 
	<meta name="DC.Subject" scheme="SCIS" content="<?php echo $_TITLE; ?>" />
	
	<meta property="og:title" content="<?php echo $_TITLE; ?>" />
	<meta property="og:description" content="<?php echo $_DESCRIPTION; ?>" />
	<meta property="og:url" content="http://www.roomraccoon.co.za/" />
	<meta property="og:locale" content="en_ZA" />
	<meta property="og:type" content="website" />
	
	<!-- CSS -->
			
	<link href="<?php echo WWWROOT; ?>style/styles.css" rel="stylesheet" type="text/css" />
	
	<!-- JAVASCRIPT -->
		
	<script type="text/javascript" src="<?php echo WWWROOT; ?>style/javascript.js"></script>
</head> 
<body>
	<div> 
		<?php
			
			if (file_exists("pages/".$_GET['p'].".php"))
			{
				include_once("pages/".$_GET['p'].".php");
			} 
			else
			{
				include_once("server-error-404-page.php");
			}
			
		?> 
	</div>
</body>
</html>