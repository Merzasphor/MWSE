--- @meta

--- This event is triggered when a mesh is loaded.
--- @class meshLoadedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field node niAmbientLight|niBillboardNode|niCamera|niCollisionSwitch|niDirectionalLight|niDynamicEffect|niGeometry|niLight|niNode|niPointLight|niSpotLight|niSwitchNode|niTriBasedGeometry|niTriShape The niAVObject-derived object of the loaded mesh.
--- @field path string The path to the mesh, relative to Data Files\Meshes
