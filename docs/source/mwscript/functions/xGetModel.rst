
xGetModel
========================================================

**Parameters:**

- *None*

**Returned:**

- ``string`` **modelPath**:

This function returns the model of an object, by a given reference.

.. note:: The path returned does not include the *Data Files\\models* prefix.


Example
--------------------------------------------------------

::

  begin Example_xGetModel

  long ref
  long model

  setx ref to xGetPCTarget
  if ( ref == 0 )
      return
  endif

  setx model to ref->xGetModel
  if ( model == 0 )
      return
  endif

  xMessageFix "Model: %s" model
  MessageBox "Model: ________________________________"

  end
