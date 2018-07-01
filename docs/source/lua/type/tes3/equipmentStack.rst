
Equipment Stack
========================================================

A container used to house equipped items. It's a simple structure that exposes the equipped item **object**, and its associated **variables**.


Properties
--------------------------------------------------------

**object** (`tes3object`_, read-only)
    The equipped object. This may be a ring, pauldron, weapon, light, or anything else that can be equipped.

**variables** (`tes3variablesNode`_, read-only)
    Variables associated with the object, including item health, charge, and other data.


.. _`boolean`: ../lua/boolean.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html
.. _`userdata`: ../lua/userdata.html

.. _`tes3object`: object.html
.. _`tes3variablesNode`: variablesNode.html
