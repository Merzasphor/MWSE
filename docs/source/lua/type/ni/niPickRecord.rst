
NiPickRecord
========================================================

The result of a ray cast.



Properties
--------------------------------------------------------

**object** (`NiAVObject`_)
    The scene graph node that was hit.

**parent** (`NiAVObject`_)
    Parent proxy scene graph node.

**intersection** (`Vector3`_)
    The exact position of the intersection. Due to floating point precision, it may be slightly inside the object, so you may need to adjust the position if used for further ray casts.

**distance** (`number`_)
    The distance of the intersection from the ray origin, as a multiplier of ray length. That is, if the ray is a unit vector this is the same as regular distance; if the ray length is 100 units, a **distance** of 0.5 is an intersection 50 units from the ray origin.

**reference** (`Reference`_)
    The reference of the object hit.

**normal** (`Vector3`_)
    The vertex normal at the intersection. Valid if the rayTest used ``returnNormal = true``.

**color** (`Vector3`_)
    The vertex color at the intersection. Valid if the rayTest used ``returnColor = true``.

**texture** (`Vector3`_)
    The texture coordinate at the intersection. Valid if the rayTest used ``returnTexture = true``.

**triangleIndex** (`number`_)
    The buffer index of the triangle hit. Valid if the rayTest used ``useModelBounds = false``.

**vertexIndex** (`number`_)
    The buffer index of the vertex hit. Valid if the rayTest used ``useModelBounds = false``.



.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html

.. _`NiAVObject`: niAVObject.html
.. _`Reference`: ../tes3/reference.html
.. _`Vector3`: ../tes3/vector3.html
