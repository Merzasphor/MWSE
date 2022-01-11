local equippedLightStack = tes3.getEquippedItem({ actor = tes3.player, objectType = tes3.objectType.light })
if (equippedLightStack) then
	mwse.log("Equipped light: %s", equippedLightStack.object.id)
else
	mwse.log("No light equipped.")
end