
spellResist
========================================================

This event is used when calculating a creature's spell resistance, and allows Lua scripts to override the behavior of spell resistance by changing the **resistedPercent** value. This can be used to enable willpower-based resistance checks, provide specific resistances to specific spells, spells that heal instead of harm, and a variety of new mechanics.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
--------------------------------------------------------

caster
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3reference`_. Read-only. The caster of the spell.

target
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3reference`_. Read-only. The target of the spell. For self-targeted spells, this matches **caster**.

resistedPercent
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`Number`_. The percent of the spell that has been resisted. This can be modified.

.. note:: A resisted percent outside the range of 0 to 100 works, but does not have consistent effects. For fire damage, for example, a value over 100 causes the spell to heal the target instead of harming them.

resistAttribute
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`Number`_. Read-only. The attribute resisted. This is an index into a `tes3mobileActor`_.effectAttributes.

.. note:: The index here is 0-based, while Lua is 1-based.

source
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3alchemy`_, `tes3enchantment`_, or `tes3spell`_. Read-only. What the spell comes from.

sourceInstance
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3magicSourceInstance`_. Read-only. The unique instance of the magic source.

effectIndex
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`Number`_. Read-only. The index of the effect in **source**'s effects list.

effectInstance
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3magicEffectInstance`_. Read-only. The unique instance of the magic effect.


Filter
--------------------------------------------------------
This event may be filtered by **source**.


.. _`Event Guide`: ../guide/events.html

.. _`Number`: ../type/lua/number.html

.. _`tes3alchemy`: ../type/tes3/alchemy.html
.. _`tes3enchantment`: ../type/tes3/enchantment.html
.. _`tes3magicEffectInstance`: ../type/tes3/magicEffectInstance.html
.. _`tes3magicSourceInstance`: ../type/tes3/magicSourceInstance.html
.. _`tes3mobileActor`: ../type/tes3/mobileActor.html
.. _`tes3reference`: ../type/tes3/reference.html
.. _`tes3spell`: ../type/tes3/spell.html
