
xSetService
========================================================

**Parameters:**

- ``long`` **services**: The combined value of services the reference should offer.

**Returned:**

- *None*

xSetService uses the value parameter to change the NPC to offer the set of services represented by the number. The service number values are used and any old services are ignored.

For example using a value of 8 will make the NPC a bookseller. A value of 131587 (1+2+512+131072) is typical for smiths. The values changed by this function are not permanent and may be reset after 72-hours or a game reload.

====== =================================
Value  Service
====== =================================
1      Barters for weapons.
2      Barters for armor.
4      Barters for clothing.
8      Barters for books.
16     Barters for ingredients.
32     Barters for lockpicks.
64     Barters for probes.
128    Barters for lights.
256    Barters for alchemical apparatus.
512    Barters for repair tools.
1024   Barters for miscellaneous items.
2048   Offers spells.
4096   Barters for enchanted items.
8192   Barters for potions.
16384  Provides training.
32768  Provides spellmaking service.
65536  Provides enchanting service.
131072 Repairs armor and weapons.
====== =================================
