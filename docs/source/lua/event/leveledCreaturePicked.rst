leveledCreaturePicked
====================================================================================================

This event is called after any leveled creature list is resolved. he event may be filtered by its list, and its pick can be overwritten. While this event allows for customization, the leveled list may be altered directly as well.

Event Data
----------------------------------------------------------------------------------------------------

tes3creature
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`number`_. The result of the pick by vanilla mechanism. This can be modified to change the result to something else.

list
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

tes3leveledCreature. Read-only. The list responsible for creating a pick.

.. _`bool`: ../../lua/type/boolean.html
.. _`nil`: ../../lua/type/nil.html
.. _`table`: ../../lua/type/table.html
.. _`string`: ../../lua/type/string.html
.. _`number`: ../../lua/type/number.html
.. _`boolean`: ../../lua/type/boolean.html
.. _`function`: ../../lua/type/function.html
