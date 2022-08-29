
local newText = [[<div align="left"><font color="002200" size="3" face="Magic Cards"><br>
Sweetroll
<br>
]]

local function example(e)
	e.text = newText
end

event.register(tes3.event.bookGetText, example)