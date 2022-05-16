--- @meta
--- @diagnostic disable:undefined-doc-name

--- An attachment to NiObjectNETs that allows the storing of arbitrary data onto the given object.
--- @class niExtraData : niObject
--- @field genericData number[] *Read-only*. Generic data held in the extra data. This is not used if a subtype of extra data is used.
--- @field next niExtraData|niStringExtraData The next extra data available on the object.
niExtraData = {}

