
Weapon
========================================================

This interface represents a weapon game object.


Properties
--------------------------------------------------------

**boundingBox** (`userdata`_)
    The object's `boundingBox`_.

**chopMax** (`number`_)
    The maximum damage from a chop attack.

**chopMin** (`number`_)
    The minimum damage from a chop attack.

**enchantment** (`enchantment`_)
    The weapon's enchant, if any.

**enchantmentCapacity** (`number`_)
    The weapon's capacity for enchantment.

**flags** (`number`_)
    The weapon's material flags.

**maxCondition** (`number`_)
    The weapon's condition.

**icon** (`string`_)
    The object's icon path, relative to 'Data Files/Icons'.

**id** (`string`_)
    The object's unique id.

**isAmmo** (`boolean`_)
    True if the weapon is an ammo type.

**isMelee** (`boolean`_)
    True if the weapon is melee.

**isOneHanded** (`boolean`_)
    True if the weapon is one handed.

**isRanged** (`boolean`_)
    True if the weapon is ranged.

**isTwoHanded** (`boolean`_)
    True if the weapon is two handed.

**model** (`string`_)
    The object's mesh path, relative to 'Data Files/Meshes'.

**name** (`string`_)
    The object's name.

**objectType** (`number`_)
    The object's `objectType`_

**reach** (`number`_)
    The weapon's attack reach.

**script** (`userdata`_)
    The object's script.

**slashMax** (`number`_)
    The maximum damage from a slash attack.

**slashMin** (`number`_)
    The minimum damage from a slash attack.

**sourceMod** (`string`_)
    The object's originating plugin filename.

**speed** (`number`_)
    The weapon's attack speed.

**thrustMax** (`number`_)
    The maximum damage from a thrust attack.

**thrustMin** (`number`_)
    The minimum damage from a thrust attack.

**type** (`weaponType`_)
    True if the weapon is an ammo type.

**value** (`number`_)
    The weapon's value in gold.

**weight** (`number`_)
    The weapon's weight.

--------------------------------------------------------

.. _`boolean`: ../lua/boolean.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html
.. _`userdata`: ../lua/userdata.html
.. _`objectType`: baseObject/objectType.html
.. _`weaponType`: weapon/weaponType.html
.. _`boundingBox`: physicalObject/boundingBox.html
.. _`enchantment`: enchantment.html
