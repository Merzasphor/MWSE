tes3.removeEffects
====================================================================================================

Removes effects from a given reference. Requires that either the effect or castType parameter be provided.

Parameters
----------------------------------------------------------------------------------------------------

castType (`number`_)
    Optional. Maps to tes3.castType constants.

chance (`number`_)
    Default: ``100``. The chance for the effect to be removed.

effect (`number`_)
    Optional. Maps to tes3.effect constants.

reference (`tes3reference`_)
    No description available.

removeSpell (`boolean`_)
    Optional. If removing by cast type, determines if the spell should be removed from the target. Defaults to true if castType is not tes3.castType.spell.

.. _`boolean`: ../../../lua/type/boolean.html
.. _`number`: ../../../lua/type/number.html
.. _`tes3reference`: ../../../lua/type/tes3reference.html
