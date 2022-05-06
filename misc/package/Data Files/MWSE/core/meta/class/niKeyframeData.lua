--- @meta
--- @diagnostic disable:undefined-doc-name

--- A collection of position, rotation, and scale keys used on NiKeyframeControllers.
--- @class niKeyframeData : niObject
--- @field positionKeyCount number *Read-only*. The number of position keys available.
--- @field positionKeys niBezPosKey[]|niPosKey[]|niTCBPosKey[] *Read-only*. The available position keys.
--- @field positionType number *Read-only*. The type of animation key used for position keys.
--- @field rotationKeyCount number *Read-only*. The number of rotation keys available.
--- @field rotationKeys niBezRotKey[]|niEulerRotKey[]|niRotKey[]|niTCBRotKey[] *Read-only*. The available rotation keys.
--- @field rotationType number *Read-only*. The type of animation key used for rotation keys.
--- @field scaleKeyCount number *Read-only*. The number of scale keys available.
--- @field scaleKeys niBezFloatKey[]|niFloatKey[]|niTCBFloatKey[] *Read-only*. The available scale keys.
--- @field scaleType number *Read-only*. The type of animation key used for scale keys.
niKeyframeData = {}

