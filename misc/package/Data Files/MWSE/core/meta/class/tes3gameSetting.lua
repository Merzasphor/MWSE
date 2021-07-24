--- @meta

--- A GMST game object.
--- @class tes3gameSetting : tes3baseObject
--- @field defaultValue number|string The default value of the GMST, if no master defines the value.
--- @field index number The array index for the GMST.
--- @field rawValue number The base value of the game setting, as stored in memory. Prefer to use .value unless you know what you're doing.
--- @field type string The type of the variable, either 'i', 'f', or 's'.
--- @field value number|string The value of the GMST.
tes3gameSetting = {}

