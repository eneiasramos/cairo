<?php
$sur = new CairoImageSurface(FORMAT_ARGB32, 10, 10);
$con = new CairoContext($sur);

$pat = new CairoLinearGradient(0, -10, 0, 10);
$pat->addColorStopRgba(0,1,0,0,1);
$pat->addColorStopRgba(1,0,0,1,0.5);
$con->setSource($pat);
$con->paint();

$sur->writeToPng("gradient-alpha-php.png");
?>
