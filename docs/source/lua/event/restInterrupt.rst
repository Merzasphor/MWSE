
restInterrupt
====================================================================================================

This event is invoked when a rest is about to be interrupted. The ambushing spawn can be overridden for a custom interrupt by either specifying a 

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
----------------------------------------------------------------------------------------------------

creature
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Leveled Creature`_ or `Actor`_. The creature that is interrupting rest. Can be set to a `Creature`_, `NPC`_, or `Leveled Creature`_.

resting
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Boolean`_. If ``true``, the player is attempting to rest, as opposed to wait.

waiting
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Boolean`_. If ``true``, the player is attempting to wait, as opposed to rest.


.. _`Event Guide`: ../guide/events.html

.. _`Boolean`: ../type/lua/boolean.html
.. _`Number`: ../type/lua/number.html

.. _`Actor`: ../type/tes3/actor.html
.. _`Creature`: ../type/tes3/creature.html
.. _`Leveled Creature`: ../type/tes3/leveledCreature.html
.. _`NPC`: ../type/tes3/npc.html
