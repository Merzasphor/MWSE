# Utility Functions

--8<-- "mwse-deprecated.md"


## `xGetGlobal`

**Parameters:**

- ``string`` **globalName**: The name of the global.

**Returned:**

- ``long`` **found**: 1 if the global was found, otherwise 0.
- ``float`` **value**: The value of the global.

Returns the **value** of a global represented by **globalName**.

***

## `xGetGSString`

**Parameters:**

- ``long`` **index**: ID of the GMST to look up.

**Returned:**

- ``string`` **value**: The GMST value at the given **index**.

Fetches a GMST string by its given **index** and returns its **value**.

***

## `xGetKeyBind`

**Parameters:**

- ``long`` **controlType**: The `Control Type`_ desired.

**Returned:**

- ``long`` **scanCode**: The `Key Scan Code`_ for the **controlType**.
- ``long`` **scanDevice**: The device type used for the associated scan code. A value of 0 is keyboard, 1 is mouse, 2 is joystick.
- ``long`` **keyCode**: The [Virtual-Key Code](https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx) for the **controlType**. If this value is 0, the scan code could not be converted to a key code.

This function allows scripts to determine what keys are configured by the player. Typically the **keyCode** is passed to `xKeyPressed` to determine if it is pressed. Other functions that require a scan code would make use of **scanCode**.


??? example "Determine if the Activation Key is Pressed"
	```
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
	```

***

## `xGetMCPFeatureState`

**Parameters:**

- ``long`` **id**: Identifier for the MCP feature.

**Returned:**

- ``short`` **state**: 1 if the feature is enabled, 0 if it is disabled, or -1 if MWSE couldn't determine the MCP installation state.

This function can be used to attempt to ensure that the user has the correct [Morrowind Code Patch](https://www.nexusmods.com/morrowind/mods/19510/?) features enabled.

!!! note
	The **id** parameter comes from **mcpatch\\describe.json**. For example, 137 matches with the *Slowfall Overhaul* component.

!!! warning
	This functions depends on the user not deleting their **mcpatch\\installed** file. If the user doesn't have this file (because they deleted it or don't have the MCP installed), this function returns a value of `-1`.

??? example
	```
	begin DetectPickPocketOverhaul
	
	short state

	setx state to xGetMCPFeatureState 77

	if (state) then
		MessageBox "Pickpocket overhaul is enabled in MCP."
	endif

	end
	```

***

## `xKeyPressed`

**Parameters:**

- ``long`` **keyCode**: The [Virtual-Key Code](https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx) to check for input.

**Returned:**

- ``long`` (many) **keyStatus**: The status of **keyCode** if the parameter is non-zero. Otherwise it returns multiple times, with every key code pressed.

Monitors the status of the keyboard (and mouse buttons). This can be similar to GetPCSneaking, but actually detects whether a particular key is really being pressed. If input parameter code is a [Virtual-Key Code](https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx) (between 1 and 254) the return value will indicate the status of that key. A non-zero value means the key is being pressed. If the input code is 0, then on each call, the function will return the key code for the key (or one of the keys) currently being pressed.

!!! warning
	Some of the codes match different keys on different keyboard layouts.

!!! note
	The key VK code for a given input can be fetched using `xKeyPressed`, instead of having to rely on hardcoded values.

***

## `xLogMessage`

**Parameters:**

- ``string`` **format**: The formatting for the log message.
- ``varies`` (many) **input**: Values to inject into the **format**.

**Returned:**

- *None*

Writes out formatted strings to the log file (mwse.log). This works much like `MessageBox` but with the additional formatting options described for `xStringBuild`. A trailing ``%`` in the format string will suppress the printing of the new line sequence allowing a single line of text to be created with two or more xLogMessage calls. The number of parameters specified in the **format** *MUST* match those supplied or there will be trouble.

!!! note
	Literal strings in MWEdit have a maximum length of 63 characters.

***

## `xMessageFix`

**Parameters:**

- ``string`` (many) **newStrings**: The strings used to overwrite the following MessageBox call.

**Returned:**

- *None*

This function allows you to use strings from variables with the MessageBox function with a few restrictions.

1. The MessageBox command must immediately follow this one.
1. The number of strings for this function must match the number of strings for the MessageBox.
1. The MessageBox can have buttons but it can't use variables.
1. The values of the strings used on the MessageBox will be replaced with the values from xMessageFix, but the MessageBox strings set a maximum size for each of the xMessageFix strings (it's OK if the MessageBox strings are longer than the MessageFix ones).

Using xMessageFix can take both the string variable and literal string types and each string acts as a format string as described for the xStringBuild function. If a string ends in a single % and the formatted string takes less space than the matching string from MessageBox, the remaining characters of the MessageBox string will be used.

While it is possible to use formatted messages and buttons, it is best to format strings with `xStringBuild` if there are buttons involved because of the limit of 12 parameters per function.

***

## `xScriptRunning`

**Parameters:**

- ``string`` **scriptName**: The name of the script to determine the status of.

**Returned:**

- ``long`` **status**: 1 if the script is running, or 0 if it is not (or does not exist).

This function is a wrapper around ``ScriptRunning`` which allows a variable input.

***

## `xSetGlobal`

**Parameters:**

- ``string`` **globalName**: The name of the global.
- ``float`` **value**: The value to set the global to.

**Returned:**

- ``long`` **found**: 1 if the global was set, otherwise 0.

Set the global represented by **globalName** to **value**.

***

## `xSetGSString`

**Parameters:**

- ``long`` **index**: ID of the GMST to look up.
- ``string`` **newValue**: The value to set the GMST to.

**Returned:**

- ``long`` **valueSet**: 1 if the value was successfully set.

Fetches a GMST string by its given **index**, and sets its value to **newValue**

***

## `xStartScript`

**Parameters:**

- ``string`` **scriptName**: The name of the script to determine the status of.

**Returned:**

- *None*

This function is a wrapper around ``StartScript`` which allows a variable input.

***

## `xStopScript`

**Parameters:**

- ``string`` **scriptName**: The name of the script to determine the status of.

**Returned:**

- *None*

This function is a wrapper around ``StartScript`` which allows a variable input.

***

## `xTextInput`

**Parameters:**

- ``string`` **string**: The string to modify with the user's input.
- ``long`` **endCode**: The [Virtual-Key Code](https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx) used to stop reading input.

**Returned:**

- ``long`` **length**: The length of **text**.
- ``string`` **text**: The text entered.

This function allows you to directly read keyboard input from the user and the results will be returned as a string. Pass a string and a virtual key code to the function. The function will wait for a key to be pressed and then take one of three actions. If the key pressed matches the **endCode** parameter, the string and its length are returned. If the key pressed is a printable ASCII character, the character is added to the string and the string and the number 0 are returned. If the key is RETURN or BACKSPACE, a new line is started or one character is removed from the string, and the modifed string and a 0 are returned. The function returns after each key press so that the current value of the string can be shown with xMessageFix and MessageBox but the string should only be used normally after the length is returned. Player controls should be disabled while this function is used.

!!! note
	`xGetKeyBind` can be used to determine a specific key the user has configured.

***

## `xTextInputAlt`

**Parameters:**

- ``string`` **string**: The string to modify with the user's input.
- ``long`` **endCode**: The [Virtual-Key Code](https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx) used to stop reading input.

**Returned:**

- ``long`` **length**: The length of **text**.
- ``string`` **text**: The text entered.

This function is identical to `xTextInput` except that the function simply checks the status of keys and returns immediately rather than waiting for a key to be pressed.

***
