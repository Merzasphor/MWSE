One of the movement events, **calcWalkSpeed** is used when calculating the base walk speed. Nearly every other movement speed event starts with this, with the exception of `calcFlySpeed`_.

The movement event flow is described below:

- Walking: **calcWalkSpeed** -> `calcMoveSpeed`_
- Running: **calcWalkSpeed** -> `calcRunSpeed`_ -> `calcMoveSpeed`_
- Swimming: **calcWalkSpeed** -> `calcSwimSpeed`_ -> `calcMoveSpeed`_
- Swimming (while running): **calcWalkSpeed** -> `calcSwimSpeed`_ -> `calcSwimRunSpeed`_ -> `calcMoveSpeed`_