dwm - dynamic window manager
============================
This is to save the changes I make to the dwm I'm using.


Installation
------------
I installed using this method:
https://wiki.archlinux.org/index.php/Dwm#makepkg_.2B_ABS

Then I replaced both config.h's outside the dwm-6.0 folder with a symlink to the one inside it.

Here's how to do it:

From inside the dwm folder you just copied from /var/abs/community/dwm

    ln -s ln -s src/dwm-6.0/config.h ./
	ln -s ln -s src/dwm-6.0/config.h src/

I think it'll work if you install it from Arch's abs and replace the dwm-6.0 folder and follow the **Configuration** step on Arch's wiki.

Running dwm
-----------
Add the following line to your .xinitrc to start dwm using startx:

    exec dwm

In order to connect dwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:

    DISPLAY=foo.bar:1 exec dwm

(This will start dwm on display :1 of the host foo.bar.)

In order to display status info in the bar, you can do something
like this in your .xinitrc:

    while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
    do
    	sleep 1
    done &
    exec dwm


Configuration
-------------
The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.
