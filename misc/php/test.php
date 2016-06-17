<?php
/** test.php
 * Quick sratch demo to learn how to use php.
 * 
 * Author: Ronald Macmaster
 */

// control statements
$name = "ronny";
if($name == ronny) {
	echo "hi ronny!\n";
}
else if($name == "walter") {
	echo "hi walter!\n";
}
else {
	echo "hi someone else!\n";
}

// for each loop with array
$myarr = array("good", 15, "golly nicholas", null, true);
$myarr[3] = strlen($myarr[2]);
foreach($myarr as $val) {
	echo $val . "\n";
}

// nested map / state machine
$map = array("state 0" => array("name" => "state 0", "output" => "ronny", "next" => "state 2"), 
		"state 1" => array("name" => "state 1", "output" => "cool!", "next" => null), 
		"state 2" => array("name" => "state 2", "output" => "is", "next" => "state 1"));

$state = $map["state 0"];
while($state != null) {
	echo "$state[output]\n";
	$state = $map[$state["next"]];
}

echo "\n\n";

// file I/O
$fhand = fopen("json", "r");
$log = fopen("log", "a+");
while(($line = fgets($fhand)) != null) {
	echo $line;
	fwrite($log, $line);
}
fclose($fhand);
fclose($log);

?>