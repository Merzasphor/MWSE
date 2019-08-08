Plays a given animation group. Optional flags can be used to define how the group starts.

Animation Start Flags
----------------------------------------------------------------------------------------------------

The ``startFlag`` parameter determines under what condition the new animation will play.

- ``tes3.animationStartFlag.normal``: The current animation will finish its full cycle, and the new animation will start from its beginning.
- ``tes3.animationStartFlag.immediate``: The current animation will stop regardless of the frame it is on, and the new animation will start from its beginning.
- ``tes3.animationStartFlag.immediateLoop``: Immediate Loop. The current animation will stop regardless of the frame it is on, and the new animation will start at the beginning of its loop cycle.
