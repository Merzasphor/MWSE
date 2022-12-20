local function onKey()
	local menu = tes3ui.findHelpLayerMenu("testing:Menu")

	if not menu then
		menu = tes3ui.createHelpLayerMenu({ id = "testing:Menu" })
		menu:destroyChildren()
		menu.absolutePosAlignX = 0.1
		menu.absolutePosAlignY = 0.05
		menu.autoWidth = false
		menu.autoHeight = false
		menu.paddingLeft = 8
		menu.paddingRight = 8
		menu.paddingTop = 8
		menu.paddingBottom = 8
		menu.alpha = 1
		menu.visible = true
		menu.flowDirection = tes3.flowDirection.leftToRight
		menu.autoWidth = true
		menu.autoHeight = true
		menu.childAlignX = 0.5
	end

	local left = menu:createBlock()
	left.flowDirection = tes3.flowDirection.topToBottom
	left.autoHeight = true
	left.autoWidth = true
	left.childAlignX = 0.5

	local right = menu:createBlock()
	right.flowDirection = tes3.flowDirection.topToBottom
	right.autoWidth = true
	right.autoHeight = true
	right.childAlignX = 0.5

	local palettes = {}
	local i = 1
	for name, palette in pairs(tes3.palette) do
		palettes[i] = {
			name = name,
			palette = palette
		}
		i = i + 1
	end
	table.sort(palettes, function(a, b)
		return a.name < b.name
	end)

	for i, entry in ipairs(palettes) do
		local label
		if i < 27 then
			label = left:createLabel({ text = entry.name })
		else
			label = right:createLabel({ text = entry.name })
		end
		label.color = tes3ui.getPalette(entry.palette)
	end
	menu:updateLayout()
end

event.register(tes3.event.keyDown, onKey, { filter = tes3.scanCode.o })
