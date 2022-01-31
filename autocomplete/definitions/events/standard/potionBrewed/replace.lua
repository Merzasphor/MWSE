event.register(tes3.event.potionBrewed, function(e)
	local p = {
		["name"] = "[*]" .. e.object.name,
		["mesh"] = e.object.mesh,
		["icon"] = e.object.icon,
		["weight"] = e.object.weight * 2,
		["value"] = e.object.value * 50,
		["effects"] = {},
	}
	for i = 1, 8 do
		p.effects[i] = e.object.effects[i]
	end

	local newPotion = tes3alchemy.create(p)
	tes3.removeItem{reference = tes3.player, item = e.object, playSound = false}
	tes3.addItem{reference = tes3.player, item = newPotion, playSound = false}
end)
