One of the movement events, **calcSwimSpeed** is used when calculating the movement speed while in water when running.

The movement event flow is described below:

- Swimming: `calcWalkSpeed`_ -> **calcSwimSpeed** -> `calcMoveSpeed`_
- Swimming (while running): `calcWalkSpeed`_ -> **calcSwimSpeed** -> `calcSwimRunSpeed`_ -> `calcMoveSpeed`_