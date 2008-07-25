<?php
$sur = new CairoImageSurface(FORMAT_ARGB32, 53, 53);
$con = new CairoContext($sur);

$con->setSourceRgb(1,0,0);
$con->translate(1,1);
$con->moveTo(0,0);
$con->lineTo(25,50);
$con->lineTo(25,0);
$con->lineTo(50,25);
$con->lineTo(0,25);
$con->closePath();
$con->fill();
$sur->writeToPng("fill-missed-stop-php.png");
?>

