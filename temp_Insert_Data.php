<?php

if(isset($_GET["temperature"])) {
   $temperature = $_GET["temperature"]; // get temperature value from HTTP GET

	$servername = "localhost";

	$database_name = "ephyzics_esp32_temp";
	// REPLACE with Database user
	$username = "ephyzics_esp32_temp";
	// REPLACE with Database user password
	$password = "zLxW9kuDhLhBygZPMqrv";


   // Create MySQL connection fom PHP to MySQL server
   $connection = new mysqli($servername, $username, $password, $database_name);
   // Check connection
   if ($connection->connect_error) {
      die("MySQL connection failed: " . $connection->connect_error);
   }

   $sql = "INSERT INTO temp_table (temp_value) VALUES ($temperature)";

   if ($connection->query($sql) === TRUE) {
      echo "New record created successfully";
   } else {
      echo "Error: " . $sql . " => " . $connection->error;
   }

   $connection->close();
} else {
   echo "temperature is not set in the HTTP request";
}
?>