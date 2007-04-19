[Setup]
AppName=Morrowind Script Extender
AppVerName=Morrowind Script Extender 0.9.4.1
AppPublisherURL=http://sourceforge.net/projects/mwse/
AppSupportURL=http://sourceforge.net/projects/mwse/
AppUpdatesURL=http://sourceforge.net/projects/mwse/
DefaultDirName={pf}\MWScriptExtender
;DefaultDirName={reg:HKLM\Software\Bethesda Softworks\Morrowind,Installed Path}
;this installs it to the Morrowind directory
DefaultGroupName=Morrowind Script Extender
LicenseFile=../GPL.txt
OutputDir=.
OutputBaseFilename=Setup
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

Name: "democopy"; Description: "Copy Demo esp to Morrowind Directory"; GroupDescription: "Demo"; Flags: unchecked

[Files]
Source: "../../MWSE_Launcher/Release/MWSE Launcher.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "../../MWSE DLL/Release/MWSE.dll"; DestDir: "{app}"; Flags: ignoreversion

; NOTE: these are 'other' files
Source: "../GPL.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "../customfunctions.dat"; DestDir: "{app}"; Flags: ignoreversion
Source: "../Readme.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "../MWSE_Scripting.html"; DestDir: "{app}"; Flags: ignoreversion
Source: "authors"; DestDir: "{app}"; Flags: ignoreversion
Source: "../../Changelog.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "Copying"; DestDir: "{app}"; Flags: ignoreversion

Source: "../MWSE_v094_Demo.esp"; DestDir: "{reg:HKLM\Software\Bethesda Softworks\Morrowind,Installed Path}\Data Files"; Flags: ignoreversion uninsneveruninstall; Tasks: democopy
Source: "../MWSE_v094_Demo.esp"; DestDir: "{app}"; Flags: ignoreversion;

; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\Morrowind Script Extender"; Filename: "{app}\MWSE Launcher.exe"
Name: "{commondesktop}\Morrowind Script Extender"; Filename: "{app}\MWSE Launcher.exe"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\Morrowind Script Extender"; Filename: "{app}\MWSE Launcher.exe"; Tasks: quicklaunchicon

Name: "{group}\Uninstall MWSE"; Filename: "{uninstallexe}"

; NOTE: there are 'other' icons
Name: "{group}\MWSE Readme"; Filename: "{app}\Readme.txt"
Name: "{group}\MWSE License"; Filename: "{app}\GPL.txt"
Name: "{group}\MWSE Scripting Guide"; Filename: "{app}\MWSE_Scripting.html"

;[Run]
;Filename: "{app}\MWSE Launcher.exe"; Description: "{cm:LaunchProgram,Morrowind Script Extender}"; Flags: nowait postinstall skipifsilent

