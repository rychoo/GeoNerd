<?php
/* 
 * Copyright (c) 2004 mgr ... Ryszard Wies³aw Czekaj <rycho@Czekaj.net>
 * All rights reserved.
 * $ Utor vi,      uti FreeBSD
 * # _________^-^__
 * # bofh@RYCHo.oRG
 * # ~~~~~~~~~ v ~~
 * This code is in the public domain for U2.
 * You must have (figlet && fortune) installed in path.

(c) 2023 I'm commercial! All from this code 33% income for me ;)
+48 882723907
https://rychon.bitcoinwallet.com/
36New7tW2QZFPSMJoHm1htCc2zhAiaFC6G
37w2SC3qoDvtXBC5Be1e2CbKPx5gwRDhDv
3PCFHnY1ujpCchFNSBAeaECZ8rGyScoRLT

 */

$rcsid = '$Id: fortfiglet.php,v 1.1 2004/04/29 17:33:44 rycho Exp rycho +2005$';
define('APP_ROOT', dirname(__FILE__));
define('IN_PHPSYSINFO', true);
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtm
l1-transitional.dtd">
<html><head>
<?php echo "<meta http-equiv=\"Refresh\" content=\"321; URL=http://RYCHoo.TheUnixPlace.com/fortfiglet/\" />"; ?>
<?php echo "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=iso-8859-1\" />"; ?>
<title>
fortfiglet with RYCHoo@freeshell.net 8-)
</title>
<script type="text/javascript">
<!--
if (self.parent.frames.length != 0){
        self.parent.location = document.location;
}
//--></script>
</head>
<body>

<?php
function fortfiglet()
{
        $litery = array(34, 36, 37, 38, 42, 43, 45, 47, 48, 49, 50,  51,  52,
        53, 54, 55, 56, 57, 58, 59, 61, 63, 64, 65, 66, 67, 68, 69,  70,  71,
        72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86,  87,  88,
        89, 90, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103,  104,  105,  106,
        107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,
        121, 122, 196, 214, 220, 223, 228, 246, 252);
        $max = sizeof($litery);
        $litera = 0; $buf = ''; $linia = ''; $pipe = ''; $sig = '';

        mt_srand( (double)microtime()*12345678 );
        $litera = mt_rand() % $max;

        $buf = sprintf("echo '%c' | /usr/pkg/bin/figlet -f eftiwall", $litery[$litera]);
        $pipe = popen($buf, "r") or die("Stream error -> $buf\n");
        $buf = "/usr/pkg/games/fortune -o";
        $sig = popen($buf, "r") or die("Stream error -> $buf\n");

        for ($max = 0; $max < 5; ++$max)
        {
                if ($linia = fgets($pipe, 255))
                {
                        $litera = strlen($linia);
                        $linia[--$litera] = ' ';
                        printf("%s", $linia);
                        if ($buf = fgets($sig, 255))
                                printf("%s", $buf);
                        else
                                printf("\n");
                }
        }
	while ($buf = fgets($sig, 255)) {
	printf("%s", $buf);
	}
        pclose($pipe);
        pclose($sig);
}
?>

<table align="center"><tr><td>
<pre>
<?php
fortfiglet();
?>
</pre>
</td></tr></table>
<?php
require_once(APP_ROOT . '/../includes/system_sub_header.php');
?>
</body></html>
