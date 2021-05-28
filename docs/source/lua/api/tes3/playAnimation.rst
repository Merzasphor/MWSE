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
    Default: ``1``. A flag for starting the group with, matching tes3.animationStartFlag.* constants. Defaults to tes3.animationStartFlag.immediate for convenience.

loopCount (`number`_)
    Optional. If provided, the animation will loop a given number of times.

mesh (`string`_)
    Optional. Deprecated. Please use tes3.loadAnimation (check its documentation).

.. _`string`: ../../../lua/type/string.html
.. _`number`: ../../../lua/type/number.html
.. _`tes3mobileActor`: ../../../lua/type/tes3mobileActor.html
.. _`tes3reference`: ../../../lua/type/tes3reference.html
