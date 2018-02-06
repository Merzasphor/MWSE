
xMessageFix
========================================================

**Parameters:**

- ``string`` (many) **newStrings**: The strings used to overwrite the following MessageBox call.

**Returned:**

- *None*

This function allows you to use strings from variables with the MessageBox function with a few restrictions.

1. The MessageBox command must immediately follow this one.

2. The number of strings for this function must match the number of strings for the MessageBox.

3. The MessageBox can have buttons but it can't use variables.

4. The values of the strings used on the MessageBox will be replaced with the values from xMessageFix, but the MessageBox strings set a maximum size for each of the xMessageFix strings (it's OK if the MessageBox strings are longer than the MessageFix ones).

Using xMessageFix can take both the string variable and literal string types and each string acts as a format string as described for the xStringBuild function. If a string ends in a single % and the formatted string takes less space than the matching string from MessageBox, the remaining characters of the MessageBox string will be used.

While it is possible to use formatted messages and buttons, it is best to format strings with `xStringBuild`_ if there are buttons involved because of the limit of 12 parameters per function.

.. _`xStringBuild`: xStringBuild.html
