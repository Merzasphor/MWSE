
local newText = [[
<DIV ALIGN="LEFT"><FONT COLOR="000000" SIZE="3" FACE="Magic Cards"><BR>
Sweetroll
<BR>
]]

local function example(e)
	e.text = newText
end

event.register(tes3.event.bookGetText, example)