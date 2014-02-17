chumby-fbwrite
==============

This is a modified version of the fbwrite utility for the Chumby that adds support for the Chumby8/Infocast8.
The original source can be found on the chumby website at http://files.chumby.com/source/misc/fbwrite-0.12.tgz

This version pulls the default framebuffer width and height from the VIDEO_X_RES and VIDEO_Y_RES environment variables (which are used to determine whether the 6x11 or 12x22 font is used).
If the CNPLATFORM environment variable is set to "silvermoon," 32-bit RGBA color will be used instead of the 16-bit 565 RGB color used on "Falconwing" devices.
