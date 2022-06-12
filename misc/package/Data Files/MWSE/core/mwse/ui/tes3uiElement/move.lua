
function tes3uiElement:move(params)
	assert(type(params) == "table", "Invalid parameter. This function must be called with table parameters.")

	local copy = self:copy({ to = params.to })
	self:destroy()

	return copy
end
