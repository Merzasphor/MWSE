
local function showMessage(e)
	if e.mobile.readiedWeapon then
		local id = e.mobile.readiedWeapon.object.skillId
		local name = tes3.getSkillName(id)

		tes3.messageBox(name)
	end
end

event.register(tes3.event.attackStart, showMessage)
