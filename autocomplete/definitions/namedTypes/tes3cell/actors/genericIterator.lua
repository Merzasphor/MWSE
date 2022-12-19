
--- This is a generic iterator function used
--- to loop over a tes3referenceList
---@param list tes3referenceList
---@return fun(): tes3reference
local function iterReferenceList(list)
	local function iterator()
		local ref = list.head

		if list.size ~= 0 then
			coroutine.yield(ref)
		end

		while ref.nextNode do
			ref = ref.nextNode
			coroutine.yield(ref)
		end
	end
	return coroutine.wrap(iterator)
end

-- Usage:
local list = tes3.player.cell.actors
for ref in iterReferenceList(list) do
	-- Do something with the reference
	tes3ui.log(ref.id)
end