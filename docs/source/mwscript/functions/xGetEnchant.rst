
xGetEnchant
========================================================

**Parameters:**

- *None*

**Returned:**

- ``string`` **enchantID**: The Object ID of the enchantment.
- ``short`` **type**: The type of the enchantment. 0 = Cast Once, 1 = Cast on Strike, 2 = Cast on Use, 3 = Constant
- ``short`` **cost**: The cost of the enchantment.
- ``float`` **currentCharge**: The current charge for the enchantment.
- ``long`` **maxCharge**: The maximum charge for the enchantment.
- ``short`` **numEffect**: The number of effects on the enchantment.
- ``long`` **autocalc**: 1 if the enchantment is auto-calculated.

Returns info about the enchantment on the target item, or 0 if no enchantment is present.

