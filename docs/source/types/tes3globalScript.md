# tes3globalScript

A global script object. Any script (in mwscript) that is not attached to any object is a global script.

## Properties

### `context`

*Read-only*. A special context used for getting and setting script's variables.

**Returns**:

* `result` ([tes3scriptContext](../../types/tes3scriptContext))

***

### `reference`

*Read-only*. A reference this global script is tied to, if any. If the reference field isn't empty, then the global script in question is a Targeted script (a name given to it in Morrowind Scripting for Dummies).

**Returns**:

* `result` ([tes3reference](../../types/tes3reference), nil)

***

### `script`

*Read-only*. Access to global script object's associated script.

**Returns**:

* `result` ([tes3script](../../types/tes3script))

***

