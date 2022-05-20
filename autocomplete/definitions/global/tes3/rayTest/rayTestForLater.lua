local result = tes3.rayTest{ -- the result can get invalidated
	position = tes3.getPlayerEyePosition(),
	direction = tes3.getPlayerEyeVector(),
	ignore = { tes3.player }
}

local refHandle

if result then
	refHandle = tes3.makeSafeObjectHandle(result.reference)
end

local function myFunction()
	-- Before using the reference, we need to check that it's still valid.
	-- References get unloaded on cell changes etc.
	if refHandle:valid() then
		-- Now we can safely do something with our stored reference.
		local reference = refHandle:getObject()

	end
end
