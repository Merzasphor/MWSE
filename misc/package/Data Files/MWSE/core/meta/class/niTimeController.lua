--- @meta

--- Controls the timing and update functions for animation controllers.
--- @class niTimeController : niObject
--- @field active boolean If the controller is active. When inactive, the target does not get updated and animation timing does not advance.
--- @field animTimingType number How the time parameter passed to the update function is treated. Type 0 is the default, which treats the update time as a delta time. Type 1 treats the update time an offset from the start of the animation.
--- @field cycleType number The animation cycle type. Type 0 is looping, type 2 is reverse, type 4 is clamped.
--- @field frequency number The animation controller's frequency value.
--- @field highKeyFrame number No description.
--- @field lastScaledTime number No description.
--- @field lastTime number No description.
--- @field lowKeyFrame number No description.
--- @field nextController niLookAtController|niTimeController The next NiTimeController in the list of controllers containing the calling controller.
--- @field phase number The phase value.
--- @field startTime number No description.
--- @field target niAlphaProperty|niAmbientLight|niBillboardNode|niCamera|niCollisionSwitch|niDirectionalLight|niDynamicEffect|niFogProperty|niGeometry|niLight|niMaterialProperty|niNode|niPointLight|niSourceTexture|niSpotLight|niStencilProperty|niSwitchNode|niTexturingProperty|niTriBasedGeometry|niTriShape|niVertexColorProperty The scene graph object that this animation controller is to animate.
niTimeController = {}

--- Starts the controller at the specified time.
--- @param time number No description yet available.
function niTimeController:start(time) end

--- Stops the controller. If you only want to pause the controller, use the `update` property.
function niTimeController:stop() end

