
xDistance
========================================================

**Parameters:**

- ``reference`` **target**: The reference of the target to get the distance from.

**Returned:**

- ``float`` **distance**: The distance between the calling reference and the **target** reference.

Calculates the distance between the calling reference and **target**.

.. note:: Unlike the vanilla ``GetDistance`` function, this function will work on non-actors.

Example: Distance from PC Target
--------------------------------------------------------

This example calculates the distance between the PC and what they are looking at.

::

  begin DistanceToTarget
  
  long pcRef
  long targetRef
  float distance
  
  setx pcRef to xGetRef "player"
  setx targetRef to xGetPCTarget
  
  setx distance to pcRef->xDistance targetRef
  
  end
