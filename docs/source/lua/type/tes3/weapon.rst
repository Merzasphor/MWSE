
Weapon
========================================================

This interface represents a weapon game object.

Properties
--------------------------------------------------------

**id** (`string`_)
    The object's unique id.

**objectType** (`number`_)
    The object's `objectType`_

**sourceMod** (`string`_)
    The object's originating plugin filename.

**model** (`string`_)
    The object's mesh path, relative to 'Data Files/Meshes'.

**boundingBox** (`userdata`_)
    The object's `boundingBox`_.

**icon** (`string`_)
    The object's icon path, relative to 'Data Files/Icons'.

**name** (`string`_)
    The object's name.

**script** (`userdata`_)
    The object's script.

**value** (`number`_)
    The weapon's value in gold.

**weight** (`number`_)
    The weapon's weight.

**health** (`number`_)
    The weapon's condition.

**chopMax** (`number`_)
    The maximum damage from a chop attack.

**chopMin** (`number`_)
    The minimum damage from a chop attack.

**slashMax** (`number`_)
    The maximum damage from a slash attack.

**slashMin** (`number`_)
    The minimum damage from a slash attack.

**thrustMax** (`number`_)
    The maximum damage from a thrust attack.

**thrustMin** (`number`_)
    The minimum damage from a thrust attack.

**speed** (`number`_)
    The weapon's attack speed.

**reach** (`number`_)
    The weapon's attack reach.

**enchantment** (`enchantment`_)
    The weapon's enchant, if any.

**enchantmentCapacity** (`number`_)
    The weapon's capacity for enchantment.

**flags** (`number`_)
    The weapon's material flags.

**isOneHanded** (`boolean`_)
    True if the weapon is one handed.

**isTwoHanded** (`boolean`_)
    True if the weapon is two handed.

**isMelee** (`boolean`_)
    True if the weapon is melee.

**isRanged** (`boolean`_)
    True if the weapon is ranged.

**isAmmo** (`boolean`_)
    True if the weapon is an ammo type.

**type** (`weaponType`_)
    True if the weapon is an ammo type.

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
