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

.. _`tes3dialogueInfo`: ../../../lua/type/tes3dialogueInfo.html
.. _`tes3dialogue`: ../../../lua/type/tes3dialogue.html
.. _`string`: ../../../lua/type/string.html
