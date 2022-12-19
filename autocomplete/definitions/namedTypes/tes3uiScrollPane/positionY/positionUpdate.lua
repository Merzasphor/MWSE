--Updating position of scroll panes:
---@type tes3uiElement
local scrollpane -- Created somewhere before

scrollpane.widget.positionY = 30

-- This will update the position of the scrollpane
scrollpane:getTopLevelMenu():updateLayout()