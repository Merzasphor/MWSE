local tes3 = {}

-- Game constants.
tes3.apparatusType = require("tes3.ApparatusType")
tes3.attachmentType = require("tes3.AttachmentType")
tes3.attribute = require("tes3.Attribute")
tes3.attributeName = require("tes3.AttributeName")
tes3.effect = require("tes3.Effect")
tes3.enchantmentType = require("tes3.EnchantmentType")
tes3.objectType = require("tes3.ObjectType")
tes3.skill = require("tes3.Skill")
tes3.skillName = require("tes3.SkillName")
tes3.skillType = require("tes3.SkillType")
tes3.specialization = require("tes3.Specialization")
tes3.specializationName = require("tes3.SpecializationName")
tes3.spellOrigin = require("tes3.SpellOrigin")
tes3.spellType = require("tes3.SpellType")
tes3.weaponType = require("tes3.WeaponType")

-------------------------------------------------
-- Extend table API
-------------------------------------------------

function table.length(T)
	local count = 0
	for _ in pairs(T) do count = count + 1 end
	return count
end

-------------------------------------------------
-- Functions
-------------------------------------------------

function tes3.getAttributeName(attributeId)
	return tes3.AttributeName[attributeId] or "Invalid"
end

function tes3.getSkillName(skillId)
	return tes3.SkillName[skillId] or "Invalid"
end

function tes3.getSpecializationName(specializationId)
	return tes3.SpecializationName[specializationId] or "Invalid"
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