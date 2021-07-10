tes3.findDialogue
====================================================================================================

Locates a root dialogue that can then be filtered down for a specific actor to return a specific dialogue info For example, a type of 2 and a page of 1 will return the "Greeting 0" topic.

Returns
----------------------------------------------------------------------------------------------------

`tes3dialogue`_.

Parameters
----------------------------------------------------------------------------------------------------

Accepts parameters through a table with the given keys:

type (`number`_)
    The type of dialogue to look for: 1 for voice, 2 for greeting, 3 for service.

page (`number`_)
    The page of dialogue to fetch.

.. _`number`: ../../../lua/type/number.html
.. _`tes3dialogue`: ../../../lua/type/tes3dialogue.html
