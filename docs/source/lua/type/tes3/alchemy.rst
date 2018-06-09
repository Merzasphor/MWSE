
Alchemy
========================================================

This interface represents an alchemy game object.

Properties
--------------------------------------------------------

.. toctree::
   :hidden:

   alchemy/autoCalc
   alchemy/effects
   alchemy/flags
   alchemy/icon
   alchemy/model
   alchemy/name
   alchemy/script
   alchemy/value
   alchemy/weight
    
`autoCalc <alchemy/autoCalc.html>`_ (`Boolean`_)
    Shows if the object uses an auto-calculated value.
    
`boundingBox <physicalObject/boundingBox.html>`_ (`Bounding Box`_)
    The two points used to represent the object's bounding box.
    
`effects <alchemy/effects.html>`_ (`Table`_ of `Effect`_)
    An array of effects on the potion.
    
`flags <alchemy/flags.html>`_ (`Number`_)
    The alchemy-specific flags.
    
`icon <alchemy/icon.html>`_ (`String`_)
    The path to the object's icon, under *Data Files/Textures*.
    
`id <baseObject/id.html>`_ (`String`_)
    The object's unique ID.
    
`model <alchemy/model.html>`_ (`String`_)
    The path to the object's model, under *Data Files/Models*.
    
`name <alchemy/name.html>`_ (`String`_)
    The user-friendly name shown for the object.

`objectType <baseObject/objectType.html>`_ (`Number`_)
    The object's type.
    
`sceneNode <object/sceneNode.html>`_ (`NiNode`_)
    Access to the scene graph node used by the object.
    
`script <alchemy/script.html>`_ (`tes3script`_)
    The currently attached script on the object, or ``nil`` if the object is not scripted.
    
`sourceMod <baseObject/sourceMod.html>`_ (`String`_)
    The mod that this object is from.
    
`value <alchemy/value.html>`_ (`Number`_)
    The base monetary value of the item.
    
`weight <alchemy/weight.html>`_ (`Number`_)
    The weight in pounds of the object.


Functions
--------------------------------------------------------

.. toctree::
   :hidden:

   alchemy/create
    
`create <alchemy/create.html>`_
    Generates a new custom object at runtime, which will be put in the save game.


.. _`Boolean`: ../lua/boolean.html
.. _`Number`: ../lua/number.html
.. _`String`: ../lua/string.html
.. _`Table`: ../lua/table.html

.. _`NiNode`: ../ni/node.html

.. _`Bounding Box`: boundingBox.html
.. _`Effect`: effect.html
.. _`tes3script`: script.html

.. _`Object Type`: ../../../mwscript/references.html#object-types
