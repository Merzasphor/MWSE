activate
====================================================================================================

This event is invoked whenever something is activated, typically by the player. Activation is usually done with the associated activate/use key, but may also be forced by scripts.

Non-player actors may also activate objects, such as when opening doors, or via MWSE functions like `xActivate`_ or ``tes3.activate()``.

Some examples of when the activate event fires includes:

- When a door is used.
- When an item is picked up.
- When someone attempts to open a container.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.

Event Data
----------------------------------------------------------------------------------------------------

activator
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3reference`_Read-only. The actor attempting to trigger the event.

target
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3reference`_Read-only. The reference that is being activated.

Examples
----------------------------------------------------------------------------------------------------

Show a message for what the player is activating
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: lua

    -- Show the id when the player activates an object.
    local function myOnActivateCallback(e)
        if (e.activator == tes3.player) then
            tes3.messageBox({ message = "Activated " .. e.target.object.id })
        end
    end
    event.register("activate", myOnActivateCallback)


Prevent the player from activating NPCs
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: lua


    -- Show the id when the player activates an object.
    local function myOnActivateCallback(e)
        -- We only care if the PC is activating something.
        if (e.activator ~= tes3.player) then
            return
        end

        -- If the player targets an NPC, block the activation.
        if (e.target.object.objectType == tes3.objectType.npc) then
            return false
        end
    end
    event.register("activate", myOnActivateCallback)


.. _`xActivate`: ../../mwscript/functions/actor/xActivate.html
.. _`Event Guide`: ../../lua/guide/events.html
.. _`tes3bodyPart`: ../../lua/type/tes3bodyPart.html
.. _`string`: ../../lua/type/string.html
.. _`mwseTimer`: ../../lua/type/mwseTimer.html
.. _`tes3book`: ../../lua/type/tes3book.html
.. _`tes3matrix33`: ../../lua/type/tes3matrix33.html
.. _`nil`: ../../lua/type/nil.html
.. _`tes3actor`: ../../lua/type/tes3actor.html
.. _`tes3clothing`: ../../lua/type/tes3clothing.html
.. _`tes3vector3`: ../../lua/type/tes3vector3.html
.. _`tes3activator`: ../../lua/type/tes3activator.html
.. _`niAVObject`: ../../lua/type/niAVObject.html
.. _`tes3boundingBox`: ../../lua/type/tes3boundingBox.html
.. _`tes3lockNode`: ../../lua/type/tes3lockNode.html
.. _`tes3cell`: ../../lua/type/tes3cell.html
.. _`tes3class`: ../../lua/type/tes3class.html
.. _`tes3apparatus`: ../../lua/type/tes3apparatus.html
.. _`number`: ../../lua/type/number.html
.. _`tes3actionData`: ../../lua/type/tes3actionData.html
.. _`niRTTI`: ../../lua/type/niRTTI.html
.. _`niObjectNET`: ../../lua/type/niObjectNET.html
.. _`function`: ../../lua/type/function.html
.. _`tes3baseObject`: ../../lua/type/tes3baseObject.html
.. _`tes3armor`: ../../lua/type/tes3armor.html
.. _`tes3reference`: ../../lua/type/tes3reference.html
.. _`tes3packedColor`: ../../lua/type/tes3packedColor.html
.. _`bool`: ../../lua/type/boolean.html
.. _`tes3rangeInt`: ../../lua/type/tes3rangeInt.html
.. _`mwseTimerController`: ../../lua/type/mwseTimerController.html
.. _`tes3wearablePart`: ../../lua/type/tes3wearablePart.html
.. _`tes3vector4`: ../../lua/type/tes3vector4.html
.. _`tes3vector2`: ../../lua/type/tes3vector2.html
.. _`tes3cellExteriorData`: ../../lua/type/tes3cellExteriorData.html
.. _`tes3travelDestinationNode`: ../../lua/type/tes3travelDestinationNode.html
.. _`tes3transform`: ../../lua/type/tes3transform.html
.. _`niObject`: ../../lua/type/niObject.html
.. _`tes3physicalObject`: ../../lua/type/tes3physicalObject.html
.. _`tes3alchemy`: ../../lua/type/tes3alchemy.html
.. _`table`: ../../lua/type/table.html
.. _`boolean`: ../../lua/type/boolean.html
.. _`tes3object`: ../../lua/type/tes3object.html
