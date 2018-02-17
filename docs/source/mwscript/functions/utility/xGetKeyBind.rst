
xGetKeyBind
========================================================

**Parameters:**

- ``long`` **controlType**: The `Control Type`_ desired.

**Returned:**

- ``long`` **scanCode**: The `Key Scan Code`_ for the **controlType**.
- ``long`` **scanDevice**: The device type used for the associated scan code. A value of 0 is keyboard, 1 is mouse, 2 is joystick.
- ``long`` **keyCode**: The `Virtual-Key Code`_ for the **controlType**. If this value is 0, the scan code could not be converted to a key code.

This function allows scripts to determine what keys are configured by the player. Typically the **keyCode** is passed to `xKeyPressed`_ to determine if it is pressed. Other functions that require a scan code would make use of **scanCode**.

.. _`Control Type`: ../../references.html#control-types
.. _`xKeyPressed`: xKeyPressed.html
.. _`Virtual-Key Code`: https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx
.. _`Key Scan Code`: https://msdn.microsoft.com/en-us/library/aa299374(v=vs.60).aspx

Example: Determine if the Activation Key is Pressed
--------------------------------------------------------

::

  Begin IsActivating

  long scanCode
  long scanDevice
  long keyCode

  ; Get input information for the Activate key.
  setx scanCode scanDevice keyCode to xGetKeyBind 5

  ifx (keyCode)
      ; Activation key was successfully obtained, get its state.
      setx isPressed to xKeyPressed keyCode
      if (isPressed)
          MessageBox "Activation key pressed!"
      endif
  endif

  StopScript "IsActivating"

  End
