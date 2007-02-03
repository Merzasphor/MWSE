@echo off

echo -- creating directory --

mkdir "MWScriptExtender 0.9.4"

echo -- copying files --

copy "..\Installer\Authors" ".\MWScriptExtender 0.9.4"
copy "..\Installer\Copying" ".\MWScriptExtender 0.9.4"

copy "..\..\MWSE_Launcher\Release\MWSE Launcher.exe" ".\MWScriptExtender 0.9.4"
copy "..\..\MWSE DLL\Release\MWSE.dll" ".\MWScriptExtender 0.9.4"

copy "..\GPL.txt" ".\MWScriptExtender 0.9.4"
copy "..\customfunctions.dat" ".\MWScriptExtender 0.9.4"
copy "..\Readme.txt" ".\MWScriptExtender 0.9.4"
copy "..\MWSE_Scripting.html" ".\MWScriptExtender 0.9.4"
copy "..\..\Changelog.txt" ".\MWScriptExtender 0.9.4"

copy "..\MWSE_v094_Demo.esp" ".\MWScriptExtender 0.9.4"

echo -- making ZIP archive --

zip.exe "MWSE0.9.4.zip" ".\MWScriptExtender 0.9.4\*.*"

echo -- making RAR archive --

rar.exe a "MWSE0.9.4.rar" ".\MWScriptExtender 0.9.4\*.*"