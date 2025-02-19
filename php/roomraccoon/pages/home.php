<center>
	<br />
		<img src='././images/screenshot_41.png' \>
	<br />
	<h1>RoomRaccoon Booking Monitoring System</h2>
	<br />
	<table>
		<thead>
			<tr>
				<th>Customer Name</th><th>Customer Contact</th><th>Hotel Booked</th><th>Referral</th><th>Amount/Rate</th>
			</tr>
		</thead>
		<tbody>
			<?php
			
				global $db_connection;
				$sql = "
					SELECT
						`A`.`customer_name`, `A`.`customer_surname`, `A`.`customer_contact`, `B`.name AS `hotel_name`, `B`.referral AS `hotel_referral`, `B`.rate AS `hotel_rate`
					FROM
						`bookings` AS `A`
					LEFT JOIN
						`properties` AS `B` ON `B`.id = `A`.property_id
					ORDER BY
						`date` DESC
					LIMIT 5";
				$result = $db_connection->query($sql);
				
				//print_r($db_connection);print_r($result);
				if ($result->num_rows > 0)
				{
					while($row = $result->fetch_assoc())
					{
						echo "<tr>";
						echo "		<td>" .$row["customer_name"]." ".$row["customer_surname"]."</td><td>".$row["customer_contact"]."</td><td>".$row["hotel_name"]."</td><td>".$row["hotel_referral"]."</td><td style='text-align:right;'>". $row["hotel_rate"]."</td>";
						echo "</tr>";
					}
				} else
				{
				      echo "No results found.";
				}
				
				$db_connection->close();
			?>
		<tbody>
	</table>
</center>