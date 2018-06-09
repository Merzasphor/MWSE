
Object
========================================================

Many things that can be represented in the Construction Set is based on this structure.

Inheriting structures: `Physical Object`_, `Apparatus`_, `Armor`_, `Book`_, `Clothing`_, `Container`_, `Door`_, `Light`_, `Lockpick`_, `MiscItem`_, `Probe`_, `RepairItem`_, `Static`_, `Activator`_, `Alchemy`_,  `Reference`_

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

.. _`Apparatus`: apparatus.html
.. _`Armor`: armor.html
.. _`Book`: book.html
.. _`Clothing`: clothing.html
.. _`Container`: container.html
.. _`Door`: door.html
.. _`Light`: light.html
.. _`Lockpick`: lockpick.html
.. _`MiscItem`: miscitem.html
.. _`Probe`: probe.html
.. _`RepairItem`: repairitem.html
.. _`Static`: static.html
.. _`Activator`: activator.html
.. _`Alchemy`: alchemy.html

.. _`Base Object`: baseObject.html
.. _`Physical Object`: physicalObject.html
.. _`Reference`: reference.html

.. _`Object Type`: ../../../mwscript/references.html#object-types
