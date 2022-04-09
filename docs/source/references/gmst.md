---
hide:
  - toc
---

# Game Settings (GMSTs)

!!! tip
	These values are available in Lua by their index in the `tes3.gmst` table. For example, `tes3.gmst.sLevelUpMsg` has a value of `682`.

!!! tip
	The value of a GMST can be retrieved by using the [`tes3.findGMST()`](https://mwse.github.io/MWSE/apis/tes3/#tes3findgmst) function. For example, `tes3.findGMST(tes3.gmst.sMonthMorningstar).value` has a value of `"Morning Star"` in an unmodded english installation of Morrowind.

Index                            | Value  | Type    | Default GMST Value
-------------------------------- | ------ | ------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
sMonthMorningstar                | `0`    | string  | `"Morning Star"`
sMonthSunsdawn                   | `1`    | string  | `"Sun's Dawn"`
sMonthFirstseed                  | `2`    | string  | `"First Seed"`
sMonthRainshand                  | `3`    | string  | `"Rain's Hand"`
sMonthSecondseed                 | `4`    | string  | `"Second Seed"`
sMonthMidyear                    | `5`    | string  | `"Mid Year"`
sMonthSunsheight                 | `6`    | string  | `"Sun's Height"`
sMonthLastseed                   | `7`    | string  | `"Last Seed"`
sMonthHeartfire                  | `8`    | string  | `"Heartfire"`
sMonthFrostfall                  | `9`    | string  | `"Frost Fall"`
sMonthSunsdusk                   | `10`   | string  | `"Sun's Dusk"`
sMonthEveningstar                | `11`   | string  | `"Evening Star"`
sSpecialization                  | `12`   | string  | `"Specialization"`
sSpecializationCombat            | `13`   | string  | `"Combat"`
sSpecializationMagic             | `14`   | string  | `"Magic"`
sSpecializationStealth           | `15`   | string  | `"Stealth"`
sSkillClassMajor                 | `16`   | string  | `"Major Skills"`
sSkillClassMinor                 | `17`   | string  | `"Minor Skills"`
sSkillClassMisc                  | `18`   | string  | `"Misc Skills"`
sRacialTraits                    | `19`   | string  | `"Racial Traits"`
sHealthPerHourOfRest             | `20`   | string  | `"Health per hour of rest"`
sHealthPerLevel                  | `21`   | string  | `"Health per level"`
sGoverningAttribute              | `22`   | string  | `"Governing Attribute"`
sClass                           | `23`   | string  | `"Class"`
sTraits                          | `24`   | string  | `"Traits"`
sJournal                         | `25`   | string  | `"Journal"`
sOK                              | `26`   | string  | `"OK"`
sClose                           | `27`   | string  | `"Close"`
sPrev                            | `28`   | string  | `"Prev"`
sNext                            | `29`   | string  | `"Next"`
sTake                            | `30`   | string  | `"Take"`
sWeaponTab                       | `31`   | string  | `"Weapon"`
sApparelTab                      | `32`   | string  | `"Apparel"`
sMagicTab                        | `33`   | string  | `"Magic"`
sMiscTab                         | `34`   | string  | `"Misc"`
sWornTab                         | `35`   | string  | `"Worn"`
sAllTab                          | `36`   | string  | `"All"`
sAttack                          | `37`   | string  | `"Attack"`
sUses                            | `38`   | string  | `"Uses"`
sQuality                         | `39`   | string  | `"Quality"`
sCharges                         | `40`   | string  | `"Charge:"`
sArmorRating                     | `41`   | string  | `"Armor Rating"`
sSlash                           | `42`   | string  | `"Slash"`
sThrust                          | `43`   | string  | `"Thrust"`
sChop                            | `44`   | string  | `"Chop"`
sEncumbrance                     | `45`   | string  | `"Encumbrance"`
sCondition                       | `46`   | string  | `"Condition"`
sWeight                          | `47`   | string  | `"Weight"`
sValue                           | `48`   | string  | `"Value"`
sLight                           | `49`   | string  | `"Light"`
sMedium                          | `50`   | string  | `"Medium"`
sHeavy                           | `51`   | string  | `"Heavy"`
sCancel                          | `52`   | string  | `"Cancel"`
sTakeAll                         | `53`   | string  | `"Take All"`
sUntilHealed                     | `54`   | string  | `"Until Healed"`
sRest                            | `55`   | string  | `"Rest"`
sWait                            | `56`   | string  | `"Wait"`
sRestIllegal                     | `57`   | string  | `"Resting here is illegal. You'll need to find a bed."`
sGold                            | `58`   | string  | `"Gold"`
sMove                            | `59`   | string  | `"Move"`
sTo                              | `60`   | string  | `"to"`
sActorInCombat                   | `61`   | string  | `"This character is in combat."`
sArmor                           | `62`   | string  | `"Armor"`
sTopics                          | `63`   | string  | `"Topics"`
sService                         | `64`   | string  | `"Service"`
sPersuasion                      | `65`   | string  | `"Persuasion"`
sBye                             | `66`   | string  | `"Bye"`
sGoodbye                         | `67`   | string  | `"Goodbye"`
sYes                             | `68`   | string  | `"Yes"`
sNo                              | `69`   | string  | `"No"`
sOn                              | `70`   | string  | `"On"`
sOff                             | `71`   | string  | `"Off"`
sFull                            | `72`   | string  | `"Full"`
sWorld                           | `73`   | string  | `"World"`
sExpelled                        | `74`   | string  | `"EXPELLED"`
sExpelledMessage                 | `75`   | string  | `"You have been expelled from"`
sFavoriteSkills                  | `76`   | string  | `"Favorite Skills"`
sGame                            | `77`   | string  | `"Game"`
sVideo                           | `78`   | string  | `"Video"`
sAudio                           | `79`   | string  | `"Audio"`
sControls                        | `80`   | string  | `"Controls"`
sPrefs                           | `81`   | string  | `"Prefs"`
sPreferences                     | `82`   | string  | `"Preferences"`
sNewGame                         | `83`   | string  | `"New Game"`
sExitGame                        | `84`   | string  | `"Exit Game"`
sOptions                         | `85`   | string  | `"Options Menu"`
sSaveGame                        | `86`   | string  | `"Save Game"`
sLoadGame                        | `87`   | string  | `"Load Game"`
sDeleteGame                      | `88`   | string  | `"Delete Game"`
sSaveGameDenied                  | `89`   | string  | `"You cannot save your game right now."`
sSaveGameFailed                  | `90`   | string  | `"An error was encountered while saving the game."`
sSaveGameTooBig                  | `91`   | string  | `"There is not enough space to save this game. Free up at least %i blocks and try again."`
sSaveGameNoMemory                | `92`   | string  | `"Unable to create Save Game. Free up 100 blocks and try again."`
sMaximumSaveGameMessage          | `93`   | string  | `"You have reached the limit of Morrowind saved games. Please delete a Morrowind saved game and try again."`
sRender_Distance                 | `94`   | string  | `"View Distance"`
sNear                            | `95`   | string  | `"Near"`
sFar                             | `96`   | string  | `"Far"`
sGamma_Correction                | `97`   | string  | `"Gamma Correction"`
sLight_Gamma                     | `98`   | string  | `"Light"`
sDark_Gamma                      | `99`   | string  | `"Dark"`
sSeldom                          | `100`  | string  | `"Seldom"`
sAlways                          | `101`  | string  | `"Always"`
sWaterTerrainReflect             | `102`  | string  | `"Reflect Terrain"`
sWaterReflectUpdate              | `103`  | string  | `"Reflection Updating"`
fWaterReflectUpdateAlways        | `104`  | float   | `0`
fWaterReflectUpdateSeldom        | `105`  | float   | `10`
sMaster                          | `106`  | string  | `"Master"`
sVoice                           | `107`  | string  | `"Voice"`
sEffects                         | `108`  | string  | `"Effects"`
sFootsteps                       | `109`  | string  | `"Footsteps"`
sMusic                           | `110`  | string  | `"Music"`
sTransparency_Menu               | `111`  | string  | `"Menu Transparency"`
sMenu_Help_Delay                 | `112`  | string  | `"Menu Help Delay"`
sAIDistance                      | `113`  | string  | `"AI Distance"`
sHigh                            | `114`  | string  | `"High"`
sLow                             | `115`  | string  | `"Low"`
sDetail_Level                    | `116`  | string  | `"Detail Level"`
sMenus                           | `117`  | string  | `"Menus"`
sStrip                           | `118`  | string  | `"Strip"`
sReturnToGame                    | `119`  | string  | `"Return To Game"`
sForward                         | `120`  | string  | `"Forward"`
sBack                            | `121`  | string  | `"Back"`
sLeft                            | `122`  | string  | `"Left"`
sRight                           | `123`  | string  | `"Right"`
sUse                             | `124`  | string  | `"Use"`
sActivate                        | `125`  | string  | `"Activate"`
sReady_Weapon                    | `126`  | string  | `"Ready Weapon"`
sReady_Magic                     | `127`  | string  | `"Ready Magic"`
sCrouch_Sneak                    | `128`  | string  | `"Sneak"`
sRun                             | `129`  | string  | `"Run"`
sAlways_Run                      | `130`  | string  | `"Always Run"`
sAuto_Run                        | `131`  | string  | `"Auto Run"`
sJump                            | `132`  | string  | `"Jump"`
sNextWeapon                      | `133`  | string  | `"Next Weapon"`
sPrevWeapon                      | `134`  | string  | `"Previous Weapon"`
sNextSpell                       | `135`  | string  | `"Next Spell"`
sPrevSpell                       | `136`  | string  | `"Previous Spell"`
sTogglePOVCmd                    | `137`  | string  | `"Toggle POV"`
sMenu_Mode                       | `138`  | string  | `"Menu Mode"`
sJournalCmd                      | `139`  | string  | `"Journal"`
sRestKey                         | `140`  | string  | `"Rest"`
sQuickMenu                       | `141`  | string  | `"Quick Menu"`
sQuick1Cmd                       | `142`  | string  | `"Quick 1"`
sQuick2Cmd                       | `143`  | string  | `"Quick 2"`
sQuick3Cmd                       | `144`  | string  | `"Quick 3"`
sQuick4Cmd                       | `145`  | string  | `"Quick 4"`
sQuick5Cmd                       | `146`  | string  | `"Quick 5"`
sQuick6Cmd                       | `147`  | string  | `"Quick 6"`
sQuick7Cmd                       | `148`  | string  | `"Quick 7"`
sQuick8Cmd                       | `149`  | string  | `"Quick 8"`
sQuick9Cmd                       | `150`  | string  | `"Quick 9"`
sQuick10Cmd                      | `151`  | string  | `"Quick 10"`
sQuickSaveCmd                    | `152`  | string  | `"Quick Save"`
sQuickLoadCmd                    | `153`  | string  | `"Quick Load"`
sKeyName_00                      | `154`  | string  | `""`
sKeyName_01                      | `155`  | string  | `"ESC"`
sKeyName_02                      | `156`  | string  | `"1"`
sKeyName_03                      | `157`  | string  | `"2"`
sKeyName_04                      | `158`  | string  | `"3"`
sKeyName_05                      | `159`  | string  | `"4"`
sKeyName_06                      | `160`  | string  | `"5"`
sKeyName_07                      | `161`  | string  | `"6"`
sKeyName_08                      | `162`  | string  | `"7"`
sKeyName_09                      | `163`  | string  | `"8"`
sKeyName_0A                      | `164`  | string  | `"9"`
sKeyName_0B                      | `165`  | string  | `"0"`
sKeyName_0C                      | `166`  | string  | `"-"`
sKeyName_0D                      | `167`  | string  | `"="`
sKeyName_0E                      | `168`  | string  | `"Back Space"`
sKeyName_0F                      | `169`  | string  | `"Tab"`
sKeyName_10                      | `170`  | string  | `"Q"`
sKeyName_11                      | `171`  | string  | `"W"`
sKeyName_12                      | `172`  | string  | `"E"`
sKeyName_13                      | `173`  | string  | `"R"`
sKeyName_14                      | `174`  | string  | `"T"`
sKeyName_15                      | `175`  | string  | `"Y"`
sKeyName_16                      | `176`  | string  | `"U"`
sKeyName_17                      | `177`  | string  | `"I"`
sKeyName_18                      | `178`  | string  | `"O"`
sKeyName_19                      | `179`  | string  | `"P"`
sKeyName_1A                      | `180`  | string  | `"["`
sKeyName_1B                      | `181`  | string  | `"]"`
sKeyName_1C                      | `182`  | string  | `"Return"`
sKeyName_1D                      | `183`  | string  | `"Left Ctrl"`
sKeyName_1E                      | `184`  | string  | `"A"`
sKeyName_1F                      | `185`  | string  | `"S"`
sKeyName_20                      | `186`  | string  | `"D"`
sKeyName_21                      | `187`  | string  | `"F"`
sKeyName_22                      | `188`  | string  | `"G"`
sKeyName_23                      | `189`  | string  | `"H"`
sKeyName_24                      | `190`  | string  | `"J"`
sKeyName_25                      | `191`  | string  | `"K"`
sKeyName_26                      | `192`  | string  | `"L"`
sKeyName_27                      | `193`  | string  | `";"`
sKeyName_28                      | `194`  | string  | `"'"`
sKeyName_29                      | `195`  | string  | `"Grave"`
sKeyName_2A                      | `196`  | string  | `"Left Shift"`
sKeyName_2B                      | `197`  | string  | `"\"`
sKeyName_2C                      | `198`  | string  | `"Z"`
sKeyName_2D                      | `199`  | string  | `"X"`
sKeyName_2E                      | `200`  | string  | `"C"`
sKeyName_2F                      | `201`  | string  | `"V"`
sKeyName_30                      | `202`  | string  | `"B"`
sKeyName_31                      | `203`  | string  | `"N"`
sKeyName_32                      | `204`  | string  | `"M"`
sKeyName_33                      | `205`  | string  | `","`
sKeyName_34                      | `206`  | string  | `"."`
sKeyName_35                      | `207`  | string  | `"/"`
sKeyName_36                      | `208`  | string  | `"Right Shift"`
sKeyName_37                      | `209`  | string  | `"Numpad *"`
sKeyName_38                      | `210`  | string  | `"Left Alt"`
sKeyName_39                      | `211`  | string  | `"SPACEBAR"`
sKeyName_3A                      | `212`  | string  | `"Caps Lock"`
sKeyName_3B                      | `213`  | string  | `"F1"`
sKeyName_3C                      | `214`  | string  | `"F2"`
sKeyName_3D                      | `215`  | string  | `"F3"`
sKeyName_3E                      | `216`  | string  | `"F4"`
sKeyName_3F                      | `217`  | string  | `"F5"`
sKeyName_40                      | `218`  | string  | `"F6"`
sKeyName_41                      | `219`  | string  | `"F7"`
sKeyName_42                      | `220`  | string  | `"F8"`
sKeyName_43                      | `221`  | string  | `"F9"`
sKeyName_44                      | `222`  | string  | `"F10"`
sKeyName_45                      | `223`  | string  | `"Num Lock"`
sKeyName_46                      | `224`  | string  | `"Scroll Lock"`
sKeyName_47                      | `225`  | string  | `"Numpad 7"`
sKeyName_48                      | `226`  | string  | `"Numpad 8"`
sKeyName_49                      | `227`  | string  | `"Numpad 9"`
sKeyName_4A                      | `228`  | string  | `"Numpad -"`
sKeyName_4B                      | `229`  | string  | `"Numpad 4"`
sKeyName_4C                      | `230`  | string  | `"Numpad 5"`
sKeyName_4D                      | `231`  | string  | `"Numpad 6"`
sKeyName_4E                      | `232`  | string  | `"Numpad +"`
sKeyName_4F                      | `233`  | string  | `"Numpad 1"`
sKeyName_50                      | `234`  | string  | `"Numpad 2"`
sKeyName_51                      | `235`  | string  | `"Numpad 3"`
sKeyName_52                      | `236`  | string  | `"Numpad 0"`
sKeyName_53                      | `237`  | string  | `"Decimal"`
sKeyName_54                      | `238`  | string  | `""`
sKeyName_55                      | `239`  | string  | `""`
sKeyName_56                      | `240`  | string  | `"OEM 102"`
sKeyName_57                      | `241`  | string  | `"F11"`
sKeyName_58                      | `242`  | string  | `"F12"`
sKeyName_59                      | `243`  | string  | `""`
sKeyName_5A                      | `244`  | string  | `""`
sKeyName_5B                      | `245`  | string  | `""`
sKeyName_5C                      | `246`  | string  | `""`
sKeyName_5D                      | `247`  | string  | `""`
sKeyName_5E                      | `248`  | string  | `""`
sKeyName_5F                      | `249`  | string  | `""`
sKeyName_60                      | `250`  | string  | `""`
sKeyName_61                      | `251`  | string  | `""`
sKeyName_62                      | `252`  | string  | `""`
sKeyName_63                      | `253`  | string  | `""`
sKeyName_64                      | `254`  | string  | `"F13"`
sKeyName_65                      | `255`  | string  | `"F14"`
sKeyName_66                      | `256`  | string  | `"F15"`
sKeyName_67                      | `257`  | string  | `""`
sKeyName_68                      | `258`  | string  | `""`
sKeyName_69                      | `259`  | string  | `""`
sKeyName_6A                      | `260`  | string  | `""`
sKeyName_6B                      | `261`  | string  | `""`
sKeyName_6C                      | `262`  | string  | `""`
sKeyName_6D                      | `263`  | string  | `""`
sKeyName_6E                      | `264`  | string  | `""`
sKeyName_6F                      | `265`  | string  | `""`
sKeyName_70                      | `266`  | string  | `"Kana"`
sKeyName_71                      | `267`  | string  | `""`
sKeyName_72                      | `268`  | string  | `""`
sKeyName_73                      | `269`  | string  | `"Abnt C1"`
sKeyName_74                      | `270`  | string  | `""`
sKeyName_75                      | `271`  | string  | `""`
sKeyName_76                      | `272`  | string  | `""`
sKeyName_77                      | `273`  | string  | `""`
sKeyName_78                      | `274`  | string  | `""`
sKeyName_79                      | `275`  | string  | `"Cnvrt"`
sKeyName_7A                      | `276`  | string  | `""`
sKeyName_7B                      | `277`  | string  | `"No Cnvrt"`
sKeyName_7C                      | `278`  | string  | `""`
sKeyName_7D                      | `279`  | string  | `"Yen"`
sKeyName_7E                      | `280`  | string  | `"Abnt C2"`
sKeyName_7F                      | `281`  | string  | `""`
sKeyName_80                      | `282`  | string  | `""`
sKeyName_81                      | `283`  | string  | `""`
sKeyName_82                      | `284`  | string  | `""`
sKeyName_83                      | `285`  | string  | `""`
sKeyName_84                      | `286`  | string  | `""`
sKeyName_85                      | `287`  | string  | `""`
sKeyName_86                      | `288`  | string  | `""`
sKeyName_87                      | `289`  | string  | `""`
sKeyName_88                      | `290`  | string  | `""`
sKeyName_89                      | `291`  | string  | `""`
sKeyName_8A                      | `292`  | string  | `""`
sKeyName_8B                      | `293`  | string  | `""`
sKeyName_8C                      | `294`  | string  | `""`
sKeyName_8D                      | `295`  | string  | `"Np Equals"`
sKeyName_8E                      | `296`  | string  | `""`
sKeyName_8F                      | `297`  | string  | `""`
sKeyName_90                      | `298`  | string  | `"PrvTrk"`
sKeyName_91                      | `299`  | string  | `"AT"`
sKeyName_92                      | `300`  | string  | `":"`
sKeyName_93                      | `301`  | string  | `"_"`
sKeyName_94                      | `302`  | string  | `"Kanji"`
sKeyName_95                      | `303`  | string  | `"Stop"`
sKeyName_96                      | `304`  | string  | `"Ax"`
sKeyName_97                      | `305`  | string  | `"Unlabeled"`
sKeyName_98                      | `306`  | string  | `""`
sKeyName_99                      | `307`  | string  | `"NxtTrk"`
sKeyName_9A                      | `308`  | string  | `""`
sKeyName_9B                      | `309`  | string  | `""`
sKeyName_9C                      | `310`  | string  | `"Right Enter"`
sKeyName_9D                      | `311`  | string  | `"Right Ctrl"`
sKeyName_9E                      | `312`  | string  | `""`
sKeyName_9F                      | `313`  | string  | `""`
sKeyName_A0                      | `314`  | string  | `"Mute"`
sKeyName_A1                      | `315`  | string  | `"Calc"`
sKeyName_A2                      | `316`  | string  | `"Play Pause"`
sKeyName_A3                      | `317`  | string  | `""`
sKeyName_A4                      | `318`  | string  | `"Media Stop"`
sKeyName_A5                      | `319`  | string  | `""`
sKeyName_A6                      | `320`  | string  | `""`
sKeyName_A7                      | `321`  | string  | `""`
sKeyName_A8                      | `322`  | string  | `""`
sKeyName_A9                      | `323`  | string  | `""`
sKeyName_AA                      | `324`  | string  | `""`
sKeyName_AB                      | `325`  | string  | `""`
sKeyName_AC                      | `326`  | string  | `""`
sKeyName_AD                      | `327`  | string  | `""`
sKeyName_AE                      | `328`  | string  | `"Volume Down"`
sKeyName_AF                      | `329`  | string  | `""`
sKeyName_B0                      | `330`  | string  | `"Volume Up"`
sKeyName_B1                      | `331`  | string  | `""`
sKeyName_B2                      | `332`  | string  | `"Web Home"`
sKeyName_B3                      | `333`  | string  | `"Numpad ,"`
sKeyName_B4                      | `334`  | string  | `""`
sKeyName_B5                      | `335`  | string  | `"Numpad /"`
sKeyName_B6                      | `336`  | string  | `""`
sKeyName_B7                      | `337`  | string  | `"SysRq"`
sKeyName_B8                      | `338`  | string  | `"Right Alt"`
sKeyName_B9                      | `339`  | string  | `""`
sKeyName_BA                      | `340`  | string  | `""`
sKeyName_BB                      | `341`  | string  | `""`
sKeyName_BC                      | `342`  | string  | `""`
sKeyName_BD                      | `343`  | string  | `""`
sKeyName_BE                      | `344`  | string  | `""`
sKeyName_BF                      | `345`  | string  | `""`
sKeyName_C0                      | `346`  | string  | `""`
sKeyName_C1                      | `347`  | string  | `""`
sKeyName_C2                      | `348`  | string  | `""`
sKeyName_C3                      | `349`  | string  | `""`
sKeyName_C4                      | `350`  | string  | `""`
sKeyName_C5                      | `351`  | string  | `"Pause"`
sKeyName_C6                      | `352`  | string  | `""`
sKeyName_C7                      | `353`  | string  | `"Home"`
sKeyName_C8                      | `354`  | string  | `"Up"`
sKeyName_C9                      | `355`  | string  | `"Page Up"`
sKeyName_CA                      | `356`  | string  | `""`
sKeyName_CB                      | `357`  | string  | `"Left"`
sKeyName_CC                      | `358`  | string  | `""`
sKeyName_CD                      | `359`  | string  | `"Right"`
sKeyName_CE                      | `360`  | string  | `""`
sKeyName_CF                      | `361`  | string  | `"End"`
sKeyName_D0                      | `362`  | string  | `"Down"`
sKeyName_D1                      | `363`  | string  | `"Page Down"`
sKeyName_D2                      | `364`  | string  | `"Insert"`
sKeyName_D3                      | `365`  | string  | `"Delete"`
sKeyName_D4                      | `366`  | string  | `""`
sKeyName_D5                      | `367`  | string  | `""`
sKeyName_D6                      | `368`  | string  | `""`
sKeyName_D7                      | `369`  | string  | `""`
sKeyName_D8                      | `370`  | string  | `""`
sKeyName_D9                      | `371`  | string  | `""`
sKeyName_DA                      | `372`  | string  | `""`
sKeyName_DB                      | `373`  | string  | `"Left Win"`
sKeyName_DC                      | `374`  | string  | `"Right Win"`
sKeyName_DD                      | `375`  | string  | `"Apps"`
sKeyName_DE                      | `376`  | string  | `"Power"`
sKeyName_DF                      | `377`  | string  | `"Sleep"`
sKeyName_E0                      | `378`  | string  | `""`
sKeyName_E1                      | `379`  | string  | `""`
sKeyName_E2                      | `380`  | string  | `""`
sKeyName_E3                      | `381`  | string  | `"Wake"`
sKeyName_E4                      | `382`  | string  | `""`
sKeyName_E5                      | `383`  | string  | `"Web Search"`
sKeyName_E6                      | `384`  | string  | `"Web Favs"`
sKeyName_E7                      | `385`  | string  | `"Web Ref"`
sKeyName_E8                      | `386`  | string  | `"Web Stop"`
sKeyName_E9                      | `387`  | string  | `"Web Fwd"`
sKeyName_EA                      | `388`  | string  | `"Web Back"`
sKeyName_EB                      | `389`  | string  | `"My Comp"`
sKeyName_EC                      | `390`  | string  | `""`
sKeyName_ED                      | `391`  | string  | `""`
sKeyName_EE                      | `392`  | string  | `""`
sKeyName_EF                      | `393`  | string  | `""`
sKeyName_F0                      | `394`  | string  | `""`
sKeyName_F1                      | `395`  | string  | `""`
sKeyName_F2                      | `396`  | string  | `""`
sKeyName_F3                      | `397`  | string  | `""`
sKeyName_F4                      | `398`  | string  | `""`
sKeyName_F5                      | `399`  | string  | `""`
sKeyName_F6                      | `400`  | string  | `""`
sKeyName_F7                      | `401`  | string  | `""`
sKeyName_F8                      | `402`  | string  | `""`
sKeyName_F9                      | `403`  | string  | `""`
sKeyName_FA                      | `404`  | string  | `""`
sKeyName_FB                      | `405`  | string  | `""`
sKeyName_FC                      | `406`  | string  | `""`
sKeyName_FD                      | `407`  | string  | `""`
sKeyName_FE                      | `408`  | string  | `""`
sKeyName_FF                      | `409`  | string  | `""`
sForwardXbox                     | `410`  | string  | `"Move Forward"`
sBackXbox                        | `411`  | string  | `"Move Backward"`
sSlideLeftXbox                   | `412`  | string  | `"Slide Left"`
sSlideRightXbox                  | `413`  | string  | `"Slide Right"`
sMenuModeXbox                    | `414`  | string  | `"Menu Mode"`
sActivateXbox                    | `415`  | string  | `"Activate"`
sUseXbox                         | `416`  | string  | `"Use"`
sReadyItemXbox                   | `417`  | string  | `"Ready Item"`
sReadyMagicXbox                  | `418`  | string  | `"Ready Magic"`
sCrouchXbox                      | `419`  | string  | `"Sneak"`
sRunXbox                         | `420`  | string  | `"Run"`
sToggleRunXbox                   | `421`  | string  | `"Toggle Run"`
sJumpXbox                        | `422`  | string  | `"Jump"`
sTogglePOVXbox                   | `423`  | string  | `"Toggle View"`
sMenuNextXbox                    | `424`  | string  | `"Next Menu"`
sMenuPrevXbox                    | `425`  | string  | `"Previous Menu"`
sJournalXbox                     | `426`  | string  | `"Journal"`
sQuick4Xbox                      | `427`  | string  | `"sQuick4Xbox"`
sQuick5Xbox                      | `428`  | string  | `"sQuick5Xbox"`
sQuick6Xbox                      | `429`  | string  | `"sQuick6Xbox"`
sQuick7Xbox                      | `430`  | string  | `"sQuick7Xbox"`
sQuick8Xbox                      | `431`  | string  | `"sQuick8Xbox"`
sQuick9Xbox                      | `432`  | string  | `"sQuick9Xbox"`
sQuick0Xbox                      | `433`  | string  | `"sQuick0Xbox"`
sOptionsMenuXbox                 | `434`  | string  | `"Options Menu"`
sSystemMenuXbox                  | `435`  | string  | `"System Menu"`
sRestMenuXbox                    | `436`  | string  | `"Rest/Wait"`
sQuickSaveXbox                   | `437`  | string  | `"Quick Save"`
sQuickLoadXbox                   | `438`  | string  | `"Quick Load"`
sMoveUpXbox                      | `439`  | string  | `"Move Up"`
sMoveDownXbox                    | `440`  | string  | `"Move Down"`
sLookUpXbox                      | `441`  | string  | `"Look Up"`
sLookDownXbox                    | `442`  | string  | `"Look Down"`
sTurnLeftXbox                    | `443`  | string  | `"Turn Left"`
sTurnRightXbox                   | `444`  | string  | `"Turn Right"`
sNextWeaponXbox                  | `445`  | string  | `"Next Weapon"`
sPrevWeaponXbox                  | `446`  | string  | `"Previous Weapon"`
sNextSpellXbox                   | `447`  | string  | `"Next Spell"`
sPrevSpellXbox                   | `448`  | string  | `"Previous Spell"`
sDialogText1Xbox                 | `449`  | string  | `"PUSH"`
sDialogText2Xbox                 | `450`  | string  | `"TO GO BACK"`
sDialogText3Xbox                 | `451`  | string  | `"TO READ MORE"`
sQuick_Save                      | `452`  | string  | `"Auto-Save when Rest"`
sShadowText                      | `453`  | string  | `"Real-time Shadows"`
sLockSuccess                     | `454`  | string  | `"Lock pick success!"`
sLockFail                        | `455`  | string  | `"Lock pick failed."`
sLockImpossible                  | `456`  | string  | `"Lock too complex."`
sTrapSuccess                     | `457`  | string  | `"Trap disarmed!"`
sTrapFail                        | `458`  | string  | `"Disarm trap failed."`
sTrapImpossible                  | `459`  | string  | `"Trap too complex, your chance to disarm it is zero"`
sTrapped                         | `460`  | string  | `"Trapped"`
sLockLevel                       | `461`  | string  | `"Lock Level"`
sKeyUsed                         | `462`  | string  | `"used to open lock"`
sUnlocked                        | `463`  | string  | `"Unlocked"`
fRepairMult                      | `464`  | float   | `1`
fRepairAmountMult                | `465`  | float   | `3`
fSpellValueMult                  | `466`  | float   | `10`
fSpellMakingValueMult            | `467`  | float   | `7`
fEnchantmentValueMult            | `468`  | float   | `1000`
fTravelMult                      | `469`  | float   | `4000`
fTravelTimeMult                  | `470`  | float   | `16000`
fMagesGuildTravel                | `471`  | float   | `10`
sBarter                          | `472`  | string  | `"Barter"`
sRepair                          | `473`  | string  | `"Repair"`
sSpells                          | `474`  | string  | `"Spells"`
sTraining                        | `475`  | string  | `"Training"`
sTravel                          | `476`  | string  | `"Travel"`
sSpellmaking                     | `477`  | string  | `"Spellmaking"`
sEnchanting                      | `478`  | string  | `"Enchanting"`
sJoystickNotFound                | `479`  | string  | `"Joystick not found."`
sJournalEntry                    | `480`  | string  | `"Your journal has been updated."`
sDay                             | `481`  | string  | `"Day"`
sCreate                          | `482`  | string  | `"Create"`
sIngredients                     | `483`  | string  | `"Ingredients"`
sApparatus                       | `484`  | string  | `"Apparatus"`
sCreatedEffects                  | `485`  | string  | `"Created Effects"`
sOnetypeEffectMessage            | `486`  | string  | `"This effect has already been added."`
sName                            | `487`  | string  | `"Name"`
sNameTitle                       | `488`  | string  | `"Name"`
sSelect                          | `489`  | string  | `"Select"`
sBuy                             | `490`  | string  | `"Buy"`
sInfo                            | `491`  | string  | `"Info"`
sMagicEffects                    | `492`  | string  | `"Magic Effects"`
sOnce                            | `493`  | string  | `"Once"`
sCostCharge                      | `494`  | string  | `"Cost/Charge"`
sCostChance                      | `495`  | string  | `"Cost/Chance"`
sAttributesMenu1                 | `496`  | string  | `"Choose an Attribute"`
sBirthsignmenu1                  | `497`  | string  | `"Abilities:"`
sBirthsignmenu2                  | `498`  | string  | `"Spells:"`
sChooseClassMenu1                | `499`  | string  | `"Specialization:"`
sChooseClassMenu2                | `500`  | string  | `"Favorite Attributes:"`
sChooseClassMenu3                | `501`  | string  | `"Major Skills:"`
sChooseClassMenu4                | `502`  | string  | `"Minor Skills:"`
sCreateClassMenuWarning          | `503`  | string  | `"Reselect your class?"`
sClassChoiceMenu1                | `504`  | string  | `"Answer his questions (Generates Class)"`
sClassChoiceMenu2                | `505`  | string  | `"Give him the info (Pick from Class List)"`
sClassChoiceMenu3                | `506`  | string  | `"Fill out forms yourself (Create Custom Class)"`
sNotifyMessage1                  | `507`  | string  | `"You can only rest on solid ground."`
sNotifyMessage2                  | `508`  | string  | `"You can't rest here enemies are nearby."`
sNotifyMessage3                  | `509`  | string  | `"You cannot sleep when dreaming."`
sNotifyMessage4                  | `510`  | string  | `"Saving..."`
sNotifyMessage4XBOX              | `511`  | string  | `"Saving. Please don't turn off your Xbox console."`
sNotifyMessage5                  | `512`  | string  | `"You must place the object you are holding into a container before exiting menus."`
sNotifyMessage6                  | `513`  | string  | `"Only one of each ingredient can be used to make a potion."`
sNotifyMessage6a                 | `514`  | string  | `"At least two ingredients are needed to make a potion."`
sNotifyMessage7                  | `515`  | string  | `"Only four ingredients can be used in a potion."`
sNotifyMessage8                  | `516`  | string  | `"Your potion failed."`
sNotifyMessage9                  | `517`  | string  | `"Your offer is refused."`
sNotifyMessage10                 | `518`  | string  | `"You have to name the spell before buying it."`
sNotifyMessage11                 | `519`  | string  | `"You have to have an item to enchant."`
sNotifyMessage12                 | `520`  | string  | `"You don't have enough gold to buy this spell."`
sNotifyMessage13                 | `521`  | string  | `"Beast races cannot wear full helmets."`
sNotifyMessage14                 | `522`  | string  | `"Beast races cannot wear boots."`
sNotifyMessage15                 | `523`  | string  | `"Beast races cannot wear shoes."`
sNotifyMessage16                 | `524`  | string  | `"You can only wear one clothing item at a time."`
sNotifyMessage16_a               | `525`  | string  | `"You can only equip one item of that type at a time."`
sNotifyMessage17                 | `526`  | string  | `"You cannot train a skill above its governing attribute."`
sNotifyMessage18                 | `527`  | string  | `"You don't have enough gold to buy this spell."`
sNotifyMessage19                 | `528`  | string  | `"Only one apparatus can be placed in each slot of the alchemy menu."`
sNotifyMessage20                 | `529`  | string  | `"Please remove the object already in the mortar and pestle slot."`
sNotifyMessage21                 | `530`  | string  | `"Please remove the object already in the alembic slot."`
sNotifyMessage22                 | `531`  | string  | `"Please remove the object already in the calcinator slot."`
sNotifyMessage23                 | `532`  | string  | `"Please remove the object already in the retort slot."`
sNotifyMessage24                 | `533`  | string  | `"You need to assign all the major and minor skill slots."`
sNotifyMessage25                 | `534`  | string  | `"You need to pick two favorite attributes."`
sNotifyMessage26                 | `535`  | string  | `"You need to pick a specialization."`
sNotifyMessage27                 | `536`  | string  | `"You need to assign all the major and minor skill slots."`
sNotifyMessage28                 | `537`  | string  | `"You can only add eight effects to a spell."`
sNotifyMessage29                 | `538`  | string  | `"You cannot add more enchantment to an object then it can hold."`
sNotifyMessage30                 | `539`  | string  | `"You have to add at least one effect to a spell."`
sNotifyMessage31                 | `540`  | string  | `"Items already enchanted cannot have another enchantment added."`
sNotifyMessage32                 | `541`  | string  | `"Only soul gems with a soul can be put in the soul gem slot."`
sNotifyMessage33                 | `542`  | string  | `"Only soul gems put in the soul gem slot."`
sNotifyMessage34                 | `543`  | string  | `"The enchantment failed and your gem is destroyed."`
sNotifyMessage35                 | `544`  | string  | `"Only one apparatus item can be equipped at a time."`
sNotifyMessage36                 | `545`  | string  | `"You have to distribute all you points before exiting."`
sNotifyMessage37                 | `546`  | string  | `"You need to type in your name."`
sNotifyMessage38                 | `547`  | string  | `"Skill Increase:"`
sNotifyMessage39                 | `548`  | string  | `"Your %s skill increased to %d."`
sNotifyMessage40                 | `549`  | string  | `"Skill Maximum Reached."`
sNotifyMessage41                 | `550`  | string  | `"Your %s skill has reached the limit of your %s."`
sNotifyMessage42                 | `551`  | string  | `"You have been released after %d day. A skill has been affected by your time in prison."`
sNotifyMessage43                 | `552`  | string  | `"You have been released after %d days. Your skills have been affected by your time in prison."`
sNotifyMessage44                 | `553`  | string  | `"Your %s skill decreased to %d."`
sNotifyMessage45                 | `554`  | string  | `"You need a Mortar and Pestle to use"`
sNotifyMessage46                 | `555`  | string  | `"You need a Alembic to use"`
sNotifyMessage47                 | `556`  | string  | `"You need a Calcinator to use"`
sNotifyMessage48                 | `557`  | string  | `"You need a Retort to use"`
sNotifyMessage49                 | `558`  | string  | `"That %s is mine."`
sNotifyMessage50                 | `559`  | string  | `"%s has no effect on you."`
sNotifyMessage51                 | `560`  | string  | `"The %s has been used up."`
sNotifyMessage52                 | `561`  | string  | `"You must have a soul gem with a soul to make an Enchanted Item"`
sNotifyMessage53                 | `562`  | string  | `"Your menu sizes and positions have been saved for exploring mode."`
sNotifyMessage54                 | `563`  | string  | `"Do you want to start a new game and lose your current game?"`
sNotifyMessage55                 | `564`  | string  | `"Please reconnect the controller and press START to continue."`
sNotifyMessage56                 | `565`  | string  | `"There's a problem with the disc you're using. It may be dirty or damaged.  Press A to continue."`
sNotifyMessage57                 | `566`  | string  | `"Please press START to begin."`
sNotifyMessage58                 | `567`  | string  | `"Your Xbox Hard Disk doesn't have enough free blocks to save games.  Press A to continue without saving  or B to free more blocks."`
sNotifyMessage59                 | `568`  | string  | `"You are over-encumbered."`
sNotifyMessage60                 | `569`  | string  | `"%s has been added to your inventory."`
sNotifyMessage61                 | `570`  | string  | `"%d %s has been added to your inventory."`
sNotifyMessage62                 | `571`  | string  | `"%s has been removed from your inventory."`
sNotifyMessage63                 | `572`  | string  | `"%d %s has been removed from your inventory."`
sNotifyMessage64                 | `573`  | string  | `"You can't sleep in someone else's bed!"`
sNotifyMessage65                 | `574`  | string  | `"You can't save a game with no name!"`
sNotifyMessage66                 | `575`  | string  | `"This will reset all controls to the default settings.  Do you wish to continue?"`
sNotifyMessage67                 | `576`  | string  | `"This will immediately change your resolution.  Do you want to continue?"`
sTeleportDisabled                | `577`  | string  | `"Teleportation magic does not work here."`
sLevitateDisabled                | `578`  | string  | `"Levitation magic does not work here."`
sInPrisonTitle                   | `579`  | string  | `"Serving time..."`
sInfoRefusal                     | `580`  | string  | `"Info Refusal"`
sAdmireSuccess                   | `581`  | string  | `"Admire Success"`
sAdmireFail                      | `582`  | string  | `"Admire Fail"`
sIntimidateSuccess               | `583`  | string  | `"Intimidate Success"`
sIntimidateFail                  | `584`  | string  | `"Intimidate Fail"`
sTauntSuccess                    | `585`  | string  | `"Taunt Success"`
sTauntFail                       | `586`  | string  | `"Taunt Fail"`
sServiceRefusal                  | `587`  | string  | `"Service Refusal"`
sBribeSuccess                    | `588`  | string  | `"Bribe Success"`
sBribeFail                       | `589`  | string  | `"Bribe Fail"`
sWerewolfRefusal                 | `590`  | string  | `"You cannot do this as a werewolf."`
sWerewolfPopup                   | `591`  | string  | `"Werewolf"`
sWerewolfRestMessage             | `592`  | string  | `"You cannot rest in werewolf form."`
sWerewolfAlarmMessage            | `593`  | string  | `"You have been detected as a known werewolf."`
sBookSkillMessage                | `594`  | string  | `"You have gained knowledge from this book."`
sLoadingMessage1                 | `595`  | string  | `"Loading Master/Plugin Files"`
sLoadingMessage2                 | `596`  | string  | `"Loading Area"`
sLoadingMessage3                 | `597`  | string  | `"Loading Area"`
sLoadingMessage4                 | `598`  | string  | `"Initializing Data..."`
sLoadingMessage5                 | `599`  | string  | `"Parsing Quests (this may take a while) Re-save when done."`
sLoadingMessage9                 | `600`  | string  | `"Clearing Data..."`
sLoadingMessage14                | `601`  | string  | `"Loading Save Game"`
sLoadingMessage15                | `602`  | string  | `"Loading (%s)"`
sInvalidSaveGameMsg              | `603`  | string  | `"This file is an invalid Save Game."`
sInvalidSaveGameMsgXBOX          | `604`  | string  | `"Unable to load saved game. Press A to continue."`
sLoadingErrorsMsg                | `605`  | string  | `"Errors were encountered loading from file '%s'."`
sMissingMastersMsg               | `606`  | string  | `"The currently selected master files and plugins do not match the ones used by this save game. Errors may occur during load or game play. Do you wish to continue?"`
sChangedMastersMsg               | `607`  | string  | `"The selected master files and plugins may have changed since this save game was created. Errors may occur during load or game play. Do you wish to continue?"`
sMastPlugMismatchMsg             | `608`  | string  | `"One of the files that "%s" is dependent on has changed since the last save.  This may result in errors. Saving again will clear this message  but not necessarily fix any errors."`
sGeneralMastPlugMismatchMsg      | `609`  | string  | `"One or more plugins could not find the correct versions of the master files they depend on. Errors may occur during load or game play. Check the "Warnings.txt" file for more information."`
sLoadLastSaveMsg                 | `610`  | string  | `"The most recent Save Game is '%s'.  Would you like to load it?"`
sMessage1                        | `611`  | string  | `"Do you want to Load a save game and lose your current game?"`
sMessage2                        | `612`  | string  | `"Quit Morrowind?"`
sMessage3                        | `613`  | string  | `"Are you sure you want to delete this Save Game?"`
sMessage4                        | `614`  | string  | `"Are you sure you want to overwrite this Save Game?"`
sMessage5                        | `615`  | string  | `"Do you wish to quit your current game?  All unsaved progress will be lost."`
sMessageQuestionAnswer1          | `616`  | string  | `"Your personality and past reflect a:"`
sMessageQuestionAnswer2          | `617`  | string  | `"Accept this Class"`
sMessageQuestionAnswer3          | `618`  | string  | `"Choose Another Class"`
sBarterDialog1                   | `619`  | string  | `"You cannot afford this transaction."`
sBarterDialog2                   | `620`  | string  | `"I cannot afford this transaction."`
sBarterDialog3                   | `621`  | string  | `"This is to heavy for you to carry."`
sBarterDialog4                   | `622`  | string  | `"I don't buy that item."`
sBarterDialog5                   | `623`  | string  | `"Thank you, Please Come Again."`
sBarterDialog6                   | `624`  | string  | `"You need to place the bartered item before existing Barter Menu!"`
sBarterDialog7                   | `625`  | string  | `"Price"`
sBarterDialog8                   | `626`  | string  | `"Offer"`
sBarterDialog9                   | `627`  | string  | `"You cannot sell summoned items!"`
sBarterDialog10                  | `628`  | string  | `"You cannot buy summoned items!"`
sBarterDialog11                  | `629`  | string  | `"You need to trade items before making an offer."`
sBarterDialog12                  | `630`  | string  | `"You cannot drop summoned items!"`
sInventoryMessage1               | `631`  | string  | `"This object is broken and cannot be equipped until fixed."`
sInventoryMessage2               | `632`  | string  | `"You cannot repair items during battle."`
sInventoryMessage3               | `633`  | string  | `"You cannot make potions during battle."`
sInventoryMessage4               | `634`  | string  | `"You cannot read during battle."`
sInventoryMessage5               | `635`  | string  | `"You cannot use soul gems during battle."`
sContentsMessage1                | `636`  | string  | `"You cannot remove summoned items from their container."`
sContentsMessage2                | `637`  | string  | `"You cannot place items in this container."`
sContentsMessage3                | `638`  | string  | `"The item will not fit."`
sAttributeListTitle              | `639`  | string  | `"Attribute List"`
sConsoleTitle                    | `640`  | string  | `"Console"`
sCreateClassMenu1                | `641`  | string  | `"Class Description"`
sCreateClassMenu2                | `642`  | string  | `"Close the Description menu before leaving Class Creation"`
sCreateClassMenu3                | `643`  | string  | `"The class needs a description."`
sCreateClassMenuHelp1            | `644`  | string  | `"You'll get +5 to all skills of your specialization. They'll also be easier to increase."`
sCreateClassMenuHelp2            | `645`  | string  | `"You'll get +10 to each of your favored attributes."`
sControlsMenu1                   | `646`  | string  | `"Reset Controls"`
sControlsMenu2                   | `647`  | string  | `"Mouse Sensitivity"`
sControlsMenu3                   | `648`  | string  | `"Press a key or push a button to set this command."`
sControlsMenu4                   | `649`  | string  | `"Vertical Sensitivity"`
sControlsMenu5                   | `650`  | string  | `"Horizontal Sensitivity"`
sControlsMenu6                   | `651`  | string  | `"Push a button to set this command."`
sGameWithoutLauncherXbox         | `652`  | string  | `"The game was started without the launcher.  Press START to continue."`
sDialogMenu1                     | `653`  | string  | `"Final Disposition:"`
sEnchantmentMenu1                | `654`  | string  | `"Enchantment Menu"`
sEnchantmentMenu2                | `655`  | string  | `"Enchantment Name"`
sEnchantmentMenu3                | `656`  | string  | `"Enchantment"`
sEnchantmentMenu4                | `657`  | string  | `"Point Cost"`
sEnchantmentMenu5                | `658`  | string  | `"Buy"`
sEnchantmentMenu6                | `659`  | string  | `"Chance"`
sEnchantmentMenu7                | `660`  | string  | `"Please remove the current soul gem before placing a different soul gem."`
sEnchantmentMenu8                | `661`  | string  | `"You cannot buy a spell that has a zero point cost."`
sEnchantmentMenu9                | `662`  | string  | `"You cannot enchant more then one item of that type at a time."`
sEnchantmentMenu10               | `663`  | string  | `"The cast cost cannot exceed the charge amount put into the time"`
sEnchantmentMenu11               | `664`  | string  | `"You must add at least one effect to an enchantment"`
sEnchantmentMenu12               | `665`  | string  | `"You have successfully created an enchanted item"`
sEnchantmentHelp1                | `666`  | string  | `"Slot for item to enchant. Only weapons, armor, scrolls and clothing that are not already enchanted can be enchanted."`
sEnchantmentHelp2                | `667`  | string  | `"Slot for the soul gem used to enchant an item. Only soul gems filled with a soul can be used. The soul amount is the total charge placed into the item."`
sEnchantmentHelp3                | `668`  | string  | `"The first number is the total amount the enchantment would cost to cast. The second number is the total enchantment cost that can be placed on this type of item."`
sEnchantmentHelp4                | `669`  | string  | `"The amount of charge points needed each time this enchantment is cast. This number is modified by your enchant skill."`
sEnchantmentHelp5                | `670`  | string  | `"The amount of soul in the soul gem in the soul gem slot"`
sEnchantmentHelp6                | `671`  | string  | `"Amount of gold to buy this enchantment"`
sEnchantmentHelp7                | `672`  | string  | `"Type of cast for the enchantment."`
sEnchantmentHelp8                | `673`  | string  | `"Name you give the spell."`
sEnchantmentHelp9                | `674`  | string  | `"Magic effects you know that you can add to an item"`
sEnchantmentHelp10               | `675`  | string  | `"Current effects on the item"`
sInputMenu1                      | `676`  | string  | `"Enter"`
sInventoryMenu1                  | `677`  | string  | `"You cannot equip items being bartered."`
sLevelUpMenu1                    | `678`  | string  | `"You have ascended to Level"`
sLevelUpMenu2                    | `679`  | string  | `"It's all suddenly obvious to you. You just have to concentrate. All the energy and time you've wasted is a sin, but without the experience you've gained, taking risks, taking responsibility for failure how could you have understood?"`
sLevelUpMenu3                    | `680`  | string  | `"x2"`
sLevelUpMenu4                    | `681`  | string  | `"x3"`
sLevelUpMsg                      | `682`  | string  | `"You should rest and meditate on what you've learned."`
sLevelUp                         | `683`  | string  | `"Level Up"`
sRange                           | `684`  | string  | `"Range"`
sArea                            | `685`  | string  | `"Area"`
sMagnitude                       | `686`  | string  | `"Magnitude"`
sDuration                        | `687`  | string  | `"Duration"`
sDrain                           | `688`  | string  | `"Drain"`
sAbsorb                          | `689`  | string  | `"Absorb"`
sFortify                         | `690`  | string  | `"Fortify"`
sRestore                         | `691`  | string  | `"Restore"`
sDamage                          | `692`  | string  | `"Damage"`
spoint                           | `693`  | string  | `"pt"`
spoints                          | `694`  | string  | `"pts"`
spercent                         | `695`  | string  | `"%"`
sfor                             | `696`  | string  | `"for"`
ssecond                          | `697`  | string  | `"sec"`
sseconds                         | `698`  | string  | `"secs"`
sin                              | `699`  | string  | `"in"`
sfootarea                        | `700`  | string  | `"ft"`
sfeet                            | `701`  | string  | `"ft"`
sXTimes                          | `702`  | string  | `"x"`
sXTimesINT                       | `703`  | string  | `"x INT"`
sonword                          | `704`  | string  | `"on"`
sNone                            | `705`  | string  | `"None"`
sDone                            | `706`  | string  | `"Done"`
sStartCell                       | `707`  | string  | `"Cavern of the Incarnate"`
sStartError                      | `708`  | string  | `"Cannot start in an empty interior cell!"`
sStartCellError                  | `709`  | string  | `"Starting interior cell "Cavern of the Incarnate" not found!"`
sAdmire                          | `710`  | string  | `"Admire"`
sIntimidate                      | `711`  | string  | `"Intimidate"`
sTaunt                           | `712`  | string  | `"Taunt"`
sBribe 10 Gold                   | `713`  | string  | `"Bribe 10 Gold"`
sBribe10Gold                     | `713`  | string  | `"Bribe 10 Gold"`
sBribe100Gold                    | `714`  | string  | `"Bribe 100 Gold"`
sBribe 100 Gold                  | `714`  | string  | `"Bribe 100 Gold"`
sBribe1000Gold                   | `715`  | string  | `"Bribe 1000 Gold"`
sBribe 1000 Gold                 | `715`  | string  | `"Bribe 1000 Gold"`
sPersuasionMenuTitle             | `716`  | string  | `"Persuasion"`
sFast                            | `717`  | string  | `"Fast"`
sSlow                            | `718`  | string  | `"Slow"`
sBestAttack                      | `719`  | string  | `"Always Use Best Attack"`
sSubtitles                       | `720`  | string  | `"Subtitles"`
sMouseFlip                       | `721`  | string  | `"Invert Y Axis"`
sCursorOff                       | `722`  | string  | `"Crosshair"`
sEnableJoystick                  | `723`  | string  | `"Enable Joystick"`
sXStrafe                         | `724`  | string  | `"X-Axis Movement"`
sStrafe                          | `725`  | string  | `"Strafe"`
sTurn                            | `726`  | string  | `"Turn"`
sMouseWheelUpShort               | `727`  | string  | `"MWheel Up"`
sMouseWheelDownShort             | `728`  | string  | `"MWheel Down"`
sMouse                           | `729`  | string  | `"Mouse"`
sJoystickShort                   | `730`  | string  | `"Joy"`
sJoystickHatShort                | `731`  | string  | `"JHat"`
sPickUp                          | `732`  | string  | `"Take"`
sItemName                        | `733`  | string  | `"Item Name"`
sNoName                          | `734`  | string  | `"NO NAME GIVEN!"`
sItem                            | `735`  | string  | `"Item"`
sRaceMenu1                       | `736`  | string  | `"Appearance"`
sRaceMenu2                       | `737`  | string  | `"Change Sex"`
sRaceMenu3                       | `738`  | string  | `"Change Face"`
sRaceMenu4                       | `739`  | string  | `"Change Hair"`
sRaceMenu5                       | `740`  | string  | `"Race"`
sRaceMenu6                       | `741`  | string  | `"Race Description"`
sRaceMenu7                       | `742`  | string  | `"Specials"`
sRestMenu1                       | `743`  | string  | `"How many hours?"`
sRestMenu2                       | `744`  | string  | `"Hours"`
sRestMenu3                       | `745`  | string  | `"REST"`
sRestMenu4                       | `746`  | string  | `"You can't rest right now."`
fRestMagicMult                   | `747`  | float   | `0.15`
sSaveMenu1                       | `748`  | string  | `"New Save Game"`
sServiceRepairTitle              | `749`  | string  | `"Repair Service Menu"`
sServiceTravelTitle              | `750`  | string  | `"Travel"`
sServiceTrainingTitle            | `751`  | string  | `"Training"`
sServiceTrainingWords            | `752`  | string  | `"I can teach nothing more about that skill"`
sServiceSpellsTitle              | `753`  | string  | `"Spells"`
sSkillsMenu1                     | `754`  | string  | `"Choose a Skill"`
sBonusSkillTitle                 | `755`  | string  | `"Skill Bonus"`
sSpecializationMenu1             | `756`  | string  | `"Choose a Specialization"`
sSpellmakingMenuTitle            | `757`  | string  | `"Spellmaking"`
sSpellmakingMenu1                | `758`  | string  | `"Spell Chance"`
sSpellmakingHelp1                | `759`  | string  | `"Name you give the spell."`
sSpellmakingHelp2                | `760`  | string  | `"Amount of Magika one cast of the spell will cost"`
sSpellmakingHelp3                | `761`  | string  | `"The chance you have to cast the spell at your current skill level"`
sSpellmakingHelp4                | `762`  | string  | `"How much gold the spell will cost you."`
sSpellmakingHelp5                | `763`  | string  | `"Magic effects you know that you can add to a spell"`
sSpellmakingHelp6                | `764`  | string  | `"Current effects on the spell"`
sKilledEssential                 | `765`  | string  | `"With this character's death, the thread of prophecy is severed. Restore a saved game to restore the weave of fate, or persist in the doomed world you have created."`
sCrimeMessage                    | `766`  | string  | `"Your crime has been reported!"`
sPotionSuccess                   | `767`  | string  | `"You created a potion"`
sMagicItem                       | `768`  | string  | `"Magic Items"`
sMagnitudeDes                    | `769`  | string  | `"The range of a spells power"`
sAreaDes                         | `770`  | string  | `"The radius the spell attempt to affect"`
sDurationDes                     | `771`  | string  | `"The length a spell lasts"`
sRangeDes                        | `772`  | string  | `"What the spell is directed at such as yourself, a target or who you touch"`
sCrimeHelp                       | `773`  | string  | `"The penalty you must pay for your crimes, if caught."`
sSoulGem                         | `774`  | string  | `"Soul"`
sCastCost                        | `775`  | string  | `"Cast Cost"`
sTravelServiceTitle              | `776`  | string  | `"Select destination"`
sSpellServiceTitle               | `777`  | string  | `"Select spell to buy"`
sRepairServiceTitle              | `778`  | string  | `"Select item to repair"`
sTrainingServiceTitle            | `779`  | string  | `"Select skill to train"`
sMortar                          | `780`  | string  | `"Mortar"`
sCalcinator                      | `781`  | string  | `"Calcinator"`
sAlembic                         | `782`  | string  | `"Alembic"`
sRetort                          | `783`  | string  | `"Retort"`
sQuestionMark                    | `784`  | string  | `"?"`
s3dAudio                         | `785`  | string  | `"3D Audio"`
s3dHardware                      | `786`  | string  | `"Hardware Accelerated"`
s3dSoftware                      | `787`  | string  | `"Software Mode"`
sYourGold                        | `788`  | string  | `"YOUR GOLD"`
sSellerGold                      | `789`  | string  | `"SELLER GOLD"`
sMaxSale                         | `790`  | string  | `"Max Sale"`
sTotalCost                       | `791`  | string  | `"TOTAL COST"`
sTotalSold                       | `792`  | string  | `"TOTAL SOLD"`
sOffer                           | `793`  | string  | `"Offer"`
sLess                            | `794`  | string  | `"Less"`
sMore                            | `795`  | string  | `"More"`
sInventory                       | `796`  | string  | `"Inventory"`
sBookPageOne                     | `797`  | string  | `"1"`
sBookPageTwo                     | `798`  | string  | `"2"`
sDisposeofCorpse                 | `799`  | string  | `"Dispose of Corpse"`
sCaughtStealingMessage           | `800`  | string  | `"Hey he's stealing my stuff!"`
sUserDefinedClass                | `801`  | string  | `"User Defined Class"`
sAsk                             | `802`  | string  | `"Ask"`
sEnchantItems                    | `803`  | string  | `"Items to Enchant"`
sSoulGemsWithSouls               | `804`  | string  | `"Soul Gems with Souls"`
sDoYouWantTo                     | `805`  | string  | `"Do you want to"`
sRechargeEnchantment             | `806`  | string  | `"Recharge Enchanted Item"`
sMake                            | `807`  | string  | `"Make an Enchanted Item"`
sSell                            | `808`  | string  | `"Sell"`
sEquip                           | `809`  | string  | `"Equip"`
sDrop                            | `810`  | string  | `"Drop"`
sContainer                       | `811`  | string  | `"Container"`
sStats                           | `812`  | string  | `"Stats"`
sMap                             | `813`  | string  | `"Map"`
sCenter                          | `814`  | string  | `"Center"`
sSaveMenuHelp01                  | `815`  | string  | `"th of"`
sSaveMenuHelp02                  | `816`  | string  | `"month"`
sSaveMenuHelp03                  | `817`  | string  | `"day"`
sSaveMenuHelp04                  | `818`  | string  | `"a.m."`
sSaveMenuHelp05                  | `819`  | string  | `"p.m."`
sSaveMenuHelp06                  | `820`  | string  | `"Delete Game?"`
sDeleteNote                      | `821`  | string  | `"Delete Note?"`
sEditNote                        | `822`  | string  | `"Edit Note"`
sBlocks                          | `823`  | string  | `"Blocks"`
sFileSize                        | `824`  | string  | `"File Size"`
sSave                            | `825`  | string  | `"Save"`
sDeleteSpell                     | `826`  | string  | `"Delete Spell"`
sQuestionDeleteSpell             | `827`  | string  | `"Are you sure you wish to delete %s?"`
sDeleteSpellError                | `828`  | string  | `"You cannot delete this item from the Magic Menu"`
sLocal                           | `829`  | string  | `"Local"`
sLoadFailedMessage               | `830`  | string  | `"Your last load failed. You must load another game or start a new game."`
sShadows                         | `831`  | string  | `"Shadows"`
sControlerVibration              | `832`  | string  | `"Controller Vibration"`
sQuanityMenuMessage01            | `833`  | string  | `"Amount to Sell"`
sQuanityMenuMessage02            | `834`  | string  | `"Amount to Buy"`
sSex                             | `835`  | string  | `"Sex"`
sHair                            | `836`  | string  | `"Hair"`
sFace                            | `837`  | string  | `"Face"`
sRepairFailed                    | `838`  | string  | `"Your repair failed!"`
sRepairSuccess                   | `839`  | string  | `"Your repair succeeded!"`
sHeal                            | `840`  | string  | `"Heal"`
sgp                              | `841`  | string  | `"gp"`
sSetValueMessage01               | `842`  | string  | `"The maximum magnitude cannot be less then the minimum magnitude!"`
sDelete                          | `843`  | string  | `"Delete"`
sVideoWarning                    | `844`  | string  | `"Warning: Video Resolution does not allow shadows."`
sResChangeWarning                | `845`  | string  | `"Desired resolution not supported by video card."`
sShift                           | `846`  | string  | `"Shift"`
sBackspace                       | `847`  | string  | `"Backspace"`
sCustomClassName                 | `848`  | string  | `"Adventurer"`
sSpace                           | `849`  | string  | `"Space"`
sInventorySelectNoItems          | `850`  | string  | `"You have no items to fill this slot."`
sInventorySelectNoSoul           | `851`  | string  | `"You have no filled Soul Gems"`
sInventorySelectNoIngredients    | `852`  | string  | `"You have no ingredients"`
sDisposeCorpseFail               | `853`  | string  | `"You can not remove this corpse"`
sQuickMenuTitle                  | `854`  | string  | `"Quick Keys"`
sQuickMenuInstruc                | `855`  | string  | `"Click on quick key slot to add a spell, magic item or inventory item"`
sQuickMenu1                      | `856`  | string  | `"Item to QuickKey"`
sQuickMenu2                      | `857`  | string  | `"Inventory Menu Item"`
sQuickMenu3                      | `858`  | string  | `"Magic Menu Item"`
sQuickMenu4                      | `859`  | string  | `"Delete QuickKey Item"`
sQuickMenu5                      | `860`  | string  | `"You no longer have"`
sQuickMenu6                      | `861`  | string  | `"Inventory Items to Quick key"`
sMagicSelectTitle                | `862`  | string  | `"Select a magic to Quick key."`
sNextRank                        | `863`  | string  | `"Next Rank:"`
sNeedOneSkill                    | `864`  | string  | `"Need one skill at"`
sNeedTwoSkills                   | `865`  | string  | `"Need two skills at"`
sand                             | `866`  | string  | `"and"`
sOneHanded                       | `867`  | string  | `"One Handed"`
sTwoHanded                       | `868`  | string  | `"Two Handed"`
sType                            | `869`  | string  | `"Type:"`
sAt                              | `870`  | string  | `"At"`
sUnequip                         | `871`  | string  | `"Unequip"`
sScrolldown                      | `872`  | string  | `"Scroll Down"`
sScrollup                        | `873`  | string  | `"Scroll Up"`
sSleepInterrupt                  | `874`  | string  | `"Your rest has been interrupted."`
sSoultrapSuccess                 | `875`  | string  | `"Your have trapped a soul"`
sCantEquipWeapWarning            | `876`  | string  | `"Finish your current attack before equipping a new weapon"`
sOfferMenuTitle                  | `877`  | string  | `"Offer Menu"`
sPowers                          | `878`  | string  | `"Powers"`
sBreath                          | `879`  | string  | `"Breath"`
sDifficulty                      | `880`  | string  | `"Difficulty"`
sEasy                            | `881`  | string  | `"Easy"`
sHard                            | `882`  | string  | `"Hard"`
sProfitValue                     | `883`  | string  | `"Profit Value"`
sCompanionShare                  | `884`  | string  | `"Companion Share"`
sCompanionWarningMessage         | `885`  | string  | `"Your mercenary is poorer now than when he contracted with you.  Your mercenary will quit if you do not give him gold or goods to bring his Profit Value to a positive value."`
sCompanionWarningButtonOne       | `886`  | string  | `"Let the mercenary quit."`
sCompanionWarningButtonTwo       | `887`  | string  | `"Return to Companion Share display."`
sAttributeStrength               | `888`  | string  | `"Strength"`
sAttributeIntelligence           | `889`  | string  | `"Intelligence"`
sAttributeWillpower              | `890`  | string  | `"Willpower"`
sAttributeAgility                | `891`  | string  | `"Agility"`
sAttributeSpeed                  | `892`  | string  | `"Speed"`
sAttributeEndurance              | `893`  | string  | `"Endurance"`
sAttributePersonality            | `894`  | string  | `"Personality"`
sAttributeLuck                   | `895`  | string  | `"Luck"`
sSkillBlock                      | `896`  | string  | `"Block"`
sSkillArmorer                    | `897`  | string  | `"Armorer"`
sSkillMediumarmor                | `898`  | string  | `"Medium Armor"`
sSkillHeavyarmor                 | `899`  | string  | `"Heavy Armor"`
sSkillBluntweapon                | `900`  | string  | `"Blunt Weapon"`
sSkillLongblade                  | `901`  | string  | `"Long Blade"`
sSkillAxe                        | `902`  | string  | `"Axe"`
sSkillSpear                      | `903`  | string  | `"Spear"`
sSkillAthletics                  | `904`  | string  | `"Athletics"`
sSkillEnchant                    | `905`  | string  | `"Enchant"`
sSkillDestruction                | `906`  | string  | `"Destruction"`
sSkillAlteration                 | `907`  | string  | `"Alteration"`
sSkillIllusion                   | `908`  | string  | `"Illusion"`
sSkillConjuration                | `909`  | string  | `"Conjuration"`
sSkillMysticism                  | `910`  | string  | `"Mysticism"`
sSkillRestoration                | `911`  | string  | `"Restoration"`
sSkillAlchemy                    | `912`  | string  | `"Alchemy"`
sSkillUnarmored                  | `913`  | string  | `"Unarmored"`
sSkillSecurity                   | `914`  | string  | `"Security"`
sSkillSneak                      | `915`  | string  | `"Sneak"`
sSkillAcrobatics                 | `916`  | string  | `"Acrobatics"`
sSkillLightarmor                 | `917`  | string  | `"Light Armor"`
sSkillShortblade                 | `918`  | string  | `"Short Blade"`
sSkillMarksman                   | `919`  | string  | `"Marksman"`
sSkillMercantile                 | `920`  | string  | `"Mercantile"`
sSkillSpeechcraft                | `921`  | string  | `"Speechcraft"`
sSkillHandtohand                 | `922`  | string  | `"Hand-to-hand"`
sHealth                          | `923`  | string  | `"Health"`
sRace                            | `924`  | string  | `"Race"`
sLevel                           | `925`  | string  | `"Level"`
sLevels                          | `926`  | string  | `"Levels"`
sFaction                         | `927`  | string  | `"Faction"`
sBirthSign                       | `928`  | string  | `"Sign"`
sBounty                          | `929`  | string  | `"Bounty"`
sReputation                      | `930`  | string  | `"Reputation"`
sSchool                          | `931`  | string  | `"School"`
sSkill                           | `932`  | string  | `"Skill"`
sSkillProgress                   | `933`  | string  | `"Progress towards skill increase"`
sSkillMaxReached                 | `934`  | string  | `"Maximum proficiency has been reached."`
sLevelProgress                   | `935`  | string  | `"Progress towards level increase"`
sMagic                           | `936`  | string  | `"Magicka"`
sMagicMenu                       | `937`  | string  | `"Magic"`
sFatigue                         | `938`  | string  | `"Fatigue"`
sSkillsMenuReputationHelp        | `939`  | string  | `"Your fame rating in the world of Morrowind."`
sStrDesc                         | `940`  | string  | `"Affects your starting Health, how much you can carry, your maximum Fatigue, and how much damage you do in melee."`
sIntDesc                         | `941`  | string  | `"Determines your maximum amount of Magicka."`
sWilDesc                         | `942`  | string  | `"Affects your ability to resist magic, and your maximum Fatigue."`
sAgiDesc                         | `943`  | string  | `"Affects your ability to dodge and hit targets in melee as well as your maximum Fatigue."`
sSpdDesc                         | `944`  | string  | `"Determines how fast you can move."`
sEndDesc                         | `945`  | string  | `"Affects your starting Health, your Health gain per level, and your maximum Fatigue."`
sPerDesc                         | `946`  | string  | `"Affects your ability to deal with other characters and how much they like you."`
sLucDesc                         | `947`  | string  | `"Affects every action you do in a small way."`
sFatDesc                         | `948`  | string  | `"How tired you are. Low fatigue makes it harder to successfully perform actions."`
sHealthDesc                      | `949`  | string  | `"The amount of damage you can take before you die. Increases every time you gain a level."`
sMagDesc                         | `950`  | string  | `"Used to cast spells. Magicka is naturally restored by resting."`
fWortChanceValue                 | `951`  | float   | `15`
sDefaultCellname                 | `952`  | string  | `"Wilderness"`
fMinWalkSpeed                    | `953`  | float   | `100`
fMaxWalkSpeed                    | `954`  | float   | `200`
fMinWalkSpeedCreature            | `955`  | float   | `5`
fMaxWalkSpeedCreature            | `956`  | float   | `300`
fEncumberedMoveEffect            | `957`  | float   | `0.3`
fBaseRunMultiplier               | `958`  | float   | `1.75`
fAthleticsRunBonus               | `959`  | float   | `1`
fJumpAcrobaticsBase              | `960`  | float   | `128`
fJumpAcroMultiplier              | `961`  | float   | `4`
fJumpEncumbranceBase             | `962`  | float   | `0.5`
fJumpEncumbranceMultiplier       | `963`  | float   | `1`
fJumpRunMultiplier               | `964`  | float   | `1`
fJumpMoveBase                    | `965`  | float   | `0.5`
fJumpMoveMult                    | `966`  | float   | `0.5`
fSwimWalkBase                    | `967`  | float   | `0.5`
fSwimRunBase                     | `968`  | float   | `0.5`
fSwimWalkAthleticsMult           | `969`  | float   | `0.02`
fSwimRunAthleticsMult            | `970`  | float   | `0.1`
fSwimHeightScale                 | `971`  | float   | `0.9`
fHoldBreathTime                  | `972`  | float   | `20`
fHoldBreathEndMult               | `973`  | float   | `0.5`
fSuffocationDamage               | `974`  | float   | `3`
fMinFlySpeed                     | `975`  | float   | `5`
fMaxFlySpeed                     | `976`  | float   | `300`
fStromWindSpeed                  | `977`  | float   | `0.7`
fStromWalkMult                   | `978`  | float   | `0.25`
fFallDamageDistanceMin           | `979`  | float   | `400`
fFallDistanceBase                | `980`  | float   | `0`
fFallDistanceMult                | `981`  | float   | `0.07`
fFallAcroBase                    | `982`  | float   | `0.25`
fFallAcroMult                    | `983`  | float   | `0.01`
iMaxActivateDist                 | `984`  | integer | `192`
iMaxInfoDist                     | `985`  | integer | `192`
fVanityDelay                     | `986`  | float   | `30`
fMaxHeadTrackDistance            | `987`  | float   | `400`
fInteriorHeadTrackMult           | `988`  | float   | `0.5`
iHelmWeight                      | `989`  | integer | `5`
iPauldronWeight                  | `990`  | integer | `10`
iCuirassWeight                   | `991`  | integer | `30`
iGauntletWeight                  | `992`  | integer | `5`
iGreavesWeight                   | `993`  | integer | `15`
iBootsWeight                     | `994`  | integer | `20`
iShieldWeight                    | `995`  | integer | `15`
fLightMaxMod                     | `996`  | float   | `0.6`
fMedMaxMod                       | `997`  | float   | `0.9`
fUnarmoredBase1                  | `998`  | float   | `0.1`
fUnarmoredBase2                  | `999`  | float   | `0.065`
iBaseArmorSkill                  | `1000` | integer | `30`
fBlockStillBonus                 | `1001` | float   | `1.25`
fDamageStrengthBase              | `1002` | float   | `0.5`
fDamageStrengthMult              | `1003` | float   | `0.1`
fSwingBlockBase                  | `1004` | float   | `1`
fSwingBlockMult                  | `1005` | float   | `1`
fFatigueBase                     | `1006` | float   | `1.25`
fFatigueMult                     | `1007` | float   | `0.5`
fFatigueReturnBase               | `1008` | float   | `2.5`
fFatigueReturnMult               | `1009` | float   | `0.02`
fEndFatigueMult                  | `1010` | float   | `0.04`
fFatigueAttackBase               | `1011` | float   | `2`
fFatigueAttackMult               | `1012` | float   | `0`
fWeaponFatigueMult               | `1013` | float   | `0.25`
fFatigueBlockBase                | `1014` | float   | `4`
fFatigueBlockMult                | `1015` | float   | `0`
fWeaponFatigueBlockMult          | `1016` | float   | `1`
fFatigueRunBase                  | `1017` | float   | `5`
fFatigueRunMult                  | `1018` | float   | `2`
fFatigueJumpBase                 | `1019` | float   | `5`
fFatigueJumpMult                 | `1020` | float   | `0`
fFatigueSwimWalkBase             | `1021` | float   | `2.5`
fFatigueSwimRunBase              | `1022` | float   | `7`
fFatigueSwimWalkMult             | `1023` | float   | `0`
fFatigueSwimRunMult              | `1024` | float   | `0`
fFatigueSneakBase                | `1025` | float   | `1.5`
fFatigueSneakMult                | `1026` | float   | `1.5`
fMinHandToHandMult               | `1027` | float   | `0.1`
fMaxHandToHandMult               | `1028` | float   | `0.5`
fHandtoHandHealthPer             | `1029` | float   | `0.1`
fCombatInvisoMult                | `1030` | float   | `0.2`
fCombatKODamageMult              | `1031` | float   | `1.5`
fCombatCriticalStrikeMult        | `1032` | float   | `4`
iBlockMinChance                  | `1033` | integer | `10`
iBlockMaxChance                  | `1034` | integer | `50`
fLevelUpHealthEndMult            | `1035` | float   | `0.1`
fSoulGemMult                     | `1036` | float   | `3`
fEffectCostMult                  | `1037` | float   | `0.5`
fSpellPriceMult                  | `1038` | float   | `2`
fFatigueSpellBase                | `1039` | float   | `0`
fFatigueSpellMult                | `1040` | float   | `0`
fFatigueSpellCostMult            | `1041` | float   | `0`
fPotionStrengthMult              | `1042` | float   | `0.5`
fPotionT1MagMult                 | `1043` | float   | `1.5`
fPotionT1DurMult                 | `1044` | float   | `0.5`
fPotionMinUsefulDuration         | `1045` | float   | `20`
fPotionT4BaseStrengthMult        | `1046` | float   | `20`
fPotionT4EquipStrengthMult       | `1047` | float   | `12`
fIngredientMult                  | `1048` | float   | `1`
fMagicItemCostMult               | `1049` | float   | `1`
fMagicItemPriceMult              | `1050` | float   | `1`
fMagicItemOnceMult               | `1051` | float   | `1`
fMagicItemUsedMult               | `1052` | float   | `1`
fMagicItemStrikeMult             | `1053` | float   | `1`
fMagicItemConstantMult           | `1054` | float   | `1`
fEnchantmentMult                 | `1055` | float   | `0.1`
fEnchantmentChanceMult           | `1056` | float   | `3`
fPCbaseMagickaMult               | `1057` | float   | `1`
fNPCbaseMagickaMult              | `1058` | float   | `2`
fAutoSpellChance                 | `1059` | float   | `80`
fAutoPCSpellChance               | `1060` | float   | `50`
iAutoSpellTimesCanCast           | `1061` | integer | `3`
iAutoSpellAttSkillMin            | `1062` | integer | `70`
iAutoSpellAlterationMax          | `1063` | integer | `5`
iAutoSpellConjurationMax         | `1064` | integer | `2`
iAutoSpellDestructionMax         | `1065` | integer | `5`
iAutoSpellIllusionMax            | `1066` | integer | `5`
iAutoSpellMysticismMax           | `1067` | integer | `5`
iAutoSpellRestorationMax         | `1068` | integer | `5`
iAutoPCSpellMax                  | `1069` | integer | `100`
iAutoRepFacMod                   | `1070` | integer | `2`
iAutoRepLevMod                   | `1071` | integer | `0`
iMagicItemChargeOnce             | `1072` | integer | `1`
iMagicItemChargeConst            | `1073` | integer | `10`
iMagicItemChargeUse              | `1074` | integer | `5`
iMagicItemChargeStrike           | `1075` | integer | `10`
iMonthsToRespawn                 | `1076` | integer | `4`
fCorpseClearDelay                | `1077` | float   | `72`
fCorpseRespawnDelay              | `1078` | float   | `72`
fBarterGoldResetDelay            | `1079` | float   | `24`
fEncumbranceStrMult              | `1080` | float   | `5`
fPickLockMult                    | `1081` | float   | `-1`
fTrapCostMult                    | `1082` | float   | `0`
fMessageTimePerChar              | `1083` | float   | `0.1`
fMagicItemRechargePerSecond      | `1084` | float   | `0.05`
i1stPersonSneakDelta             | `1085` | integer | `10`
iBarterSuccessDisposition        | `1086` | integer | `1`
iBarterFailDisposition           | `1087` | integer | `-1`
iLevelupTotal                    | `1088` | integer | `10`
iLevelupMajorMult                | `1089` | integer | `1`
iLevelupMinorMult                | `1090` | integer | `1`
iLevelupMajorMultAttribute       | `1091` | integer | `1`
iLevelupMinorMultAttribute       | `1092` | integer | `1`
iLevelupMiscMultAttriubte        | `1093` | integer | `1`
iLevelupSpecialization           | `1094` | integer | `1`
iLevelUp01Mult                   | `1095` | integer | `2`
iLevelUp02Mult                   | `1096` | integer | `2`
iLevelUp03Mult                   | `1097` | integer | `2`
iLevelUp04Mult                   | `1098` | integer | `2`
iLevelUp05Mult                   | `1099` | integer | `3`
iLevelUp06Mult                   | `1100` | integer | `3`
iLevelUp07Mult                   | `1101` | integer | `3`
iLevelUp08Mult                   | `1102` | integer | `4`
iLevelUp09Mult                   | `1103` | integer | `4`
iLevelUp10Mult                   | `1104` | integer | `5`
iSoulAmountForConstantEffect     | `1105` | integer | `400`
fConstantEffectMult              | `1106` | float   | `15`
fEnchantmentConstantDurationMult | `1107` | float   | `100`
fEnchantmentConstantChanceMult   | `1108` | float   | `0.5`
fWeaponDamageMult                | `1109` | float   | `0.1`
fSeriousWoundMult                | `1110` | float   | `0`
fKnockDownMult                   | `1111` | float   | `0.5`
iKnockDownOddsBase               | `1112` | integer | `50`
iKnockDownOddsMult               | `1113` | integer | `50`
fCombatArmorMinMult              | `1114` | float   | `0.25`
fHandToHandReach                 | `1115` | float   | `1`
fVoiceIdleOdds                   | `1116` | float   | `10`
iVoiceAttackOdds                 | `1117` | integer | `10`
iVoiceHitOdds                    | `1118` | integer | `30`
fProjectileMinSpeed              | `1119` | float   | `400`
fProjectileMaxSpeed              | `1120` | float   | `3000`
fThrownWeaponMinSpeed            | `1121` | float   | `300`
fThrownWeaponMaxSpeed            | `1122` | float   | `1000`
fTargetSpellMaxSpeed             | `1123` | float   | `1000`
fProjectileThrownStoreChance     | `1124` | float   | `25`
iPickMinChance                   | `1125` | integer | `5`
iPickMaxChance                   | `1126` | integer | `75`
fDispRaceMod                     | `1127` | float   | `5`
fDispPersonalityMult             | `1128` | float   | `0.5`
fDispPersonalityBase             | `1129` | float   | `50`
fDispFactionMod                  | `1130` | float   | `3`
fDispFactionRankBase             | `1131` | float   | `1`
fDispFactionRankMult             | `1132` | float   | `0.5`
fDispCrimeMod                    | `1133` | float   | `0`
fDispDiseaseMod                  | `1134` | float   | `-10`
iDispAttackMod                   | `1135` | integer | `-50`
fDispWeaponDrawn                 | `1136` | float   | `-5`
fDispBargainSuccessMod           | `1137` | float   | `1`
fDispBargainFailMod              | `1138` | float   | `-1`
fDispPickPocketMod               | `1139` | float   | `-25`
iDaysinPrisonMod                 | `1140` | integer | `100`
fDispAttacking                   | `1141` | float   | `-10`
fDispStealing                    | `1142` | float   | `-0.5`
iDispTresspass                   | `1143` | integer | `-20`
iDispKilling                     | `1144` | integer | `-50`
iTrainingMod                     | `1145` | integer | `10`
iAlchemyMod                      | `1146` | integer | `2`
fBargainOfferBase                | `1147` | float   | `50`
fBargainOfferMulti               | `1148` | float   | `-4`
fDispositionMod                  | `1149` | float   | `1`
fPersonalityMod                  | `1150` | float   | `5`
fLuckMod                         | `1151` | float   | `10`
fReputationMod                   | `1152` | float   | `1`
fLevelMod                        | `1153` | float   | `5`
fBribe10Mod                      | `1154` | float   | `35`
fBribe100Mod                     | `1155` | float   | `75`
fBribe1000Mod                    | `1156` | float   | `150`
fPerDieRollMult                  | `1157` | float   | `0.3`
fPerTempMult                     | `1158` | float   | `1`
iPerMinChance                    | `1159` | integer | `5`
iPerMinChange                    | `1160` | integer | `10`
fSpecialSkillBonus               | `1161` | float   | `0.8`
fMajorSkillBonus                 | `1162` | float   | `0.75`
fMinorSkillBonus                 | `1163` | float   | `1`
fMiscSkillBonus                  | `1164` | float   | `1.25`
iAlarmKilling                    | `1165` | integer | `90`
iAlarmAttack                     | `1166` | integer | `50`
iAlarmStealing                   | `1167` | integer | `1`
iAlarmPickPocket                 | `1168` | integer | `20`
iAlarmTresspass                  | `1169` | integer | `5`
fAlarmRadius                     | `1170` | float   | `2000`
iCrimeKilling                    | `1171` | integer | `1000`
iCrimeAttack                     | `1172` | integer | `40`
fCrimeStealing                   | `1173` | float   | `1`
iCrimePickPocket                 | `1174` | integer | `25`
iCrimeTresspass                  | `1175` | integer | `5`
iCrimeThreshold                  | `1176` | integer | `1000`
iCrimeThresholdMultiplier        | `1177` | integer | `10`
fCrimeGoldDiscountMult           | `1178` | float   | `0.5`
fCrimeGoldTurnInMult             | `1179` | float   | `0.9`
iFightAttack                     | `1180` | integer | `100`
iFightAttacking                  | `1181` | integer | `50`
iFightDistanceBase               | `1182` | integer | `20`
fFightDistanceMultiplier         | `1183` | float   | `0.005`
iFightAlarmMult                  | `1184` | integer | `1`
fFightDispMult                   | `1185` | float   | `0.2`
fFightStealing                   | `1186` | float   | `50`
iFightPickpocket                 | `1187` | integer | `25`
iFightTrespass                   | `1188` | integer | `25`
iFightKilling                    | `1189` | integer | `50`
iFlee                            | `1190` | integer | `0`
iGreetDistanceMultiplier         | `1191` | integer | `6`
iGreetDuration                   | `1192` | integer | `4`
fGreetDistanceReset              | `1193` | float   | `512`
fIdleChanceMultiplier            | `1194` | float   | `0.75`
fSneakUseDist                    | `1195` | float   | `500`
fSneakUseDelay                   | `1196` | float   | `1`
fSneakDistanceBase               | `1197` | float   | `0.5`
fSneakDistanceMultiplier         | `1198` | float   | `0.002`
fSneakSpeedMultiplier            | `1199` | float   | `0.75`
fSneakViewMult                   | `1200` | float   | `1.5`
fSneakNoViewMult                 | `1201` | float   | `0.5`
fSneakSkillMult                  | `1202` | float   | `1`
fSneakBootMult                   | `1203` | float   | `-1`
fCombatDistance                  | `1204` | float   | `128`
fCombatAngleXY                   | `1205` | float   | `0.6666667`
fCombatAngleZ                    | `1206` | float   | `0.6666667`
fCombatForceSideAngle            | `1207` | float   | `0.3333333`
fCombatTorsoSideAngle            | `1208` | float   | `0.5`
fCombatTorsoStartPercent         | `1209` | float   | `0.3`
fCombatTorsoStopPercent          | `1210` | float   | `0.8`
fCombatBlockLeftAngle            | `1211` | float   | `-1`
fCombatBlockRightAngle           | `1212` | float   | `0.3333333`
fCombatDelayCreature             | `1213` | float   | `0.1`
fCombatDelayNPC                  | `1214` | float   | `0.1`
sTargetCriticalStrike            | `1215` | string  | `"Critical Damage!"`
fAIMeleeWeaponMult               | `1216` | float   | `2`
fAIRangeMeleeWeaponMult          | `1217` | float   | `5`
fAIMagicSpellMult                | `1218` | float   | `3`
fAIRangeMagicSpellMult           | `1219` | float   | `5`
fAIMeleeArmorMult                | `1220` | float   | `1`
fAIMeleeSummWeaponMult           | `1221` | float   | `1`
fAIFleeHealthMult                | `1222` | float   | `7`
fAIFleeFleeMult                  | `1223` | float   | `0.3`
fPickPocketMod                   | `1224` | float   | `0.3`
fSleepRandMod                    | `1225` | float   | `0.25`
fSleepRestMod                    | `1226` | float   | `0.3`
iNumberCreatures                 | `1227` | integer | `1`
fAudioDefaultMinDistance         | `1228` | float   | `5`
fAudioDefaultMaxDistance         | `1229` | float   | `40`
fAudioVoiceDefaultMinDistance    | `1230` | float   | `10`
fAudioVoiceDefaultMaxDistance    | `1231` | float   | `60`
fAudioMinDistanceMult            | `1232` | float   | `20`
fAudioMaxDistanceMult            | `1233` | float   | `50`
fNPCHealthBarTime                | `1234` | float   | `3`
fNPCHealthBarFade                | `1235` | float   | `0.5`
fDifficultyMult                  | `1236` | float   | `5`
fWereWolfRunMult                 | `1237` | float   | `1.3`
fWereWolfSilverWeaponDamageMult  | `1238` | float   | `2`
iWereWolfBounty                  | `1239` | integer | `1000`
fWereWolfStrength                | `1240` | float   | `150`
fWereWolfAgility                 | `1241` | float   | `150`
fWereWolfEndurance               | `1242` | float   | `150`
fWereWolfSpeed                   | `1243` | float   | `90`
fWereWolfHandtoHand              | `1244` | float   | `100`
fWereWolfUnarmored               | `1245` | float   | `100`
iWereWolfLevelToAttack           | `1246` | integer | `20`
iWereWolfFightMod                | `1247` | integer | `100`
iWereWolfFleeMod                 | `1248` | integer | `100`
fWereWolfAthletics               | `1249` | float   | `50`
fWereWolfAcrobatics              | `1250` | float   | `80`
fWereWolfHealth                  | `1251` | float   | `2`
fWereWolfFatigue                 | `1252` | float   | `400`
fWereWolfMagicka                 | `1253` | float   | `100`
fWereWolfIntellegence            | `1254` | float   | `0`
fWereWolfWillPower               | `1255` | float   | `0`
fWereWolfPersonality             | `1256` | float   | `0`
fWereWolfLuck                    | `1257` | float   | `25`
fWereWolfBlock                   | `1258` | float   | `0`
fWereWolfArmorer                 | `1259` | float   | `0`
fWereWolfMediumArmor             | `1260` | float   | `0`
fWereWolfHeavyArmor              | `1261` | float   | `0`
fWereWolfBluntWeapon             | `1262` | float   | `0`
fWereWolfLongBlade               | `1263` | float   | `0`
fWereWolfAxe                     | `1264` | float   | `0`
fWereWolfSpear                   | `1265` | float   | `0`
fWereWolfDestruction             | `1266` | float   | `0`
fWereWolfAlteration              | `1267` | float   | `0`
fWereWolfIllusion                | `1268` | float   | `0`
fWereWolfConjuration             | `1269` | float   | `0`
fWereWolfMysticism               | `1270` | float   | `0`
fWereWolfRestoration             | `1271` | float   | `0`
fWereWolfEnchant                 | `1272` | float   | `0`
fWereWolfAlchemy                 | `1273` | float   | `0`
fWereWolfSecurity                | `1274` | float   | `0`
fWereWolfSneak                   | `1275` | float   | `95`
fWereWolfLightArmor              | `1276` | float   | `0`
fWereWolfShortBlade              | `1277` | float   | `0`
fWereWolfMarksman                | `1278` | float   | `0`
fWereWolfMerchantile             | `1279` | float   | `0`
fWereWolfSpeechcraft             | `1280` | float   | `0`
fCombatDistanceWerewolfMod       | `1281` | float   | `0.3`
fFleeDistance                    | `1282` | float   | `3000`
sEffectWaterBreathing            | `1283` | string  | `"Water Breathing"`
sEffectSwiftSwim                 | `1284` | string  | `"Swift Swim"`
sEffectWaterWalking              | `1285` | string  | `"Water Walking"`
sEffectShield                    | `1286` | string  | `"Shield"`
sEffectFireShield                | `1287` | string  | `"Fire Shield"`
sEffectLightningShield           | `1288` | string  | `"Lightning Shield"`
sEffectFrostShield               | `1289` | string  | `"Frost Shield"`
sEffectBurden                    | `1290` | string  | `"Burden"`
sEffectFeather                   | `1291` | string  | `"Feather"`
sEffectJump                      | `1292` | string  | `"Jump"`
sEffectLevitate                  | `1293` | string  | `"Levitate"`
sEffectSlowFall                  | `1294` | string  | `"SlowFall"`
sEffectLock                      | `1295` | string  | `"Lock"`
sEffectOpen                      | `1296` | string  | `"Open"`
sEffectFireDamage                | `1297` | string  | `"Fire Damage"`
sEffectShockDamage               | `1298` | string  | `"Shock Damage"`
sEffectFrostDamage               | `1299` | string  | `"Frost Damage"`
sEffectDrainAttribute            | `1300` | string  | `"Drain Attribute"`
sEffectDrainHealth               | `1301` | string  | `"Drain Health"`
sEffectDrainSpellpoints          | `1302` | string  | `"Drain Magicka"`
sEffectDrainFatigue              | `1303` | string  | `"Drain Fatigue"`
sEffectDrainSkill                | `1304` | string  | `"Drain Skill"`
sEffectDamageAttribute           | `1305` | string  | `"Damage Attribute"`
sEffectDamageHealth              | `1306` | string  | `"Damage Health"`
sEffectDamageMagicka             | `1307` | string  | `"Damage Magicka"`
sEffectDamageFatigue             | `1308` | string  | `"Damage Fatigue"`
sEffectDamageSkill               | `1309` | string  | `"Damage Skill"`
sEffectPoison                    | `1310` | string  | `"Poison"`
sEffectWeaknessToFire            | `1311` | string  | `"Weakness to Fire"`
sEffectWeaknessToFrost           | `1312` | string  | `"Weakness to Frost"`
sEffectWeaknessToShock           | `1313` | string  | `"Weakness to Shock"`
sEffectWeaknessToMagicka         | `1314` | string  | `"Weakness to Magicka"`
sEffectWeaknessToCommonDisease   | `1315` | string  | `"Weakness to Common Disease"`
sEffectWeaknessToBlightDisease   | `1316` | string  | `"Weakness to Blight Disease"`
sEffectWeaknessToCorprusDisease  | `1317` | string  | `"Weakness to Corprus Disease"`
sEffectWeaknessToPoison          | `1318` | string  | `"Weakness to Poison"`
sEffectWeaknessToNormalWeapons   | `1319` | string  | `"Weakness to Normal Weapons"`
sEffectDisintegrateWeapon        | `1320` | string  | `"Disintegrate Weapon"`
sEffectDisintegrateArmor         | `1321` | string  | `"Disintegrate Armor"`
sEffectInvisibility              | `1322` | string  | `"Invisibility"`
sEffectChameleon                 | `1323` | string  | `"Chameleon"`
sEffectLight                     | `1324` | string  | `"Light"`
sEffectSanctuary                 | `1325` | string  | `"Sanctuary"`
sEffectNightEye                  | `1326` | string  | `"Night Eye"`
sEffectCharm                     | `1327` | string  | `"Charm"`
sEffectParalyze                  | `1328` | string  | `"Paralyze"`
sEffectSilence                   | `1329` | string  | `"Silence"`
sEffectBlind                     | `1330` | string  | `"Blind"`
sEffectSound                     | `1331` | string  | `"Sound"`
sEffectCalmHumanoid              | `1332` | string  | `"Calm Humanoid"`
sEffectCalmCreature              | `1333` | string  | `"Calm Creature"`
sEffectFrenzyHumanoid            | `1334` | string  | `"Frenzy Humanoid"`
sEffectFrenzyCreature            | `1335` | string  | `"Frenzy Creature"`
sEffectDemoralizeHumanoid        | `1336` | string  | `"Demoralize Humanoid"`
sEffectDemoralizeCreature        | `1337` | string  | `"Demoralize Creature"`
sEffectRallyHumanoid             | `1338` | string  | `"Rally Humanoid"`
sEffectRallyCreature             | `1339` | string  | `"Rally Creature"`
sEffectDispel                    | `1340` | string  | `"Dispel"`
sEffectSoultrap                  | `1341` | string  | `"Soultrap"`
sEffectTelekinesis               | `1342` | string  | `"Telekinesis"`
sEffectMark                      | `1343` | string  | `"Mark"`
sEffectRecall                    | `1344` | string  | `"Recall"`
sEffectDivineIntervention        | `1345` | string  | `"Divine Intervention"`
sEffectAlmsiviIntervention       | `1346` | string  | `"Almsivi Intervention"`
sEffectDetectAnimal              | `1347` | string  | `"Detect Animal"`
sEffectDetectEnchantment         | `1348` | string  | `"Detect Enchantment"`
sEffectDetectKey                 | `1349` | string  | `"Detect Key"`
sEffectSpellAbsorption           | `1350` | string  | `"Spell Absorption"`
sEffectReflect                   | `1351` | string  | `"Reflect"`
sEffectCureCommonDisease         | `1352` | string  | `"Cure Common Disease"`
sEffectCureBlightDisease         | `1353` | string  | `"Cure Blight Disease"`
sEffectCureCorprusDisease        | `1354` | string  | `"Cure Corprus Disease"`
sEffectCurePoison                | `1355` | string  | `"Cure Poison"`
sEffectCureParalyzation          | `1356` | string  | `"Cure Paralyzation"`
sEffectRestoreAttribute          | `1357` | string  | `"Restore Attribute"`
sEffectRestoreHealth             | `1358` | string  | `"Restore Health"`
sEffectRestoreSpellPoints        | `1359` | string  | `"Restore Magicka"`
sEffectRestoreFatigue            | `1360` | string  | `"Restore Fatigue"`
sEffectRestoreSkill              | `1361` | string  | `"Restore Skill"`
sEffectFortifyAttribute          | `1362` | string  | `"Fortify Attribute"`
sEffectFortifyHealth             | `1363` | string  | `"Fortify Health"`
sEffectFortifySpellpoints        | `1364` | string  | `"Fortify Magicka"`
sEffectFortifyFatigue            | `1365` | string  | `"Fortify Fatigue"`
sEffectFortifySkill              | `1366` | string  | `"Fortify Skill"`
sEffectFortifyMagickaMultiplier  | `1367` | string  | `"Fortify Maximum Magicka"`
sEffectAbsorbAttribute           | `1368` | string  | `"Absorb Attribute"`
sEffectAbsorbHealth              | `1369` | string  | `"Absorb Health"`
sEffectAbsorbSpellPoints         | `1370` | string  | `"Absorb Magicka"`
sEffectAbsorbFatigue             | `1371` | string  | `"Absorb Fatigue"`
sEffectAbsorbSkill               | `1372` | string  | `"Absorb Skill"`
sEffectResistFire                | `1373` | string  | `"Resist Fire"`
sEffectResistFrost               | `1374` | string  | `"Resist Frost"`
sEffectResistShock               | `1375` | string  | `"Resist Shock"`
sEffectResistMagicka             | `1376` | string  | `"Resist Magicka"`
sEffectResistCommonDisease       | `1377` | string  | `"Resist Common Disease"`
sEffectResistBlightDisease       | `1378` | string  | `"Resist Blight Disease"`
sEffectResistCorprusDisease      | `1379` | string  | `"Resist Corprus Disease"`
sEffectResistPoison              | `1380` | string  | `"Resist Poison"`
sEffectResistNormalWeapons       | `1381` | string  | `"Resist Normal Weapons"`
sEffectResistParalysis           | `1382` | string  | `"Resist Paralysis"`
sEffectRemoveCurse               | `1383` | string  | `"Remove Curse"`
sEffectTurnUndead                | `1384` | string  | `"Turn Undead"`
sEffectSummonScamp               | `1385` | string  | `"Summon Scamp"`
sEffectSummonClannfear           | `1386` | string  | `"Summon Clannfear"`
sEffectSummonDaedroth            | `1387` | string  | `"Summon Daedroth"`
sEffectSummonDremora             | `1388` | string  | `"Summon Dremora"`
sEffectSummonAncestralGhost      | `1389` | string  | `"Summon Ancestral Ghost"`
sEffectSummonSkeletalMinion      | `1390` | string  | `"Summon Skeletal Minion"`
sEffectSummonLeastBonewalker     | `1391` | string  | `"Summon Bonewalker"`
sEffectSummonGreaterBonewalker   | `1392` | string  | `"Summon Greater Bonewalker"`
sEffectSummonBonelord            | `1393` | string  | `"Summon Bonelord"`
sEffectSummonWingedTwilight      | `1394` | string  | `"Summon Winged Twilight"`
sEffectSummonHunger              | `1395` | string  | `"Summon Hunger"`
sEffectSummonGoldensaint         | `1396` | string  | `"Summon Golden Saint"`
sEffectSummonFlameAtronach       | `1397` | string  | `"Summon Flame Atronach"`
sEffectSummonFrostAtronach       | `1398` | string  | `"Summon Frost Atronach"`
sEffectSummonStormAtronach       | `1399` | string  | `"Summon Storm Atronach"`
sEffectFortifyAttackBonus        | `1400` | string  | `"Fortify Attack"`
sEffectCommandCreatures          | `1401` | string  | `"Command Creature"`
sEffectCommandHumanoids          | `1402` | string  | `"Command Humanoid"`
sEffectBoundDagger               | `1403` | string  | `"Bound Dagger"`
sEffectBoundLongsword            | `1404` | string  | `"Bound Longsword"`
sEffectBoundMace                 | `1405` | string  | `"Bound Mace"`
sEffectBoundBattleAxe            | `1406` | string  | `"Bound Battle Axe"`
sEffectBoundSpear                | `1407` | string  | `"Bound Spear"`
sEffectBoundLongbow              | `1408` | string  | `"Bound Longbow"`
sEffectExtraSpell                | `1409` | string  | `"EXTRA SPELL"`
sEffectBoundCuirass              | `1410` | string  | `"Bound Cuirass"`
sEffectBoundHelm                 | `1411` | string  | `"Bound Helm"`
sEffectBoundBoots                | `1412` | string  | `"Bound Boots"`
sEffectBoundShield               | `1413` | string  | `"Bound Shield"`
sEffectBoundGloves               | `1414` | string  | `"Bound Gloves"`
sEffectCorpus                    | `1415` | string  | `"Corprus"`
sEffectVampirism                 | `1416` | string  | `"Vampirism"`
sEffectSummonCenturionSphere     | `1417` | string  | `"Summon Centurion Sphere"`
sEffectSunDamage                 | `1418` | string  | `"Sun Damage"`
sEffectStuntedMagicka            | `1419` | string  | `"Stunted Magicka"`
sEffectSummonFabricant           | `1420` | string  | `"Summon Fabricant"`
sEffectSummonCreature01          | `1421` | string  | `"Call Wolf"`
sEffectSummonCreature02          | `1422` | string  | `"Call Bear"`
sEffectSummonCreature03          | `1423` | string  | `"Summon Bonewolf"`
sEffectSummonCreature04          | `1424` | string  | `"sEffectSummonCreature04"`
sEffectSummonCreature05          | `1425` | string  | `"sEffectSummonCreature05"`
sSchoolAlteration                | `1426` | string  | `"Alteration"`
sSchoolConjuration               | `1427` | string  | `"Conjuration"`
sSchoolDestruction               | `1428` | string  | `"Destruction"`
sSchoolIllusion                  | `1429` | string  | `"Illusion"`
sSchoolMysticism                 | `1430` | string  | `"Mysticism"`
sSchoolRestoration               | `1431` | string  | `"Restoration"`
sTypeSpell                       | `1432` | string  | `"Spells"`
sTypeAbility                     | `1433` | string  | `"Abilities"`
sTypeBlightDisease               | `1434` | string  | `"Blight Disease"`
sTypeDisease                     | `1435` | string  | `"Disease"`
sTypeCurse                       | `1436` | string  | `"Curse"`
sTypePower                       | `1437` | string  | `"Powers"`
sItemCastOnce                    | `1438` | string  | `"Cast Once"`
sItemCastWhenStrikes             | `1439` | string  | `"Cast When Strikes"`
sItemCastWhenUsed                | `1440` | string  | `"Cast When Used"`
sItemCastConstant                | `1441` | string  | `"Constant Effect"`
sRangeSelf                       | `1442` | string  | `"Self"`
sRangeTouch                      | `1443` | string  | `"Touch"`
sRangeTarget                     | `1444` | string  | `"Target"`
sMagicSkillFail                  | `1445` | string  | `"You failed casting the spell."`
sMagicInsufficientSP             | `1446` | string  | `"You do not have enough Magicka to cast the spell."`
sMagicInsufficientCharge         | `1447` | string  | `"Item does not have enough charge."`
sPowerAlreadyUsed                | `1448` | string  | `"You already used that power today."`
sMagicInvalidTarget              | `1449` | string  | `"Your spell did not get a target."`
sMagicLockSuccess                | `1450` | string  | `"Your spell has locked its target."`
sMagicOpenSuccess                | `1451` | string  | `"Your spell has unlocked its target."`
sMagicTargetResistsWeapons       | `1452` | string  | `"Your weapon has no effect."`
sMagicContractDisease            | `1453` | string  | `"You have contracted %s"`
fMagicDetectRefreshRate          | `1454` | float   | `0.5`
fMagicStartIconBlink             | `1455` | float   | `3`
fMagicCreatureCastDelay          | `1456` | float   | `1.5`
sMagicScampID                    | `1457` | string  | `"Scamp_summon"`
sMagicClannfearID                | `1458` | string  | `"Clannfear_summon"`
sMagicDaedrothID                 | `1459` | string  | `"Daedroth_summon"`
sMagicDremoraID                  | `1460` | string  | `"Dremora_summon"`
sMagicAncestralGhostID           | `1461` | string  | `"Ancestor_Ghost_summon"`
sMagicSkeletalMinionID           | `1462` | string  | `"Skeleton_summon"`
sMagicLeastBonewalkerID          | `1463` | string  | `"Bonewalker_summon"`
sMagicGreaterBonewalkerID        | `1464` | string  | `"Bonewalker_Greater_summ"`
sMagicBonelordID                 | `1465` | string  | `"Bonelord_summon"`
sMagicWingedTwilightID           | `1466` | string  | `"Winged Twilight_summon"`
sMagicHungerID                   | `1467` | string  | `"Hunger_summon"`
sMagicGoldenSaintID              | `1468` | string  | `"Golden Saint_summon"`
sMagicFlameAtronachID            | `1469` | string  | `"Atronach_Flame_summon"`
sMagicFrostAtronachID            | `1470` | string  | `"Atronach_Frost_summon"`
sMagicStormAtronachID            | `1471` | string  | `"Atronach_Storm_summon"`
sMagicCenturionSphereID          | `1472` | string  | `"centurion_sphere_summon"`
sMagicFabricantID                | `1473` | string  | `"Fabricant_summon"`
sMagicCreature01ID               | `1474` | string  | `"BM_wolf_grey_summon"`
sMagicCreature02ID               | `1475` | string  | `"BM_bear_black_summon"`
sMagicCreature03ID               | `1476` | string  | `"BM_wolf_bone_summon"`
sMagicCreature04ID               | `1477` | string  | `"sMagicCreature04ID"`
sMagicCreature05ID               | `1478` | string  | `"sMagicCreature05ID"`
sMagicBoundDaggerID              | `1479` | string  | `"Bound_Dagger"`
sMagicBoundLongswordID           | `1480` | string  | `"Bound_Longsword"`
sMagicBoundMaceID                | `1481` | string  | `"Bound_Mace"`
sMagicBoundBattleAxeID           | `1482` | string  | `"Bound_Battle_Axe"`
sMagicBoundSpearID               | `1483` | string  | `"Bound_Spear"`
sMagicBoundLongbowID             | `1484` | string  | `"Bound_Longbow"`
sMagicBoundCuirassID             | `1485` | string  | `"Bound_Cuirass"`
sMagicBoundHelmID                | `1486` | string  | `"Bound_Helm"`
sMagicBoundBootsID               | `1487` | string  | `"Bound_Boots"`
sMagicBoundShieldID              | `1488` | string  | `"Bound_Shield"`
sMagicBoundLeftGauntletID        | `1489` | string  | `"Bound_Gauntlet_Left"`
sMagicBoundRightGauntletID       | `1490` | string  | `"Bound_Gauntlet_Right"`
fDiseaseXferChance               | `1491` | float   | `2.5`
fElementalShieldMult             | `1492` | float   | `0.1`
sMagicCorprusWorsens             | `1493` | string  | `"Your case of Corprus has worsened."`
sMagicCannotRecast               | `1494` | string  | `"You cannot re-cast this spell while it is still in effect."`
fMagicSunBlockedMult             | `1495` | float   | `0.5`
sMagicPCResisted                 | `1496` | string  | `"You resisted magic."`
sMagicTargetResisted             | `1497` | string  | `"Target resisted magic."`
sMagicInvalidEffect              | `1498` | string  | `"You cannot cast this effect right now."`
sAcrobat                         | `1499` | string  | `"Acrobat"`
sAgent                           | `1500` | string  | `"Agent"`
sArcher                          | `1501` | string  | `"Archer"`
sAssassin                        | `1502` | string  | `"Assassin"`
sBarbarian                       | `1503` | string  | `"Barbarian"`
sBard                            | `1504` | string  | `"Bard"`
sBattlemage                      | `1505` | string  | `"Battlemage"`
sCrusader                        | `1506` | string  | `"Crusader"`
sCustom                          | `1507` | string  | `"Custom"`
sHealer                          | `1508` | string  | `"Healer"`
sKnight                          | `1509` | string  | `"Knight"`
sMage                            | `1510` | string  | `"Mage"`
sMonk                            | `1511` | string  | `"Monk"`
sNightblade                      | `1512` | string  | `"Nightblade"`
sPilgrim                         | `1513` | string  | `"Pilgrim"`
sRogue                           | `1514` | string  | `"Rogue"`
sScout                           | `1515` | string  | `"Scout"`
sSorceror                        | `1516` | string  | `"Sorcerer"`
sSpellsword                      | `1517` | string  | `"Spellsword"`
sThief                           | `1518` | string  | `"Thief"`
sWarrior                         | `1519` | string  | `"Warrior"`
sWitchhunter                     | `1520` | string  | `"Witchhunter"`
