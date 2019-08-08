local hitResult = tes3.rayTest({ position = tes3.getCameraPosition(), direction = tes3.getCameraVector() })
local hitReference = hitResult and hitResult.reference
if (hitReference == nil) then
	return
end

tes3.messageBox("The camera is looking at a '%s'", hitReference.object.name or hitReference.object.id)