
xSetEnchantInfo
========================================================

**Parameters:**

- ``string`` **enchantID**: Object ID of the enchantment to modify.
- ``long`` **type**: 0 = Cast Once, 1 = Cast When Strikes, 2 = Cast When Used, 3 = Constant.
- ``long`` **cost**: New cost per use.
- ``long`` **charge**: New maximum charge.
- ``long`` **autoCalc**: 0 = Off, 1 = On.

**Returned:**

- ``long`` **result**: 1 on success, 0 on failure.

Sets the properties of the given **enchantId**.
