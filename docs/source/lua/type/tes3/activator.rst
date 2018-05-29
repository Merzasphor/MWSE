
Activator
========================================================

    "An activator is any object that does something in the world, but cannot be picked up. Signs, flags, levers, pressure plates, etc. It may give off sound, flash lights, and any number of effects. Activators can also be given animation." -- Morrowind Construction Set

This interface represents an activator game object.

Properties
--------------------------------------------------------

boundingBox
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`BoundingBox`_. The bounding box used for the object when it is placed in the world.

id
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`String`_. Read-only. The object's unique id.

model
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`String`_. Read-only. The path to the object's model, under *Data Files/Models*.

name
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`String`_. The user-friendly name shown for the object.

objectType
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. Read-only. The object's `Object Type`_, which will always be 1230259009. This matches the constant ``tes3.objectType.activator``.

script
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Script`_. Read-only. The currently attached script on the object, or ``nil`` if the object is not scripted.


.. _`Boolean`: ../lua/boolean.html
.. _`Number`: ../lua/number.html
.. _`String`: ../lua/string.html
.. _`Table`: ../lua/table.html

.. _`BoundingBox`: boundingBox.html
.. _`Script`: script.html

.. _`Object Type`: ../../../mwscript/references.html#object-types
