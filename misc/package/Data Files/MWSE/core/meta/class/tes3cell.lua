--- @meta

--- An exterior or interior game area.
--- @class tes3cell : tes3baseObject
--- @field activators tes3referenceList *Read-only*. One of the three reference collections for a cell.
--- @field actors tes3referenceList *Read-only*. One of the three reference collections for a cell.
--- @field ambientColor tes3packedColor The cell's ambient color. Only available on interior cells.
--- @field behavesAsExterior boolean If true, the cell behaves as an exterior instead of an interior for certain properties. Only available on interior cells.
--- @field cellFlags number A numeric representation of the packed bit flags for the cell, typically accessed from other properties.
--- @field displayName string The name of the cell as displayed on the in-game UI. For exterior cells without an assigned name, this is the region name.
--- @field editorName string The name of the cell as displayed in the Construction Set. For exterior cells, this includes the cell coordinates.
--- @field fogColor tes3packedColor The cell's fog color. Only available on interior cells.
--- @field fogDensity number The cell's fog density. Only available on interior cells.
--- @field gridX number The cell's X grid coordinate. Only available on exterior cells.
--- @field gridY number The cell's Y grid coordinate. Only available on exterior cells.
--- @field hasWater boolean If true, the cell has water. Only applies to interior cells.
--- @field isInterior boolean If true, the cell is an interior.
--- @field name string The name and id of the cell. See also displayName and editorName.
--- @field pickObjectsRoot niBillboardNode|niCollisionSwitch|niNode|niSwitchNode The scenegraph node containing player-interactable objects from this cell.
--- @field region tes3region The region associated with the cell. Only available on exterior cells, or interior cells that behave as exterior cells.
--- @field restingIsIllegal boolean If true, the player may not rest in the cell.
--- @field staticObjectsRoot tes3region The scenegraph node containing static non-player-interactable objects from this cell.
--- @field statics tes3referenceList *Read-only*. One of the three reference collections for a cell.
--- @field sunColor tes3packedColor The cell's sun color. Only available on interior cells.
--- @field waterLevel number The water level in the cell. Only available on interior cells.
tes3cell = {}

--- Determines if a given X/Y coordinate falls in the given cell. This will always be true for interior cells.
--- @param x number The X position to test.
--- @param y number The Y position to test.
--- @return boolean inCell true, if the point is found in the cell.
function tes3cell:isPointInCell(x, y) end

--- Used in a for loop, iterates over objects in the cell.
--- @param filter number *Optional*. The TES3 object type to filter results by.
function tes3cell:iterateReferences(filter) end

