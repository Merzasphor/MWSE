--- @meta

--- This event is invoked whenever the player gains experience in a skill. The event can be blocked to prevent progress. Additionally, both the skill gaining experience and the progress gained can be changed.
--- @class exerciseSkillEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field progress number The amount of experience that skill is gaining. Note that experience is not on a scale of 1 to 100. This value is modifiable.
--- @field skill number *Read-only*. The skill that is gaining experience. This can be changed to provide experience to a different skill.
