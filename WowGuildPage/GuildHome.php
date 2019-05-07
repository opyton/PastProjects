<?php
    include 'GuildNavBar.php';
?>


      <h1>World of Warcraft Guild Website</h1>

      <p>

        For this project we are creating a website that holds <br>

        information about a Guild in the popular MMORPG WoW

      </p>

<table>

      <?php

         $dsn = 'mysql:dbname=Project;host=172.17.149.64';

         $user='alamber';

         $passwd='#Jester0813';

         $conn = new PDO($dsn,$user,$passwd);

//       print "<tr><td>connected</td></tr>";

            $listUsers = $conn->prepare("Select * FROM User");

            $listUsers->execute();

            $pairs = $listUsers->fetchAll();

      $id = 0;

      $arr = array();

            forEach($pairs as $users){

                  $userName = $users[1];

      $arr[$id] = $userName;

      $id++;

      }



            $listEntries = $conn->prepare("Select id, time, contents FROM Entry");

            $listEntries->execute();

            $ePairs = $listEntries->fetchAll();

      forEach($ePairs as $entries){

       $id = $entries['id'];

       $time = $entries['time'];

       $contents = $entries['contents'];

      $eUser =  $arr[$id-2];

      print "<tr><td>$eUser</td><td>$time</td><td>$contents</td></tr>";

      }

         ?>

</table>

<div>

  <?php

         if(!empty($_GET['message'])){

         $message = $_GET['message'];

         print "Password Was Incorrect";

         }

         ?>

<form method="POST" action="submit.php">

User:<br>

  <select id="user" name="user">

    <?php

       print "<option value=$arr[0]>$arr[0]</option>";

        print "<option value=$arr[1]>$arr[1]</option>";

        print "<option value=$arr[2]>$arr[2]</option>";

        print "<option value=$arr[3]>$arr[3]</option>";

       ?>

  </select>

<br>Password:<br>

<input name="passwd" type="password" id="passwd">

<br>Diary Entry:<br>

<input type="text" id="contents" name="contents">

<br>

<input type="submit">

</form>

</div>


<?php
    include 'GuildBot.php';
?>