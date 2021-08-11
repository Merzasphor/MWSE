--- @meta

--- This event fires when a crime is witnessed by an actor.
--- @class crimeWitnessedEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field position tes3vector The position that the crime ocurred at.
--- @field value number The bounty value of the crime.
--- @field type string The type of crime that was committed.
--- @field witnessMobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The mobile actor of the reference that witnessed the crime.
--- @field witness tes3reference The reference that witnessed the crime.
--- @field realTimestamp number The timestamp that the crime ocurred at.
crimeWitnessed = {}

