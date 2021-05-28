tes3.dropItem
====================================================================================================

Drops one or more items from a reference's inventory onto the ground at their feet.

Returns
----------------------------------------------------------------------------------------------------

`tes3reference`_.

Parameters
----------------------------------------------------------------------------------------------------

Accepts parameters through a table with the given keys:

reference (`tes3mobileActor`_, `tes3reference`_, `string`_)
    The reference whose inventory will be modified.

item (`tes3item`_, `string`_)
    The item to drop.

itemData (`tes3itemData`_)
    Optional. The item data to match.

count (`number`_)
    Default: ``1``. The number of items to drop.

matchExact (`boolean`_)
    Default: ``true``. If true, the exact item will be matched. This is important if you want to drop an item without item data.

updateGUI (`boolean`_)
    Default: ``true``. If false, the player or contents menu won't be updated.

.. _`boolean`: ../../../lua/type/boolean.html
.. _`string`: ../../../lua/type/string.html
.. _`number`: ../../../lua/type/number.html
.. _`tes3mobileActor`: ../../../lua/type/tes3mobileActor.html
.. _`tes3reference`: ../../../lua/type/tes3reference.html
.. _`tes3item`: ../../../lua/type/tes3item.html
.. _`tes3itemData`: ../../../lua/type/tes3itemData.html
