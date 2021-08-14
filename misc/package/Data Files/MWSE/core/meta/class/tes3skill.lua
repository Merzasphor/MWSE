--- @meta

--- A skill object.
--- @class tes3skill : tes3baseObject
--- @field actions table *Read-only*. A table with 4 values. The amount of experience an action (use of skill) awards.
--- @field attribute number *Read-only*. Skill's governing attribute. Maps to tes3.attribute.* constants.
--- @field iconPath string *Read-only*. The path to the icon for the skill.
--- @field name string *Read-only*. The player-facing name of the skill.
--- @field specialization number The specialization in which the skill belongs. Maps to tes3.specialization.* constants.
tes3skill = {}

