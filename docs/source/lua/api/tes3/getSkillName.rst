
tes3.getSkillName
========================================================

**Parameters:**

- ``number`` **id**: The `Skill ID`_ to get the name of.

**Returned:**

- ``string`` **name**: The name of the skill, or *invalid* if the **id** is invalid.

This function returns the **name** of an skill, given its **id**.

.. warning:: This function is zero-based. When iterating over some structures, the indexes might start at one. Take this into account.

Examples
--------------------------------------------------------

.. code-block:: lua

  -- Print out the names of each skill.
  for i = 0, 26 do
      print( i .. " : " .. tes3.getSkillName(i))
  end

.. _`Skill ID`: ../../../mwscript/references.html#skills
