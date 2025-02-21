<center>
		<img src='././images/screenshot_41.png' \>
	<br />
	<h1>RoomRaccoon Shopping List</h2>
	<br />
	<?php
		if(isset($_REQUEST['save']))
		{
			if(isset($_REQUEST['id']) && ($_REQUEST['id'] > 0) )
			{
				if($db_connection->query("UPDATE `products` SET name='".$_REQUEST['name']."'"
					.",`description`='".$_REQUEST['description']."'"
					.",`category`='".$_REQUEST['category']."'"
					.",`price`='".$_REQUEST['price']."'"
					.",`date`='".date("Y-m-d H:i:s")."'"
					." WHERE id='".$_REQUEST['id']."'"))
				{
					$msg = "Successfully updated the folowing product: ".$_REQUEST['name']."..";
					echo "<i  class='notice-save'>$msg</i>\n";
				}else
				{
					$msg = "Sorry, the following product could not be added.";
					echo "<i  class='notice-cancel'>$msg</i>\n";
				}
				
			}
			else 
			{
				if($db_connection->query("INSERT INTO `products` (`name`,`category`,`description`,`sku`,`price`,`currency`,`date`) VALUES('".$_REQUEST['name']."',"
					."'".$_REQUEST['category']."','".$_REQUEST['description']."','".$_REQUEST['sku']."','".$_REQUEST['price']."','".$_REQUEST['currency']."',"
					."'".date("Y-m-d H:i:s")."')"))
				{
					$msg = "Successfully added the following product: ".$_REQUEST['name']."..";
					echo "<i  class='notice-save'>$msg</i>\n";
				}else
				{
					$msg = "Sorry, the following product could not be added.";
					echo "<i  class='notice-cancel'>$msg</i>\n";
				}
				
			}
		}
		
		if(isset($_GET['edit']) || isset($_GET['new']))
		{
			$v = array('1'=>'','2'=>'','3'=>'','4'=>'','5'=>'','6'=>'','7'=>'','8'=>'');
		
			$result_category = $db_connection->query("SELECT `A`.`id`,`A`.`name` FROM `categories` AS `A`");
				
			if(isset($_GET['new']))
			{
				$heading = "New Product";
			}
			else if(isset($_GET['edit']))
			{
				$heading = "Edit Product";
				
				$result_products = $db_connection->query("SELECT `A`.* FROM `products` AS `A` WHERE `A`.id='".$_GET['edit']."' LIMIT 1");
				if(isset($result_products->num_rows) && ($result_products->num_rows > 0))
				{
					$row_products = $result_products->fetch_assoc();
					
					$v = array('1'=>$row_products["id"],'2'=>$row_products["category"],'3'=>$row_products['name'],'4'=>$row_products['description'],'5'=>$row_products["sku"],'6'=>$row_products["barcode"],'7'=>$row_products["price"]);
				
				}
			
			}
	?>
		<form id="login" name="login" method="POST" action='<?php echo "?p=home"; ?>'>
			<input name="id" type="hidden" value='<? echo $_GET['edit']; ?>'>
			<table width="100%" cellpadding='0' cellspacing='0'>
				<tr><td valign='top' class='heading' colspan='2'<strong><?php echo $heading; ?></strong></td></tr>
				<tr><td colspan='2'>&nbsp;</td></tr>
				<tr><td align="left" class="txtn2">Name: <i style='color:#F00;'>*</i></td><td><input name="name" type="text" value="<? echo $v['3'];?>" style="width:300px" ></td></tr>
				<tr><td align="left" class="txtn2">Description: </td><td><textarea name='description' style="width:300px;height:80px;"><? echo $v['4'];?></textarea></td></tr>
				<tr><td align="left" class="txtn2">Category: <i style='color:#F00;'>*</i></td><td>
					<select name="category" id="category">
						<?php
							if(isset($result_category->num_rows) && ($result_category->num_rows > 0))
							{
								while($row_category = $result_category->fetch_assoc())
								{
									echo "<option value='".$row_category["id"]."'>".$row_category["name"]."</option>";
								}
							}
						?>
					</select>
				</td></tr>
				<tr><td align="left" class="txtn2">SKU: <i style='color:#F00;'></i></td><td><input name="sku" type="text" value="<? echo $v['5'];?>" style="width:300px" ></td></tr>
				<tr><td align="left" class="txtn2">Barcode: <i style='color:#F00;'></i></td><td><input name="barcode" type="text" value="<? echo $v['6'];?>" style="width:150px" ></td></tr>
				<tr><td align="left" class="txtn2">Price: <i style='color:#F00;'>*</i></td><td><input name="price" type="text" value="<? echo $v['7'];?>" style="width:100px" ></td></tr>
				<tr><td align="left" class="txtn2">Currency: <i style='color:#F00;'></i></td><td>
					<select name="currency" id="currency">
						<option value="R">R</option>
						<option value="$">$</option>
					</select>
				</td></tr>
				<tr><td align="left" class="txtn2"><input name="cancel" tabindex="-1" type="submit" value="Cancel" class="button" style="float:right;color:#DB0000;width:70px;" ></td><td><input name="save" tabindex="1" type="submit" value="Save" class="button" style="width:100px;"></td></tr>
				<tr><td colspan='2'>&nbsp;</td></tr>
			</table>		
		</form>
	<?php }else{ ?>
	<table style="width:75%;">
		<thead>
			<tr>
				<td colspan="6" style="text-align:right;">
					<a href="<? echo WWWROOT; ?>?new=1">Add New Product</a>
				</td>
			</tr>
			<tr>
				<th>Product Name</th><th>Product SKU</th><th>Product Description</th><th>Price</th><th></th><th>Actions</th>
			</tr>
		</thead>
		<tbody>
			<?php
			
				global $db_connection;
				$sql = "
					SELECT
						`A`.*
					FROM
						`products` AS `A`
					LEFT JOIN
						`categories` AS `B` ON `B`.id = `A`.category
					ORDER BY
						`A`.`date` DESC
					LIMIT 15";
				$result = $db_connection->query($sql);
				
				//print_r($db_connection);print_r($result);
				if (isset($result->num_rows) && ($result->num_rows > 0))
				{
					while($row = $result->fetch_assoc())
					{
						echo "<tr>";
						echo "		<td>" .$row["name"]."</td><td>".$row["sku"]."</td><td><i style='colot:#DDD;'>".$row["description"]."<i></td><td style='text-align:right;'>". $row["currency"]." ". $row["price"]."</td>
						<td align='center'>
							<a href='?delete=".$row["id"]."'><img alt='Mark' src='images/checkbox_no.png' border='0'></a>
						</td>
						<td align='center'>
							<a href='?edit=".$row["id"]."'><img alt='Edit Item' src='images/edit.gif' border='0'></a>&nbsp;&nbsp;
							<a href='?delete=".$row["id"]."'><img alt='Delete Item' src='images/delete.gif' border='0'></a>
						</td>
						";
						echo "</tr>";
					}
				} else
				{
				      //echo "No results found.";
				}
				
				$db_connection->close();
			?>
		<tbody>
	</table>
	<?php } ?>
</center>