potionBrewFailed
====================================================================================================

The potionBrewFailed event is raised when the player fails a potion brew attempt.

Event Data
----------------------------------------------------------------------------------------------------

alembic
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3apparatus`_. Read-only. The alembic apparatus used to create the potion.

calcinator
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3apparatus`_. Read-only. The calcinator apparatus used to create the potion.

ingredients
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`table`_. Read-only. An array of up to 4 tes3ingredient objects, which were used to create the potion.

mortar
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3apparatus`_. Read-only. The mortar apparatus used to create the potion.

retort
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3apparatus`_. Read-only. The retort apparatus used to create the potion.

.. _`table`: ../../lua/type/table.html
.. _`tes3apparatus`: ../../lua/type/tes3apparatus.html
