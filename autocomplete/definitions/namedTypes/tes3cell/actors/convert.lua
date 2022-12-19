
-- This function loops over the references inside the
-- tes3referenceList and adds them to an array-style table
---@param list tes3referenceList
---@return tes3reference[]
local function referenceListToTable(list)
	local result = {}
	local i = 1
	if list.size == 0 then
		return {}
	end
	local ref = list.head

	while ref.nextNode do
		result[i] = ref
		i = i + 1
		ref = ref.nextNode
	end

	-- Add the last reference
	result[i] = ref

	return result
end

-- Usage:
local list = tes3.player.cell.actors

-- The references is now a simple array style table
-- that can be looped over with regular ipairs()
local references = referenceListToTable(list)

for i, ref in ipairs(references) do
	-- Do something with the reference
	tes3ui.log(ref.id)
end