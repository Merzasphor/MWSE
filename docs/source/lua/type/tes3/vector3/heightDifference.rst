
heightDifference
========================================================

Calculates the height difference to another `Vector3`_.

.. code-block:: lua

    vector:heightDifference(secondVector)

Return Value
--------------------------------------------------------

`Number`_. The result of the operation.


Parameters
--------------------------------------------------------

secondVector
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Vector3`_. The second vector to get the vertical difference with.


Example
--------------------------------------------------------

.. code-block:: lua

    -- Get the player position.
    local playerPos = tes3.getPlayerRef().position

    -- Get Galbedir's position.
    local galbedirPos = tes3.getReference("galbedir").position

    -- Print the difference in vertical position.
    local difference = playerPos:heightDifference(galbedirPos)
    mwse.log("Vertical difference: %f", difference)


.. _`Number`: ../../lua/number.html

.. _`Vector3`: ../vector3.html
