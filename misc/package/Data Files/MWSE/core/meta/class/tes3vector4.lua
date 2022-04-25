--- @meta
--- @diagnostic disable:undefined-doc-name

--- A set of 4 floating-point numbers. You can perform following arithmetic with this type: `+`, `-`, and `*`.
--- @class tes3vector4
--- @field w number The 1st value in the vector.
--- @field x number The 2nd value in the vector.
--- @field y number The 3rd value in the vector.
--- @field z number The 4th value in the vector.
tes3vector4 = {}

--- Creates a new vector. If no parameters are provided, an empty set will be constructed.
--- @param x number? *Optional*. No description yet available.
--- @param y number? *Optional*. No description yet available.
--- @param z number? *Optional*. No description yet available.
--- @param w number? *Optional*. No description yet available.
--- @return tes3vector4 vector No description yet available.
function tes3vector4.new(x, y, z, w) end

--- Creates a copy of the vector.
--- @return tes3vector4 result No description yet available.
function tes3vector4:copy() end

--- Calculates the length of the vector.
--- @return number result No description yet available.
function tes3vector4:length() end

