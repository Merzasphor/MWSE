local function showNotifyMenu(str, ...)
	return tes3.messageBox(tostring(str):format(...))
end

return showNotifyMenu
