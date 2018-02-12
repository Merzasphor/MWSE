
xActivate
========================================================

**Parameters:**

- ``reference`` **target**: What the reference will try to activate. 

**Returned:**

- *None*

This function allows the forced activation of one reference onto another. Unlike the vanilla ``Activate`` function, this allows variable input and will work even when ``OnActivate`` hasn't been triggered in the script.

.. note:: Unlike the vanilla activate function, the reference is the actor that will activate something, rather than the object to activate.

Example: Force the PC to Activate
--------------------------------------------------------

::

  begin test
  
  long targetRef
  long pcRef
  
  ; Don't force pickup if we're not sneaking.
  if ( GetPCSneaking == 0 )
      return
  endif
  
  ; Get a reference to what the player is looking at.
  setx targetRef to xGetPCTarget
  if ( targetRef == 0 )
      return
  endif
  
  ; Get a reference to the player, and force them to activate what they are looking at.
  setx pcRef to xGetRef "player"
  pcRef->xActivate targetRef
  
  end
