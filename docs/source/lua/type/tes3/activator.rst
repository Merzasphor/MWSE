
Activator
========================================================

    "An activator is any object that does something in the world, but cannot be picked up. Signs, flags, levers, pressure plates, etc. It may give off sound, flash lights, and any number of effects. Activators can also be given animation." -- Morrowind Construction Set

This interface represents an activator game object.

Properties
--------------------------------------------------------

.. toctree::
   :hidden:

   activator/model
   activator/name
   activator/script
    
`id <baseObject/id.html>`_ (`String`_)
    The object's unique ID.

`objectType <baseObject/objectType.html>`_ (`Number`_)
    The object's type.
    
`sourceMod <baseObject/sourceMod.html>`_ (`String`_)
    The mod that this object is from.
    
`sceneNode <object/sceneNode.html>`_ (`NiNode`_)
    Access to the scene graph node used by the object.
    
`boundingBox <physicalObject/boundingBox.html>`_ (`Bounding Box`_)
    The two points used to represent the object's bounding box.
    
`model <activator/model.html>`_ (`String`_)
    The path to the object's model, under *Data Files/Models*.
    
`name <activator/name.html>`_ (`String`_)
    The user-friendly name shown for the object.
    
`script <activator/script.html>`_ (`tes3script`_)
    The currently attached script on the object, or ``nil`` if the object is not scripted.


.. _`Boolean`: ../lua/boolean.html
.. _`Number`: ../lua/number.html
.. _`String`: ../lua/string.html
.. _`Table`: ../lua/table.html

.. _`NiNode`: ../ni/node.html

.. _`Bounding Box`: boundingBox.html
.. _`tes3script`: script.html
