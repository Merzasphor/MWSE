tes3.getEquippedItem
====================================================================================================

Returns an actor's equipped item stack, provided a given filter

Returns
----------------------------------------------------------------------------------------------------

`tes3equipmentStack`_.

Parameters
----------------------------------------------------------------------------------------------------

Accepts parameters through a table with the given keys:

actor (`tes3reference`_, `tes3mobileActor`_, `tes3actor`_)
    No description available.

enchanted (`boolean`_)
    Optional. If true, filters to enchanted items.

objectType (`number`_)
    Optional. Maps to tes3.objectType constants. Used to filter equipment by type.

slot (`number`_)
    Optional. Maps to tes3.armorSlot or tes3.clothingSlot. Used to filter equipment by slot.

type (`number`_)
    Optional. Maps to tes3.weaponType. Used to filter equipment by type.

Examples
----------------------------------------------------------------------------------------------------

Get Player’s Shield
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This example shows the player’s shield.

.. code-block:: lua

    local equippedShieldStack = tes3.getEquippedItem({ actor = tes3.player, objectType = tes3.objectType.armor, slot = tes3.armorSlot.shield })
    if (equippedShieldStack) then
        mwse.log("Equipped shield: %s", equippedShieldStack.object.id)
    else
        mwse.log("No shield equipped.")
    end


Get Player’s Equipped Light
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

In this example, we print the object ID of the player’s equipped light source.

.. code-block:: lua

    local equippedLightStack = tes3.getEquippedItem({ actor = tes3.player, objectType = tes3.objectType.light })
    if (equippedLightStack) then
        mwse.log("Equipped light: %s", equippedLightStack.object.id)
    else
        mwse.log("No light equipped.")
    end


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
