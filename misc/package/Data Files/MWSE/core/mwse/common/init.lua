local common = {}

local dynamicTextMT = {}

--- Returns `true` if the value is or inherits from tes3reference.
---@param value any
---@return boolean
function common.isReference(value)
	return type(value) == "userdata" and value.objectType == tes3.objectType.reference
end

--- Returns `true` if the value is or inherits from tes3mobileActor.
---@param value any
---@return boolean
function common.isMobileActor(value)
	return type(value) == "userdata" and value.objectType and
			(value.objectType == tes3.objectType.mobileActor or
			value.objectType == tes3.objectType.mobileCreature or
			value.objectType == tes3.objectType.mobileNPC or
			value.objectType == tes3.objectType.mobilePlayer)
end

--- Returns `true` if the value is or inherits from tes3actor.
---@param value any
---@return boolean
function common.isActor(value)
	return type(value) == "userdata" and value.objectType and
			(value.objectType == tes3.objectType.container or
			value.objectType == tes3.objectType.creature or
			value.objectType == tes3.objectType.npc)
end

--- Gets the related `tes3reference` of a value. Simply returns the value if it already is a `tes3reference`. Returns `nil` if none has been found.
---@param value any
---@return tes3reference?
function common.getRelatedReference(value)
	if value then
		if type(value) == "string" then
			return tes3.getReference(value)
		elseif common.isReference(value) then
			return value
		elseif common.isMobileActor(value) then
			return value.reference
		elseif common.isActor(value) then
			return value.reference or value.mobile and value.mobile.reference
		end
	end
	return nil
end

--- Gets the related `tes3mobileActor` of a value. Simply returns the value if it already is a `tes3mobileActor`. Returns `nil` if none has been found.
---@param value any
---@return tes3mobileActor?
function common.getRelatedMobileActor(value)
	if value then
		if type(value) == "string" then
			local reference = tes3.getReference(value)
			if reference and common.isMobileActor(reference.mobile) then
				return reference.mobile
			end
		elseif common.isReference(value) and common.isMobileActor(value.mobile) then
			return value.mobile
		elseif common.isActor(value) then
			local mobile = value.mobile or value.reference and value.reference.mobile
			if common.isMobileActor(mobile) then
				return mobile
			end
		end
	end
	return nil
end

function common.resolveDynamicValue(value, ...)
	if (type(value) == "function") then
		return value(...)
	else
		return value
	end
end

function common.resolveDynamicText(value, ...)
	return tostring(common.resolveDynamicValue(value, ...))
end

function dynamicTextMT:__call(...)
	return common.resolveDynamicValue(self.value, self, ...)
end

function dynamicTextMT:__tostring()
	return common.resolveDynamicText(self.value, self)
end

function common.makeDynamicText(value)
	if (value == nil) then
		return nil
	end
	return setmetatable({ value = value }, dynamicTextMT)
end

common.ui = require("mwse.common.ui")

return common
