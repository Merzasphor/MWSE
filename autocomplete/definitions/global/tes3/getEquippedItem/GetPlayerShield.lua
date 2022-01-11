local equippedShieldStack = tes3.getEquippedItem({ actor = tes3.player, objectType = tes3.objectType.armor, slot = tes3.armorSlot.shield })
if (equippedShieldStack) then
	mwse.log("Equipped shield: %s", equippedShieldStack.object.id)
else
	mwse.log("No shield equipped.")
end