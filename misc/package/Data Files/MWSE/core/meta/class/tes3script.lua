--- @meta

--- A script object.
--- @class tes3script : tes3baseObject
--- @field context tes3scriptContext *Read-only*. A special context used for getting and setting script's variables.
--- @field floatVariableCount number *Read-only*. The number of variables of float type in the script.
--- @field longVariableCount number *Read-only*. The number of variables of long type in the script.
--- @field shortVariableCount number *Read-only*. The number of variables of short type in the script.
tes3script = {}

--- This method fetches all of the script's variables as a table.
--- @return table results The table with all of script's variable names as keys. Each entry has the following fields:
--- 	1. type - 's', 'f' or 'l', which stand for short, float, and long
--- 	2. index - the order of occurrence of the variable in the script, starting from 0
--- 	3. value - this can have nil value
function tes3script:getVariableData() end

