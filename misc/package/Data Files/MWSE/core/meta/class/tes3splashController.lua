--- @meta
--- @diagnostic disable:undefined-doc-name

--- A core game controller responsible for controlling temporary graphics.
--- @class tes3splashController
--- @field activeSplashes tes3splashControllerActiveSplash[] *Read-only*. A list of [`tes3splashControllerActiveSplash`](https://mwse.github.io/MWSE/types/tes3splashControllerActiveSplash/) objects.
--- @field bloodMeshCount number *Read-only*. The number of loaded blood meshes.
--- @field bloodMeshes niBillboardNode[]|niCollisionSwitch[]|niNode[]|niSwitchNode[] *Read-only*. A list of loaded blood meshes.
--- @field bloodSplashDurations number[] *Read-only*. A list of blood splash durations.
--- @field bloodTextureCount number *Read-only*. The number of loaded blood textures.
--- @field bloodTextureProperties niTexturingProperty[] *Read-only*. A list of loaded blood texturing properties.
--- @field bloodTextures niSourceTexture[] *Read-only*. A list of blood splash textures.
tes3splashController = {}

