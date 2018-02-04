
xGetInputConfig
========================================================

**Parameters:**

- ``long`` **controlType**: The `Control Type`_ desired. 
- ``long`` **returnType**: If 0, **keyCode** is a `Virtual-Key Code`_ and the second returned value if the code **wasConverted**. If 1, the **keyCode** returned is a `Key Scan Code`_s and the second parameter is the **device** for context.

**Returned:**

- ``long`` **keyCode**: The `Virtual-Key Code`_ or `Key Scan Code`_ for the **controlType**.
- ``long`` **wasConverted** or **device**: A special value based on **returnType**.

This function allows scripts to determine what keys are configured by the player. Typically the **keyCode** is passed to `xKeyPressed`_ to determine if it is pressed.

.. _`Control Type`: ../references.html#control-types
.. _`xKeyPressed`: xKeyPressed.html
.. _`Virtual-Key Code`: https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx
.. _`Key Scan Code`: https://msdn.microsoft.com/en-us/library/aa299374(v=vs.60).aspx

Example: Determine if the Activation Key is Pressed
--------------------------------------------------------

::

  Begin IsActivating
  
  long keyCode
  long converted
  long isPressed
  
  setx keyCode converted to xGetInputConfig 5 0
  
  ifx (converted)
      ; Activation key was successfully obtained, get its state.
      setx isPressed to xKeyPressed keyCode
      if (isPressed)
          MessageBox "Activation key pressed!"
      endif
  endif
  
  StopScript "IsActivating"
  
  End
