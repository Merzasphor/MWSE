# exerciseSkill

This event is invoked whenever the player gains experience in a skill. The event can be blocked to prevent progress. Additionally, both the skill gaining experience and the progress gained can be changed.

```lua
--- @param e exerciseSkillEventData
local function exerciseSkillCallback(e)
end
event.register(tes3.event.exerciseSkill, exerciseSkillCallback)
```

!!! tip
	This event can be filtered based on the **`skill`** event data.

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `progress` (number): The amount of experience that skill is gaining. Note that experience is not on a scale of 1 to 100. This value is modifiable.
* `skill` (number): The ID of the skill that is gaining experience. The IDs used are available in Lua by their indentifier in the [`tes3.skill`](https://mwse.github.io/MWSE/references/skills/) namespace. This can be changed to provide experience to a different skill.

