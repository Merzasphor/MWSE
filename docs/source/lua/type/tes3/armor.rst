
Armor
========================================================

This interface represents an armor game object.

Properties
--------------------------------------------------------

**id** (`string`_)
    The object's unique id.

**objectType** (`number`_)
    The object's `objectType`_

**sourceMod** (`string`_)
    The object's originating plugin filename.

**mesh** (`string`_)
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
    The object's value in gold.

**weight** (`number`_)
    The object's weight.

**isLeftPart** (`boolean`_)
    The object uses a left inventory slot.

**armorRating** (`number`_)
    The object's armor rating.

**enchantCapacity** (`number`_)
    The object's maximum enchantment capacity.

**enchantment** (`userdata`_)
    The object's enchantment.

**health** (`number`_)
    The object's durability.

**slot** (`armorSlot`_)
    The object's equipment slot.

**weightClass** (`number`_)
    The object's weightClass.


--------------------------------------------------------

.. _`boolean`: ../lua/boolean.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html
.. _`userdata`: ../lua/userdata.html
.. _`objectType`: baseObject/objectType.html
.. _`boundingBox`: physicalObject/boundingBox.html
.. _`armorSlot`: armor/armorSlot.html
