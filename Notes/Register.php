<?php
    include 'dbc.php';

    $name = $_POST['name'];
    $weight = $_POST['weight'];
    $age = $_POST['age'];

    $insert = "INSERT INTO ravindu (name, weight, age) VALUES ('$name', '$weight', '$age')";

    if(mysqli_query($connect, $insert)){
        echo "Data inserted successfully";
    }else{
        echo "Data not inserted";
    }

    header("Locationindex.html?signup=success");
?>