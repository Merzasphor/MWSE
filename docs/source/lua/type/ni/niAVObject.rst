
NiAVObject
========================================================

A displayable scene graph node with transforms.

Inheriting structures: `NiNode`_.


Properties
--------------------------------------------------------

**flags** (`number`_)
    Raw flags data.

**appCulled** (`boolean`_)
    ``true`` if the object is excluded from rendering.

**parent** (`NiNode`_)
    The parent node of this node.

**properties** (`table`_ of ``NiProperty``)
    Child properties. Read-only.

**rotation** (`Matrix33`_)
    The local rotation matrix of this node relative to its parent. ``propagatePositionChange`` should be called after changes are made to update the scene graph.

**translation** (`Vector3`_)
    The local translation of this node relative to its parent. ``propagatePositionChange`` should be called after changes are made to update the scene graph.

**scale** (`number`_)
    The uniform scaling applied to this node. ``propagatePositionChange`` should be called after changes are made to update the scene graph.

**worldBoundOrigin** (`Vector3`_)
    The center of the bounding sphere in world coordinates.

**worldBoundRadius** (`number`_)
    The radius of the bounding sphere.

**worldTransform** (``Transform``)
    The object-to-world transform of this node, with properties ``rotation``, ``translation``, and ``scale``.


Inherited from ``NiObjectNET``:

**controller** (``NiController``)
    The object's animation controller. Read-only.

**name** (`string`_)
    The object's scene graph name.


Inherited from ``NiObject``:

**refCount** (`number`_)
    The number of active references to this object. Read-only.

**RTTI** (``RTTI``)
    The runtime type information for the object instance. Read-only.

**runTimeTypeInformation** (``RTTI``)
    The runtime type information for the object instance. Read-only.


Functions
--------------------------------------------------------

`NiAVObject`_ **getObjectByName** (`string`_ name)
    Searches the current object and children for an object with the given name.

``NiProperty`` **getProperty** (``NiPropertyType`` propertyType)
    Finds a property by type.

**attachProperty** (``NiProperty`` property)
    Attaches a property to the object.

**detachProperty** (`number`_ propertyType)
    Detaches a property by type.

**clearTransforms** ()
    Resets the local transform.

**propagatePositionChange** ()
    Updates world transforms of the object and all its children after changes are made to local transform data.

**updateNodeEffects** ()
    Updates effects dependent on the object transform.

**updateTextureProperties** ()
    Unknown.

    
Inherited from ``NiObjectNET``:

**prependController** (``NiTimeController`` controller)
    Adds a controller to the object.

**removeController** (``NiTimeController`` controller)
    Removes a controller from the object.

**removeAllControllers** ()
    Removes all controllers from the object.


Inherited from ``NiObject``:

``NiObject`` **clone** ()
    Creates a shallow copy of this object.

`boolean`_ **isOfType** (``RTTI`` rtti)
    Returns ``true`` if the object type exactly matches the ``rtti`` type.

`boolean`_ **isInstanceOfType** (``RTTI`` rtti)
    Returns ``true`` if the object type matches or inherits from from the ``rtti`` type.



.. _`boolean`: ../lua/boolean.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html

.. _`NiAVObject`: niAVObject.html
.. _`NiNode`: niNode.html

.. _`Matrix33`: ../tes/matrix33.html
.. _`Vector3`: ../test/vector3.html
