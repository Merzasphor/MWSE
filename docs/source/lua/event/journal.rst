
journal
====================================================================================================

The **journal** event is invoked when a journal state progresses.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
----------------------------------------------------------------------------------------------------

index
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. The new index of the journal state. Read-only.

new
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Boolean`_. If true, the journal is newly added to the player. This effectively means that **index** has increased past 0. Read-only.

previousIndex
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. The previous index of the journal state. Read-only.

topic
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Dialogue`_. The topic that dictates the journal entry. Read-only.


.. _`Event Guide`: ../guide/events.html

.. _`Boolean`: ../type/lua/boolean.html
.. _`Number`: ../type/lua/number.html

.. _`Dialogue`: ../type/tes3/dialogue.html
