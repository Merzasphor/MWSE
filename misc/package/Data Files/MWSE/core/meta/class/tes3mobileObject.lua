--- @meta

--- The base object from which all other mobiles (AI/movement using) structures derive.
--- @class tes3mobileObject
--- @field boundSize tes3vector3 A vector that shows the size of the bounding box in each direction. Note that this is a convenience feature, and delivers the `x` and `y` values from `boundSize2D` with the `z` value of the mobile's `height`. Editing the values of the returned vector will not change the values that they came from, though setting the property itself will work.
--- @field boundSize2D tes3vector2 A vector that shows the size of the bounding box in X and Y directions. `boundSize` is a convenience property that exposes the bounding in 3 dimensions.
--- @field cellX number *Read-only*. The X grid coordinate of the cell the mobile is in.
--- @field cellY number *Read-only*. The Y grid coordinate of the cell the mobile is in.
--- @field flags number Access to the root mobile object flags, represented as an integer. Should not be accessed directly.
--- @field height number The height of the mobile above the ground.
--- @field impulseVelocity tes3vector3 A vector that represents the 3D acceleration of the object.
--- @field movementCollision boolean Controls if the mobile has movement collision active. When false, the mobile can move through any object, but can still block other mobiles, and can still be hit in combat. Actors will still follow pathgrids, ramps and stairs when navigating.
--- @field movementFlags number Access to the root mobile object movement flags, represented as an integer. Should not be accessed directly.
--- @field objectType number *Read-only*. The type of mobile object. Maps to values in [`tes3.objectType`](https://mwse.github.io/MWSE/references/object-types/) namespace.
--- @field playerDistance number The distance to the player. Updated every frame when the mobile is in an active cell.
--- @field position tes3vector3 A vector that represents the 3D position of the object.
--- @field prevMovementFlags number Access to the root mobile object movement flags from the previous frame, represented as an integer. Should not be accessed directly.
--- @field reference tes3reference *Read-only*. Access to the reference object for the mobile, if any.
--- @field velocity tes3vector3 A vector that represents the 3D velocity of the object.
tes3mobileObject = {}

