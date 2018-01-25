# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/).

## [v2.0.0] - 2018-MM-DD [unreleased]

This release marks a complete under the hood rewrite of how MWSE functions. Version 2.0 is designed to be 100% compatible with previous version of MWSE.

### Added
- Performance improvements across the board. The underlying mechanism used to extend Morrowind's scripting system has been entirely rewritten to improve performance. This version of MWSE makes frequent raycasting to what the player is looking at, single-frame `xContent` loops, and other scripting necessities more viable.
- `xGetMCPFeatureState`: The [Morrowind Code Patch](https://www.nexusmods.com/morrowind/mods/19510) has become more important with its fixes to the script parser, and other scripting extensions. If the user has the MCP installed and hasn't deleted the mcpatch folder, this function will let the script know if a MCP feature is enabled or disabled. The ID passed to this function can be found in the describe.json file in the mcpatch folder.
- `xStartScript`, `xStopScript` and `xScriptRunning`: These functions are wrappers around their non-MWSE counterparts, and accept a variable input. Additionally, calling `xStopScript 0` will effectively call `xStopScript` on the current script.
- `xGetModel`: This function gets the targeted reference's model as a string. It will work on anything but NPC or CREATURE references, which return `0`.

### Changed
- String storage has changed under the hood. It's just as reliable as before, but is more recognizable. Strings are stored by ID rather than as string pointers, starting at an index of 40,000. An invalid/empty response is still treated as zero. Scripters do not need to change how they handle strings in any way.
- Version information has adapted to something more traditional. MWSE is mature software that has been out for many years. It isn't in alpha or beta anymore. As such, it is treating pre-2.0 MWSE as version 1, and making the leap to version 2 with this entire rewrite. 
- `xStringParse`: This function can now be used to determine MWSE's version number at runtime. This can be useful for ensuring that a feature is available. Correct usage is `setx version versionCheck to xStringParse "MWSE_VERSION" versionNumberDesired`.
  * The first returned value is a `long` with a value starting at `2000000` for version 2.0.0. This continues to a pattern, where the hypothetical version 5.59.3 would return `5059003`. On versions of MWSE prior to 2.0, `xStringParse` will return `0`.
  * The second parameter can be used as a version check, and the second returned value will be `1` if the current version meets that requirement. For example, `setx version versionCheck to xStringParse "MWSE_VERSION" 2001000` will set `versionCheck` to `1` if the current MWSE version is at least 2.1.0. Otherwise `versionCheck` will be `0`.

### Fixed
- `xSetName` is safe to use, and no longer rewrites random portions of memory. This function used to cause various issues if the new name was longer than the old name on most object types. This could cause random value changes, and make the game prone to crashing.

## [0.9.5-alpha.YYYYMMDD] - 2017-MM-DD

### Changed
- Changed project base from Visual Studio 2005 to Visual Studio 2017.

## [0.9.5-alpha.20171114] - 2017-11-14

### Added
- New function to get the race of the player and NPCs: xGetRace.
- New function get the number of elements in an array: xGetArraySize
- New function to remove all elements in an array: xClearArray

### Fixed
- Calling xSetArrayValue with an invalid array id could crash the game.

## [0.9.5-alpha.20171112] - 2017-11-12

### Fixed
- In some cases, evaluating string format codes could fail (xMessageFix,
  xStringBuild, xLogMessage, xFileWriteText).

## [0.9.5-alpha.20171111] - 2017-11-11

### Added
- New function to get maximum, current (modified), and unmodified encumbrance:
  xGetEncumbrance.
- New functions to get maximum magicka and fatigue, to complement xGetMaxHealth:
  xGetMaxMagicka, xGetMaxFatigue

### Changed
- xMessageFix, xStringBuild, xLogMessage, xFileWriteText print a message to the
  log when invalid format codes are encountered. The log message contains the
  invalid codes, the original format string, and the resulting string.
- xGetMagic now works with NPC and creature references, in addition to the
  player.
- xGetMaxHealth, xGetSkill, xGetBaseAttribute, xGetAttribute, xModAttribute now
  work with creature references, in addition to the player and NPCs.
- xGetEnchant now works with ammo.

### Fixed
- Better handling of invalid format codes in xMessageFix, xStringBuild,
  xLogMessage, xFileWriteText. All invalid codes are removed in the resulting
  string, preventing them from propagating to MessageBox via xMessageFix and
  potentially causing a crash.

## [0.9.5-alpha.20171006] - 2017-10-06

### Fixed
- xNextRef no longer crashes when passed a null reference. Now it returns a null reference and prints a message to the log instead.

## [0.9.5-alpha.20151016] - 2015-10-16

### Added
- New functions to generate random numbers: xRandomLong, xRandomFloat.

### Changed
- Removed string length limits for xLogMessage, xStringBuild, xFileWriteText.
- xGetEnchant now works with scrolls.
- Upgraded boost to 1.59.0.

### Fixed
- xMessageFix no longer ignores the trailing "%" flag (null terminator suppression) when updating button strings.

## [0.9.5-alpha.20150902] - 2015-09-02

### Changed
- xSetLevel is now a wrapper for the native SetLevel function.

## [0.9.5-alpha.20150829] - 2015-08-29

### Added
- New functions: xSetLevel, xGetSkill, xGetBaseAttribute, xGetAttribute, xGetMaxHealth, xModAttribute

### Changed
- xContentList, xGetName now work with ammo and lockpicks.
- xSetName, xSetQuality, xSetWeight now work with lockpicks.
- xGetBaseSkill now works with NPCs.

## [0.9.5-alpha.20150722] - 2015-07-22
### Added
- New functions to read/write string GMSTs: xGetGSString, xSetGSString.

## [0.9.5-alpha.20150718] - 2015-07-18
### Added
- New functions to read and write skill parameters: xGetSkillInfo, xSetSkillInfo.

### Changed
- xCreateSpell now creates spells with a default cost of 1.
- xGetProgressLevel, xSetProgressLevel, xModProgressLevel, xGetProgressSkill, xSetProgressSkill, xModProgressSkill 
no longer need an explicit player reference. They now implicitly access the player's reference as needed.

### Fixed
- xStringMatch no longer finds partial pattern matches.
- xCreateSpell now properly truncates spell names to 31 characters and avoids using more memory for names than needed.
- xCreateSpell no longer creates spells that cannot be added to an actor.

## [0.9.5-alpha.20150707] - 2015-07-07
### Added
- New functions to read/write base magic effect properties: xGetBaseEffectInfo, xSetBaseEffectInfo.
- New functions to create/delete custom spells: xCreateSpell, xDeleteSpell.

### Changed
- xSetSpellInfo, xGetSpellInfo now include spell origin (module, spellmaking).
- Combined skill and attribute ids into a single parameter/return value for xAddEffect, xSetEffectInfo, xGetEffectInfo.
- xSetSpellInfo now limits spell names to 31 characters.

### Fixed
- No longer crashes on exit after changing the name of a spell.

## [0.9.5-alpha.20150630] - 2015-06-30
### Added
- New function to return all ownership information about a reference: xGetOwnerInfo.
- New function to compute exponentiation: xPow
- New functions to perform bitwise operations on longs: xShift, xBitAnd, xBitOr, xBitXor, xBitNot.
- New functions to perform boolean logic: xAnd, xOr, xXor, xNot.
- New functions to manipulate global variables based on their string representation: xGetGlobal, xSetGlobal.
- New functions to modify spell and enchantment properties: xSetSpellInfo, xSetEnchantInfo, xSetEffectInfo, xDeleteEffect, xAddEffect.
- New function to return the type and id of the player's currently readied magic: xGetMagic.

### Changed
- Reverted xGetOwner change from [0.9.5-alpha.20150617] to maintain compatibility with old mods.
- Skill progress functions now support normalized progress values and invoke the game's native skill-up function: xGetProgressSkill, xSetProgressSkill, xModProgressSkill.
- Level progress functions now invoke the game's native level-up message function: xSetProgressLevel, xGetProgressLevel.

### Deprecated
- xGetOwner - Replaced by xGetOwnerInfo.
- xGetBaseAcrobatics, xGetBaseAlchemy, xGetBaseAlteration,
xGetBaseArmorer, xGetBaseAthletics, xGetBaseAxe, xGetBaseBlock, xGetBaseBluntWeapon, xGetBaseConjuration, 
xGetBaseDestruction, xGetBaseEnchant, xGetBaseHandToHand, xGetBaseHeavyArmor, xGetBaseIllusion, xGetBaseLightArmor,
xGetBaseLongBlade, xGetBaseMarksman, xGetBaseMediumArmor, xGetBaseMercantile, xGetBaseMysticism,
xGetBaseRestoration, xGetBaseSecurity, xGetBaseShortBlade, xGetBaseSneak, xGetBaseSpear,
xGetBaseSpeechcraft, xGetBaseUnarmored - Replaced by xGetBaseSkill
- xGetSpellEffectInfo - Replaced by xGetEffectInfo
- xGetEnchantEffectInfo - Replaced by xGetEffectInfo


## [0.9.5-alpha.20150617] - 2015-06-17
### Added
- New functions to support arrays: xCreateArray, xSetArrayValue, xGetArrayValue.
- New functions to read and manipulate skill progress: xGetProgressSkill, xSetProgressSkill, xModProgressSkill.
- New function to modify level progress by a fixed value: xModProgressLevel.
- New function to get base skill values using an arugment to determine the skill to read: xGetBaseSkill.

### Changed
- xGetOwner now returns the id string of faction owners.
- Modified xGetProgressLevel, xSetProgressLevel to make use of player data structures instead of fixed offsets.

### Fixed
- xSetProgressLevel no longer fails when setting progress to zero.

## [WIP-2015-02-16] - 2015-02-16
### Added
- Ported MGE XE GMST functions: xGetGS, xSetGSLong, xSetGSFloat.

## [WIP-2015-01-29] - 2015-01-29
### Added
- Compatibility with MGE XE 0.10.0 beta 9 or later.

### Fixed
- Another access violation issue resolved. (Fix courtesy of Hrnchamd.)

## [WIP-2014-12-06] - 2014-12-06
### Added
- New function to get information about the class of the player or NPCs: xGetClass.

## [WIP-2014-11-26] - 2014-11-26
### Added
- New functions to get information about enchantments on items, enchantment properties, and enchantment effects: xGetEnchant, xGetEnchantInfo, xGetEnchantEffectInfo.

## [WIP-2014-11-25] - 2014-11-25
### Added
- New function to determine if a player or NPC has a specific spell: xGetSpell.
- New function to iterate through a player's or NPC's known spells: xSpellList.

## [WIP-2014-11-23] - 2014-11-23
### Added
- New functions to return information about spells and spell effects: xGetSpellInfo, xGetSpellEffectInfo.
- New functions to allow longs to be stored in globals: xLongToFloats, xFloatsToLong.

### Fixed
- Access violation issue resolved.

## [WIP-2014-11-15] - 2014-11-15
### Added
- New function to get the spell id of a trap: xGetTrap.
- New function to remove a trap: xRemoveTrap.
- New wrapper for ExplodeSpell: xExplodeSpell.

## [WIP-2014-11-14] - 2014-11-14
### Added
- New function to set the player's progress to the next level: xSetProgressLevel.

## [WIP-2014-11-09] - 2014-11-09
### Fixed
- xGetContentList now returns the weight and value of ammo and repair items.

### Added
- Function to return the lock level of a door or container: xGetLockLevel.

## [WIP-2014-11-08] - 2014-11-08
### Fixed
- xFirstItem, xFirstStatic, and xNextRef now find all references in exterior cells.
- xFirstNPC, xFirstItem, xFirstStatic, and xNextRef skip references that have been deleted by plugins.

## [WIP-2014-11-07-b] - 2014-11-07
### Fixed
- xFirstNPC and xNextRef now find all NPCs in exterior cells.

## [WIP-2014-11-07-a] - 2014-11-07
### Fixed
- xGetCondition now correctly reads max condition when current condition is not available (e.g. item never damaged).

## [WIP-2014-11-07] - 2014-11-07
### Changed
- xGetValue and xGetWeight now support ammo and repair items.

## [WIP-2014-11-06] - 2014-11-06
### Fixed
- xGetCondition now returns the current (not max) condition of armor, weapons, lockpicks, probes, and repair items.

## [WIP-2014-11-02] - 2014-11-02
### Added
- New functions to read the base skills of the player: xGetBaseAcrobatics, xGetBaseAlchemy, xGetBaseAlteration,
xGetBaseArmorer, xGetBaseAthletics, xGetBaseAxe, xGetBaseBlock, xGetBaseBluntWeapon, xGetBaseConjuration, 
xGetBaseDestruction, xGetBaseEnchant, xGetBaseHandToHand, xGetBaseHeavyArmor, xGetBaseIllusion, xGetBaseLightArmor,
xGetBaseLongBlade, xGetBaseMarksman, xGetBaseMediumArmor, xGetBaseMercantile, xGetBaseMysticism,
xGetBaseRestoration, xGetBaseSecurity, xGetBaseShortBlade, xGetBaseSneak, xGetBaseSpear,
xGetBaseSpeechcraft, xGetBaseUnarmored.
- New function to read the player's progress to the next level: xGetProgressLevel.

# Original Changelog.txt

--------------------------------------------------------------------------------

MWSE 0.9.3: Changelog  
Developers: AnthonyG, Fliggerty, Timeslip, Tp21, grmcdorman  
Original Developers: CdCooley, FreshFish

--------------------------------------------------------------------------------

## 2007-02-24 by Grant McDorman <grmcdorman>
Changed MWSE.DLL to be in Morrowind directory. When injecting the DLL, try
to find MWSE.DLL in the launcher directory and the Morrowind directory; if
the DLL differs in version, or is not present in the Morrowind directory,
copy the file from the launcher directory to the Morrowind directory. Also
fix the 'view log' to look in the Morrowind directory as well, and to detect
the absence of the log (instead of launching Notepad anyway).

## 2007-02-24 by Grant McDorman <grmcdorman>
Changed mechanism for locating MWSE.DLL in launcher, to try and squish bug
1666719.

## 2007-02-03 by Grant McDorman <grmcdorman>
Copied Ted's ArchiveMaker to trunk from 0.9.4 release tag.

## 2007-02-02 by Grant McDorman <grmcdorman>
In installer, drop obsolete install of shortcut to Readme.html in Start Menu.
Also fix incorrect Quick Launch shortcut.

## 2007-02-02 by Grant McDorman <grmcdorman>
Changed installer: dropped Readme.html, added Readme, License (GPL.txt),
MWSE Scripting Guide (MWSE_Scripting.html) to Start Menu entry, corrected
desktop icon error.

## 2007-01-31 by Grant McDorman <grmcdorman>
MWSE_Scripting.html updated: now valid HTML, and includes description
of xStringMatch.

## 2007-01-30 by Grant McDorman <grmcdorman>
Added detailed error handling to launcher, improved injection marginally.
Also fixed syntax errors in Setup script.

## 2007-01-27 by Fliggerty
- Finished Demo esp.
- Added new functions to MWSE_Scripting.html

## 2007-01-27 by Grant McDorman <grmcdorman>
Fix xSetMaxCondition: it did not enforce condition to be no greater than
max condition.

## 2007-01-27 by Grant McDorman <grmcdorman>
Remove unneeded and confusing 'mwse 0.9.3' directory (contents moved to
parent)
Installer build script fetches Changelog.txt and binaries from their initial
locations (no copying)

## 2007-01-25 by Grant McDorman <grmcdorman>
Launcher updated to have a status bar. Messages in the status bar give:

- launcher version (when first started)
- "Morrowind started" when "Launch Morrowind" pressed
- "MWSE <version> loaded in Morrowind <version>"
- "Morrowind exited"

Also, log moved from Morrowind directory to directory containing MWSE.DLL,
and MWSE.DLL logs its version in the log file when started.

## 2007-01-24 by Grant McDorman <grmcdorman>
New launcher (formerly known as the loader). Written using WTL 8, it has
the following features:

- Buttons to launch Morrowind's launcher, view MWSE log, and exit
- Launcher does not need to be in Morrowind directory (but MWSE.dll needs to be in _launcher's_ directory)
- Does not hang or use lots of CPU when looking for Morrowind to start
- Log is once again a text file (MWSELog.txt in Morrowind directory)
- Detects Morrowind (and injects MWSE.dll) when Morrowind is launched externally
- Buttons (launch, view log) disable/enable as appropriate

## 2007-01-22 by Grant McDorman <grmcdorman>
Regular expression string match (xStringMatch). Uses Boost library.

## 2007-01-20 by Grant McDorman <grmcdorman>
Implemented set functions for value, weight, quality, condition, max condition,
charge, and max charge. Also various code cleanups.

## 2007-01-18 by Tp21
Implemented new Logging class: cLog.
everything you log, is put through to the MWSELoaders' console.

## 2007-01-09 by AnthonyG
- Oh so much changes... Hm..
- Now has GUI
- MWSE DLL can now send messages to the loader's console via Mailslots
- Optimizations

## 2007-01-06 by Tp21
You can now run Another program with MWSELoader by just popping in the program location as an command line argument. it'll run the program, and just sit and wait until Morrowind is launched.

## 2007-01-05 by AnthonyG
New logging methods available, Up to the rest of the team to use them or not

## 2007-01-05 by AnthonyG
- Morrowind Script Extender is now directory dependent, You no longer have to place it in Morrowind's install directory
- Under the hood improvements
- New silent and console mode binary options(Not available to end-user, Developer's choice).

## 2007-01-05 by Tp21
- new 0.9.3 branch, that includes the new MWSE.
- Added Resource information to both DLL and loader, added icon to loader
- removed the Memlook function, that doesn't work now it doesn't has an interactive console available. and nobody used it anyway because it's an debug function

[Unreleased]: https://github.com/Merzasphor/MWSE/compare/v0.9.5-alpha.20171114...HEAD
[0.9.5-alpha.20171114]: https://github.com/Merzasphor/MWSE/compare/v0.9.5-alpha.20171112...v0.9.5-alpha.20171114
[0.9.5-alpha.20171112]: https://github.com/Merzasphor/MWSE/compare/v0.9.5-alpha.20171111...v0.9.5-alpha.20171112
[0.9.5-alpha.20171111]: https://github.com/Merzasphor/MWSE/compare/v0.9.5-alpha.20171006...v0.9.5-alpha.20171111
[0.9.5-alpha.20171006]: https://github.com/Merzasphor/MWSE/compare/v0.9.5-alpha.201501016...v0.9.5-alpha.20171006
[0.9.5-alpha.20151016]: https://github.com/Merzasphor/MWSE/compare/v0.9.5-alpha.20150902...v0.9.5-alpha.201501016
[0.9.5-alpha.20150902]: https://github.com/Merzasphor/MWSE/compare/v0.9.5-alpha.20150829...v0.9.5-alpha.20150902
[0.9.5-alpha.20150829]: https://github.com/Merzasphor/MWSE/compare/v0.9.5-alpha.20150722...v0.9.5-alpha.20150829
[0.9.5-alpha.20150722]: https://github.com/Merzasphor/MWSE/compare/v0.9.5-alpha.20150718...v0.9.5-alpha.20150722
[0.9.5-alpha.20150718]: https://github.com/Merzasphor/MWSE/compare/v0.9.5-alpha.20150707...v0.9.5-alpha.20150718
[0.9.5-alpha.20150707]: https://github.com/Merzasphor/MWSE/compare/v0.9.5-alpha.20150630...v0.9.5-alpha.20150707
[0.9.5-alpha.20150630]: https://github.com/Merzasphor/MWSE/compare/v0.9.5-alpha.20150617...v0.9.5-alpha.20150630
[0.9.5-alpha.20150617]: https://github.com/Merzasphor/MWSE/compare/b7007ac...v0.9.5-alpha.20150617
[WIP-2015-02-16]: https://github.com/Merzasphor/MWSE/compare/dc4fe3a...b7007ac
[WIP-2015-01-29]: https://github.com/Merzasphor/MWSE/compare/b966eac...dc4fe3a
[WIP-2014-12-06]: https://github.com/Merzasphor/MWSE/compare/8f1b171...b966eac
[WIP-2014-11-26]: https://github.com/Merzasphor/MWSE/compare/e120a16...8f1b171
[WIP-2014-11-25]: https://github.com/Merzasphor/MWSE/compare/bcd3312...e120a16
[WIP-2014-11-23]: https://github.com/Merzasphor/MWSE/compare/8e11d2b...bcd3312
[WIP-2014-11-15]: https://github.com/Merzasphor/MWSE/compare/8868e5b...8e11d2b
[WIP-2014-11-14]: https://github.com/Merzasphor/MWSE/compare/7a1ccf2...8868e5b
[WIP-2014-11-09]: https://github.com/Merzasphor/MWSE/compare/f09a89b...7a1ccf2
[WIP-2014-11-08]: https://github.com/Merzasphor/MWSE/compare/88ee11e...f09a89b
[WIP-2014-11-07-b]: https://github.com/Merzasphor/MWSE/compare/32c1f7d...88ee11e
[WIP-2014-11-07-a]: https://github.com/Merzasphor/MWSE/compare/318ada2...32c1f7d
[WIP-2014-11-07]: https://github.com/Merzasphor/MWSE/compare/31667b6...318ada2
[WIP-2014-11-06]: https://github.com/Merzasphor/MWSE/compare/44210ba...31667b6
[WIP-2014-11-02]: https://github.com/Merzasphor/MWSE/compare/74abbe8...44210ba

