
Alchemy
========================================================

This interface represents an alchemy game object.

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
    The object's weight.The object's weight.

**effects** (`userdata`_)
    The object's effect list.

**autoCalc** (`boolean`_)
    The object's value was calculated automatically.


--------------------------------------------------------

.. _`boolean`: ../lua/boolean.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html
.. _`userdata`: ../lua/userdata.html
.. _`objectType`: baseObject/objectType.html
.. _`boundingBox`: physicalObject/boundingBox.html
