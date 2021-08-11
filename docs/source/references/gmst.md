---
hide:
  - toc
---

# Game Settings (GMSTs)

!!! tip
	These values are available in Lua by their identifier in the `tes3.gmst.*` namespace. For example, `tes3.gmst.sMonthMorningstar` has a value of `0`.

Index | Type    | Identifier                       | Default Value
----- | ------- | -------------------------------- | --------------------------------------------
0     | string  | sMonthMorningstar                | `"sMonthMorningstar"`
1     | string  | sMonthSunsdawn                   | `"sMonthSunsdawn"`
2     | string  | sMonthFirstseed                  | `"sMonthFirstseed"`
3     | string  | sMonthRainshand                  | `"sMonthRainshand"`
4     | string  | sMonthSecondseed                 | `"sMonthSecondseed"`
5     | string  | sMonthMidyear                    | `"sMonthMidyear"`
6     | string  | sMonthSunsheight                 | `"sMonthSunsheight"`
7     | string  | sMonthLastseed                   | `"sMonthLastseed"`
8     | string  | sMonthHeartfire                  | `"sMonthHeartfire"`
9     | string  | sMonthFrostfall                  | `"sMonthFrostfall"`
10    | string  | sMonthSunsdusk                   | `"sMonthSunsdusk"`
11    | string  | sMonthEveningstar                | `"sMonthEveningstar"`
12    | string  | sSpecialization                  | `"sSpecialization"`
13    | string  | sSpecializationCombat            | `"sCombat"`
14    | string  | sSpecializationMagic             | `"sMagic"`
15    | string  | sSpecializationStealth           | `"sStealth"`
16    | string  | sSkillClassMajor                 | `"sSkillClassMajor"`
17    | string  | sSkillClassMinor                 | `"sSkillClassMinor"`
18    | string  | sSkillClassMisc                  | `"sSkillClassMisc"`
19    | string  | sRacialTraits                    | `"sRacialTraits"`
20    | string  | sHealthPerHourOfRest             | `"sHealthPerHourOfRest"`
21    | string  | sHealthPerLevel                  | `"sHealthPerLevel"`
22    | string  | sGoverningAttribute              | `"sGoverningAttribute"`
23    | string  | sClass                           | `"sClass"`
24    | string  | sTraits                          | `"sTraits"`
25    | string  | sJournal                         | `"sJournal"`
26    | string  | sOK                              | `"sOK"`
27    | string  | sClose                           | `"Close"`
28    | string  | sPrev                            | `"Prev"`
29    | string  | sNext                            | `"Next"`
30    | string  | sTake                            | `"Take"`
31    | string  | sWeaponTab                       | `"sWeaponTab"`
32    | string  | sApparelTab                      | `"sApparelTab"`
33    | string  | sMagicTab                        | `"sMagicTab"`
34    | string  | sMiscTab                         | `"sMiscTab"`
35    | string  | sWornTab                         | `"Worn"`
36    | string  | sAllTab                          | `"All"`
37    | string  | sAttack                          | `"Attack"`
38    | string  | sUses                            | `"Uses"`
39    | string  | sQuality                         | `"Quality:"`
40    | string  | sCharges                         | `"Charge"`
41    | string  | sArmorRating                     | `"sArmorRating"`
42    | string  | sSlash                           | `"sSlash"`
43    | string  | sThrust                          | `"sThrust"`
44    | string  | sChop                            | `"sChop"`
45    | string  | sEncumbrance                     | `"sEncumbrance"`
46    | string  | sCondition                       | `"sCondition"`
47    | string  | sWeight                          | `"sWeight"`
48    | string  | sValue                           | `"sValue"`
49    | string  | sLight                           | `"sLight"`
50    | string  | sMedium                          | `"sMedium"`
51    | string  | sHeavy                           | `"sHeavy"`
52    | string  | sCancel                          | `"sCancel"`
53    | string  | sTakeAll                         | `"Take All"`
54    | string  | sUntilHealed                     | `"Until Healed"`
55    | string  | sRest                            | `"sRest"`
56    | string  | sWait                            | `"sWait"`
57    | string  | sRestIllegal                     | `"sRestIllegal"`
58    | string  | sGold                            | `"sGold"`
59    | string  | sMove                            | `"sMove"`
60    | string  | sTo                              | `"to"`
61    | string  | sActorInCombat                   | `"This character is in combat."`
62    | string  | sArmor                           | `"Armor"`
63    | string  | sTopics                          | `"Topics"`
64    | string  | sService                         | `"Service"`
65    | string  | sPersuasion                      | `"Persuasion"`
66    | string  | sBye                             | `"Bye"`
67    | string  | sGoodbye                         | `"Goodbye"`
68    | string  | sYes                             | `"Yes"`
69    | string  | sNo                              | `"No"`
70    | string  | sOn                              | `"On"`
71    | string  | sOff                             | `"Off"`
72    | string  | sFull                            | `"Full"`
73    | string  | sWorld                           | `"World"`
74    | string  | sExpelled                        | `"EXPELLED"`
75    | string  | sExpelledMessage                 | `"You have been expelled from "`
76    | string  | sFavoriteSkills                  | `"Favorite Skills"`
77    | string  | sGame                            | `"Game"`
78    | string  | sVideo                           | `"Video"`
79    | string  | sAudio                           | `"Audio"`
80    | string  | sControls                        | `"Controls"`
81    | string  | sPrefs                           | `"Prefs"`
82    | string  | sPreferences                     | `"Preferences"`
83    | string  | sNewGame                         | `"New Game"`
84    | string  | sExitGame                        | `"Exit Game"`
85    | string  | sOptions                         | `"Options Menu"`
86    | string  | sSaveGame                        | `"Save Game"`
87    | string  | sLoadGame                        | `"Load Game"`
88    | string  | sDeleteGame                      | `"Delete Game"`
89    | string  | sSaveGameDenied                  | `"You can not save your game right now."`
90    | string  | sSaveGameFailed                  | `"An error was encountered while saving the game."`
91    | string  | sSaveGameTooBig                  | `"There is not enough space to save this game. Free up at least %i blocks and try again."`
92    | string  | sSaveGameNoMemory                | `"Unable to create Save Game. Free up 100 blocks and try again."`
93    | string  | sMaximumSaveGameMessage          | `"You have reached the limit of Morrowind saved games. Please delete a Morrowind saved game and try again."`
94    | string  | sRender_Distance                 | `"Render Distance"`
95    | string  | sNear                            | `"Near"`
96    | string  | sFar                             | `"Far"`
97    | string  | sGamma_Correction                | `"Gamma Correction"`
98    | string  | sLight_Gamma                     | `"Light"`
99    | string  | sDark_Gamma                      | `"Dark"`
100   | string  | sSeldom                          | `"Seldom"`
101   | string  | sAlways                          | `"Always"`
102   | string  | sWaterTerrainReflect             | `"Reflect Terrain"`
103   | string  | sWaterReflectUpdate              | `"Reflection Updating"`
104   | float   | fWaterReflectUpdateAlways        | `0.0000`
105   | float   | fWaterReflectUpdateSeldom        | `10.0000`
106   | string  | sMaster                          | `"Master"`
107   | string  | sVoice                           | `"Voice"`
108   | string  | sEffects                         | `"Effect"`
109   | string  | sFootsteps                       | `"Footsteps"`
110   | string  | sMusic                           | `"Music"`
111   | string  | sTransparency_Menu               | `"Transparency Menu"`
112   | string  | sMenu_Help_Delay                 | `"Menu Help Delay"`
113   | string  | sAIDistance                      | `"AI Distance"`
114   | string  | sHigh                            | `"High"`
115   | string  | sLow                             | `"Low"`
116   | string  | sDetail_Level                    | `"Detail Level"`
117   | string  | sMenus                           | `"Menus"`
118   | string  | sStrip                           | `"Strip"`
119   | string  | sReturnToGame                    | `"Return To Game"`
120   | string  | sForward                         | `"Forward"`
121   | string  | sBack                            | `"Back"`
122   | string  | sLeft                            | `"Left"`
123   | string  | sRight                           | `"Right"`
124   | string  | sUse                             | `"Use"`
125   | string  | sActivate                        | `"Activate"`
126   | string  | sReady_Weapon                    | `"Ready Weapon"`
127   | string  | sReady_Magic                     | `"Ready Magic"`
128   | string  | sCrouch_Sneak                    | `"Crouch/Sneak"`
129   | string  | sRun                             | `"Run"`
130   | string  | sAlways_Run                      | `"Always Run"`
131   | string  | sAuto_Run                        | `"Auto Run"`
132   | string  | sJump                            | `"Jump"`
133   | string  | sNextWeapon                      | `"NextWeapon"`
134   | string  | sPrevWeapon                      | `"PrevWeapon"`
135   | string  | sNextSpell                       | `"NextSpell"`
136   | string  | sPrevSpell                       | `"PrevSpell"`
137   | string  | sTogglePOVCmd                    | `"Toggle POV"`
138   | string  | sMenu_Mode                       | `"Menu Mode"`
139   | string  | sJournalCmd                      | `"Journal"`
140   | string  | sRestKey                         | `"Rest Menu"`
141   | string  | sQuickMenu                       | `"Quick Menu"`
142   | string  | sQuick1Cmd                       | `"Quick 1"`
143   | string  | sQuick2Cmd                       | `"Quick 2"`
144   | string  | sQuick3Cmd                       | `"Quick 3"`
145   | string  | sQuick4Cmd                       | `"Quick 4"`
146   | string  | sQuick5Cmd                       | `"Quick 5"`
147   | string  | sQuick6Cmd                       | `"Quick 6"`
148   | string  | sQuick7Cmd                       | `"Quick 7"`
149   | string  | sQuick8Cmd                       | `"Quick 8"`
150   | string  | sQuick9Cmd                       | `"Quick 9"`
151   | string  | sQuick10Cmd                      | `"Quick 10"`
152   | string  | sQuickSaveCmd                    | `"Quick Save"`
153   | string  | sQuickLoadCmd                    | `"Quick Load"`
154   | string  | sKeyName_00                      | `""`
155   | string  | sKeyName_01                      | `"ESC"`
156   | string  | sKeyName_02                      | `"1"`
157   | string  | sKeyName_03                      | `"2"`
158   | string  | sKeyName_04                      | `"3"`
159   | string  | sKeyName_05                      | `"4"`
160   | string  | sKeyName_06                      | `"5"`
161   | string  | sKeyName_07                      | `"6"`
162   | string  | sKeyName_08                      | `"7"`
163   | string  | sKeyName_09                      | `"8"`
164   | string  | sKeyName_0A                      | `"9"`
165   | string  | sKeyName_0B                      | `"0"`
166   | string  | sKeyName_0C                      | `"-"`
167   | string  | sKeyName_0D                      | `"="`
168   | string  | sKeyName_0E                      | `"Back Space"`
169   | string  | sKeyName_0F                      | `"Tab"`
170   | string  | sKeyName_10                      | `"Q"`
171   | string  | sKeyName_11                      | `"W"`
172   | string  | sKeyName_12                      | `"E"`
173   | string  | sKeyName_13                      | `"R"`
174   | string  | sKeyName_14                      | `"T"`
175   | string  | sKeyName_15                      | `"Y"`
176   | string  | sKeyName_16                      | `"U"`
177   | string  | sKeyName_17                      | `"I"`
178   | string  | sKeyName_18                      | `"O"`
179   | string  | sKeyName_19                      | `"P"`
180   | string  | sKeyName_1A                      | `"["`
181   | string  | sKeyName_1B                      | `"]"`
182   | string  | sKeyName_1C                      | `"Return"`
183   | string  | sKeyName_1D                      | `"Left Ctrl"`
184   | string  | sKeyName_1E                      | `"A"`
185   | string  | sKeyName_1F                      | `"S"`
186   | string  | sKeyName_20                      | `"D"`
187   | string  | sKeyName_21                      | `"F"`
188   | string  | sKeyName_22                      | `"G"`
189   | string  | sKeyName_23                      | `"H"`
190   | string  | sKeyName_24                      | `"J"`
191   | string  | sKeyName_25                      | `"K"`
192   | string  | sKeyName_26                      | `"L"`
193   | string  | sKeyName_27                      | `";"`
194   | string  | sKeyName_28                      | `"'"`
195   | string  | sKeyName_29                      | `"Grave"`
196   | string  | sKeyName_2A                      | `"Left Shift"`
197   | string  | sKeyName_2B                      | `"\"`
198   | string  | sKeyName_2C                      | `"Z"`
199   | string  | sKeyName_2D                      | `"X"`
200   | string  | sKeyName_2E                      | `"C"`
201   | string  | sKeyName_2F                      | `"V"`
202   | string  | sKeyName_30                      | `"B"`
203   | string  | sKeyName_31                      | `"N"`
204   | string  | sKeyName_32                      | `"M"`
205   | string  | sKeyName_33                      | `","`
206   | string  | sKeyName_34                      | `"."`
207   | string  | sKeyName_35                      | `"/"`
208   | string  | sKeyName_36                      | `"Right Shift"`
209   | string  | sKeyName_37                      | `"Numpad *"`
210   | string  | sKeyName_38                      | `"Left Alt"`
211   | string  | sKeyName_39                      | `"Space"`
212   | string  | sKeyName_3A                      | `"Caps Lock"`
213   | string  | sKeyName_3B                      | `"F1"`
214   | string  | sKeyName_3C                      | `"F2"`
215   | string  | sKeyName_3D                      | `"F3"`
216   | string  | sKeyName_3E                      | `"F4"`
217   | string  | sKeyName_3F                      | `"F5"`
218   | string  | sKeyName_40                      | `"F6"`
219   | string  | sKeyName_41                      | `"F7"`
220   | string  | sKeyName_42                      | `"F8"`
221   | string  | sKeyName_43                      | `"F9"`
222   | string  | sKeyName_44                      | `"F10"`
223   | string  | sKeyName_45                      | `"Num Lock"`
224   | string  | sKeyName_46                      | `"Scroll Lock"`
225   | string  | sKeyName_47                      | `"Numpad 7"`
226   | string  | sKeyName_48                      | `"Numpad 8"`
227   | string  | sKeyName_49                      | `"Numpad 9"`
228   | string  | sKeyName_4A                      | `"Numpad -"`
229   | string  | sKeyName_4B                      | `"Numpad 4"`
230   | string  | sKeyName_4C                      | `"Numpad 5"`
231   | string  | sKeyName_4D                      | `"Numpad 6"`
232   | string  | sKeyName_4E                      | `"Numpad +"`
233   | string  | sKeyName_4F                      | `"Numpad 1"`
234   | string  | sKeyName_50                      | `"Numpad 2"`
235   | string  | sKeyName_51                      | `"Numpad 3"`
236   | string  | sKeyName_52                      | `"Numpad 0"`
237   | string  | sKeyName_53                      | `"Decimal"`
238   | string  | sKeyName_54                      | `""`
239   | string  | sKeyName_55                      | `""`
240   | string  | sKeyName_56                      | `"OEM 102"`
241   | string  | sKeyName_57                      | `"F11"`
242   | string  | sKeyName_58                      | `"F12"`
243   | string  | sKeyName_59                      | `""`
244   | string  | sKeyName_5A                      | `""`
245   | string  | sKeyName_5B                      | `""`
246   | string  | sKeyName_5C                      | `""`
247   | string  | sKeyName_5D                      | `""`
248   | string  | sKeyName_5E                      | `""`
249   | string  | sKeyName_5F                      | `""`
250   | string  | sKeyName_60                      | `""`
251   | string  | sKeyName_61                      | `""`
252   | string  | sKeyName_62                      | `""`
253   | string  | sKeyName_63                      | `""`
254   | string  | sKeyName_64                      | `"F13"`
255   | string  | sKeyName_65                      | `"F14"`
256   | string  | sKeyName_66                      | `"F15"`
257   | string  | sKeyName_67                      | `""`
258   | string  | sKeyName_68                      | `""`
259   | string  | sKeyName_69                      | `""`
260   | string  | sKeyName_6A                      | `""`
261   | string  | sKeyName_6B                      | `""`
262   | string  | sKeyName_6C                      | `""`
263   | string  | sKeyName_6D                      | `""`
264   | string  | sKeyName_6E                      | `""`
265   | string  | sKeyName_6F                      | `""`
266   | string  | sKeyName_70                      | `"Kana"`
267   | string  | sKeyName_71                      | `""`
268   | string  | sKeyName_72                      | `""`
269   | string  | sKeyName_73                      | `"Abnt C1"`
270   | string  | sKeyName_74                      | `""`
271   | string  | sKeyName_75                      | `""`
272   | string  | sKeyName_76                      | `""`
273   | string  | sKeyName_77                      | `""`
274   | string  | sKeyName_78                      | `""`
275   | string  | sKeyName_79                      | `"Cnvrt"`
276   | string  | sKeyName_7A                      | `""`
277   | string  | sKeyName_7B                      | `"No Cnvrt"`
278   | string  | sKeyName_7C                      | `""`
279   | string  | sKeyName_7D                      | `"Yen"`
280   | string  | sKeyName_7E                      | `"Abnt C2"`
281   | string  | sKeyName_7F                      | `""`
282   | string  | sKeyName_80                      | `""`
283   | string  | sKeyName_81                      | `""`
284   | string  | sKeyName_82                      | `""`
285   | string  | sKeyName_83                      | `""`
286   | string  | sKeyName_84                      | `""`
287   | string  | sKeyName_85                      | `""`
288   | string  | sKeyName_86                      | `""`
289   | string  | sKeyName_87                      | `""`
290   | string  | sKeyName_88                      | `""`
291   | string  | sKeyName_89                      | `""`
292   | string  | sKeyName_8A                      | `""`
293   | string  | sKeyName_8B                      | `""`
294   | string  | sKeyName_8C                      | `""`
295   | string  | sKeyName_8D                      | `"Np Equals"`
296   | string  | sKeyName_8E                      | `""`
297   | string  | sKeyName_8F                      | `""`
298   | string  | sKeyName_90                      | `"PrvTrk"`
299   | string  | sKeyName_91                      | `"AT"`
300   | string  | sKeyName_92                      | `":"`
301   | string  | sKeyName_93                      | `"_"`
302   | string  | sKeyName_94                      | `"Kanji"`
303   | string  | sKeyName_95                      | `"Stop"`
304   | string  | sKeyName_96                      | `"Ax"`
305   | string  | sKeyName_97                      | `"Unlabeled"`
306   | string  | sKeyName_98                      | `""`
307   | string  | sKeyName_99                      | `"NxtTrk"`
308   | string  | sKeyName_9A                      | `""`
309   | string  | sKeyName_9B                      | `""`
310   | string  | sKeyName_9C                      | `"Right Enter"`
311   | string  | sKeyName_9D                      | `"Right Ctrl"`
312   | string  | sKeyName_9E                      | `""`
313   | string  | sKeyName_9F                      | `""`
314   | string  | sKeyName_A0                      | `"Mute"`
315   | string  | sKeyName_A1                      | `"Calc"`
316   | string  | sKeyName_A2                      | `"Play Pause"`
317   | string  | sKeyName_A3                      | `""`
318   | string  | sKeyName_A4                      | `"Media Stop"`
319   | string  | sKeyName_A5                      | `""`
320   | string  | sKeyName_A6                      | `""`
321   | string  | sKeyName_A7                      | `""`
322   | string  | sKeyName_A8                      | `""`
323   | string  | sKeyName_A9                      | `""`
324   | string  | sKeyName_AA                      | `""`
325   | string  | sKeyName_AB                      | `""`
326   | string  | sKeyName_AC                      | `""`
327   | string  | sKeyName_AD                      | `""`
328   | string  | sKeyName_AE                      | `"Volume Down"`
329   | string  | sKeyName_AF                      | `""`
330   | string  | sKeyName_B0                      | `"Volume Up"`
331   | string  | sKeyName_B1                      | `""`
332   | string  | sKeyName_B2                      | `"Web Home"`
333   | string  | sKeyName_B3                      | `"Numpad ,"`
334   | string  | sKeyName_B4                      | `""`
335   | string  | sKeyName_B5                      | `"Numpad /"`
336   | string  | sKeyName_B6                      | `""`
337   | string  | sKeyName_B7                      | `"SysRq"`
338   | string  | sKeyName_B8                      | `"Right Alt"`
339   | string  | sKeyName_B9                      | `""`
340   | string  | sKeyName_BA                      | `""`
341   | string  | sKeyName_BB                      | `""`
342   | string  | sKeyName_BC                      | `""`
343   | string  | sKeyName_BD                      | `""`
344   | string  | sKeyName_BE                      | `""`
345   | string  | sKeyName_BF                      | `""`
346   | string  | sKeyName_C0                      | `""`
347   | string  | sKeyName_C1                      | `""`
348   | string  | sKeyName_C2                      | `""`
349   | string  | sKeyName_C3                      | `""`
350   | string  | sKeyName_C4                      | `""`
351   | string  | sKeyName_C5                      | `"Pause"`
352   | string  | sKeyName_C6                      | `""`
353   | string  | sKeyName_C7                      | `"Home"`
354   | string  | sKeyName_C8                      | `"Up"`
355   | string  | sKeyName_C9                      | `"Page Up"`
356   | string  | sKeyName_CA                      | `""`
357   | string  | sKeyName_CB                      | `"Left"`
358   | string  | sKeyName_CC                      | `""`
359   | string  | sKeyName_CD                      | `"Right"`
360   | string  | sKeyName_CE                      | `""`
361   | string  | sKeyName_CF                      | `"End"`
362   | string  | sKeyName_D0                      | `"Down"`
363   | string  | sKeyName_D1                      | `"Page Down"`
364   | string  | sKeyName_D2                      | `"Insert"`
365   | string  | sKeyName_D3                      | `"Delete"`
366   | string  | sKeyName_D4                      | `""`
367   | string  | sKeyName_D5                      | `""`
368   | string  | sKeyName_D6                      | `""`
369   | string  | sKeyName_D7                      | `""`
370   | string  | sKeyName_D8                      | `""`
371   | string  | sKeyName_D9                      | `""`
372   | string  | sKeyName_DA                      | `""`
373   | string  | sKeyName_DB                      | `"Left Win"`
374   | string  | sKeyName_DC                      | `"Right Win"`
375   | string  | sKeyName_DD                      | `"Apps"`
376   | string  | sKeyName_DE                      | `"Power"`
377   | string  | sKeyName_DF                      | `"Sleep"`
378   | string  | sKeyName_E0                      | `""`
379   | string  | sKeyName_E1                      | `""`
380   | string  | sKeyName_E2                      | `""`
381   | string  | sKeyName_E3                      | `"Wake"`
382   | string  | sKeyName_E4                      | `""`
383   | string  | sKeyName_E5                      | `"Web Search"`
384   | string  | sKeyName_E6                      | `"Web Favs"`
385   | string  | sKeyName_E7                      | `"Web Ref"`
386   | string  | sKeyName_E8                      | `"Web Stop"`
387   | string  | sKeyName_E9                      | `"Web Fwd"`
388   | string  | sKeyName_EA                      | `"Web Back"`
389   | string  | sKeyName_EB                      | `"My Comp"`
390   | string  | sKeyName_EC                      | `""`
391   | string  | sKeyName_ED                      | `""`
392   | string  | sKeyName_EE                      | `""`
393   | string  | sKeyName_EF                      | `""`
394   | string  | sKeyName_F0                      | `""`
395   | string  | sKeyName_F1                      | `""`
396   | string  | sKeyName_F2                      | `""`
397   | string  | sKeyName_F3                      | `""`
398   | string  | sKeyName_F4                      | `""`
399   | string  | sKeyName_F5                      | `""`
400   | string  | sKeyName_F6                      | `""`
401   | string  | sKeyName_F7                      | `""`
402   | string  | sKeyName_F8                      | `""`
403   | string  | sKeyName_F9                      | `""`
404   | string  | sKeyName_FA                      | `""`
405   | string  | sKeyName_FB                      | `""`
406   | string  | sKeyName_FC                      | `""`
407   | string  | sKeyName_FD                      | `""`
408   | string  | sKeyName_FE                      | `""`
409   | string  | sKeyName_FF                      | `""`
410   | string  | sForwardXbox                     | `"Move Forward"`
411   | string  | sBackXbox                        | `"Move Backward"`
412   | string  | sSlideLeftXbox                   | `"Slide Left"`
413   | string  | sSlideRightXbox                  | `"Slide Right"`
414   | string  | sMenuModeXbox                    | `"Menu Mode"`
415   | string  | sActivateXbox                    | `"Activate"`
416   | string  | sUseXbox                         | `"Use"`
417   | string  | sReadyItemXbox                   | `"Ready Item"`
418   | string  | sReadyMagicXbox                  | `"Ready Magic"`
419   | string  | sCrouchXbox                      | `"Crouch"`
420   | string  | sRunXbox                         | `"Run"`
421   | string  | sToggleRunXbox                   | `"Toggle Run"`
422   | string  | sJumpXbox                        | `"Jump"`
423   | string  | sTogglePOVXbox                   | `"Toggle P.O.V."`
424   | string  | sMenuNextXbox                    | `"Next Menu"`
425   | string  | sMenuPrevXbox                    | `"Previous Menu"`
426   | string  | sJournalXbox                     | `"Journal"`
427   | string  | sQuick4Xbox                      | `"sQuick4Xbox"`
428   | string  | sQuick5Xbox                      | `"sQuick5Xbox"`
429   | string  | sQuick6Xbox                      | `"sQuick6Xbox"`
430   | string  | sQuick7Xbox                      | `"sQuick7Xbox"`
431   | string  | sQuick8Xbox                      | `"sQuick8Xbox"`
432   | string  | sQuick9Xbox                      | `"sQuick9Xbox"`
433   | string  | sQuick0Xbox                      | `"sQuick0Xbox"`
434   | string  | sOptionsMenuXbox                 | `"Options Menu"`
435   | string  | sSystemMenuXbox                  | `"System Menu"`
436   | string  | sRestMenuXbox                    | `"Rest/Wait"`
437   | string  | sQuickSaveXbox                   | `"Quick Save"`
438   | string  | sQuickLoadXbox                   | `"Quick Load"`
439   | string  | sMoveUpXbox                      | `"Move Up"`
440   | string  | sMoveDownXbox                    | `"Move Down"`
441   | string  | sLookUpXbox                      | `"Look Up"`
442   | string  | sLookDownXbox                    | `"Look Down"`
443   | string  | sTurnLeftXbox                    | `"Turn Left"`
444   | string  | sTurnRightXbox                   | `"Turn Right"`
445   | string  | sNextWeaponXbox                  | `"Next Weapon"`
446   | string  | sPrevWeaponXbox                  | `"Previous Weapon"`
447   | string  | sNextSpellXbox                   | `"Next Spell"`
448   | string  | sPrevSpellXbox                   | `"Previous Spell"`
449   | string  | sDialogText1Xbox                 | `"PUSH"`
450   | string  | sDialogText2Xbox                 | `"TO GO BACK"`
451   | string  | sDialogText3Xbox                 | `"TO READ MORE"`
452   | string  | sQuick_Save                      | `"Quick-Save when Rest"`
453   | string  | sShadowText                      | `"Real-time Shadows"`
454   | string  | sLockSuccess                     | `"Lock pick success!"`
455   | string  | sLockFail                        | `"Lock pick failed."`
456   | string  | sLockImpossible                  | `"Lock too complex, your chance to pick it is zero"`
457   | string  | sTrapSuccess                     | `"Disarm trap success!"`
458   | string  | sTrapFail                        | `"Disarm trap failed."`
459   | string  | sTrapImpossible                  | `"Trap too complex, your chance to disarm it is zero"`
460   | string  | sTrapped                         | `"Trapped"`
461   | string  | sLockLevel                       | `"Lock Level"`
462   | string  | sKeyUsed                         | `"used to open lock."`
463   | string  | sUnlocked                        | `"Unlocked"`
464   | float   | fRepairMult                      | `1.0000`
465   | float   | fRepairAmountMult                | `0.5000`
466   | float   | fSpellValueMult                  | `10.0000`
467   | float   | fSpellMakingValueMult            | `1.0000`
468   | float   | fEnchantmentValueMult            | `1.0000`
469   | float   | fTravelMult                      | `200.0000`
470   | float   | fTravelTimeMult                  | `2667.0000`
471   | float   | fMagesGuildTravel                | `10.0000`
472   | string  | sBarter                          | `"Barter"`
473   | string  | sRepair                          | `"Repair"`
474   | string  | sSpells                          | `"Spells"`
475   | string  | sTraining                        | `"Training"`
476   | string  | sTravel                          | `"Travel"`
477   | string  | sSpellmaking                     | `"Spellmaking"`
478   | string  | sEnchanting                      | `"Enchanting"`
479   | string  | sJoystickNotFound                | `"Joystick not found."`
480   | string  | sJournalEntry                    | `"Your journal has been updated."`
481   | string  | sDay                             | `"Day"`
482   | string  | sCreate                          | `"Create"`
483   | string  | sIngredients                     | `"Ingredients"`
484   | string  | sApparatus                       | `"Apparatus"`
485   | string  | sCreatedEffects                  | `"Created Effects"`
486   | string  | sOnetypeEffectMessage            | `"This effect has already been added."`
487   | string  | sName                            | `"Name"`
488   | string  | sNameTitle                       | `"Name"`
489   | string  | sSelect                          | `"Select"`
490   | string  | sBuy                             | `"Buy"`
491   | string  | sInfo                            | `"Info"`
492   | string  | sMagicEffects                    | `"Magic Effects"`
493   | string  | sOnce                            | `"Once"`
494   | string  | sCostCharge                      | `"Cost/Charge"`
495   | string  | sCostChance                      | `"Cost/Chance"`
496   | string  | sAttributesMenu1                 | `"Choose an Attribute "`
497   | string  | sBirthsignmenu1                  | `"Abilities"`
498   | string  | sBirthsignmenu2                  | `"Spells"`
499   | string  | sChooseClassMenu1                | `"Specilization:"`
500   | string  | sChooseClassMenu2                | `"Favorite Attributes:"`
501   | string  | sChooseClassMenu3                | `"Major Skills:"`
502   | string  | sChooseClassMenu4                | `"Minor Skills:"`
503   | string  | sCreateClassMenuWarning          | `"Reselect your class?"`
504   | string  | sClassChoiceMenu1                | `"(1) Answer Questions (Generates Class)"`
505   | string  | sClassChoiceMenu2                | `"(2) Give him the info. (Pick from Class List)"`
506   | string  | sClassChoiceMenu3                | `"(3) Fill out yourself. (Create Custom Class)"`
507   | string  | sNotifyMessage1                  | `"You can't rest when in water or flying."`
508   | string  | sNotifyMessage2                  | `"You can't rest here enemies are nearby."`
509   | string  | sNotifyMessage3                  | `"You can't sleep when dreaming."`
510   | string  | sNotifyMessage4                  | `"Saving..."`
511   | string  | sNotifyMessage4XBOX              | `"Saving Game. Please don't turn off your Xbox console."`
512   | string  | sNotifyMessage5                  | `"You must place the object you are holding into a container before exiting menus."`
513   | string  | sNotifyMessage6                  | `"Only one of each ingredient can be used to make a potion."`
514   | string  | sNotifyMessage6a                 | `"At least two ingredients are needed to make a potion."`
515   | string  | sNotifyMessage7                  | `"Only eight ingredients can be used in a potion."`
516   | string  | sNotifyMessage8                  | `"Your potion failed."`
517   | string  | sNotifyMessage9                  | `"Your offer is refused."`
518   | string  | sNotifyMessage10                 | `"You have to type a name."`
519   | string  | sNotifyMessage11                 | `"You have to have an item to enchant."`
520   | string  | sNotifyMessage12                 | `"You don't have enough money to buy this spell."`
521   | string  | sNotifyMessage13                 | `"Beast races can not wear full helmets."`
522   | string  | sNotifyMessage14                 | `"Beast races can not wear boots."`
523   | string  | sNotifyMessage15                 | `"Beast races can not wear shoes."`
524   | string  | sNotifyMessage16                 | `"You can only wear one clothing item at a time."`
525   | string  | sNotifyMessage16_a               | `"You can only equip one item  of that type at a time."`
526   | string  | sNotifyMessage17                 | `"Can't raise the skill above the attribute."`
527   | string  | sNotifyMessage18                 | `"You don't have enough money to buy this spell."`
528   | string  | sNotifyMessage19                 | `"Only one apparatus can be placed in each slot of the alchemy menu."`
529   | string  | sNotifyMessage20                 | `"Please remove the object already in the morter and pestal slot."`
530   | string  | sNotifyMessage21                 | `"Please remove the object already in the alembic slot."`
531   | string  | sNotifyMessage22                 | `"Please remove the object already in the calcinator slot."`
532   | string  | sNotifyMessage23                 | `"Please remove the object already in the retort slot."`
533   | string  | sNotifyMessage24                 | `"You need to assign all the major and minor skill slots."`
534   | string  | sNotifyMessage25                 | `"You need to pick two favorite attributes."`
535   | string  | sNotifyMessage26                 | `"You need to pick a specilization."`
536   | string  | sNotifyMessage27                 | `"You need to assign all the major and minor skill slots."`
537   | string  | sNotifyMessage28                 | `"You can only add eight effects to a spell."`
538   | string  | sNotifyMessage29                 | `"You can not add more enchantment to an object then it can hold."`
539   | string  | sNotifyMessage30                 | `"You have to add at least one effect to a spell."`
540   | string  | sNotifyMessage31                 | `"Items already enchanted can not have another enchanment added."`
541   | string  | sNotifyMessage32                 | `"Only soul gems with a soul can be put in the soulgem slot."`
542   | string  | sNotifyMessage33                 | `"Only soul gems  put in the soulgem slot."`
543   | string  | sNotifyMessage34                 | `"The enchantment failed and your object is distroyed."`
544   | string  | sNotifyMessage35                 | `"Only one item of this type can be equipped at a time."`
545   | string  | sNotifyMessage36                 | `"You have to distribute all you points before exiting the levelup menu."`
546   | string  | sNotifyMessage37                 | `"You need to type in a name."`
547   | string  | sNotifyMessage38                 | `"Skill Increase:"`
548   | string  | sNotifyMessage39                 | `"\nYour %s skill increased to %d."`
549   | string  | sNotifyMessage40                 | `"Skill Maximum Reached."`
550   | string  | sNotifyMessage41                 | `"Your %s skill has reached the limit of your %s.\n"`
551   | string  | sNotifyMessage42                 | `"You have been released after %d day.\r\nA skill has been effected by your time in prison.\n "`
552   | string  | sNotifyMessage43                 | `"You have been released after %d days.\r\nYour skills have been effected by your time in prison.\n "`
553   | string  | sNotifyMessage44                 | `"\nYour %s skill decreased to %d."`
554   | string  | sNotifyMessage45                 | `"You need a Mortar and Pestle to use"`
555   | string  | sNotifyMessage46                 | `"You need a Alembic to use"`
556   | string  | sNotifyMessage47                 | `"You need a Calcinator to use"`
557   | string  | sNotifyMessage48                 | `"You need a Retort to use"`
558   | string  | sNotifyMessage49                 | `"That %s is mine."`
559   | string  | sNotifyMessage50                 | `"%s has no effect on you."`
560   | string  | sNotifyMessage51                 | `"The %s has been used up and disappears."`
561   | string  | sNotifyMessage52                 | `"You must have a soulgem with a soul to make an Enchanted Item"`
562   | string  | sNotifyMessage53                 | `"Your menu sizes and positions have been saved for exploring mode."`
563   | string  | sNotifyMessage54                 | `"Do you want to start a new game and lose your current game?"`
564   | string  | sNotifyMessage55                 | `"Please reconnect the controller and press START to continue."`
565   | string  | sNotifyMessage56                 | `"The disc you are using may be dirty or damaged.\nPress A to continue."`
566   | string  | sNotifyMessage57                 | `"Please press START to begin."`
567   | string  | sNotifyMessage58                 | `"Your Xbox Hard Disk doesn't have enough free blocks to save games. \nPress A to continue without saving \nor B to free more blocks."`
568   | string  | sNotifyMessage59                 | `"You are over-encumbered."`
569   | string  | sNotifyMessage60                 | `"%s has been added to your inventory."`
570   | string  | sNotifyMessage61                 | `"%d %s has been added to your inventory."`
571   | string  | sNotifyMessage62                 | `"%s has been removed from your inventory."`
572   | string  | sNotifyMessage63                 | `"%d %s has been removed from your inventory."`
573   | string  | sNotifyMessage64                 | `"You can't sleep in someone else's bed!"`
574   | string  | sNotifyMessage65                 | `"You can't save a game with no name!"`
575   | string  | sNotifyMessage66                 | `"This will reset all controls to the default settings.  Do you wish to continue?"`
576   | string  | sNotifyMessage67                 | `"This will immediately change your resolution.  Do you want to continue?"`
577   | string  | sTeleportDisabled                | `"Teleportation magic does not work here."`
578   | string  | sLevitateDisabled                | `"Levitation magic does not work here."`
579   | string  | sInPrisonTitle                   | `"Serving time..."`
580   | string  | sInfoRefusal                     | `"Info Refusal"`
581   | string  | sAdmireSuccess                   | `"Admire Success"`
582   | string  | sAdmireFail                      | `"Admire Fail"`
583   | string  | sIntimidateSuccess               | `"Intimidate Success"`
584   | string  | sIntimidateFail                  | `"Intimidate Fail"`
585   | string  | sTauntSuccess                    | `"Taunt Success"`
586   | string  | sTauntFail                       | `"Taunt Fail"`
587   | string  | sServiceRefusal                  | `"Service Refusal"`
588   | string  | sBribeSuccess                    | `"Bribe Success"`
589   | string  | sBribeFail                       | `"Bribe Fail"`
590   | string  | sWerewolfRefusal                 | `"You cannot do this as a werewolf."`
591   | string  | sWerewolfPopup                   | `"Werewolf"`
592   | string  | sWerewolfRestMessage             | `"You cannot rest in werewolf form."`
593   | string  | sWerewolfAlarmMessage            | `"You have been detected changing from a werewolf state."`
594   | string  | sBookSkillMessage                | `"You have gained knowledge from this book."`
595   | string  | sLoadingMessage1                 | `"Loading Master/Plugin Files"`
596   | string  | sLoadingMessage2                 | `"Loading Interior"`
597   | string  | sLoadingMessage3                 | `"Loading Exterior"`
598   | string  | sLoadingMessage4                 | `"Initializing Loaded Data..."`
599   | string  | sLoadingMessage5                 | `"Parsing Quests..."`
600   | string  | sLoadingMessage9                 | `"Clearing Altered Data..."`
601   | string  | sLoadingMessage14                | `"Loading Save Game (%s)"`
602   | string  | sLoadingMessage15                | `"Loading File (%s)"`
603   | string  | sInvalidSaveGameMsg              | `"This file is an invalid Save Game."`
604   | string  | sInvalidSaveGameMsgXBOX          | `"Unable to load saved game. Press A to continue."`
605   | string  | sLoadingErrorsMsg                | `"Errors were encountered loading from file '%s'."`
606   | string  | sMissingMastersMsg               | `"The currently selected master files and plugins do not match the ones used by this save game. Errors may occur during load or game play.\nDo you wish to continue?"`
607   | string  | sChangedMastersMsg               | `"The selected master files and plugins may have changed since this save game was created. Errors may occur during load or game play.\nDo you wish to continue?"`
608   | string  | sMastPlugMismatchMsg             | `"One of the files that "%s" is dependent on has changed since the last save.\r\nThis may result in errors. Saving again will clear this message\r\nbut not necessarily fix any errors.\r\n"`
609   | string  | sGeneralMastPlugMismatchMsg      | `"One or more plugins could not find the correct versions of the master files they depend on. Errors may occur during load or game play. Check the "Warnings.txt" file for more information."`
610   | string  | sLoadLastSaveMsg                 | `"The most recent Save Game is '%s'. \nWould you like to load it?"`
611   | string  | sMessage1                        | `"Do you want to Load a save game and lose your current game?"`
612   | string  | sMessage2                        | `"Quit Morrowind?"`
613   | string  | sMessage3                        | `"Are you sure you want to delete this Save Game?"`
614   | string  | sMessage4                        | `"Are you sure you want to overwrite this Save Game?"`
615   | string  | sMessage5                        | `"Do you wish to quit your current game? \nAll unsaved progress will be lost."`
616   | string  | sMessageQuestionAnswer1          | `"Your personality and past reflect that of a:"`
617   | string  | sMessageQuestionAnswer2          | `"Accept this Class"`
618   | string  | sMessageQuestionAnswer3          | `"Choose Another Class"`
619   | string  | sBarterDialog1                   | `"You can not afford this transaction."`
620   | string  | sBarterDialog2                   | `"I can not afford this transaction."`
621   | string  | sBarterDialog3                   | `"This is to heavy for you to carry.	"`
622   | string  | sBarterDialog4                   | `"I don't buy that item."`
623   | string  | sBarterDialog5                   | `"Thank you, Please Come Again."`
624   | string  | sBarterDialog6                   | `"You need to place the bartered item before existing Barter Menu!"`
625   | string  | sBarterDialog7                   | `"Price"`
626   | string  | sBarterDialog8                   | `"Offer"`
627   | string  | sBarterDialog9                   | `"You can not sell summoned items!"`
628   | string  | sBarterDialog10                  | `"You can't buy summoned items!"`
629   | string  | sBarterDialog11                  | `"You need to trade items before making an offer."`
630   | string  | sBarterDialog12                  | `"You can not drop summoned items!"`
631   | string  | sInventoryMessage1               | `"You can not equip objects whose health is less then one!"`
632   | string  | sInventoryMessage2               | `"You can not repair items duing battle!"`
633   | string  | sInventoryMessage3               | `"You can not make potions during battle!"`
634   | string  | sInventoryMessage4               | `"You can not read duing battle!"`
635   | string  | sInventoryMessage5               | `"You can not use soul gems duing battle!"`
636   | string  | sContentsMessage1                | `"You can't remove summoned items from their container."`
637   | string  | sContentsMessage2                | `"You can't store objects in organic containers."`
638   | string  | sContentsMessage3                | `"This container can not hold that item."`
639   | string  | sAttributeListTitle              | `"Attribute List"`
640   | string  | sConsoleTitle                    | `"Console"`
641   | string  | sCreateClassMenu1                | `"Class Description"`
642   | string  | sCreateClassMenu2                | `"Close the Description menu before leaving Class Creation"`
643   | string  | sCreateClassMenu3                | `"The class needs a description."`
644   | string  | sCreateClassMenuHelp1            | `"You'll get +5 to all skills of your specialization. They'll also be easier to increase."`
645   | string  | sCreateClassMenuHelp2            | `"You'll get +10 to each of your favored attributes."`
646   | string  | sControlsMenu1                   | `"Reset Controls"`
647   | string  | sControlsMenu2                   | `"Mouse Sensitivity"`
648   | string  | sControlsMenu3                   | `"Press a key or push a button to set this command."`
649   | string  | sControlsMenu4                   | `"Vertical Sensitivity"`
650   | string  | sControlsMenu5                   | `"Horizontal Sensitivity"`
651   | string  | sControlsMenu6                   | `"Push a button to set this command."`
652   | string  | sGameWithoutLauncherXbox         | `"The game was started without the launcher.  Press START to continue."`
653   | string  | sDialogMenu1                     | `"Final Disposition: "`
654   | string  | sEnchantmentMenu1                | `"Enchantment Menu"`
655   | string  | sEnchantmentMenu2                | `"Name"`
656   | string  | sEnchantmentMenu3                | `"Enchantment"`
657   | string  | sEnchantmentMenu4                | `"Point Cost"`
658   | string  | sEnchantmentMenu5                | `"Buy"`
659   | string  | sEnchantmentMenu6                | `"Chance"`
660   | string  | sEnchantmentMenu7                | `"Please remove the current soulgem before placing a different soulgem."`
661   | string  | sEnchantmentMenu8                | `"You can't buy a spell that has a zero point cost."`
662   | string  | sEnchantmentMenu9                | `"You can not enchant more then one item of that type at a time."`
663   | string  | sEnchantmentMenu10               | `"The cast cost can not exceed the charge amount put into the time"`
664   | string  | sEnchantmentMenu11               | `"You must add at least one effect to an enchantment"`
665   | string  | sEnchantmentMenu12               | `"You have successfully created an enchanted item"`
666   | string  | sEnchantmentHelp1                | `"Slot for item to enchant. Only weapons, armor, scrolls and clothing that are not already enchanted can be enchanted."`
667   | string  | sEnchantmentHelp2                | `"Slot for the soul gem used to enchant an item. Only soul gems filled with a soul can be used. The soul amount is the total charge placed into the item."`
668   | string  | sEnchantmentHelp3                | `"The first number is the total amount the enchantment would cost to cast. The second number is the total enchantment cost that can be placed on this type of item."`
669   | string  | sEnchantmentHelp4                | `"The amount of charge points needed each time this enchantment is cast. This number is modified by your enchant skill."`
670   | string  | sEnchantmentHelp5                | `"The amount of soul in the soulgem in the soulgem slot"`
671   | string  | sEnchantmentHelp6                | `"Amount of gold to buy this enchantment"`
672   | string  | sEnchantmentHelp7                | `"Type of cast for the enchantment."`
673   | string  | sEnchantmentHelp8                | `"Name you give the spell."`
674   | string  | sEnchantmentHelp9                | `"Magic effects you know that you can add to an item"`
675   | string  | sEnchantmentHelp10               | `"Current effects on the item"`
676   | string  | sInputMenu1                      | `"Enter"`
677   | string  | sInventoryMenu1                  | `"You can't equip items being bartered!"`
678   | string  | sLevelUpMenu1                    | `"You have ascended to Level "`
679   | string  | sLevelUpMenu2                    | `"It's all suddenly obvious to you. You just have to concentrate. All the energy and time you've wasted it's a sin but without the experience you've gained, taking risks, taking responsibility for failure how could you have understood?"`
680   | string  | sLevelUpMenu3                    | `"x2"`
681   | string  | sLevelUpMenu4                    | `"x3"`
682   | string  | sLevelUpMsg                      | `"Your are ready for your next Level Up!"`
683   | string  | sLevelUp                         | `"Level Up"`
684   | string  | sRange                           | `"Range"`
685   | string  | sArea                            | `"Area"`
686   | string  | sMagnitude                       | `"Magnitude"`
687   | string  | sDuration                        | `"Duration"`
688   | string  | sDrain                           | `"Drain"`
689   | string  | sAbsorb                          | `"Absorb"`
690   | string  | sFortify                         | `"Fortify"`
691   | string  | sRestore                         | `"Restore"`
692   | string  | sDamage                          | `"Damage"`
693   | string  | spoint                           | `"point"`
694   | string  | spoints                          | `"points"`
695   | string  | spercent                         | `"percent"`
696   | string  | sfor                             | `"for"`
697   | string  | ssecond                          | `"second"`
698   | string  | sseconds                         | `"seconds"`
699   | string  | sin                              | `"in"`
700   | string  | sfootarea                        | `"foot"`
701   | string  | sfeet                            | `"feet"`
702   | string  | sXTimes                          | `"x"`
703   | string  | sXTimesINT                       | `"x INT"`
704   | string  | sonword                          | `"on"`
705   | string  | sNone                            | `"None"`
706   | string  | sDone                            | `"Done"`
707   | string  | sStartCell                       | `"Imperial Prison Ship"`
708   | string  | sStartError                      | `"Cannot start in an empty interior cell!"`
709   | string  | sStartCellError                  | `"Starting interior cell "Imperial Prison Ship" not found!"`
710   | string  | sAdmire                          | `"Admire"`
711   | string  | sIntimidate                      | `"Intimidate"`
712   | string  | sTaunt                           | `"Taunt"`
713   | string  | sBribe 10 Gold                   | `"Bribe 10 Gold"`
714   | string  | sBribe 100 Gold                  | `"Bribe 100 Gold"`
715   | string  | sBribe 1000 Gold                 | `"Bribe 1000 Gold"`
716   | string  | sPersuasionMenuTitle             | `"Persuasion Menu"`
717   | string  | sFast                            | `"Fast"`
718   | string  | sSlow                            | `"Slow"`
719   | string  | sBestAttack                      | `"Always Use Best Attack"`
720   | string  | sSubtitles                       | `"Subtitles"`
721   | string  | sMouseFlip                       | `"Mouse Flip Y"`
722   | string  | sCursorOff                       | `"Cursor Off"`
723   | string  | sEnableJoystick                  | `"Enable Joystick"`
724   | string  | sXStrafe                         | `"X-Axis Movement"`
725   | string  | sStrafe                          | `"Strafe"`
726   | string  | sTurn                            | `"Turn"`
727   | string  | sMouseWheelUpShort               | `"MWheel Up"`
728   | string  | sMouseWheelDownShort             | `"MWheel Down"`
729   | string  | sMouse                           | `"Mouse"`
730   | string  | sJoystickShort                   | `"Joy"`
731   | string  | sJoystickHatShort                | `"JHat"`
732   | string  | sPickUp                          | `"Pick Up"`
733   | string  | sItemName                        | `"Item Name"`
734   | string  | sNoName                          | `"NO NAME GIVEN!"`
735   | string  | sItem                            | `"Item"`
736   | string  | sRaceMenu1                       | `"Appearance"`
737   | string  | sRaceMenu2                       | `"Change Sex"`
738   | string  | sRaceMenu3                       | `"Change Face"`
739   | string  | sRaceMenu4                       | `"Change Hair"`
740   | string  | sRaceMenu5                       | `"Select Race"`
741   | string  | sRaceMenu6                       | `"Race Description"`
742   | string  | sRaceMenu7                       | `"Specials"`
743   | string  | sRestMenu1                       | `"How many hours ?"`
744   | string  | sRestMenu2                       | `"Hours"`
745   | string  | sRestMenu3                       | `"REST"`
746   | string  | sRestMenu4                       | `"You can't rest right now."`
747   | float   | fRestMagicMult                   | `0.0500`
748   | string  | sSaveMenu1                       | `"NewSaveGame"`
749   | string  | sServiceRepairTitle              | `"Repair Service Menu"`
750   | string  | sServiceTravelTitle              | `"Travel Service Menu"`
751   | string  | sServiceTrainingTitle            | `"Training Service Menu"`
752   | string  | sServiceTrainingWords            | `"I can teach nothing more about that skill"`
753   | string  | sServiceSpellsTitle              | `"Spells Service Menu"`
754   | string  | sSkillsMenu1                     | `"Choose a Skill"`
755   | string  | sBonusSkillTitle                 | `"Bonus Skills"`
756   | string  | sSpecializationMenu1             | `"Choose a Specialization"`
757   | string  | sSpellmakingMenuTitle            | `"SpellMaking Menu"`
758   | string  | sSpellmakingMenu1                | `"Spell Chance"`
759   | string  | sSpellmakingHelp1                | `"Name you give the spell."`
760   | string  | sSpellmakingHelp2                | `"Amount of Magika one cast of the spell will cost"`
761   | string  | sSpellmakingHelp3                | `"The chance you have to cast the spell at your current skill level"`
762   | string  | sSpellmakingHelp4                | `"How much gold the spell will cost you."`
763   | string  | sSpellmakingHelp5                | `"Magic effects you know that you can add to a spell"`
764   | string  | sSpellmakingHelp6                | `"Current effects on the spell"`
765   | string  | sKilledEssential                 | `"Oh no you've killed somebody important!"`
766   | string  | sCrimeMessage                    | `"Your crime has been reported!"`
767   | string  | sPotionSuccess                   | `"You created a potion"`
768   | string  | sMagicItem                       | `"Magic Item(s)"`
769   | string  | sMagnitudeDes                    | `"The range  of a spells power"`
770   | string  | sAreaDes                         | `"The radius the spell attempt to affect"`
771   | string  | sDurationDes                     | `"The length a spell lasts"`
772   | string  | sRangeDes                        | `"What the spell is directed at such as yourself, a target or who you touch"`
773   | string  | sCrimeHelp                       | `"The penalty you must pay for your crimes, if caught."`
774   | string  | sSoulGem                         | `"Soul"`
775   | string  | sCastCost                        | `"Cast Cost"`
776   | string  | sTravelServiceTitle              | `"Click on Place name to travel"`
777   | string  | sSpellServiceTitle               | `"Click on Spell name to buy Spell"`
778   | string  | sRepairServiceTitle              | `"Click on item name to repair"`
779   | string  | sTrainingServiceTitle            | `"Click on skill to train"`
780   | string  | sMortar                          | `"Mortar"`
781   | string  | sCalcinator                      | `"Calcinator"`
782   | string  | sAlembic                         | `"Alembic"`
783   | string  | sRetort                          | `"Retort"`
784   | string  | sQuestionMark                    | `"?"`
785   | string  | s3dAudio                         | `"3D Audio"`
786   | string  | s3dHardware                      | `"Hardware Accelerated"`
787   | string  | s3dSoftware                      | `"Software Mode"`
788   | string  | sYourGold                        | `"YOUR GOLD"`
789   | string  | sSellerGold                      | `"SELLER GOLD"`
790   | string  | sMaxSale                         | `"Max Sale"`
791   | string  | sTotalCost                       | `"TOTAL COST"`
792   | string  | sTotalSold                       | `"TOTAL SOLD"`
793   | string  | sOffer                           | `"Offer"`
794   | string  | sLess                            | `"Less"`
795   | string  | sMore                            | `"More"`
796   | string  | sInventory                       | `"Inventory"`
797   | string  | sBookPageOne                     | `"1"`
798   | string  | sBookPageTwo                     | `"2"`
799   | string  | sDisposeofCorpse                 | `"Dispose of Corpse"`
800   | string  | sCaughtStealingMessage           | `"Hey he stealing my stuff!"`
801   | string  | sUserDefinedClass                | `"User Defined Class"`
802   | string  | sAsk                             | `"Ask"`
803   | string  | sEnchantItems                    | `"Items to Enchant"`
804   | string  | sSoulGemsWithSouls               | `"SoulGems with Souls"`
805   | string  | sDoYouWantTo                     | `"Do you want to "`
806   | string  | sRechargeEnchantment             | `"Recharge Enchanted Item "`
807   | string  | sMake Enchantment                | `"Make an Enchanted Item "`
808   | string  | sSell                            | `"Sell"`
809   | string  | sEquip                           | `"Equip"`
810   | string  | sDrop                            | `"Drop"`
811   | string  | sContainer                       | `"Container "`
812   | string  | sStats                           | `"Stats "`
813   | string  | sMap                             | `"Map "`
814   | string  | sCenter                          | `"Center "`
815   | string  | sSaveMenuHelp01                  | `"th of"`
816   | string  | sSaveMenuHelp02                  | `"month"`
817   | string  | sSaveMenuHelp03                  | `"day"`
818   | string  | sSaveMenuHelp04                  | `"a.m."`
819   | string  | sSaveMenuHelp05                  | `"p.m."`
820   | string  | sSaveMenuHelp06                  | `"Delete Game?"`
821   | string  | sDeleteNote                      | `"Delete Note?"`
822   | string  | sEditNote                        | `"Edit Note"`
823   | string  | sBlocks                          | `"Blocks"`
824   | string  | sFileSize                        | `"File Size"`
825   | string  | sSave                            | `"Save"`
826   | string  | sDeleteSpell                     | `"Delete Spell"`
827   | string  | sQuestionDeleteSpell             | `"Are you sure you wish to delete %s?"`
828   | string  | sDeleteSpellError                | `"You can not delete this item from the Magic Menu"`
829   | string  | sLocal                           | `"Local"`
830   | string  | sLoadFailedMessage               | `"Your last load failed. You must load another game or start a new game."`
831   | string  | sShadows                         | `"Shadows"`
832   | string  | sControlerVibration              | `"Controller Vibration"`
833   | string  | sQuanityMenuMessage01            | `"Amount to Sell"`
834   | string  | sQuanityMenuMessage02            | `"Amount to Buy"`
835   | string  | sSex                             | `"Sex"`
836   | string  | sHair                            | `"Hair"`
837   | string  | sFace                            | `"Face"`
838   | string  | sRepairFailed                    | `"Your repair failed!"`
839   | string  | sRepairSuccess                   | `"Your repair succeeded!"`
840   | string  | sHeal                            | `"Heal"`
841   | string  | sgp                              | `"gp"`
842   | string  | sSetValueMessage01               | `"The maximum magnitude can not be less then the minimum magnitude!"`
843   | string  | sDelete                          | `"Delete"`
844   | string  | sVideoWarning                    | `"MenuVideo Warning Video Resolution does not allow shadows."`
845   | string  | sResChangeWarning                | `"Desired resolution not supported by video card."`
846   | string  | sShift                           | `"Shift"`
847   | string  | sBackspace                       | `"Backspace"`
848   | string  | sCustomClassName                 | `"Custom Class"`
849   | string  | sSpace                           | `"Space"`
850   | string  | sInventorySelectNoItems          | `"You have no items to fill this slot."`
851   | string  | sInventorySelectNoSoul           | `"You have no filled Soul Gems"`
852   | string  | sInventorySelectNoIngredients    | `"You have no ingredients"`
853   | string  | sDisposeCorpseFail               | `"You can not remove this corpse"`
854   | string  | sQuickMenuTitle                  | `"QUICK KEY MENU"`
855   | string  | sQuickMenuInstruc                | `"Click on quick key slot to add a spell, magic item or inventory item"`
856   | string  | sQuickMenu1                      | `"MenuItem to QuickKey"`
857   | string  | sQuickMenu2                      | `"Inventory Menu Item"`
858   | string  | sQuickMenu3                      | `"Magic Menu Item"`
859   | string  | sQuickMenu4                      | `"Delete QuickKey Item"`
860   | string  | sQuickMenu5                      | `"You no longer have"`
861   | string  | sQuickMenu6                      | `"Inventory Items to Quick key"`
862   | string  | sMagicSelectTitle                | `"Select a magic to Quick key."`
863   | string  | sNextRank                        | `"Next Rank:"`
864   | string  | sNeedOneSkill                    | `"Need one skill at"`
865   | string  | sNeedTwoSkills                   | `"Need two skills at"`
866   | string  | sand                             | `"and"`
867   | string  | sOneHanded                       | `"One Handed"`
868   | string  | sTwoHanded                       | `"Two Handed"`
869   | string  | sType                            | `"Type:"`
870   | string  | sAt                              | `"At"`
871   | string  | sUnequip                         | `"Unequip"`
872   | string  | sScrolldown                      | `"Scroll Down"`
873   | string  | sScrollup                        | `"Scroll Up"`
874   | string  | sSleepInterrupt                  | `"Your rest has been intruppted"`
875   | string  | sSoultrapSuccess                 | `"Your have trapped a soul"`
876   | string  | sCantEquipWeapWarning            | `"Finish your current attack before equipping a new weapon"`
877   | string  | sOfferMenuTitle                  | `"Offer Menu"`
878   | string  | sPowers                          | `"Powers"`
879   | string  | sBreath                          | `"Breath"`
880   | string  | sDifficulty                      | `"Difficulty"`
881   | string  | sEasy                            | `"Easy"`
882   | string  | sHard                            | `"Hard"`
883   | string  | sProfitValue                     | `"Profit Value"`
884   | string  | sCompanionShare                  | `"Companion Share"`
885   | string  | sCompanionWarningMessage         | `"Your mercenary is poorer now than when he contracted with you.  Your mercenary will quit if you do not give him gold or goods to bring his Profit Value to a positive value."`
886   | string  | sCompanionWarningButtonOne       | `"Let the mercenary quit."`
887   | string  | sCompanionWarningButtonTwo       | `"Return to Companion Share display."`
888   | string  | sAttributeStrength               | `"sAttributeStrength"`
889   | string  | sAttributeIntelligence           | `"sAttributeIntelligence"`
890   | string  | sAttributeWillpower              | `"sAttributeWillpower"`
891   | string  | sAttributeAgility                | `"sAttributeAgility"`
892   | string  | sAttributeSpeed                  | `"sAttributeSpeed"`
893   | string  | sAttributeEndurance              | `"sAttributeEndurance"`
894   | string  | sAttributePersonality            | `"sAttributePersonality"`
895   | string  | sAttributeLuck                   | `"sAttributeLuck"`
896   | string  | sSkillBlock                      | `"Block"`
897   | string  | sSkillArmorer                    | `"Armorer"`
898   | string  | sSkillMediumarmor                | `"Mediumarmor"`
899   | string  | sSkillHeavyarmor                 | `"Heavyarmor"`
900   | string  | sSkillBluntweapon                | `"Bluntweapon"`
901   | string  | sSkillLongblade                  | `"Longblade"`
902   | string  | sSkillAxe                        | `"Axe"`
903   | string  | sSkillSpear                      | `"Spear"`
904   | string  | sSkillAthletics                  | `"Athletics"`
905   | string  | sSkillEnchant                    | `"Enchant"`
906   | string  | sSkillDestruction                | `"Destruction"`
907   | string  | sSkillAlteration                 | `"Alteration"`
908   | string  | sSkillIllusion                   | `"Illusion"`
909   | string  | sSkillConjuration                | `"Conjuration"`
910   | string  | sSkillMysticism                  | `"Mysticism"`
911   | string  | sSkillRestoration                | `"Restoration"`
912   | string  | sSkillAlchemy                    | `"Alchemy"`
913   | string  | sSkillUnarmored                  | `"Unarmored"`
914   | string  | sSkillSecurity                   | `"Security"`
915   | string  | sSkillSneak                      | `"Sneak"`
916   | string  | sSkillAcrobatics                 | `"Acrobatics"`
917   | string  | sSkillLightarmor                 | `"Lightarmor"`
918   | string  | sSkillShortblade                 | `"Shortblade"`
919   | string  | sSkillMarksman                   | `"Marksman"`
920   | string  | sSkillMercantile                 | `"Mercantile"`
921   | string  | sSkillSpeechcraft                | `"Speechcraft"`
922   | string  | sSkillHandtohand                 | `"Handtohand"`
923   | string  | sHealth                          | `"Health"`
924   | string  | sRace                            | `"Race"`
925   | string  | sLevel                           | `"Level"`
926   | string  | sLevels                          | `"Levels"`
927   | string  | sFaction                         | `"Faction"`
928   | string  | sBirthSign                       | `"Birth Sign"`
929   | string  | sBounty                          | `"Bounty"`
930   | string  | sReputation                      | `"Reputation"`
931   | string  | sSchool                          | `"School"`
932   | string  | sSkill                           | `"Skill"`
933   | string  | sSkillProgress                   | `"sSkillProgress"`
934   | string  | sSkillMaxReached                 | `"Maximum proficiency has been reached."`
935   | string  | sLevelProgress                   | `"sLevelProgress"`
936   | string  | sMagic                           | `"sMagic"`
937   | string  | sMagicMenu                       | `"Magic"`
938   | string  | sFatigue                         | `"sFatigue"`
939   | string  | sSkillsMenuReputationHelp        | `"Your fame rating in the world of Morrowind"`
940   | string  | sStrDesc                         | `"sStrDesc"`
941   | string  | sIntDesc                         | `"sIntDesc"`
942   | string  | sWilDesc                         | `"sWilDesc"`
943   | string  | sAgiDesc                         | `"sAgiDesc"`
944   | string  | sSpdDesc                         | `"sSpdDesc"`
945   | string  | sEndDesc                         | `"sEndDesc"`
946   | string  | sPerDesc                         | `"sPerDesc"`
947   | string  | sLucDesc                         | `"sLucDesc"`
948   | string  | sFatDesc                         | `"sFatDesc"`
949   | string  | sHealthDesc                      | `"sHealthDesc"`
950   | string  | sMagDesc                         | `"sMagDesc"`
951   | float   | fWortChanceValue                 | `15.0000`
952   | string  | sDefaultCellname                 | `"Wilderness"`
953   | float   | fMinWalkSpeed                    | `150.0000`
954   | float   | fMaxWalkSpeed                    | `300.0000`
955   | float   | fMinWalkSpeedCreature            | `5.0000`
956   | float   | fMaxWalkSpeedCreature            | `300.0000`
957   | float   | fEncumberedMoveEffect            | `0.7500`
958   | float   | fBaseRunMultiplier               | `1.5000`
959   | float   | fAthleticsRunBonus               | `1.5000`
960   | float   | fJumpAcrobaticsBase              | `128.0000`
961   | float   | fJumpAcroMultiplier              | `4.0000`
962   | float   | fJumpEncumbranceBase             | `0.5000`
963   | float   | fJumpEncumbranceMultiplier       | `1.0000`
964   | float   | fJumpRunMultiplier               | `1.2000`
965   | float   | fJumpMoveBase                    | `0.5000`
966   | float   | fJumpMoveMult                    | `0.5000`
967   | float   | fSwimWalkBase                    | `0.5000`
968   | float   | fSwimRunBase                     | `0.5000`
969   | float   | fSwimWalkAthleticsMult           | `0.0200`
970   | float   | fSwimRunAthleticsMult            | `0.1000`
971   | float   | fSwimHeightScale                 | `0.9000`
972   | float   | fHoldBreathTime                  | `20.0000`
973   | float   | fHoldBreathEndMult               | `0.5000`
974   | float   | fSuffocationDamage               | `3.0000`
975   | float   | fMinFlySpeed                     | `5.0000`
976   | float   | fMaxFlySpeed                     | `300.0000`
977   | float   | fStromWindSpeed                  | `0.7000`
978   | float   | fStromWalkMult                   | `0.2000`
979   | float   | fFallDamageDistanceMin           | `300.0000`
980   | float   | fFallDistanceBase                | `0.0000`
981   | float   | fFallDistanceMult                | `0.1000`
982   | float   | fFallAcroBase                    | `0.2500`
983   | float   | fFallAcroMult                    | `0.0100`
984   | integer | iMaxActivateDist                 | `128`
985   | integer | iMaxInfoDist                     | `128`
986   | float   | fVanityDelay                     | `30.0000`
987   | float   | fMaxHeadTrackDistance            | `400.0000`
988   | float   | fInteriorHeadTrackMult           | `0.5000`
989   | integer | iHelmWeight                      | `5`
990   | integer | iPauldronWeight                  | `10`
991   | integer | iCuirassWeight                   | `30`
992   | integer | iGauntletWeight                  | `5`
993   | integer | iGreavesWeight                   | `15`
994   | integer | iBootsWeight                     | `20`
995   | integer | iShieldWeight                    | `15`
996   | float   | fLightMaxMod                     | `0.6000`
997   | float   | fMedMaxMod                       | `0.9000`
998   | float   | fUnarmoredBase1                  | `0.0500`
999   | float   | fUnarmoredBase2                  | `0.1000`
1000  | integer | iBaseArmorSkill                  | `30`
1001  | float   | fBlockStillBonus                 | `1.2500`
1002  | float   | fDamageStrengthBase              | `0.5000`
1003  | float   | fDamageStrengthMult              | `0.1000`
1004  | float   | fSwingBlockBase                  | `0.5000`
1005  | float   | fSwingBlockMult                  | `0.5000`
1006  | float   | fFatigueBase                     | `1.0000`
1007  | float   | fFatigueMult                     | `1.0000`
1008  | float   | fFatigueReturnBase               | `1.5000`
1009  | float   | fFatigueReturnMult               | `1.0000`
1010  | float   | fEndFatigueMult                  | `0.0100`
1011  | float   | fFatigueAttackBase               | `1.0000`
1012  | float   | fFatigueAttackMult               | `1.0000`
1013  | float   | fWeaponFatigueMult               | `0.2000`
1014  | float   | fFatigueBlockBase                | `1.0000`
1015  | float   | fFatigueBlockMult                | `1.0000`
1016  | float   | fWeaponFatigueBlockMult          | `0.2000`
1017  | float   | fFatigueRunBase                  | `1.5000`
1018  | float   | fFatigueRunMult                  | `1.5000`
1019  | float   | fFatigueJumpBase                 | `3.0000`
1020  | float   | fFatigueJumpMult                 | `10.0000`
1021  | float   | fFatigueSwimWalkBase             | `0.5000`
1022  | float   | fFatigueSwimRunBase              | `1.5000`
1023  | float   | fFatigueSwimWalkMult             | `0.5000`
1024  | float   | fFatigueSwimRunMult              | `1.5000`
1025  | float   | fFatigueSneakBase                | `1.5000`
1026  | float   | fFatigueSneakMult                | `1.5000`
1027  | float   | fMinHandToHandMult               | `0.5000`
1028  | float   | fMaxHandToHandMult               | `1.0000`
1029  | float   | fHandtoHandHealthPer             | `0.1000`
1030  | float   | fCombatInvisoMult                | `0.2000`
1031  | float   | fCombatKODamageMult              | `2.0000`
1032  | float   | fCombatCriticalStrikeMult        | `4.0000`
1033  | integer | iBlockMinChance                  | `5`
1034  | integer | iBlockMaxChance                  | `50`
1035  | float   | fLevelUpHealthEndMult            | `0.1000`
1036  | float   | fSoulGemMult                     | `3.0000`
1037  | float   | fEffectCostMult                  | `0.5000`
1038  | float   | fSpellPriceMult                  | `1.0000`
1039  | float   | fFatigueSpellBase                | `1.0000`
1040  | float   | fFatigueSpellMult                | `1.0000`
1041  | float   | fFatigueSpellCostMult            | `1.0000`
1042  | float   | fPotionStrengthMult              | `0.5000`
1043  | float   | fPotionT1MagMult                 | `3.0000`
1044  | float   | fPotionT1DurMult                 | `2.0000`
1045  | float   | fPotionMinUsefulDuration         | `20.0000`
1046  | float   | fPotionT4BaseStrengthMult        | `20.0000`
1047  | float   | fPotionT4EquipStrengthMult       | `12.0000`
1048  | float   | fIngredientMult                  | `1.0000`
1049  | float   | fMagicItemCostMult               | `1.0000`
1050  | float   | fMagicItemPriceMult              | `1.0000`
1051  | float   | fMagicItemOnceMult               | `1.0000`
1052  | float   | fMagicItemUsedMult               | `1.0000`
1053  | float   | fMagicItemStrikeMult             | `1.0000`
1054  | float   | fMagicItemConstantMult           | `1.0000`
1055  | float   | fEnchantmentMult                 | `1.0000`
1056  | float   | fEnchantmentChanceMult           | `3.0000`
1057  | float   | fPCbaseMagickaMult               | `1.0000`
1058  | float   | fNPCbaseMagickaMult              | `2.0000`
1059  | float   | fAutoSpellChance                 | `50.0000`
1060  | float   | fAutoPCSpellChance               | `75.0000`
1061  | integer | iAutoSpellTimesCanCast           | `3`
1062  | integer | iAutoSpellAttSkillMin            | `70`
1063  | integer | iAutoSpellAlterationMax          | `5`
1064  | integer | iAutoSpellConjurationMax         | `5`
1065  | integer | iAutoSpellDestructionMax         | `5`
1066  | integer | iAutoSpellIllusionMax            | `5`
1067  | integer | iAutoSpellMysticismMax           | `5`
1068  | integer | iAutoSpellRestorationMax         | `5`
1069  | integer | iAutoPCSpellMax                  | `100`
1070  | integer | iAutoRepFacMod                   | `2`
1071  | integer | iAutoRepLevMod                   | `0`
1072  | integer | iMagicItemChargeOnce             | `1`
1073  | integer | iMagicItemChargeConst            | `10`
1074  | integer | iMagicItemChargeUse              | `5`
1075  | integer | iMagicItemChargeStrike           | `10`
1076  | integer | iMonthsToRespawn                 | `4`
1077  | float   | fCorpseClearDelay                | `6.0000`
1078  | float   | fCorpseRespawnDelay              | `6.0000`
1079  | float   | fBarterGoldResetDelay            | `24.0000`
1080  | float   | fEncumbranceStrMult              | `5.0000`
1081  | float   | fPickLockMult                    | `-10.0000`
1082  | float   | fTrapCostMult                    | `-0.5000`
1083  | float   | fMessageTimePerChar              | `0.1000`
1084  | float   | fMagicItemRechargePerSecond      | `0.0028`
1085  | integer | i1stPersonSneakDelta             | `10`
1086  | integer | iBarterSuccessDisposition        | `1`
1087  | integer | iBarterFailDisposition           | `-1`
1088  | integer | iLevelupTotal                    | `10`
1089  | integer | iLevelupMajorMult                | `2`
1090  | integer | iLevelupMinorMult                | `1`
1091  | integer | iLevelupMajorMultAttribute       | `1`
1092  | integer | iLevelupMinorMultAttribute       | `1`
1093  | integer | iLevelupMiscMultAttriubte        | `1`
1094  | integer | iLevelupSpecialization           | `1`
1095  | integer | iLevelUp01Mult                   | `1`
1096  | integer | iLevelUp02Mult                   | `2`
1097  | integer | iLevelUp03Mult                   | `3`
1098  | integer | iLevelUp04Mult                   | `4`
1099  | integer | iLevelUp05Mult                   | `5`
1100  | integer | iLevelUp06Mult                   | `6`
1101  | integer | iLevelUp07Mult                   | `7`
1102  | integer | iLevelUp08Mult                   | `8`
1103  | integer | iLevelUp09Mult                   | `9`
1104  | integer | iLevelUp10Mult                   | `10`
1105  | integer | iSoulAmountForConstantEffect     | `400`
1106  | float   | fConstantEffectMult              | `15.0000`
1107  | float   | fEnchantmentConstantDurationMult | `100.0000`
1108  | float   | fEnchantmentConstantChanceMult   | `0.5000`
1109  | float   | fWeaponDamageMult                | `0.1000`
1110  | float   | fSeriousWoundMult                | `0.2500`
1111  | float   | fKnockDownMult                   | `0.5000`
1112  | integer | iKnockDownOddsBase               | `25`
1113  | integer | iKnockDownOddsMult               | `25`
1114  | float   | fCombatArmorMinMult              | `0.2500`
1115  | float   | fHandToHandReach                 | `0.7000`
1116  | float   | fVoiceIdleOdds                   | `100.0000`
1117  | integer | iVoiceAttackOdds                 | `30`
1118  | integer | iVoiceHitOdds                    | `30`
1119  | float   | fProjectileMinSpeed              | `400.0000`
1120  | float   | fProjectileMaxSpeed              | `1000.0000`
1121  | float   | fThrownWeaponMinSpeed            | `100.0000`
1122  | float   | fThrownWeaponMaxSpeed            | `500.0000`
1123  | float   | fTargetSpellMaxSpeed             | `1000.0000`
1124  | float   | fProjectileThrownStoreChance     | `75.0000`
1125  | integer | iPickMinChance                   | `5`
1126  | integer | iPickMaxChance                   | `75`
1127  | float   | fDispRaceMod                     | `5.0000`
1128  | float   | fDispPersonalityMult             | `0.5000`
1129  | float   | fDispPersonalityBase             | `50.0000`
1130  | float   | fDispFactionMod                  | `5.0000`
1131  | float   | fDispFactionRankBase             | `0.5000`
1132  | float   | fDispFactionRankMult             | `0.5000`
1133  | float   | fDispCrimeMod                    | `0.0100`
1134  | float   | fDispDiseaseMod                  | `-10.0000`
1135  | integer | iDispAttackMod                   | `-20`
1136  | float   | fDispWeaponDrawn                 | `-5.0000`
1137  | float   | fDispBargainSuccessMod           | `1.0000`
1138  | float   | fDispBargainFailMod              | `-1.0000`
1139  | float   | fDispPickPocketMod               | `-25.0000`
1140  | integer | iDaysinPrisonMod                 | `100`
1141  | float   | fDispAttacking                   | `-10.0000`
1142  | float   | fDispStealing                    | `-0.1000`
1143  | integer | iDispTresspass                   | `-20`
1144  | integer | iDispKilling                     | `-50`
1145  | integer | iTrainingMod                     | `10`
1146  | integer | iAlchemyMod                      | `10`
1147  | float   | fBargainOfferBase                | `50.0000`
1148  | float   | fBargainOfferMulti               | `-4.0000`
1149  | float   | fDispositionMod                  | `1.0000`
1150  | float   | fPersonalityMod                  | `5.0000`
1151  | float   | fLuckMod                         | `10.0000`
1152  | float   | fReputationMod                   | `1.0000`
1153  | float   | fLevelMod                        | `5.0000`
1154  | float   | fBribe10Mod                      | `25.0000`
1155  | float   | fBribe100Mod                     | `50.0000`
1156  | float   | fBribe1000Mod                    | `100.0000`
1157  | float   | fPerDieRollMult                  | `0.2000`
1158  | float   | fPerTempMult                     | `2.0000`
1159  | integer | iPerMinChance                    | `5`
1160  | integer | iPerMinChange                    | `10`
1161  | float   | fSpecialSkillBonus               | `0.8000`
1162  | float   | fMajorSkillBonus                 | `0.7500`
1163  | float   | fMinorSkillBonus                 | `1.0000`
1164  | float   | fMiscSkillBonus                  | `1.2500`
1165  | integer | iAlarmKilling                    | `90`
1166  | integer | iAlarmAttack                     | `50`
1167  | integer | iAlarmStealing                   | `1`
1168  | integer | iAlarmPickPocket                 | `20`
1169  | integer | iAlarmTresspass                  | `5`
1170  | float   | fAlarmRadius                     | `4096.0000`
1171  | integer | iCrimeKilling                    | `1000`
1172  | integer | iCrimeAttack                     | `40`
1173  | float   | fCrimeStealing                   | `1.0000`
1174  | integer | iCrimePickPocket                 | `25`
1175  | integer | iCrimeTresspass                  | `5`
1176  | integer | iCrimeThreshold                  | `100`
1177  | integer | iCrimeThresholdMultiplier        | `10`
1178  | float   | fCrimeGoldDiscountMult           | `0.3000`
1179  | float   | fCrimeGoldTurnInMult             | `0.9000`
1180  | integer | iFightAttack                     | `100`
1181  | integer | iFightAttacking                  | `50`
1182  | integer | iFightDistanceBase               | `20`
1183  | float   | fFightDistanceMultiplier         | `0.0050`
1184  | integer | iFightAlarmMult                  | `1`
1185  | float   | fFightDispMult                   | `1.0000`
1186  | float   | fFightStealing                   | `0.1000`
1187  | integer | iFightPickpocket                 | `25`
1188  | integer | iFightTrespass                   | `25`
1189  | integer | iFightKilling                    | `50`
1190  | integer | iFlee                            | `0`
1191  | integer | iGreetDistanceMultiplier         | `10`
1192  | integer | iGreetDuration                   | `3`
1193  | float   | fGreetDistanceReset              | `512.0000`
1194  | float   | fIdleChanceMultiplier            | `1.0000`
1195  | float   | fSneakUseDist                    | `512.0000`
1196  | float   | fSneakUseDelay                   | `2.0000`
1197  | float   | fSneakDistanceBase               | `0.5000`
1198  | float   | fSneakDistanceMultiplier         | `0.0005`
1199  | float   | fSneakSpeedMultiplier            | `0.5000`
1200  | float   | fSneakViewMult                   | `1.5000`
1201  | float   | fSneakNoViewMult                 | `0.5000`
1202  | float   | fSneakSkillMult                  | `1.0000`
1203  | float   | fSneakBootMult                   | `-0.5000`
1204  | float   | fCombatDistance                  | `128.0000`
1205  | float   | fCombatAngleXY                   | `60.0000`
1206  | float   | fCombatAngleZ                    | `60.0000`
1207  | float   | fCombatForceSideAngle            | `30.0000`
1208  | float   | fCombatTorsoSideAngle            | `45.0000`
1209  | float   | fCombatTorsoStartPercent         | `0.3000`
1210  | float   | fCombatTorsoStopPercent          | `0.7000`
1211  | float   | fCombatBlockLeftAngle            | `-90.0000`
1212  | float   | fCombatBlockRightAngle           | `30.0000`
1213  | float   | fCombatDelayCreature             | `0.1000`
1214  | float   | fCombatDelayNPC                  | `0.1000`
1215  | string  | sTargetCriticalStrike            | `"%s is hit by a critical strike!"`
1216  | float   | fAIMeleeWeaponMult               | `2.0000`
1217  | float   | fAIRangeMeleeWeaponMult          | `5.0000`
1218  | float   | fAIMagicSpellMult                | `3.0000`
1219  | float   | fAIRangeMagicSpellMult           | `5.0000`
1220  | float   | fAIMeleeArmorMult                | `1.0000`
1221  | float   | fAIMeleeSummWeaponMult           | `1.0000`
1222  | float   | fAIFleeHealthMult                | `10.0000`
1223  | float   | fAIFleeFleeMult                  | `1.0000`
1224  | float   | fPickPocketMod                   | `0.5000`
1225  | float   | fSleepRandMod                    | `0.5000`
1226  | float   | fSleepRestMod                    | `0.3000`
1227  | integer | iNumberCreatures                 | `3`
1228  | float   | fAudioDefaultMinDistance         | `5.0000`
1229  | float   | fAudioDefaultMaxDistance         | `40.0000`
1230  | float   | fAudioVoiceDefaultMinDistance    | `10.0000`
1231  | float   | fAudioVoiceDefaultMaxDistance    | `60.0000`
1232  | float   | fAudioMinDistanceMult            | `20.0000`
1233  | float   | fAudioMaxDistanceMult            | `50.0000`
1234  | float   | fNPCHealthBarTime                | `3.0000`
1235  | float   | fNPCHealthBarFade                | `0.5000`
1236  | float   | fDifficultyMult                  | `5.0000`
1237  | float   | fWereWolfRunMult                 | `1.5000`
1238  | float   | fWereWolfSilverWeaponDamageMult  | `1.5000`
1239  | integer | iWereWolfBounty                  | `10000`
1240  | float   | fWereWolfStrength                | `150.0000`
1241  | float   | fWereWolfAgility                 | `150.0000`
1242  | float   | fWereWolfEndurance               | `150.0000`
1243  | float   | fWereWolfSpeed                   | `150.0000`
1244  | float   | fWereWolfHandtoHand              | `100.0000`
1245  | float   | fWereWolfUnarmored               | `100.0000`
1246  | integer | iWereWolfLevelToAttack           | `20`
1247  | integer | iWereWolfFightMod                | `100`
1248  | integer | iWereWolfFleeMod                 | `100`
1249  | float   | fWereWolfAthletics               | `150.0000`
1250  | float   | fWereWolfAcrobatics              | `150.0000`
1251  | float   | fWereWolfHealth                  | `2.0000`
1252  | float   | fWereWolfFatigue                 | `400.0000`
1253  | float   | fWereWolfMagicka                 | `100.0000`
1254  | float   | fWereWolfIntellegence            | `1.0000`
1255  | float   | fWereWolfWillPower               | `1.0000`
1256  | float   | fWereWolfPersonality             | `1.0000`
1257  | float   | fWereWolfLuck                    | `1.0000`
1258  | float   | fWereWolfBlock                   | `1.0000`
1259  | float   | fWereWolfArmorer                 | `1.0000`
1260  | float   | fWereWolfMediumArmor             | `1.0000`
1261  | float   | fWereWolfHeavyArmor              | `1.0000`
1262  | float   | fWereWolfBluntWeapon             | `1.0000`
1263  | float   | fWereWolfLongBlade               | `1.0000`
1264  | float   | fWereWolfAxe                     | `1.0000`
1265  | float   | fWereWolfSpear                   | `1.0000`
1266  | float   | fWereWolfDestruction             | `1.0000`
1267  | float   | fWereWolfAlteration              | `1.0000`
1268  | float   | fWereWolfIllusion                | `1.0000`
1269  | float   | fWereWolfConjuration             | `1.0000`
1270  | float   | fWereWolfMysticism               | `1.0000`
1271  | float   | fWereWolfRestoration             | `1.0000`
1272  | float   | fWereWolfEnchant                 | `1.0000`
1273  | float   | fWereWolfAlchemy                 | `1.0000`
1274  | float   | fWereWolfSecurity                | `1.0000`
1275  | float   | fWereWolfSneak                   | `1.0000`
1276  | float   | fWereWolfLightArmor              | `1.0000`
1277  | float   | fWereWolfShortBlade              | `1.0000`
1278  | float   | fWereWolfMarksman                | `1.0000`
1279  | float   | fWereWolfMerchantile             | `1.0000`
1280  | float   | fWereWolfSpeechcraft             | `1.0000`
1281  | float   | fCombatDistanceWerewolfMod       | `0.3000`
1282  | float   | fFleeDistance                    | `3000.0000`
1283  | string  | sEffectWaterBreathing            | `"sEffectWaterBreathing"`
1284  | string  | sEffectSwiftSwim                 | `"sEffectSwiftSwim"`
1285  | string  | sEffectWaterWalking              | `"sEffectWaterWalking"`
1286  | string  | sEffectShield                    | `"sEffectShield"`
1287  | string  | sEffectFireShield                | `"sEffectFireShield"`
1288  | string  | sEffectLightningShield           | `"sEffectLightningShield"`
1289  | string  | sEffectFrostShield               | `"sEffectFrostShield"`
1290  | string  | sEffectBurden                    | `"sEffectBurden"`
1291  | string  | sEffectFeather                   | `"sEffectFeather"`
1292  | string  | sEffectJump                      | `"sEffectJump"`
1293  | string  | sEffectLevitate                  | `"sEffectLevitate"`
1294  | string  | sEffectSlowFall                  | `"sEffectSlowFall"`
1295  | string  | sEffectLock                      | `"sEffectLock"`
1296  | string  | sEffectOpen                      | `"sEffectOpen"`
1297  | string  | sEffectFireDamage                | `"sEffectFireDamage"`
1298  | string  | sEffectShockDamage               | `"sEffectShockDamage"`
1299  | string  | sEffectFrostDamage               | `"sEffectFrostDamage"`
1300  | string  | sEffectDrainAttribute            | `"sEffectDrainAttribute"`
1301  | string  | sEffectDrainHealth               | `"sEffectDrainHealth"`
1302  | string  | sEffectDrainSpellpoints          | `"sEffectDrainSpellpoints"`
1303  | string  | sEffectDrainFatigue              | `"sEffectDrainFatigue"`
1304  | string  | sEffectDrainSkill                | `"sEffectDrainSkill"`
1305  | string  | sEffectDamageAttribute           | `"sEffectDamageAttribute"`
1306  | string  | sEffectDamageHealth              | `"sEffectDamageHealth"`
1307  | string  | sEffectDamageMagicka             | `"sEffectDamageMagicka"`
1308  | string  | sEffectDamageFatigue             | `"sEffectDamageFatigue"`
1309  | string  | sEffectDamageSkill               | `"sEffectDamageSkill"`
1310  | string  | sEffectPoison                    | `"sEffectPoison"`
1311  | string  | sEffectWeaknessToFire            | `"sEffectWeaknessToFire"`
1312  | string  | sEffectWeaknessToFrost           | `"sEffectWeaknessToFrost"`
1313  | string  | sEffectWeaknessToShock           | `"sEffectWeaknessToShock"`
1314  | string  | sEffectWeaknessToMagicka         | `"sEffectWeaknessToMagicka"`
1315  | string  | sEffectWeaknessToCommonDisease   | `"sEffectWeaknessToCommonDisease"`
1316  | string  | sEffectWeaknessToBlightDisease   | `"sEffectWeaknessToBlightDisease"`
1317  | string  | sEffectWeaknessToCorprusDisease  | `"sEffectWeaknessToCorprusDisease"`
1318  | string  | sEffectWeaknessToPoison          | `"sEffectWeaknessToPoison"`
1319  | string  | sEffectWeaknessToNormalWeapons   | `"sEffectWeaknessToNormalWeapons"`
1320  | string  | sEffectDisintegrateWeapon        | `"sEffectDisintegrateWeapon"`
1321  | string  | sEffectDisintegrateArmor         | `"sEffectDisintegrateArmor"`
1322  | string  | sEffectInvisibility              | `"sEffectInvisibility"`
1323  | string  | sEffectChameleon                 | `"sEffectChameleon"`
1324  | string  | sEffectLight                     | `"sEffectLight"`
1325  | string  | sEffectSanctuary                 | `"sEffectSanctuary"`
1326  | string  | sEffectNightEye                  | `"sEffectNightEye"`
1327  | string  | sEffectCharm                     | `"sEffectCharm"`
1328  | string  | sEffectParalyze                  | `"sEffectParalyze"`
1329  | string  | sEffectSilence                   | `"sEffectSilence"`
1330  | string  | sEffectBlind                     | `"sEffectBlind"`
1331  | string  | sEffectSound                     | `"sEffectSound"`
1332  | string  | sEffectCalmHumanoid              | `"sEffectCalmHumanoid"`
1333  | string  | sEffectCalmCreature              | `"sEffectCalmCreature"`
1334  | string  | sEffectFrenzyHumanoid            | `"sEffectFrenzyHumanoid"`
1335  | string  | sEffectFrenzyCreature            | `"sEffectFrenzyCreature"`
1336  | string  | sEffectDemoralizeHumanoid        | `"sEffectDemoralizeHumanoid"`
1337  | string  | sEffectDemoralizeCreature        | `"sEffectDemoralizeCreature"`
1338  | string  | sEffectRallyHumanoid             | `"sEffectRallyHumanoid"`
1339  | string  | sEffectRallyCreature             | `"sEffectRallyCreature"`
1340  | string  | sEffectDispel                    | `"sEffectDispel"`
1341  | string  | sEffectSoultrap                  | `"sEffectSoultrap"`
1342  | string  | sEffectTelekinesis               | `"sEffectTelekinesis"`
1343  | string  | sEffectMark                      | `"sEffectMark"`
1344  | string  | sEffectRecall                    | `"sEffectRecall"`
1345  | string  | sEffectDivineIntervention        | `"sEffectDivineIntervention"`
1346  | string  | sEffectAlmsiviIntervention       | `"sEffectAlmsiviIntervention"`
1347  | string  | sEffectDetectAnimal              | `"sEffectDetectAnimal"`
1348  | string  | sEffectDetectEnchantment         | `"sEffectDetectEnchantment"`
1349  | string  | sEffectDetectKey                 | `"sEffectDetectKey"`
1350  | string  | sEffectSpellAbsorption           | `"sEffectSpellAbsorption"`
1351  | string  | sEffectReflect                   | `"sEffectReflect"`
1352  | string  | sEffectCureCommonDisease         | `"sEffectCureCommonDisease"`
1353  | string  | sEffectCureBlightDisease         | `"sEffectCureBlightDisease"`
1354  | string  | sEffectCureCorprusDisease        | `"sEffectCureCorprusDisease"`
1355  | string  | sEffectCurePoison                | `"sEffectCurePoison"`
1356  | string  | sEffectCureParalyzation          | `"sEffectCureParalyzation"`
1357  | string  | sEffectRestoreAttribute          | `"sEffectRestoreAttribute"`
1358  | string  | sEffectRestoreHealth             | `"sEffectRestoreHealth"`
1359  | string  | sEffectRestoreSpellPoints        | `"sEffectRestoreSpellPoints"`
1360  | string  | sEffectRestoreFatigue            | `"sEffectRestoreFatigue"`
1361  | string  | sEffectRestoreSkill              | `"sEffectRestoreSkill"`
1362  | string  | sEffectFortifyAttribute          | `"sEffectFortifyAttribute"`
1363  | string  | sEffectFortifyHealth             | `"sEffectFortifyHealth"`
1364  | string  | sEffectFortifySpellpoints        | `"sEffectFortifySpellpoints"`
1365  | string  | sEffectFortifyFatigue            | `"sEffectFortifyFatigue"`
1366  | string  | sEffectFortifySkill              | `"sEffectFortifySkill"`
1367  | string  | sEffectFortifyMagickaMultiplier  | `"sEffectFortifyMagickaMultiplier"`
1368  | string  | sEffectAbsorbAttribute           | `"sEffectAbsorbAttribute"`
1369  | string  | sEffectAbsorbHealth              | `"sEffectAbsorbHealth"`
1370  | string  | sEffectAbsorbSpellPoints         | `"sEffectAbsorbSpellPoints"`
1371  | string  | sEffectAbsorbFatigue             | `"sEffectAbsorbFatigue"`
1372  | string  | sEffectAbsorbSkill               | `"sEffectAbsorbSkill"`
1373  | string  | sEffectResistFire                | `"sEffectResistFire"`
1374  | string  | sEffectResistFrost               | `"sEffectResistFrost"`
1375  | string  | sEffectResistShock               | `"sEffectResistShock"`
1376  | string  | sEffectResistMagicka             | `"sEffectResistMagicka"`
1377  | string  | sEffectResistCommonDisease       | `"sEffectResistCommonDisease"`
1378  | string  | sEffectResistBlightDisease       | `"sEffectResistBlightDisease"`
1379  | string  | sEffectResistCorprusDisease      | `"sEffectResistCorprusDisease"`
1380  | string  | sEffectResistPoison              | `"sEffectResistPoison"`
1381  | string  | sEffectResistNormalWeapons       | `"sEffectResistNormalWeapons"`
1382  | string  | sEffectResistParalysis           | `"sEffectResistParalysis"`
1383  | string  | sEffectRemoveCurse               | `"sEffectRemoveCurse"`
1384  | string  | sEffectTurnUndead                | `"sEffectTurnUndead"`
1385  | string  | sEffectSummonScamp               | `"sEffectSummonScamp"`
1386  | string  | sEffectSummonClannfear           | `"sEffectSummonClannfear"`
1387  | string  | sEffectSummonDaedroth            | `"sEffectSummonDaedroth"`
1388  | string  | sEffectSummonDremora             | `"sEffectSummonDremora"`
1389  | string  | sEffectSummonAncestralGhost      | `"sEffectSummonAncestralGhost"`
1390  | string  | sEffectSummonSkeletalMinion      | `"sEffectSummonSkeletalMinion"`
1391  | string  | sEffectSummonLeastBonewalker     | `"sEffectSummonLeastBonewalker"`
1392  | string  | sEffectSummonGreaterBonewalker   | `"sEffectSummonGreaterBonewalker"`
1393  | string  | sEffectSummonBonelord            | `"sEffectSummonBonelord"`
1394  | string  | sEffectSummonWingedTwilight      | `"sEffectSummonWingedTwilight"`
1395  | string  | sEffectSummonHunger              | `"sEffectSummonHunger"`
1396  | string  | sEffectSummonGoldensaint         | `"sEffectSummonGoldensaint"`
1397  | string  | sEffectSummonFlameAtronach       | `"sEffectSummonFlameAtronach"`
1398  | string  | sEffectSummonFrostAtronach       | `"sEffectSummonFrostAtronach"`
1399  | string  | sEffectSummonStormAtronach       | `"sEffectSummonStormAtronach"`
1400  | string  | sEffectFortifyAttackBonus        | `"sEffectFortifyAttackBonus"`
1401  | string  | sEffectCommandCreatures          | `"sEffectCommandCreatures"`
1402  | string  | sEffectCommandHumanoids          | `"sEffectCommandHumanoids"`
1403  | string  | sEffectBoundDagger               | `"sEffectBoundDagger"`
1404  | string  | sEffectBoundLongsword            | `"sEffectBoundLongsword"`
1405  | string  | sEffectBoundMace                 | `"sEffectBoundMace"`
1406  | string  | sEffectBoundBattleAxe            | `"sEffectBoundBattleAxe"`
1407  | string  | sEffectBoundSpear                | `"sEffectBoundSpear"`
1408  | string  | sEffectBoundLongbow              | `"sEffectBoundLongbow"`
1409  | string  | sEffectExtraSpell                | `"sEffectExtraSpell"`
1410  | string  | sEffectBoundCuirass              | `"sEffectBoundCuirass"`
1411  | string  | sEffectBoundHelm                 | `"sEffectBoundHelm"`
1412  | string  | sEffectBoundBoots                | `"sEffectBoundBoots"`
1413  | string  | sEffectBoundShield               | `"sEffectBoundShield"`
1414  | string  | sEffectBoundGloves               | `"sEffectBoundGloves"`
1415  | string  | sEffectCorpus                    | `"sEffectCorpus"`
1416  | string  | sEffectVampirism                 | `"sEffectVampirism"`
1417  | string  | sEffectSummonCenturionSphere     | `"sEffectSummonCenturionSphere"`
1418  | string  | sEffectSunDamage                 | `"sEffectSunDamage"`
1419  | string  | sEffectStuntedMagicka            | `"sEffectStuntedMagicka"`
1420  | string  | sEffectSummonFabricant           | `"sEffectSummonFabricant"`
1421  | string  | sEffectSummonCreature01          | `"sEffectSummonCreature01"`
1422  | string  | sEffectSummonCreature02          | `"sEffectSummonCreature02"`
1423  | string  | sEffectSummonCreature03          | `"sEffectSummonCreature03"`
1424  | string  | sEffectSummonCreature04          | `"sEffectSummonCreature04"`
1425  | string  | sEffectSummonCreature05          | `"sEffectSummonCreature05"`
1426  | string  | sSchoolAlteration                | `"sSchoolAlteration"`
1427  | string  | sSchoolConjuration               | `"sSchoolConjuration"`
1428  | string  | sSchoolDestruction               | `"sSchoolDestruction"`
1429  | string  | sSchoolIllusion                  | `"sSchoolIllusion"`
1430  | string  | sSchoolMysticism                 | `"sSchoolMysticism"`
1431  | string  | sSchoolRestoration               | `"sSchoolRestoration"`
1432  | string  | sTypeSpell                       | `"sTypeSpell"`
1433  | string  | sTypeAbility                     | `"sTypeAbility"`
1434  | string  | sTypeBlightDisease               | `"sTypeBlightDisease"`
1435  | string  | sTypeDisease                     | `"sTypeDisease"`
1436  | string  | sTypeCurse                       | `"sTypeCurse"`
1437  | string  | sTypePower                       | `"sTypePower"`
1438  | string  | sItemCastOnce                    | `"sItemCastOnce"`
1439  | string  | sItemCastWhenStrikes             | `"sItemCastWhenStrikes"`
1440  | string  | sItemCastWhenUsed                | `"sItemCastWhenUsed"`
1441  | string  | sItemCastConstant                | `"sItemCastConstant"`
1442  | string  | sRangeSelf                       | `"sRangeSelf"`
1443  | string  | sRangeTouch                      | `"sRangeTouch"`
1444  | string  | sRangeTarget                     | `"sRangeTarget"`
1445  | string  | sMagicSkillFail                  | `"sMagicSkillFail"`
1446  | string  | sMagicInsufficientSP             | `"sMagicInsufficientSP"`
1447  | string  | sMagicInsufficientCharge         | `"sMagicInsufficientCharge"`
1448  | string  | sPowerAlreadyUsed                | `"sPowerAlreadyUsed"`
1449  | string  | sMagicInvalidTarget              | `"sMagicInvalidTarget"`
1450  | string  | sMagicLockSuccess                | `"sMagicLockSuccess"`
1451  | string  | sMagicOpenSuccess                | `"sMagicOpenSuccess"`
1452  | string  | sMagicTargetResistsWeapons       | `"sMagicTargetResistsWeapons"`
1453  | string  | sMagicContractDisease            | `"You have contracted %s"`
1454  | float   | fMagicDetectRefreshRate          | `0.0167`
1455  | float   | fMagicStartIconBlink             | `3.0000`
1456  | float   | fMagicCreatureCastDelay          | `1.5000`
1457  | string  | sMagicScampID                    | `"Scamp"`
1458  | string  | sMagicClannfearID                | `"Clannfear"`
1459  | string  | sMagicDaedrothID                 | `"Daedroth"`
1460  | string  | sMagicDremoraID                  | `"Dremora"`
1461  | string  | sMagicAncestralGhostID           | `"Ancestor_Ghost"`
1462  | string  | sMagicSkeletalMinionID           | `"Skeleton"`
1463  | string  | sMagicLeastBonewalkerID          | `"Bonewalker"`
1464  | string  | sMagicGreaterBonewalkerID        | `"Bonewalker_Greater"`
1465  | string  | sMagicBonelordID                 | `"Bonelord"`
1466  | string  | sMagicWingedTwilightID           | `"Winged Twilight"`
1467  | string  | sMagicHungerID                   | `"Hunger"`
1468  | string  | sMagicGoldenSaintID              | `"Golden Saint"`
1469  | string  | sMagicFlameAtronachID            | `"Atronach_Flame"`
1470  | string  | sMagicFrostAtronachID            | `"Atronach_Frost"`
1471  | string  | sMagicStormAtronachID            | `"Atronach_Storm"`
1472  | string  | sMagicCenturionSphereID          | `"centurion_sphere"`
1473  | string  | sMagicFabricantID                | `"Fabricant"`
1474  | string  | sMagicCreature01ID               | `"sMagicCreature01ID"`
1475  | string  | sMagicCreature02ID               | `"sMagicCreature02ID"`
1476  | string  | sMagicCreature03ID               | `"sMagicCreature03ID"`
1477  | string  | sMagicCreature04ID               | `"sMagicCreature04ID"`
1478  | string  | sMagicCreature05ID               | `"sMagicCreature05ID"`
1479  | string  | sMagicBoundDaggerID              | `"Bound_Dagger"`
1480  | string  | sMagicBoundLongswordID           | `"Bound_Longsword"`
1481  | string  | sMagicBoundMaceID                | `"Bound_Mace"`
1482  | string  | sMagicBoundBattleAxeID           | `"Bound_Battle_Axe"`
1483  | string  | sMagicBoundSpearID               | `"Bound_Spear"`
1484  | string  | sMagicBoundLongbowID             | `"Bound_Longbow"`
1485  | string  | sMagicBoundCuirassID             | `"Bound_Cuirass"`
1486  | string  | sMagicBoundHelmID                | `"Bound_Helm"`
1487  | string  | sMagicBoundBootsID               | `"Bound_Boots"`
1488  | string  | sMagicBoundShieldID              | `"Bound_Shield"`
1489  | string  | sMagicBoundLeftGauntletID        | `"Bound_Gauntlet_Left"`
1490  | string  | sMagicBoundRightGauntletID       | `"Bound_Gauntlet_Right"`
1491  | float   | fDiseaseXferChance               | `5.0000`
1492  | float   | fElementalShieldMult             | `0.1000`
1493  | string  | sMagicCorprusWorsens             | `"Your case of Corprus has worsened."`
1494  | string  | sMagicCannotRecast               | `"You cannot re-cast this spell while it is still in effect."`
1495  | float   | fMagicSunBlockedMult             | `0.5000`
1496  | string  | sMagicPCResisted                 | `"You resisted magic."`
1497  | string  | sMagicTargetResisted             | `"Target resisted magic."`
1498  | string  | sMagicInvalidEffect              | `"You cannot cast this effect right now."`
1499  | string  | sAcrobat                         | `"Acrobat"`
1500  | string  | sAgent                           | `"Agent"`
1501  | string  | sArcher                          | `"Archer"`
1502  | string  | sAssassin                        | `"Assassin"`
1503  | string  | sBarbarian                       | `"Barbarian"`
1504  | string  | sBard                            | `"Bard"`
1505  | string  | sBattlemage                      | `"Battlemage"`
1506  | string  | sCrusader                        | `"Crusader"`
1507  | string  | sCustom                          | `"Custom"`
1508  | string  | sHealer                          | `"Healer"`
1509  | string  | sKnight                          | `"Knight"`
1510  | string  | sMage                            | `"Mage"`
1511  | string  | sMonk                            | `"Monk"`
1512  | string  | sNightblade                      | `"Nightblade"`
1513  | string  | sPilgrim                         | `"Pilgrim"`
1514  | string  | sRogue                           | `"Rogue"`
1515  | string  | sScout                           | `"Scout"`
1516  | string  | sSorceror                        | `"Sorceror"`
1517  | string  | sSpellsword                      | `"Spellsword"`
1518  | string  | sThief                           | `"Thief"`
1519  | string  | sWarrior                         | `"Warrior"`
1520  | string  | sWitchhunter                     | `"Witchhunter"`
