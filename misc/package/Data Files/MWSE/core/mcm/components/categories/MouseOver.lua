--[[local Parent = require("mcm.components.categories.Category")

local MouseOver = Parent:new()
MouseOver.triggerOn = "MCM:MouseOver"
MouseOver.triggerOff = "MCM:MouseLeave"

function MouseOver:createSubcomponentsContainer(parentBlock)
    Parent.createSubcomponentsContainer(self, parentBlock)

    local doMouseOver(component)
        if component.mouseOverComponents then
        self.elements.subcomponentsContainer:destroyChildren()
            self.createSubcomponents(self.elements.subcomponentsContainer, component.mouseOverComponents)
        end
    end
    local doMouseLeave()
        parentBlock:destroyChildren()
        self:createSubcomponents(self.elements.subcomponentsContainer, self.components)
    end
    event.register(self.triggerOn, doMouseOver)
    event.register(self.triggerOff, doMouseLeave)

end

return MouseOver]]--