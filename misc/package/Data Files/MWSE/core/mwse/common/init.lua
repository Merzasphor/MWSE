local common = {}

local dynamicTextMT = {}

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
