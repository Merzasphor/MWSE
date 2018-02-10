
xGetStackSize
========================================================

**Parameters:**

- *None*

**Returned:**

- ``long`` **stackSize**: The amount of items in the stack, or 0 if not called on a reference.

This function returns the stack size of a given reference. For example if used on a reference to iron arrows, xGetStackSize will tell you how many arrows there are in that stack.


Example: Get player target's stack size.
--------------------------------------------------------

::

  begin Example_xGetStackSize

  long ref
  long size

  setx ref to xGetPCTarget
  if ( ref == 0 )
      return
  endif

  setx size to ref->xGetStackSize

  if ( size > 1 )
      MessageBox "Target stack size is %g." size
  else
      MessageBox "Target is a single item."
  endif

  end
