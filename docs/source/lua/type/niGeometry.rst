niGeometry
====================================================================================================

Base class for most geometric objects. Includes basic vertex and normal management.
    

Properties
----------------------------------------------------------------------------------------------------

`appCulled`_ (`boolean`_)
    A flag indicating if this object is culled. When culled, it will not render, and raycasts ignore it.

`flags`_ (`number`_)
    Flags, dependent on the specific object type.

`name`_ (`string`_)
    The human-facing name of the given object.

`parent`_ (`niNode`_)
    The object's parent. It may not have one if it is not attached to the scene.

`properties`_ (`niPropertyLinkedList`_)
    The list of properties attached to this niAVObject.

`references`_ (`string`_)
    Read-only. The number of references that exist for the given object. When this value hits zero, the object's memory is freed.

`rotation`_ (`tes3matrix33`_)
    The object's local rotation matrix.

`runTimeTypeInformation`_ (`niRTTI`_)
    The runtime type information for this object.

`scale`_ (`number`_)
    The object's local uniform scaling factor.

`translation`_ (`tes3vector3`_)
    The object's local translation vector.

.. toctree::
    :hidden:

    niGeometry/appCulled
    niGeometry/flags
    niGeometry/name
    niGeometry/parent
    niGeometry/properties
    niGeometry/references
    niGeometry/rotation
    niGeometry/runTimeTypeInformation
    niGeometry/scale
    niGeometry/translation

.. _`appCulled`: niGeometry/appCulled.html
.. _`flags`: niGeometry/flags.html
.. _`name`: niGeometry/name.html
.. _`parent`: niGeometry/parent.html
.. _`properties`: niGeometry/properties.html
.. _`references`: niGeometry/references.html
.. _`rotation`: niGeometry/rotation.html
.. _`runTimeTypeInformation`: niGeometry/runTimeTypeInformation.html
.. _`scale`: niGeometry/scale.html
.. _`translation`: niGeometry/translation.html

Methods
----------------------------------------------------------------------------------------------------

`attachProperty`_
    Attach a property to this object.

`clearTransforms`_
    Resets the object's local transform.

`clone`_ (`niObject`_)
    Creates a copy of this object.

`detachProperty`_ (`niProperty`_)
    Detaches and returns a property from the object which matches the given property type.

`getObjectByName`_ (`niAVObject`_)
    Searches this node and all child nodes recursively for a node with a name that matches the argument.

`getProperty`_ (`niProperty`_)
    Gets an attached property by property type.

`isInstanceOfType`_ (`boolean`_)
    Determines if the object is of a given type, or of a type derived from the given type. Types can be found in the tes3.niType table.

`isOfType`_ (`boolean`_)
    Determines if the object is of a given type. Types can be found in the tes3.niType table.

`prependController`_
    Add a controller to the object as the first controller.

`removeAllControllers`_
    Removes all controllers.

`removeController`_
    Removes a controller from the object.

`update`_
    Updates the world transforms of this node and its children, which makes changes visible for rendering. Use after changing any local rotation, translation, scale, or bounds.

`updateEffects`_
    Update all attached effects.

`updateProperties`_
    Update all attached properties.

.. toctree::
    :hidden:

    niGeometry/attachProperty
    niGeometry/clearTransforms
    niGeometry/clone
    niGeometry/detachProperty
    niGeometry/getObjectByName
    niGeometry/getProperty
    niGeometry/isInstanceOfType
    niGeometry/isOfType
    niGeometry/prependController
    niGeometry/removeAllControllers
    niGeometry/removeController
    niGeometry/update
    niGeometry/updateEffects
    niGeometry/updateProperties

.. _`attachProperty`: niGeometry/attachProperty.html
.. _`clearTransforms`: niGeometry/clearTransforms.html
.. _`clone`: niGeometry/clone.html
.. _`detachProperty`: niGeometry/detachProperty.html
.. _`getObjectByName`: niGeometry/getObjectByName.html
.. _`getProperty`: niGeometry/getProperty.html
.. _`isInstanceOfType`: niGeometry/isInstanceOfType.html
.. _`isOfType`: niGeometry/isOfType.html
.. _`prependController`: niGeometry/prependController.html
.. _`removeAllControllers`: niGeometry/removeAllControllers.html
.. _`removeController`: niGeometry/removeController.html
.. _`update`: niGeometry/update.html
.. _`updateEffects`: niGeometry/updateEffects.html
.. _`updateProperties`: niGeometry/updateProperties.html

.. _`niObject`: ../../lua/type/niObject.html
.. _`boolean`: ../../lua/type/boolean.html
.. _`string`: ../../lua/type/string.html
.. _`number`: ../../lua/type/number.html
.. _`niNode`: ../../lua/type/niNode.html
.. _`tes3matrix33`: ../../lua/type/tes3matrix33.html
.. _`niAVObject`: ../../lua/type/niAVObject.html
.. _`niRTTI`: ../../lua/type/niRTTI.html
.. _`niPropertyLinkedList`: ../../lua/type/niPropertyLinkedList.html
.. _`niProperty`: ../../lua/type/niProperty.html
.. _`tes3vector3`: ../../lua/type/tes3vector3.html
