
--- This is a generic iterator function that is used
--- to loop over all the items in an inventory
---@param ref tes3reference
---@return fun(): tes3item, integer, tes3itemData|nil
local function iterItems(ref)
	local function iterator()
		for _, stack in pairs(ref.object.inventory) do
			---@cast stack tes3itemStack
			local item = stack.object

			-- Account for restocking items,
			-- since their count is negative
			local count = math.abs(stack.count)

			-- first yield stacks with custom data
			if stack.variables then
				for _, data in pairs(stack.variables) do
					if data then
						coroutine.yield(item, data.count, data)
						count = count - data.count
					end
				end
			end
			-- then yield all the remaining copies
			if count > 0 then
				coroutine.yield(item, count)
			end
		end
	end
	return coroutine.wrap(iterator)
end

for item, count, itemData in iterItems(tes3.player) do
	debug.log(item)
	debug.log(count)
	debug.log(itemData)
end