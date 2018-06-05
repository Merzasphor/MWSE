
Vector3
========================================================

This structure is a collection of three floating-point numbers. It is often used to represent a position or look vector.


Properties
--------------------------------------------------------
    
`length <vector3/length.html>`_
    The length of the vector.

`x <vector3/x.html>`_
    The first value in the vector.
    
`y <vector3/y.html>`_
    The second value in the vector.
    
`z <vector3/z.html>`_
    The third value in the vector.


Functions
--------------------------------------------------------

`cross <vector3/cross.html>`_
    Calculates the cross-product with another vector.
    
`distance <vector3/distance.html>`_
    Get the distance to another vector.
    
`dot <vector3/dot.html>`_
    Calculates the dot-product with another vector.
    
`heightDifference <vector3/heightDifference.html>`_
    Get the difference in height to another vector.
    
`negate <vector3/negate.html>`_
    Multiplies each of the values by -1.


Meta-Functions
--------------------------------------------------------

add
    Two vectors can be added together using the ``+`` operator.

length
    The ``#`` operator can be used to get the `length <vector3/length.html>`_ of the vector.


subtract
    Two vectors can be subtracted from one another using the ``-`` operator.


tostring
    Vectors can be serialized into a string.

    .. code-block:: lua

        -- Print the player's position.
        mwse.log("Player position: %s", tes3.getPlayerRef().position)
