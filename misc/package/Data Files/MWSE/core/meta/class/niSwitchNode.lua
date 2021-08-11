--- @meta

--- Represents groups of multiple scene graph subtrees, only one of which is visible at any given time. They are useful for showing different states of a model depending on engine / lua logic. If you detach the active subtree, the switch node will set the active subtree to none, or to an index of -1.
--- @class niSwitchNode : niNode, niAVObject, niObjectNET, niObject
--- @field switchIndex number The value of the active child index. This index represents the index of the active child in the array of the NiSwitchNode. If this index is –1, then no child is active.
niSwitchNode = {}

--- Gets the active child node, or returns nil if the switch index is -1.
--- @return niAmbientLight|niBillboardNode|niCamera|niCollisionSwitch|niDirectionalLight|niDynamicEffect|niGeometry|niLight|niNode|niPointLight|niSpotLight|niSwitchNode|niTriBasedGeometry|niTriShape result No description yet available.
function niSwitchNode:getActiveChild() end

