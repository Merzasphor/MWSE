
Physical Object
========================================================

Anything that can be physically represented in the world is based on this structure.

Inheriting structures: `Alchemy`_, `Armor`_, `Reference`_.

Inherited structures: `Base Object`_, `Object`_.


Properties
--------------------------------------------------------

.. toctree::
   :hidden:

   physicalObject/boundingBox
    
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


.. _`Boolean`: ../lua/boolean.html
.. _`Number`: ../lua/number.html
.. _`String`: ../lua/string.html
.. _`Table`: ../lua/table.html

.. _`Alchemy`: alchemy.html
.. _`Armor`: armor.html
.. _`Base Object`: baseObject.html
.. _`Bounding Box`: boundingBox.html
.. _`Object`: object.html
.. _`Reference`: reference.html

.. _`Object Type`: ../../../mwscript/references.html#object-types
