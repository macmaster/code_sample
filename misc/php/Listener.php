<?php

/** Listener.php *************************
 *
 * Created on Jun 14, 2016
 * (c) Copyright IBM Corporation 2016
 *
 *****************************************/

/**
 * Queries Tetris for a list of service agreements. <br>
 * 
 * @param $liability the liability of the service agreement.
 * @param $profile_id the profile of the service agreement.
 */
function query_agreements($liability, $profile_id) {
	// build query url
	// ex. https://extbasictetris03.podc.sl.edst.ibm.com/tetris/serviceagreements/Cisco/billingid/120478
	$url = "https://extbasictetris03.podc.sl.edst.ibm.com/tetris/serviceagreements";
	$url = $url . "/$liability" . "/billingid" . "/$profile_id";
	
	// setup curl
	$conn = curl_init();
	curl_setopt($conn,CURLOPT_URL, $url);
	curl_setopt($conn,CURLOPT_FAILONERROR,true);
	curl_setopt($conn,CURLOPT_RETURNTRANSFER, true);
	curl_setopt($conn,CURLOPT_HEADER, false);
	curl_setopt($conn, CURLOPT_SSL_VERIFYHOST, false);
	curl_setopt($conn, CURLOPT_SSL_VERIFYPEER, false);
	
	$result = curl_exec($conn);
	
	if($result === false) {
		echo 'JsonRequest Error: ' . print_r(curl_getinfo($conn),true) . "\n";
		$error = curl_error($conn);
		$errno = curl_errno($conn);
		echo "error: $error \t  errorno: $errno\n";
	}
	
	// curl and return.
	curl_close($conn);
	return $result ? : "[]";
	
}


/**
 * top level driver for testing the listener lib
 */
function driver(){
	echo "driver started.\n";
	$liabilities = array("IBM", "Cisco");
	$resolutions = array("IBM", "Cisco");

	// query service
	for($idx = 120400; $idx < 120600; $idx++){
		$response = query_agreements($liabilities[1], $idx);
		echo "$response\n";
	}
}

driver();