local hitResult = tes3.rayTest({ position = tes3.getPlayerEyePosition(), direction = tes3.getPlayerEyeVector() })
local hitReference = hitResult and hitResult.reference
if (hitReference == nil) then
	return
end

tes3.messageBox("The player is looking at a '%s'", hitReference.object.name or hitReference.object.id)