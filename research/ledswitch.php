 <html>
 <head>
 <meta name="viewport" content="width=device-width" />
 <title>LED Control</title>
 </head>
         <body>
         LED Control:
         <form method="get" action="ledswitch.php">
                <input type="submit" value="GREEN" name="on" style="width:200px; height:100px; background:green; font-size:50px">
                <input type="submit" value="RED" name="off" style="width:200px; height:100px; background:red; font-size:50px">

         </form>
         <?php
         $setmode4 = shell_exec("/usr/local/bin/gpio -g mode 4 out");
         $setmode5 = shell_exec("/usr/local/bin/gpio -g mode 5 out");
         if(isset($_GET['on'])){
                 $gpio_on = shell_exec("/usr/local/bin/gpio -g write 4 1");
                 $gpio_on = shell_exec("/usr/local/bin/gpio -g write 5 0");
         }
         else if(isset($_GET['off'])){
                 $gpio_off = shell_exec("/usr/local/bin/gpio -g write 4 0");
                 $gpio_on = shell_exec("/usr/local/bin/gpio -g write 5 1");
         }
         ?>
         </body>
 </html>
