tes3.addItem
====================================================================================================

Adds an item to a given reference's inventory.

Returns
----------------------------------------------------------------------------------------------------

`number`_.

Parameters
----------------------------------------------------------------------------------------------------

Accepts parameters through a table with the given keys:

reference (`tes3reference`_, `tes3mobileActor`_, `string`_)
    Who to give items to.

item (`tes3item`_, `string`_)
    The item to add.

count (`number`_)
    Default: ``1``. The maximum number of items to add.

playSound (`boolean`_)
    Default: ``true``. If false, the up/down sound for the item won't be played.

limit (`boolean`_)
    Default: ``false``. If false, items can be placed into containers that shouldn't normally be allowed. This includes organic containers, and containers that are full.

updateGUI (`boolean`_)
    Default: ``true``. If false, the function won't manually resync the player's GUI state. This can result in some optimizations, though `tes3ui.forcePlayerInventoryUpdate()` must manually be called after all inventory updates are finished.

.. _`bool`: ../../../lua/type/boolean.html
.. _`nil`: ../../../lua/type/nil.html
.. _`table`: ../../../lua/type/table.html
.. _`string`: ../../../lua/type/string.html
.. _`number`: ../../../lua/type/number.html
.. _`boolean`: ../../../lua/type/boolean.html
.. _`function`: ../../../lua/type/function.html
