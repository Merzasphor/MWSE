
local function onCollision(e)
	if e.reference ~= tes3.player then
		return
	end

	local target = e.target
	if not target then
		return
	end

	if target.object.objectType == tes3.objectType.door then
		tes3.messageBox("Ouch!\nMaybe I should open it first?")
	end
end

event.register("collision", onCollision)
