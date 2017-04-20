<?php
$value = $_POST['value'];	// take the value of value field
$from = $_POST['from'];		// take the value of from field
$ip = $_SERVER['REMOTE_ADDR'];	// the cilent's IP address
echo "Your value = ".$value." from=".$from." and your ip address is ".$ip."\n";		// echo is a message send back to the cilent
$today=date("Y_m_d H:i:s");	// current time
$file = "curltest.log";		// the log file name
if(file_exists($file)){
	$fp = fopen($file, "a");	// open the file in appending mode
}
else{
	$fp = fopen($file, "w");	// open the file in writing mode
}
// prepare a line of record to write to a file, in CSV format
$record = $today . ", " . $from . ", " . $ip . ", " . $value . "\n";
fwrite($fp, $record);			// write to a file
fclose($fp);					// close a open file
?>