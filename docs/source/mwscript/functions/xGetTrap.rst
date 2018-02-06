
xGetTrap
========================================================

**Parameters:**

- *None*

**Returned:**

- ``string`` **spellID**: The trap's spell ID.
- ``string`` **spellName**: The trap's spell name.
- ``short`` **spellCost**: The trap's spell cost.

Returns info about the reference's trap spell. Only works on container and doors. All returns will be zero if no trap is present.

.. tip:: Use `xSetTrap`_ to edit this value.

.. _`xSetTrap`: xSetTrap.html