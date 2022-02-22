--- @meta

--- This event is triggered before a keyframes file is loaded. The path can be changed to instead load a different keyframes file.
--- @class keyframesLoadEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field path string The path to the keyframes file, relative to Data Files\Meshes.
--- @field sequenceName string The name of the associated NiSequence object.
