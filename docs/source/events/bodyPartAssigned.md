# bodyPartAssigned

Allows reading and overwriting body part assignments.

```lua
--- @param e bodyPartAssignedEventData
local function bodyPartAssignedCallback(e)
end
event.register(tes3.event.bodyPartAssigned, bodyPartAssignedCallback)
```

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `bodyPart` ([tes3bodyPart](../../types/tes3bodyPart)): The body part object assigned.
* `index` (number): *Read-only*. The body slot index of the newly assigned body part. Maps to values in [`tes3.activeBodyPart`](https://mwse.github.io/MWSE/references/active-body-parts/) constants.
* `isFirstPerson` (boolean): *Read-only*. A flag that controls whether the newly assigned body part is used while the camera is in the first person.
* `manager` ([tes3bodyPartManager](../../types/tes3bodyPartManager)): *Read-only*. The access to the body part manager that is associated with the reference that had a body part assigned.
* `object` ([tes3physicalObject](../../types/tes3physicalObject)): *Read-only*. Access to the physical object for the assigned body part.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference for the actor whose body part was assigned.

