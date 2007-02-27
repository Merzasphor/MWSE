
Morrowind Script Extender

03-08-2005 CDC

26-02-2007 SF MWSE Dev Team
Cody Erekson
Tim Peters
Grant McDorman
Anthony Garcia

 

The Morrowind Script Extender is a program designed to increase the
features available to Morrowind scripters. When run with the game, it
adds extra script functions, allowing the creation of plugins that are
impossible or at least very difficult while running the game alone.

This version builds upon the 0.9.2 version from cdcooley, it only
supports Morrowind version 1.6.1820 (Bloodmoon and GOTY versions).

For any support go to: http://sourceforge.net/projects/mwse, or PM Tp21,
games1216(AnthonyG), or Fliggerty on the TES Forums.

The Morrowind Script Extender is free software, licensed according to
the GNU Public License, and comes with ABSOLUTELY NO WARRANTY. See the
file gpl.txt for details if you are interested in distributing or
modifying the program.

************************************

0.9.4.1 Update

This update, 0.9.4.1, contains no new features over 0.9.4. However, one
bug, 1666719, has been fixed. This bug resulted in the message
 Could not inject MWSE into Morrowind: MWSE.DLL failed to load in Morrowind
and MWSE failed to work. This has been fixed by having the Launcher
copy MWSE.DLL to the Morrowind directory. No other changes have been
made; MWSE.DLL is, in fact, identical to the 0.9.4 version.

Bug 1666718 (crash on exit) remains unfixed.

************************************

Installing and Running the Program

If you have downloaded the installer, it will install by default to
C:\Program Files\MWScriptExtender.  You will be given the option to
install elsewhere though.  

If you have downloaded the ZIP file, place MWSE Launcher.exe and
MWSE.dll in a location of your choice.

It will work regardless of which directory it is installed into.

The first time the MWSE Launcher is run, it will copy MWSE.DLL to the
Morrowind directory. For that reason, you will need to either be able
to write to the Morrowind directory the first time you run MWSE, or you
must copy the file MWSE.DLL manually.

For multiple Morrowind installations, the MWSE Launcher will find the
location of the last installed version. It checks the registry key
HKLM\Software\Bethesda Softworks\Morrowind,Installed Path and launches
the Morrowind Launcher.exe found there. However, it will also check
for Morrowind.exe in the same directory. To avoid renaming your
installation folders, you can simply put a copy of MWSE into each
installation directory.

You can also launch Morrowind manually; to do this, start the MWSE
Launcher, and then start Morrowind. The launcher will detect that you
have started Morrowind and inject the MWSE scripting into Morrowind.


************************************

Special Considerations


Limited Accounts on Windows XP: MWSE will work with limited accounts in
Windows XP, provided that the MWSE Launcher can write to the Morrowind
directory the first time it is run.

Log file: The MWSE log file is in the Morrowind directory (same place
as Morrowind's 'warnings.txt'). It is named MWSELog.txt.

Other extenders: MWSE is known to work with Morrowind Graphic Extender
(MGE) and Morrowind Extender (MWE). However, MGE scripting does not work
as of the current MGE release; a future MGE release may correct this.

************************************

MWSE Launcher: There is now a GUI style launcher.  It has three buttons:
Launch Morrowind, View Log, and Exit.  Launch Morrowind will start
Morrowind Launcher.exe; note that the MWSE Launcher does not have to be
restarted to launch Morrowind again.  View Log will open MWSElog.txt.
Finally, the Exit button will close the MWSE Launcher.

************************************

Source and Support files for Modders and Scripters and updated versions
can be found at: http://sourceforge.net/projects/mwse, you can find all
the package details there.

Bugs and feature requests should be submitted at
http://sourceforge.net/tracker/?group_id=172997.

