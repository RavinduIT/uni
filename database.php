<?php
include 'dbc.php';
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
    <body>
    
    <?php



        $sql = "SELECT * FROM ravindu";
        $result = mysqli_query($connect, $sql);
        $numberofrows = mysqli_num_rows($result);
        echo "Number of rows" . $numberofrows . "<br>";
        if($numberofrows > 0){
            while($rowdata = mysqli_fetch_assoc($result)){
                echo $rowdata['name'] . "<br>";
            }
        }
    ?>




</body>
</html>