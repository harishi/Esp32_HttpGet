<!DOCTYPE html>
<html>
<body>
<script>
    function autoRefresh() {
        window.location = window.location.href;
    }
    setInterval('autoRefresh()', 5000);
</script>
<?php
$servername = "localhost";
// REPLACE with your Database name
$dbname = "ephyzics_esp32_temp";
// REPLACE with Database user
$username = "ephyzics_esp32_temp";
// REPLACE with Database user password
$password = "zLxW9kuDhLhBygZPMqrv";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

$sql = "SELECT * FROM temp_table";
echo '<table cellspacing="5" cellpadding="5">
      <tr> 
        <td>temp_id</td> 
        <td>temp_value</td> 
      </tr>';

if ($result = $conn -> query($sql)) 
{
  while ($row = $result -> fetch_row())
  {
  		$row_ID            = $row[0];
        $row_value         = $row[1];

       echo '<tr>  
        <td>' .$row_ID . '</td>         
        <td>' .$row_value . '</td>  
		</tr>';
  }
// Free result set
$result -> free_result();
}
$conn->close();
?> 
</table>
</body>
</html>
