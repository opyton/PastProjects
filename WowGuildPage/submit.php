<?php

 $dsn = 'mysql:dbname=Project;host=172.17.149.64';

         $user='alamber';

         $passwd='#Jester0813';

         $conn = new PDO($dsn,$user,$passwd);



  $listUsers = $conn->prepare("Select * FROM User");

            $listUsers->execute();

            $pairs = $listUsers->fetchAll();

      $id = 0;

      $arr = array();

            forEach($pairs as $users){

                  $userName = $users[1];

      $arr[$id] = $userName;

//      print $arr[$id];

      $id++;

      }



//Collect data from form

$dbUser = $_POST['user'];

$uPasswd = md5($_POST['passwd']);

$contents = $_POST['contents'];

$pwArr = array();

$i = 0;



//Puts user passwords into an array

$listPasswd = $conn->prepare("Select * FROM User");

            $listPasswd->execute();

            $pswds = $listPasswd->fetchAll();

            forEach($pswds as $pswd){

//      print "hello";

           $userPswd = $pswd[2];

                   $pwArr[$i] = $userPswd;

//                 print $pwArr[$i];

                   $i++;

}



$dbUserN = -1;



if($dbUser == "Austin"){

           $dbUserN = 4;

//         print "success";

}else if($dbUser == "Nathan"){

      $dbUserN = 2;

}else if($dbUser == "Slappy"){

      $dbUserN = 3;

}else if($dbUser == "Hardison"){

      $dbUserN = 5;

}



//print "<br>";

//print $uPasswd;

//print "<br>";

//print md5("#Thirt33n13");

//print "<br>";

//print $pwArr[$dbUserN-2];



//if the password is correct then add a new Entry, if it is not correct

//then redirect back to the project diary page to retry

if(md5($uPasswd) == $pwArr[$dbUserN-2]){

//          print $dbUser;

//          print $contents;

            $sql = "INSERT INTO Entry (id, time, contents)

VALUES ($dbUser, date('y-m-j, h:i:s' $contents)";

       if($conn->query($sql) === TRUE){

                             echo "New Entry Submitted";

       }

}

else{

header("Location: http://172.17.149.63/Assn4/diary.php?message=IncorrectPassword");

}

?>