
xModService
========================================================

**Parameters:**

- ``long`` **services**: The combined value of services the reference should offer (positive) or refuse (negative).

**Returned:**

- *None*

Uses the **services** parameter to modify the services offered by an NPC. A positive value adds that service (or set of services) to those already offered. A negative value will remove a service or service. The changes are not permanent.

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
