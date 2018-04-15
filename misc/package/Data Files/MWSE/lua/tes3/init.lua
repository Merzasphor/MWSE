local tes3 = {}

-- Game constants.
tes3.apparatusType = require("tes3.apparatusType")
tes3.attachmentType = require("tes3.attachmentType")
tes3.attribute = require("tes3.attribute")
tes3.attributeName = require("tes3.attributeName")
tes3.effect = require("tes3.effect")
tes3.enchantmentType = require("tes3.enchantmentType")
tes3.objectType = require("tes3.objectType")
tes3.skill = require("tes3.skill")
tes3.skillName = require("tes3.skillName")
tes3.skillType = require("tes3.skillType")
tes3.specialization = require("tes3.specialization")
tes3.specializationName = require("tes3.specializationName")
tes3.spellOrigin = require("tes3.spellOrigin")
tes3.spellType = require("tes3.spellType")
tes3.weaponType = require("tes3.weaponType")

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
	return tes3.attributeName[attributeId] or "invalid"
end

function tes3.getSkillName(skillId)
	return tes3.skillName[skillId] or "invalid"
end

function tes3.getSpecializationName(specializationId)
	return tes3.specializationName[specializationId] or "invalid"
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