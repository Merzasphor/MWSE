[Setup]
AppName=Morrowind Script Extender
AppVerName=Morrowind Script Extender 0.9.4
AppPublisherURL=http://sourceforge.net/projects/mwse/
AppSupportURL=http://sourceforge.net/projects/mwse/
AppUpdatesURL=http://sourceforge.net/projects/mwse/
DefaultDirName={pf}\MWScriptExtender
;DefaultDirName={reg:HKLM\Software\Bethesda Softworks\Morrowind,Installed Path}
;this installs it to the Morrowind directory
DefaultGroupName=Morrowind Script Extender
LicenseFile=D:\Darksecond\Desktop\Setup2\GPL.txt
OutputDir=D:\Darksecond\Desktop\Setup2
OutputBaseFilename=setup
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

Name: "democopy"; Description: "Copy Demo esp to Morrowind Directory"; GroupDescription: "Demo"; Flags: unchecked

[Files]
Source: "D:\Darksecond\Desktop\Setup2\MWSEloader.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Darksecond\Desktop\Setup2\MWSE.dll"; DestDir: "{app}"; Flags: ignoreversion

; NOTE: these are 'other' files
Source: "D:\Darksecond\Desktop\Setup2\GPL.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Darksecond\Desktop\Setup2\customfunctions.dat"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Darksecond\Desktop\Setup2\Readme.html"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Darksecond\Desktop\Setup2\authors"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Darksecond\Desktop\Setup2\Changelog.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Darksecond\Desktop\Setup2\Copying"; DestDir: "{app}"; Flags: ignoreversion

Source: "D:\Darksecond\Desktop\Setup2\MWSE_v092a_Demo.esp"; DestDir: "{reg:HKLM\Software\Bethesda Softworks\Morrowind,Installed Path}\Data Files"; Flags: ignoreversion uninsneveruninstall; Tasks: democopy
Source: "D:\Darksecond\Desktop\Setup2\MWSE_v092a_Demo.esp"; DestDir: "{app}"; Flags: ignoreversion;

; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\Morrowind Script Extender"; Filename: "{app}\MWSEloader.exe"
Name: "{commondesktop}\Morrowind Script Extender"; Filename: "{app}\MWSEloader.exe"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\Morrowind Script Extender"; Filename: "{app}\MWSEloader.exe"; Tasks: quicklaunchicon

Name: "{group}\Uninstall MWSE"; Filename: "{uninstallexe}"

; NOTE: there are 'other' icons
Name: "{group}\Readme"; Filename: "{app}\Readme.html"

;[Run]
;Filename: "{app}\MWSEloader.exe"; Description: "{cm:LaunchProgram,Morrowind Script Extender}"; Flags: nowait postinstall skipifsilent

