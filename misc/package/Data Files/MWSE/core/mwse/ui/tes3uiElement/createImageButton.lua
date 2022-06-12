
-- TODO: Change this into a proper widget.

--- @param container tes3uiElement
--- @param index number
local function setImageButtonToIndex(container, index)
	for i, imageButton in ipairs(container.children) do
		imageButton.visible = (i == index)
	end
end

function tes3uiElement:createImageButton(params)
	-- Get the button block params.
	local blockParams = params.blockParams or {
		id = params.id,
	}
	local idleParams = params.idleParams or {
		id = params.idleId,
		path = params.idle,
	}
	local overParams = params.overParams or {
		id = params.overId,
		path = params.over,
	}
	local pressedParams = params.pressedParams or {
		id = params.pressedId,
		path = params.pressed,
	}

	-- Create our parent block.
	local buttonBlock = self:createBlock(blockParams)
	buttonBlock.autoWidth = true
	buttonBlock.autoHeight = true

	-- Create our child buttons using the params provided.
	local buttonIdle = buttonBlock:createImage(idleParams)
	local buttonOver = buttonBlock:createImage(overParams)
	local buttonPressed = buttonBlock:createImage(pressedParams)

	-- Prevent any of the above-created buttons from consuming the mouse events.
	buttonIdle.consumeMouseEvents = false
	buttonOver.consumeMouseEvents = false
	buttonPressed.consumeMouseEvents = false

	-- Hide the over/pressed buttons for now.
	buttonOver.visible = false
	buttonPressed.visible = false

	-- Create the functions to hide/show buttons based on mouse state.
	buttonBlock:register("mouseOver", function(e)
		setImageButtonToIndex(e.source, 2)
	end)
	buttonBlock:register("mouseLeave", function(e)
		setImageButtonToIndex(e.source, 1)
	end)
	buttonBlock:register("mouseDown", function(e)
		setImageButtonToIndex(e.source, 3)
	end)
	buttonBlock:register("mouseRelease", function(e)
		setImageButtonToIndex(e.source, 2)
	end)

	-- Return the created block.
	return buttonBlock
end
