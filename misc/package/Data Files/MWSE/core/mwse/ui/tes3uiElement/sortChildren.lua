
function tes3uiElement:sortChildren(fn)
	-- Sort our children list.
	local children = self.children
	table.sort(children, fn)

	-- Rearrange children.
	for i, child in ipairs(children) do
		self:reorderChildren(i, child, 1)
	end
end
