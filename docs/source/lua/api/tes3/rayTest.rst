
tes3.rayTest
========================================================

Performs a ray test against the game world, returning a ``pickRecord`` with many details on the intersection location. Note that it is relatively CPU intensive, so it should be limited to an active feature.

.. code-block:: lua

    local hitResult = tes3.rayTest({ position = ref.position, direction = tes3vector3.new(0, 0, -1), ignore = { ref } })
    if (hitResult) then
        tes3.messageBox{ message = "Hit " .. hitResult.reference.object.id }
    end
.. code-block:: lua

    local function RayTestDown(ref)

        local result = tes3.rayTest{ position = ref.position, direction = tes3vector3.new(0,0,-1), findAll = true, ignore = {ref} };

        if result then
            for i, hit in pairs(result) do
                if hit.reference then
                    mwse.log('Ray hit #%d: %s', i, hit.reference.id);
                else
                    local shouldBeLand = hit.object.parent.parent;
                    mwse.log("Ray hit #%d: %s", i, shouldBeLand.name);
                end
            end
        end
    end
    
    
Return Value
----------------------------------------------------------------------------------------------------

`NiPickRecord`_ or ``table`` of `NiPickRecord`_. Data about the intersection, or an array if **findAll** is true. ``nil`` if no intersections are found.


Parameters
----------------------------------------------------------------------------------------------------

All parameters are delivered via a table.

- `Vector3`_ **position** ``required``
    Position of the ray origin.

- `Vector3`_ **direction** ``required``
    Direction of the ray. Does not have to be unit length.

- `number`_ **maxDistance** ``optional``
    Maximum distance to trace. Using maxDistance when possible helps reduce the performance cost of ray traces, particularly in exteriors.

- `string`_ **ignore** ``optional``
    A list of references or scene nodes that should be ignored by the ray cast. Useful for avoid occulsion by a target object or the player.

- `string`_ **findAll** ``optional`` (default: false)
    If the test should find all ray intersections, instead of only the first.

- `string`_ **sort** ``optional`` (default: true)
    Sort intersections by distance.
    
- `string`_ **useModelBounds** ``optional`` (default: false)
    Use model bounds for intersection, instead of exact triangles.
    
- `string`_ **useModelCoordinates** ``optional`` (default: false)
    Use model coordinates, instead of world coordinates.
    
- `string`_ **useBackTriangles** ``optional`` (default: false)
    Include intersections with back-facing triangles.
    
- `string`_ **observeAppCullFlag** ``optional`` (default: true)
    Ignore intersections with culled (hidden) models.
    
- `string`_ **returnColor** ``optional`` (default: )
    Calculate and return the vertex color at intersections.
    
- `string`_ **returnNormal** ``optional`` (default: true)
    Calculate and return the vertex normal at intersections.
    
- `string`_ **returnSmoothNormal** ``optional`` (default: false)
    Use normal interpolation for calculating vertex normals.
    
- `string`_ **returnTexture** ``optional`` (default: false)
    Calculate and return the texture coordinate at intersections.



.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html

.. _`Vector3`: ../../type/tes3/vector3.html
.. _`NiPickRecord`: ../../type/ni/niPickRecord.html
