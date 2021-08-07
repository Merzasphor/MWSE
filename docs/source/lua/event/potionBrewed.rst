potionBrewed
====================================================================================================

The potionBrewed event is raised when the player brews a new potion.

Event Data
----------------------------------------------------------------------------------------------------

alembic
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3apparatus`_. Read-only. The alembic apparatus used to create the potion.

calcinator
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3apparatus`_. Read-only. The calcinator apparatus used to create the potion.

ingredients
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`table`_. Read-only. An array of up to 4 tes3ingredient objects, which were used to create the potion.

mortar
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3apparatus`_. Read-only. The mortar apparatus used to create the potion.

object
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3alchemy`_. Read-only. The potion created by the player.

retort
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3apparatus`_. Read-only. The retort apparatus used to create the potion.

Examples
----------------------------------------------------------------------------------------------------

Replace a brewed potion with a modified version
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: lua

    event.register("potionBrewed", function(e)
        local p = {
            ["name"] = "[*]" .. e.object.name,
            ["mesh"] = e.object.mesh,
            ["icon"] = e.object.icon,
            ["weight"] = e.object.weight * 2,
            ["value"] = e.object.value * 50,
            ["effects"] = {},
        }
        for i = 1, 8 do
            p.effects[i] = e.object.effects[i]
        end

        local newPotion = tes3alchemy.create(p)
        tes3.removeItem{reference = tes3.player, item = e.object, playSound = false}
        tes3.addItem{reference = tes3.player, item = newPotion, playSound = false}
    end)


.. _`table`: ../../lua/type/table.html
.. _`tes3alchemy`: ../../lua/type/tes3alchemy.html
.. _`tes3apparatus`: ../../lua/type/tes3apparatus.html
