
Object
========================================================

Many things that can be represented in the Construction Set is based on this structure.

Inheriting structures: `Physical Object`_, `Alchemy`_, `Armor`_, `Reference`_. 

Inherited structures: `Base Object`_.


Properties
--------------------------------------------------------

.. toctree::
   :hidden:

   object/sceneNode
    
`id <baseObject/id.html>`_ (`String`_)
    The object's unique ID.

`objectType <baseObject/objectType.html>`_ (`Number`_)
    The object's type.
    
`sceneNode <object/sceneNode.html>`_ (`NiNode`_)
    Access to the scene graph node used by the object.
    
`sourceMod <baseObject/sourceMod.html>`_ (`String`_)
    The mod that this object is from.


.. _`Boolean`: ../lua/boolean.html
.. _`Number`: ../lua/number.html
.. _`String`: ../lua/string.html
.. _`Table`: ../lua/table.html

.. _`NiNode`: ../ni/node.html

.. _`Object Type`: ../../../mwscript/references.html#object-types

.. _`Alchemy`: alchemy.html
.. _`Armor`: armor.html
.. _`Base Object`: baseObject.html
.. _`Physical Object`: physicalObject.html
.. _`Reference`: reference.html
