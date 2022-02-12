# tes3aiPlanner

A game object which contains information on actor's current and assigned AI packages.

## Properties

### `currentPackageIndex`

*Read-only*. Access to index of currently active AI package in packages table.

**Returns**:

* `result` (number)

***

### `mobile`

The access to mobile actor this `tes3aiPlanner` object works on.

**Returns**:

* `result` ([tes3mobileActor](../../types/tes3mobileActor))

***

### `nextOpenPackageIndex`

*Read-only*. 

**Returns**:

* `result` (number)

***

### `packages`

*Read-only*. The table with `tes3aiPackage` objects assigned to this mobile actor.

**Returns**:

* `result` (table)

***

## Methods

### `getActivePackage`

Fetches currently active AI package.

```lua
local result = tes3aiPlanner:getActivePackage()
```

**Returns**:

* `result` ([tes3aiPackageActivate](../../types/tes3aiPackageActivate), [tes3aiPackageEscort](../../types/tes3aiPackageEscort), [tes3aiPackageFollow](../../types/tes3aiPackageFollow), [tes3aiPackageTravel](../../types/tes3aiPackageTravel), [tes3aiPackageWander](../../types/tes3aiPackageWander))

***

