tes3.cast
====================================================================================================

Casts a spell from a given reference to a target reference. The caster doesn't need to know the spell. By default, an actor casting will stop and perform its cast animation, but the 'instant' flag can start the cast instantly, and allow more control over the spell.

Returns
----------------------------------------------------------------------------------------------------

`boolean`_.

Parameters
----------------------------------------------------------------------------------------------------

Accepts parameters through a table with the given keys:

reference (`tes3reference`_, `tes3mobileActor`_, `string`_)
    The caster reference.

target (`tes3reference`_, `tes3mobileActor`_, `string`_)
    The target reference.

spell (`tes3spell`_, `string`_)
    The spell the caster uses.

instant (`boolean`_)
    Default: ``false``. When true, the spell is cast instantly. No animation is performed.

alwaysSucceeds (`boolean`_)
    Default: ``true``. When true, the spell cannot fail and does not consume magicka. When false, it is cast using the actor's spell skill and requires and takes enough magicka to cast. Only applies when 'instant' is true.

bypassResistances (`boolean`_)
    Default: ``false``. The spell will bypass the target's resistances. Only applies when 'instant' is true.

.. _`tes3spell`: ../../../lua/type/tes3spell.html
.. _`boolean`: ../../../lua/type/boolean.html
.. _`string`: ../../../lua/type/string.html
.. _`tes3mobileActor`: ../../../lua/type/tes3mobileActor.html
.. _`tes3reference`: ../../../lua/type/tes3reference.html
