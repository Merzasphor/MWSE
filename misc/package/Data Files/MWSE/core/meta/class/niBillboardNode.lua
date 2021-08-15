--- @meta

--- This node adjusts its render-time orientation so that the local z axis will face the camera. It supports multiple modes: camera parallel, or rotation around the local Y axis.
--- @class niBillboardNode : niNode, niAVObject, niObjectNET, niObject
--- @field mode number The orientation mode.
--- `0` Always face camera. Local z-axis becomes parallel to the camera. Minimizes rotation difference from the previous frame for smoother motion.
--- `1` Rotate about up vector. The object is rotated around its local y-axis so that its z-axis is pointing towards the camera.
--- `2` Rigid face camera. Local z-axis becomes parallel to the camera. Does not depend on previous frame.
--- 
niBillboardNode = {}

--- Updates the world transform to point at a camera. Used automatically during rendering. This method is only needed when you need to get the world transform without rendering.
--- @param camera niCamera No description yet available.
function niBillboardNode:rotateToCamera(camera) end

