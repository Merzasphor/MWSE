tes3.rayTest
====================================================================================================

Preforms a ray test and returns various information related to the result(s). If findAll is set, the result will be a table of results, otherwise only the first result is returned.

Returns
----------------------------------------------------------------------------------------------------

`niPickRecord`_.

Parameters
----------------------------------------------------------------------------------------------------

Accepts parameters through a table with the given keys:

position (`tes3vector3`_, `table`_)
    No description available.

direction (`tes3vector3`_, `table`_)
    No description available.

findAll (`boolean`_)
    If true, the ray test won't stop after the first result.

sort (`boolean`_)
    Default: ``true``. If true, the results will be sorted by distance from the origin position.

useModelBounds (`boolean`_)
    If true, model bounds will be tested for intersection. Otherwise triangles will be used.

useModelCoordinates (`boolean`_)
    If true, model coordinates will be used instead of world coordinates.

useBackTriangles (`boolean`_)
    No description available.

observeAppCullFlag (`boolean`_)
    Default: ``true``. No description available.

returnColor (`boolean`_)
    No description available.

returnNormal (`boolean`_)
    Default: ``true``. No description available.

returnSmoothNormal (`boolean`_)
    No description available.

returnTexture (`boolean`_)
    No description available.

ignore (`table`_)
    Optional. An array of references and/or scene graph nodes to cull from the result(s).

.. _`tes3bodyPart`: ../../../lua/type/tes3bodyPart.html
.. _`string`: ../../../lua/type/string.html
.. _`mwseTimer`: ../../../lua/type/mwseTimer.html
.. _`tes3book`: ../../../lua/type/tes3book.html
.. _`tes3matrix33`: ../../../lua/type/tes3matrix33.html
.. _`nil`: ../../../lua/type/nil.html
.. _`tes3actor`: ../../../lua/type/tes3actor.html
.. _`tes3clothing`: ../../../lua/type/tes3clothing.html
.. _`tes3vector3`: ../../../lua/type/tes3vector3.html
.. _`tes3activator`: ../../../lua/type/tes3activator.html
.. _`niAVObject`: ../../../lua/type/niAVObject.html
.. _`tes3boundingBox`: ../../../lua/type/tes3boundingBox.html
.. _`tes3lockNode`: ../../../lua/type/tes3lockNode.html
.. _`tes3cell`: ../../../lua/type/tes3cell.html
.. _`tes3class`: ../../../lua/type/tes3class.html
.. _`tes3apparatus`: ../../../lua/type/tes3apparatus.html
.. _`number`: ../../../lua/type/number.html
.. _`tes3actionData`: ../../../lua/type/tes3actionData.html
.. _`niRTTI`: ../../../lua/type/niRTTI.html
.. _`niObjectNET`: ../../../lua/type/niObjectNET.html
.. _`function`: ../../../lua/type/function.html
.. _`tes3baseObject`: ../../../lua/type/tes3baseObject.html
.. _`tes3armor`: ../../../lua/type/tes3armor.html
.. _`tes3reference`: ../../../lua/type/tes3reference.html
.. _`tes3packedColor`: ../../../lua/type/tes3packedColor.html
.. _`bool`: ../../../lua/type/boolean.html
.. _`tes3rangeInt`: ../../../lua/type/tes3rangeInt.html
.. _`mwseTimerController`: ../../../lua/type/mwseTimerController.html
.. _`tes3wearablePart`: ../../../lua/type/tes3wearablePart.html
.. _`tes3vector4`: ../../../lua/type/tes3vector4.html
.. _`tes3vector2`: ../../../lua/type/tes3vector2.html
.. _`tes3cellExteriorData`: ../../../lua/type/tes3cellExteriorData.html
.. _`tes3travelDestinationNode`: ../../../lua/type/tes3travelDestinationNode.html
.. _`tes3transform`: ../../../lua/type/tes3transform.html
.. _`niObject`: ../../../lua/type/niObject.html
.. _`tes3physicalObject`: ../../../lua/type/tes3physicalObject.html
.. _`tes3alchemy`: ../../../lua/type/tes3alchemy.html
.. _`table`: ../../../lua/type/table.html
.. _`boolean`: ../../../lua/type/boolean.html
.. _`tes3object`: ../../../lua/type/tes3object.html
