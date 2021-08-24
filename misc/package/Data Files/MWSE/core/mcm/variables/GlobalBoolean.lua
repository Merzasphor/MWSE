--[[
	Stores variable as a Global short, but treats it as a Boolean, returning true/false
]]--

-- Parent class
local Parent = require("mcm.variables.Variable")

-- Class object
local GlobalVar = Parent:new()
GlobalVar.inGameOnly = true

function GlobalVar:get()
	local global = tes3.findGlobal(self.id)
	if not global then
		mwse.log("ERROR: global %s does not exist", self.id)
		return nil
	end
	if global.value ~= nil then
		return global.value ~= 0
	else
		return nil
	end
end

function GlobalVar:set(newValue)
	local global = tes3.findGlobal(self.id)
	if not global then
		mwse.log("ERROR: global %s does not exist", self.id)
		return nil
	end
	global.value = newValue and 1 or 0
end

return GlobalVar
