
xGetBaseID
========================================================

**Parameters:**

- *None*

**Returned:**

- ``string`` **id**: The reference's base object ID.

`xGetBaseID`_ returns reference's base object ID. In contrast to `xRefID`_, this function will not include the hexadecimal suffix that identifies unique instances of containers, creatures, or NPCs. For example, where `xRefID`_ would return "Fargoth00000000", `xGetBaseID`_ would instead return just "Fargoth".

.. _`xGetBaseID`: xGetBaseID.html
.. _`xRefID`: xRefID.html