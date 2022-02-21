--- @meta

--- This event is triggered before a mesh is loaded. The path can be changed to instead load a different mesh.
--- @class meshLoadEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field path string The path to the mesh, relative to Data Files\Meshes
