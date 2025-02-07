<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    
    <form method="get">
        <input type="text" name="name">
        <input type="submit" value="Submit">
    </form>

    <?php
        if(isset($_GET['name'])){
            $var = $_GET['name'];
            echo "Your name is ".$var.".";
        }
    ?>

    <?php
        // Array
        $arr = array(25, 66, 78, 45, 89);
        echo "2nd element is ".$arr[1].".";

        // Associative Array
        $arr = array("name"=>"John", "age"=>25, "city"=>"New York");
        echo "Name is ".$arr['name'].".";

        // Multidimensional Array
        $arr = array(
            array("name"=>"John", "age"=>25, "city"=>"New York"),
            array("name"=>"Doe", "age"=>30, "city"=>"Los Angeles"),
            array("name"=>"Smith", "age"=>35, "city"=>"Chicago")
        );
        echo "Name is ".$arr[0]['name'].".";

        // String
        $x = "Ravindu";
        $y = "Lakshan";
        echo $x." ".$y;

        $x .= " ".$y;
        echo $x;

        // Loop
        for($i=0; $i<5; $i++){
            echo $i;
        }

        // Foreach
        $arr = array(25, 66, 78, 45, 89);
        foreach($arr as $value){
            echo $value;
        }

        // While
        $i = 0;
        while($i<5){
            echo $i;
            $i++;
        }

        // Do While
        $i = 0;
        do{
            echo $i;
            $i++;
        }while($i<5);

        // Function
        function myFunction($name){
            echo "Hello ".$name.".";
        }
        myFunction("John");

        // Include

    ?>

</body>
</html>