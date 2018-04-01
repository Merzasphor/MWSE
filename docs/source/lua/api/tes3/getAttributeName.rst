
tes3.getAttributeName
========================================================

**Parameters:**

- ``number`` **id**: The `Attribute ID`_ to get the name of.

**Returned:**

- ``string`` **name**: The name of the attribute, or *invalid* if the **id** is invalid.

This function returns the **name** of an attribute, given its **id**.

.. warning:: This function is zero-based. When iterating over some structures, the indexes might start at one. Take this into account.

Examples
--------------------------------------------------------

.. code-block:: lua

  -- Print out the names of each attribute.
  for i = 0, 7 do
      print( i .. " : " .. tes3.getAttributeName(i))
  end

.. _`Attribute ID`: ../../../mwscript/references.html#attributes
