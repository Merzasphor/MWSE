weaponReadied
====================================================================================================

This event is called when a weapon is readied, and pairs with the weaponUnreadied event. It can be used to reliably tell if a specific weapon is readied for attack. This does not necessarily mean that the animation state has changed for the first time.

Event Data
----------------------------------------------------------------------------------------------------

reference
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

tes3reference. Read-only. The reference associated with the change in readied weapon.

weaponStack
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

tes3baseObject. Read-only. The bundle that contains the newly readied weapon and its associated data.

.. _`bool`: ../../lua/type/boolean.html
.. _`nil`: ../../lua/type/nil.html
.. _`table`: ../../lua/type/table.html
.. _`string`: ../../lua/type/string.html
.. _`number`: ../../lua/type/number.html
.. _`boolean`: ../../lua/type/boolean.html
.. _`function`: ../../lua/type/function.html
