This event is called when an actor’s movement speed is calculated. The event allows modification of this value, to dehardcode actor movement speeds.
Invoked after all other movement speed events are finished.

The movement event flow is described below:

- Walking: `calcWalkSpeed`_ -> **calcMoveSpeed**
- Running: `calcWalkSpeed`_ -> `calcRunSpeed`_ -> **calcMoveSpeed**
- Swimming: `calcWalkSpeed`_ -> `calcSwimSpeed`_ -> **calcMoveSpeed**
- Swimming (while running): `calcWalkSpeed`_ -> `calcSwimSpeed`_ -> `calcSwimRunSpeed`_ -> **calcMoveSpeed**
- Flying: `calcFlySpeed`_ -> **calcMoveSpeed**