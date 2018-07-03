
spellCast
========================================================

This event is triggered when any spell is cast successfully; this includes spells cast via scripts. This occurs at the end of the casting animation, just after the magic projectile has been constructed.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
--------------------------------------------------------

caster
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3reference`_. Read-only. The caster of the spell.

target
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3reference`_. Read-only. The target of the spell. For self-targeted spells, this matches **caster**.

source
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3spell`_. Read-only. What the spell comes from.

sourceInstance
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3magicSourceInstance`_. Read-only. The unique instance of the magic source.

spellCastChance
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`Number`_. Read-only. The chance of the caster successfully casting the spell.


Filter
--------------------------------------------------------
This event may be filtered by **source**.


.. _`Event Guide`: ../guide/events.html

.. _`Number`: ../type/lua/number.html

.. _`tes3magicSourceInstance`: ../type/tes3/magicSourceInstance.html
.. _`tes3reference`: ../type/tes3/reference.html
.. _`tes3spell`: ../type/tes3/spell.html
