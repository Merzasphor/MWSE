local ench = tes3.mobilePlayer.currentSpell
local charge = tes3.calculateChargeUse{ mobile = tes3.mobilePlayer, enchantment = ench }
tes3.messageBox{ message = string.format("%s uses %d charge", ench.id, charge) }