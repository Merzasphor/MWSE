--- @meta
--- @diagnostic disable:undefined-doc-name

--- An object that has a name, extra data, and controllers.
--- @class niObjectNET : niObject
--- @field controller niKeyframeController|niLookAtController|niTimeController *Read-only*. The first controller available on the object.
--- @field extraData niExtraData *Read-only*. The first extra data available on the object.
--- @field name string The human-facing name of the given object.
niObjectNET = {}

--- Searches for an niExtraData on this object to see if it has one that holds a related reference.
--- @param searchParents boolean? *Default*: `false`. If true, all parent objects (if applicable) are also searched.
--- @return tes3reference? reference No description yet available.
function niObjectNET:getGameReference(searchParents) end

--- Add a controller to the object as the first controller.
--- @param type niKeyframeController|niLookAtController|niTimeController No description yet available.
function niObjectNET:prependController(type) end

--- Removes all controllers.
function niObjectNET:removeAllControllers() end

--- Removes a controller from the object.
--- @param controller niKeyframeController|niLookAtController|niTimeController No description yet available.
function niObjectNET:removeController(controller) end

--- Sets a given flag in the niObjectNET flag data. The specifics use of the flag is dependent on the real underlying type.
--- @param state boolean No description yet available.
--- @param index number No description yet available.
function niObjectNET:setFlag(state, index) end

