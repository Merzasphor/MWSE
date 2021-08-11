--- @meta

--- This event is raised just after determining which armor piece, if any, was hit with an attack. The slots can be modified, to draw focus onto specific armor slots.
--- @class calcArmorPieceHitEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field reference tes3reference A shortcut to the mobile's reference.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The mobile who is being hit.
--- @field slot number The primary slot that is targeted.
--- @field fallback number A secondary slot to check for equipment on, if no armor is found using the primary slot.
calcArmorPieceHit = {}

