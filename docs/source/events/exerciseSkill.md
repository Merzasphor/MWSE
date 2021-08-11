# exerciseSkill

This event is invoked whenever the player gains experience in a skill. The event can be blocked to prevent progress. Additionally, both the skill gaining experience and the progress gained can be changed.

```lua
--- @type e event.exerciseSkill
local function exerciseSkillCallback(e)
end
event.register("exerciseSkill", exerciseSkillCallback)
```

This event can be filtered based on the **`skill`** event data.

## Event Data

* `progress` (number): The amount of experience that skill is gaining. Note that experience is not on a scale of 1 to 100. This value is modifiable.
* `skill` (number): The skill that is gaining experience. This can be changed to provide experience to a different skill.

