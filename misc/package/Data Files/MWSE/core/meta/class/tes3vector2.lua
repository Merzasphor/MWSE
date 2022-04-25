--- @meta
--- @diagnostic disable:undefined-doc-name

--- A simple pair of floating-point numbers. You can perform following arithmetic with this type: `+`, `-`, and `*`.
--- @class tes3vector2
--- @field x number The first value in the vector.
--- @field y number The second value in the vector.
tes3vector2 = {}

--- Creates a new vector. If no parameters are provided, an empty set will be constructed.
--- @param x number? *Optional*. No description yet available.
--- @param y number? *Optional*. No description yet available.
--- @return tes3vector2 vector No description yet available.
function tes3vector2.new(x, y) end

--- Creates a copy of the vector.
--- @return tes3vector2 result No description yet available.
function tes3vector2:copy() end

--- Calculates the length of the vector.
--- @return number result No description yet available.
function tes3vector2:length() end

