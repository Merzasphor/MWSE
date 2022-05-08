--- @meta
--- @diagnostic disable:undefined-doc-name

--- An animation key for euler rotations.
--- @class niEulerRotKey : niRotKey, niAnimationKey
--- @field keyOrder number *Read-only*. An array of 3 values that define the ordering used for the contained keys.
--- @field keys table<number, niBezFloatKey[]|niFloatKey[]|niTCBFloatKey[]> *Read-only*. A table of x/y/z rotation keys. Each value in the table is an array of animation keys, with a length matching `numKeys`. Because an axis key can be `nil`, use `pairs` instead of `ipairs` to iterate over this table.
--- @field keyTypes number *Read-only*. An array of 3 values that define the types used for the contained keys.
--- @field lastIndices number *Read-only*. An array of 3 values that define the last indices used for each key.
--- @field numKeys number *Read-only*. An array of 3 values that define the number of keys in each xRotations/yRotations/zRotations.
niEulerRotKey = {}

