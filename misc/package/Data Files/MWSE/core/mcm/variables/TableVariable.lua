local Parent = require("mcm.variables.Variable")

local TableVariable = Parent:new()

function TableVariable:get()
	if self.table[self.id] == nil then
		self.table[self.id] = self.defaultSetting
	end
	return self.table[self.id]
end

function TableVariable:set(newVal)
	if (self.converter) then
		newVal = self.converter(newVal)
	end

	self.table[self.id] = newVal
end

return TableVariable
