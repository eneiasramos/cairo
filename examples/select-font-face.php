<?php
	$TEXT_SIZE = 12;
	$sur = new CairoImageSurface(FORMAT_ARGB32, 192, 16);
	$con = new CairoContext($sur);
    $con->save ();
    $con->setSourceRgb ( 1.0, 1.0, 1.0); /* white */
    $con->paint ();
    $con->restore ();

    $con->setSourceRgb ( 0, 0, 0); /* black */

    $con->selectFontFace ( "Bitstream Vera Serif",
                FONT_SLANT_NORMAL,
                FONT_WEIGHT_NORMAL);
    $con->setFontSize ( $TEXT_SIZE);

    $con->moveTo ( 0, $TEXT_SIZE);
    $con->showText ( "i-am-serif");

    $con->selectFontFace ( "Bitstream Vera Sans",
                FONT_SLANT_NORMAL,
                FONT_WEIGHT_NORMAL);
    $con->showText ( " i-am-sans");

    $con->selectFontFace ( "Bitstream Vera Sans Mono",
                FONT_SLANT_NORMAL,
                FONT_WEIGHT_NORMAL);
    $con->showText ( " i-am-mono");
	$sur->writeToPng("select-font-face-php.png");


?>
