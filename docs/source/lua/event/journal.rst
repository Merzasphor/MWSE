journal
====================================================================================================

The journal event is invoked when a journal state progresses.

Event Data
----------------------------------------------------------------------------------------------------

topic
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

tes3dialogue. Read-only. The topic that dictates the journal entry.

previousIndex
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`number`_. Read-only. The previous index of the journal state.

index
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`number`_. Read-only. The new index of the journal state.

new
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`boolean`_. Read-only. If true, the journal is newly added to the player. This effectively means that index has increased past 0.

.. _`bool`: ../../lua/type/boolean.html
.. _`nil`: ../../lua/type/nil.html
.. _`table`: ../../lua/type/table.html
.. _`string`: ../../lua/type/string.html
.. _`number`: ../../lua/type/number.html
.. _`boolean`: ../../lua/type/boolean.html
.. _`function`: ../../lua/type/function.html
