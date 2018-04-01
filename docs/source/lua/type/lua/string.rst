
String
========================================================

A string is an array of characters, representing text. Lua is 8-bit clean: strings can contain any 8-bit value, including embedded zeros (``'\0'``). Lua is also encoding-agnostic; it makes no assumptions about the contents of a string.

.. note:: In logical expressions, ``nil`` evaluates to ``false``.


Length
--------------------------------------------------------

Lua strings respect the ``#`` operator to determine its length.

.. code-block:: lua

  local str = "my cool string"
  local strLength = #str


Concatenation
--------------------------------------------------------

Strings can be formed by concatenating different objects, including other strings. The double dot (``'..'``) operator performs this operation.

.. code-block:: lua

  local x = 42
  print("x value: " .. x)

As an alternative, the `string.format() <../../api/string/format.html>`_ function can be used.
