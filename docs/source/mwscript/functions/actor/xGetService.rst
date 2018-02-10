
xGetService
========================================================

**Parameters:**

- ``long`` **mask**: A filter to limit the **services** returned.

**Returned:**

- ``long`` **services**: The services offered by the reference, limited by **mask**.

This function returns a bitfield of services offered by a given reference.

The service values are shown in the following table. If an NPC offers more than one service the sum of the service numbers will be returned. The **mask** parameter can be used as a filter to limit the return value to only consider the services indicated.

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

.. note:: Previous versions of MWSE made use of xIsTrader, xIsTrainer, and xIsProvider. This function supercedes those. Old scripts that use them will continue to work, but new scripts should make use of xGetService.
