
Base Object
========================================================

Almost anything that can be represented in the Construction Set is based on this structure.

Inheriting structures: `Object`_, `Physical Object`_, `Alchemy`_, `Armor`_, `Reference`_.


Properties
--------------------------------------------------------

.. toctree::
   :hidden:

   baseObject/objectType

**id** (`String`_)
    The object's unique ID.

`objectType <baseObject/objectType.html>`_ (`Number`_)
    The object's type.

**sourceMod** (`String`_)
    The mod that this object is from.

**disabled** (`Boolean`_)
    ``true`` if the object is disabled. Read-only.

**deleted** (`Boolean`_)
    ``true`` if the object is deleted. Read-only.


.. _`Boolean`: ../lua/boolean.html
.. _`Number`: ../lua/number.html
.. _`String`: ../lua/string.html
.. _`Table`: ../lua/table.html

.. _`Alchemy`: alchemy.html
.. _`Armor`: armor.html
.. _`Object`: object.html
.. _`Physical Object`: physicalObject.html
.. _`Reference`: reference.html
