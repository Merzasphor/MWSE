local tes3 = {}

-- Game constants.
tes3.ApparatusType = require("tes3.ApparatusType")
tes3.AttachmentType = require("tes3.AttachmentType")
tes3.Attribute = require("tes3.Attribute")
tes3.AttributeName = require("tes3.AttributeName")
tes3.Effect = require("tes3.Effect")
tes3.EnchantmentType = require("tes3.EnchantmentType")
tes3.ObjectType = require("tes3.ObjectType")
tes3.Skill = require("tes3.Skill")
tes3.SkillName = require("tes3.SkillName")
tes3.SkillType = require("tes3.SkillType")
tes3.Specialization = require("tes3.Specialization")
tes3.SpecializationName = require("tes3.SpecializationName")
tes3.SpellOrigin = require("tes3.SpellOrigin")
tes3.SpellType = require("tes3.SpellType")
tes3.WeaponType = require("tes3.WeaponType")

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
			local data = node.data
			node = node.nextNode
			return data
		end
	end
end

return tes3