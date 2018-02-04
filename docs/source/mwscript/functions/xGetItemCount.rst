
xGetItemCount
========================================================

**Parameters:**

- ``string`` **objectId**: The item's object ID to get the count of.

**Returned:**

- ``long`` **itemCount**: The number of items that the reference has.

This is a wrapper function around ``GetItemCount`` that allows variable input.


Example
--------------------------------------------------------

::

  begin Example_xGetItemCount

  long ref

  long id
  long count

  setx ref to xGetRef "player"

  setx id to xStringBuild "Gold_001"

  setx count to ref->xGetItemCount id

  MessageBox "Total Gold: %g" count

  StopScript Example_xGetItemCount

  end
