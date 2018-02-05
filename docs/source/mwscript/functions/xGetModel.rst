
xGetModel
========================================================

**Parameters:**

- ``string`` **objectId**: The object ID to get the model of. If 0, the reference will be used.

**Returned:**

- ``string`` **modelPath**: The path to the model.

This function returns the model of an object. This can be done by passing a string for the object Id, or 0 can be passed to use the script's reference.

.. note:: The path returned does not include the *Data Files\\models* prefix.

Example: Get Model by Object ID
--------------------------------------------------------

::

  begin Example_xGetModelById

  long model

  setx model to xGetModel "ingred_bonemeal_01"
  if ( model == 0 )
      return
  endif

  xMessageFix "Model: %s" model
  MessageBox "Model: ________________________________"

  end

Example: Get Model by Reference
--------------------------------------------------------

::

  begin Example_xGetModelByRef

  long ref
  long model

  setx ref to xGetPCTarget
  if ( ref == 0 )
      return
  endif

  setx model to ref->xGetModel 0
  if ( model == 0 )
      return
  endif

  xMessageFix "Model: %s" model
  MessageBox "Model: ________________________________"

  end
