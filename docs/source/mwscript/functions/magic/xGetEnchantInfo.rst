
xGetEnchantInfo
========================================================

**Parameters:**

- ``string`` **objectID**: The Object ID of the enchantment.

**Returned:**

- ``short`` **type**: 0 = Cast Once, 1 = Cast When Strikes, 2 = Cast When Used, 3 = Constant
- ``short`` **cost**: The cost of using the enchantment.
- ``long`` **maxCharge**: The maximum charge for the enchantment.
- ``short`` **numEffects**: The number of effects on the enchantment.
- ``long`` **autocalc**: 0 = off, 1 = on

Returns info about the given **enchantId**, or 0 if **enchantId** is invalid.
