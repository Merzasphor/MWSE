One of the movement events, **calcSwimRunSpeed** is used when calculating the movement speed while in water when running.

The movement event flow is described below:

- Swimming (while running): `calcWalkSpeed`_ -> `calcSwimSpeed`_ -> **calcSwimRunSpeed** -> `calcMoveSpeed`_