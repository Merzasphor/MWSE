--- @meta
--- @diagnostic disable:undefined-doc-name

--- A 4 by 4 matrix. You can perform following arithmetic with this type: `+`, `-`, `*`, and `==`.
--- @class tes3matrix44
--- @field w tes3vector4 The 1st row of the matrix.
--- @field x tes3vector4 The 2nd row of the matrix.
--- @field y tes3vector4 The 3rd row of the matrix.
--- @field z tes3vector4 The 4th row of the matrix.
tes3matrix44 = {}

--- Creates a new 4 by 4 matrix from 4 provided vectors, 16 numbers or creates an empty matrix if nothing is provided.
--- @param x0 number? *Optional*. No description yet available.
--- @param y0 number? *Optional*. No description yet available.
--- @param z0 number? *Optional*. No description yet available.
--- @param w0 number? *Optional*. No description yet available.
--- @param x1 number? *Optional*. No description yet available.
--- @param y1 number? *Optional*. No description yet available.
--- @param z1 number? *Optional*. No description yet available.
--- @param w1 number? *Optional*. No description yet available.
--- @param x2 number? *Optional*. No description yet available.
--- @param y2 number? *Optional*. No description yet available.
--- @param z2 number? *Optional*. No description yet available.
--- @param w2 number? *Optional*. No description yet available.
--- @param x3 number? *Optional*. No description yet available.
--- @param y3 number? *Optional*. No description yet available.
--- @param z3 number? *Optional*. No description yet available.
--- @param w3 number? *Optional*. No description yet available.
--- @param x tes3vector4? *Optional*. No description yet available.
--- @param y tes3vector4? *Optional*. No description yet available.
--- @param z tes3vector4? *Optional*. No description yet available.
--- @param w tes3vector4? *Optional*. No description yet available.
--- @return tes3matrix44 matrix No description yet available.
function tes3matrix44.new(x0, y0, z0, w0, x1, y1, z1, w1, x2, y2, z2, w2, x3, y3, z3, w3, x, y, z, w) end

--- Creates a copy of the matrix.
--- @return tes3matrix44 result No description yet available.
function tes3matrix44:copy() end

--- Zeroes out all values in the matrix.
function tes3matrix44:toZero() end

