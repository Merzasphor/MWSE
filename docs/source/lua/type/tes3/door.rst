
Door
========================================================

This interface represents an door game object.

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

**name** (`string`_)
    The object's name.

**script** (`userdata`_)
    The object's script.

**closeSound** (`string`_)
    The sound ID to be played when opening.

**openSound** (`string`_)
    The sound ID to be played when closing.


--------------------------------------------------------

.. _`boolean`: ../lua/boolean.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html
.. _`userdata`: ../lua/userdata.html
.. _`objectType`: baseObject/objectType.html
.. _`boundingBox`: physicalObject/boundingBox.html
