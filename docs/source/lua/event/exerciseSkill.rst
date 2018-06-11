
exerciseSkill
========================================================

This event is invoked whenever the player gains experience in a skill. The event can be blocked to prevent progress. Additionally, both the skill gaining experience and the progress gained can be changed.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
--------------------------------------------------------

skill
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`Number`_. The skill that is gaining experience. This can be changed to provide experience to a different skill.

progress
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. The amount of experience that skill is gaining. Note that experience is not on a scale of 1 to 100. This value is modifiable.


Filter
--------------------------------------------------------
This event may be filtered by **skill**.


.. _`Event Guide`: ../guide/events.html

.. _`Number`: ../type/lua/number.html
