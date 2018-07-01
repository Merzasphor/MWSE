
tes3.getEquippedItem
====================================================================================================

Fetches a currently equipped `Equipment Stack`_ from an `Actor`_.

.. code-block:: lua

    local equippedLightStack = tes3.getEquippedItem({ actor = tes3.player, objectType = tes3.objectType.light })


Return Value
----------------------------------------------------------------------------------------------------

`Equipment Stack`_. The stack of equipment.


Parameters
----------------------------------------------------------------------------------------------------

All parameters are delivered via a table.

**actor** (`Actor`_, `Mobile Actor`_, or `Reference`_)
    Who to get the equipment of. 

**objectType** (`Object Type`_)
    Filter the object type to retrieve. Relates to the ``tes3.objectType.*`` constants.

**slot** or **type** (`number`_)
    Filter the slot or type of the item to retrieve. This will filter the weapon type, clothing or armor slot.

**enchanted** (`boolean`_)
    If provided, the result will be filtered by the enchantment state. A ``true`` value limits the result to enchanted items, while a ``false`` value will only return unenchanted items.


Examples
----------------------------------------------------------------------------------------------------

Get Player's Equipped Light
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

In this example, we print the object ID of the player's equipped light source.

.. code-block:: lua

    local equippedLightStack = tes3.getEquippedItem({ actor = tes3.player, objectType = tes3.objectType.light })
    if (equippedLightStack) then
        mwse.log("Equipped light: %s", equippedLightStack.object.id)
    else
        mwse.log("No light equipped.")
    end


Get Player's Shield
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This example shows the player's shield.

.. code-block:: lua

    local equippedLightStack = tes3.getEquippedItem({ actor = tes3.player, objectType = tes3.objectType.armor, slot = tes3.armorSlot.shield })
    if (equippedLightStack) then
        mwse.log("Equipped light: %s", equippedLightStack.object.id)
    else
        mwse.log("No light equipped.")
    end


.. _`boolean`: ../../type/lua/boolean.html
.. _`number`: ../../type/lua/number.html

.. _`Actor`: ../../type/tes3/actor.html
.. _`Equipment Stack`: ../../type/tes3/equipmentStack.html
.. _`Mobile Actor`: ../../type/tes3/mobileActor.html
.. _`Object Type`: ../../type/tes3/baseObject/objectType.html
.. _`Reference`: ../../type/tes3/reference.html
