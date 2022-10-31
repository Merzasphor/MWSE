
--- This function returns `true` if the reference
--- has a variable companion set to 1 in its script.
---@param reference tes3reference
---@return boolean
local function hasCompanionShare(reference)

	-- This shows that we can read any variable inside
	-- `tes3scriptContext` objects as if it was normal Lua table
	-- (`reference.context` is of `tes3scriptContext` type)
    local companion = reference.context["companion"]
    return companion and companion == 1
end
