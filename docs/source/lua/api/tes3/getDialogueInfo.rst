tes3.getDialogueInfo
====================================================================================================

Locates and returns a Dialogue Info by a given id. This involves file IO and is an expensive call. Results should be cached.

Returns
----------------------------------------------------------------------------------------------------

`tes3dialogueInfo`_.

Parameters
----------------------------------------------------------------------------------------------------

dialogue (`tes3dialogue`_, `string`_)
    The dialogue that the info belongs to.

id (`string`_)
    The numerical, unique id for the info object.

.. _`bool`: ../../../lua/type/boolean.html
.. _`nil`: ../../../lua/type/nil.html
.. _`table`: ../../../lua/type/table.html
.. _`string`: ../../../lua/type/string.html
.. _`number`: ../../../lua/type/number.html
.. _`boolean`: ../../../lua/type/boolean.html
.. _`function`: ../../../lua/type/function.html
