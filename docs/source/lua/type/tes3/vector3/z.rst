
z
========================================================

This property provides access to the first value in a `Vector3`_.

.. note:: As vectors can be used to represent colors, this property can be accessed using ``b``.


Example: Print a vector's values
--------------------------------------------------------

This example shows how to use `x`_, `y`_, and **z** and print it to the MWSE log.

.. code-block:: lua

    local position = tes3.getPlayerRef().position
    mwse.log("Player position: x = %f, y = %f, z = %f", position.x, position.y, position.z)

.. _`Vector3`: ../vector3.html
.. _`x`: x.html
.. _`y`: y.html
