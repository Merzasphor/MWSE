local tes3 = {}

-- Game constants.
tes3.apparatusType = require("mwse.tes3.apparatusType")
tes3.attachmentType = require("mwse.tes3.attachmentType")
tes3.attribute = require("mwse.tes3.attribute")
tes3.attributeName = require("mwse.tes3.attributeName")
tes3.effect = require("mwse.tes3.effect")
tes3.enchantmentType = require("mwse.tes3.enchantmentType")
tes3.keybind = require("mwse.tes3.keybind")
tes3.keyTransition = require("mwse.tes3.keyTransition")
tes3.objectType = require("mwse.tes3.objectType")
tes3.skill = require("mwse.tes3.skill")
tes3.skillName = require("mwse.tes3.skillName")
tes3.skillType = require("mwse.tes3.skillType")
tes3.specialization = require("mwse.tes3.specialization")
tes3.specializationName = require("mwse.tes3.specializationName")
tes3.spellOrigin = require("mwse.tes3.spellOrigin")
tes3.spellType = require("mwse.tes3.spellType")
tes3.weaponType = require("mwse.tes3.weaponType")

-------------------------------------------------
-- Functions
-------------------------------------------------

-- Translate an attribute constant to a readable name.
function tes3.getAttributeName(attributeId)
	return tes3.attributeName[attributeId] or "invalid"
end

-- Translate an skill constant to a readable name.
function tes3.getSkillName(skillId)
	return tes3.skillName[skillId] or "invalid"
end

-- Translate an specialization constant to a readable name.
function tes3.getSpecializationName(specializationId)
	return tes3.specializationName[specializationId] or "invalid"
end

-- Return an attachment from a reference.
function tes3.getAttachment(reference, attachment)
	return reference and reference.attachments and reference.attachments[attachment]
end

-- Get a reference's owner.
function tes3.getOwner(reference)
	local vars = tes3.getAttachment(reference, "variables")
	if (vars) then
		return vars.owner
	end
end

-- Iterator to use TES3::Iterator in a for loop.
function tes3.iterate(iterator)
	local node = iterator.head
	return function()
		if (node) then
			local data = node.nodeData
			node = node.nextNode
			return data
		end
	end
end

-- Iterator to use TES3::TArray in a for loop.
function tes3.loopTArray(tarray)
	local index = 0
	local length = #tarray
	return function()
		index = index + 1
		if (index <= length) then
			return tarray[index]
		end
	end
end

return tes3