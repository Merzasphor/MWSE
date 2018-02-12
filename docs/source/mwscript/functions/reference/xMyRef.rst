
xMyRef
========================================================

**Parameters:**

- **None**

**Returned:**

- ``long`` **reference**: The caller's reference.

Returns a reference to the calling object.


Example: Detect if target from local script.
-------------------------------------------------------

::

  begin Example_xMyRef

  long myRef
  long targetRef

  setx targetRef to xGetPCTarget
  if ( targetRef == 0 )
      return
  endif

  setx myRef to xMyRef
  if ( myRef == targetRef )
      MessageBox "I'm being targetted!"
  endif

  end
