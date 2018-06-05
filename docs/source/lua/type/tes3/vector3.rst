
Vector3
========================================================

This structure is a collection of three floating-point numbers. It is often used to represent a position or look vector.


Properties
--------------------------------------------------------

.. toctree::
   :maxdepth: 1

   vector3/length
   vector3/x
   vector3/y
   vector3/z


Functions
--------------------------------------------------------

.. toctree::
   :maxdepth: 1

   vector3/cross
   vector3/distance
   vector3/dot
   vector3/heightDifference
   vector3/negate


Meta-Functions
--------------------------------------------------------

add
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Two vectors can be added together using the ``+`` operator.


length
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The ``#`` operator can be used to get the `length`_ of the vector.


subtract
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Two vectors can be subtracted from one another using the ``-`` operator.


tostring
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Vectors can be serialized into a string.

.. code-block:: lua

    -- Print the player's position.
    mwse.log("Player position: %s", tes3.getPlayerRef().position)


.. _`length`: vector3/length.html
