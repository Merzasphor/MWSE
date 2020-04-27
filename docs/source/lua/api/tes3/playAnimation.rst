tes3.playAnimation
====================================================================================================

Plays a given animation group. Optional flags can be used to define how the group starts.

Animation Start Flags
----------------------------------------------------------------------------------------------------

The ``startFlag`` parameter determines under what condition the new animation will play.

- ``tes3.animationStartFlag.normal``: The current animation will finish its full cycle, and the new animation will start from its beginning.
- ``tes3.animationStartFlag.immediate``: The current animation will stop regardless of the frame it is on, and the new animation will start from its beginning.
- ``tes3.animationStartFlag.immediateLoop``: Immediate Loop. The current animation will stop regardless of the frame it is on, and the new animation will start at the beginning of its loop cycle.

Parameters
----------------------------------------------------------------------------------------------------

Accepts parameters through a table with the given keys:

reference (`tes3mobileActor`_, `tes3reference`_, `string`_)
    The reference that will play the animation.

group (`number`_)
    Default: ``0``. The group id -- a value from 0 to 149. Maps to tes3.animationGroup.* constants.

startFlag (`number`_)
    Default: ``0``. A flag for starting the group with, matching tes3.animationStartFlag.* constants.

loopCount (`number`_)
    Optional. If provided, the animation will loop a given number of times.

.. _`bool`: ../../../lua/type/boolean.html
.. _`nil`: ../../../lua/type/nil.html
.. _`table`: ../../../lua/type/table.html
.. _`string`: ../../../lua/type/string.html
.. _`number`: ../../../lua/type/number.html
.. _`boolean`: ../../../lua/type/boolean.html
.. _`function`: ../../../lua/type/function.html
