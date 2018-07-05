
restInterrupt
====================================================================================================

This event is invoked when a rest is about to be interrupted. The creature (either a specific actor or a leveled creature) can be overriden for a custom interrupt.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
----------------------------------------------------------------------------------------------------

creature
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Leveled Creature`_. The creature that is interrupting rest. Can be set to a leveled creature, or an `Actor`_.


.. _`Event Guide`: ../guide/events.html

.. _`Number`: ../type/lua/number.html
.. _`Actor`: ../type/tes3/actor.html
.. _`Leveled Creature`: ../type/tes3/leveledCreature.html
