One of the movement events, **calcRunSpeed** is used when calculating when the player is running, but not swimming or flying.

The movement event flow is described below:

- Running: `calcWalkSpeed`_ -> **calcRunSpeed** -> `calcMoveSpeed`_