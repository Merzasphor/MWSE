--- @meta

--- A core game object used for storing game settings.
--- @class tes3game
--- @field parentWindowHandle number *Read-only*. The Windows HWND for the parent window.
--- @field playerTarget tes3reference *Read-only*. The current activation target.
--- @field renderDistance number The game's rendering distance.
--- @field screenShotsEnabled boolean State on if screenshots are enabled.
--- @field screenX number *Read-only*. The screen's horizontal position.
--- @field screenY number *Read-only*. The screen's vertical position.
--- @field soundQuality number Sound quality level.
--- @field voice number Mix volumes for voices.
--- @field volumeEffect number Mix volumes for effects.
--- @field volumeFootsteps number Mix volumes for footsteps.
--- @field volumeMaster number Mix volumes for all sounds.
--- @field volumeMedia number Mix volumes for music.
--- @field windowHandle number *Read-only*. The Windows HWND for the window.
--- @field wireframeProperty niAlphaProperty|niFogProperty|niMaterialProperty|niStencilProperty|niTexturingProperty|niVertexColorProperty *Read-only*. The reused wireframe property, appled when toggling wireframe rendering.
--- @field worldSceneGraphRoot niBillboardNode|niCollisionSwitch|niNode|niSwitchNode *Read-only*. Access to the root of the scene graph.
tes3game = {}

--- Clears data related to activation, resetting what the player can activate.
function tes3game:clearTarget() end

