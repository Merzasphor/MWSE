return {
	type = "function",
	description = [[This function creates a new custom magic effect. The effect can be scripted through lua.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{
				name = "id",
				type = "number",
				description = "Id of the new effect. Maps to newly claimed `tes3.effect` constants with `tes3.claimSpellEffectId()`. If the effect of this id already exists, an error will be thrown."
			},
			{
				name = "name",
				type = "string",
				optional = true,
				default = "Unnamed Effect",
				description = "Name of the effect."
			},
			{
				name = "baseCost",
				type = "number",
				optional = true,
				default = 1.0,
				description = "Base magicka cost for the effect."
			},
			{
				name = "school",
				type = "number",
				optional = true,
				default = "tes3.magicSchool.alteration",
				description = "The magic school the new effect will be assigned to. Maps to [`tes3.magicSchool`](https://mwse.github.io/MWSE/references/magic-schools/) constants."
			},
			{
				name = "size",
				type = "number",
				optional = true,
				default = 1.0,
				-- description = ""
			},
			{
				name = "sizeCap",
				type = "number",
				optional = true,
				default = 1.0,
				-- description = ""
			},
			{
				name = "speed",
				type = "number",
				optional = true,
				default = 1.0,
				-- description = ""
			},
			{
				name = "description",
				type = "string",
				optional = true,
				default = "No description available.",
				description = "Description for the effect."
			},
			{
				name = "lighting",
				optional = true,
				type = "table",
				tableParams = {
					{
						name = "x",
						type = "number",
						default = 1.0,
						description = "Value of red color channel. In range of 0 - 1."
					},
					{
						name = "y",
						type = "number",
						default = 1.0,
						description = "Value of green color channel. In range of 0 - 1."
					},
					{
						name = "z",
						type = "number",
						default = 1.0,
						description = "Value of blue color channel. In range of 0 - 1."
					},
				},
			},
			{
				name = "icon",
				type = "string",
				description = "Path to the effect icon. Must be a string no longer than 31 characters long."
			},
			{
				name = "particleTexture",
				type = "string",
				description = "Path to the particle texture to use for the effect. Must be a string no longer than 31 characters long."
			},
			{
				name = "castSound",
				type = "string",
				description = "The sound ID which will be played on casting a spell with this effect. Must be a string no longer than 31 characters long. If not specified, the default sound for the spell school will be used."
			},
			{
				name = "boltSound",
				type = "string",
				description = "The sound ID which will be played when a spell with this effect is in flight. Must be a string no longer than 31 characters long. If not specified, the default sound for the spell school will be used."
			},
			{
				name = "hitSound",
				type = "string",
				description = "The sound ID which will be played when a spell with this effect hits something. Must be a string no longer than 31 characters long. If not specified, the default sound for the spell school will be used."
			},
			{
				name = "areaSound",
				type = "string",
				description = "The sound ID which will be played on area of effect impact. Must be a string no longer than 31 characters long. If not specified, the default sound for the spell school will be used."
			},
			{
				name = "castVFX",
				type = "tes3physicalObject",
				optional = true,
				-- description = ""
			},
			{
				name = "boltVFX",
				type = "tes3physicalObject",
				optional = true,
				-- description = ""
			},
			{
				name = "hitVFX",
				type = "tes3physicalObject",
				optional = true,
				-- description = ""
			},
			{
				name = "areaVFX",
				type = "tes3physicalObject",
				optional = true,
				-- description = ""
			},
			{
				name = "allowEnchanting",
				type = "boolean",
				optional = true,
				default = true,
				description = "A flag which controls whether this effect can be used in a custom enchantment."
			},
			{
				name = "allowSpellmaking",
				type = "boolean",
				optional = true,
				default = true,
				description = "A flag which controls whether this effect can be used in a custom spell."
			},
			{
				name = "appliesOnce",
				type = "boolean",
				optional = true,
				default = true,
				description = "A flag which controls whether this effect applies once or is a ticking effect."
			},
			{
				name = "canCastSelf",
				type = "boolean",
				optional = true,
				default = true,
				description = "A flag which controls whether this effect can be used with cast on self range."
			},
			{
				name = "canCastTarget",
				type = "boolean",
				optional = true,
				default = true,
				description = "A flag which controls whether this effect can be used with cast on target range."
			},
			{
				name = "canCastTouch",
				type = "boolean",
				optional = true,
				default = true,
				description = "A flag which controls whether this effect can be used with cast on touch range."
			},
			{
				name = "casterLinked",
				type = "boolean",
				optional = true,
				default = true,
				-- description = ""
			},
			{
				name = "hasContinuousVFX",
				type = "boolean",
				optional = true,
				default = true,
				description = "A flag which controls whether the effect's VFX be played during its whole duration?"
			},
			{
				name = "hasNoDuration",
				type = "boolean",
				optional = true,
				default = true,
				description = "A flag which controls whether this effect doesn't have duration."
			},
			{
				name = "hasNoMagnitude",
				type = "boolean",
				optional = true,
				default = true,
				description = "A flag which controls whether this effect doesn't have magnitude."
			},
			{
				name = "illegalDaedra",
				type = "boolean",
				optional = true,
				default = true,
				description = "A flag which controls whether this effect is illegal to use in public, because it summons Daedra. Note: this mechanic is not implemented in the game. Some mods might rely on this parameter."
			},
			{
				name = "isHarmful",
				type = "boolean",
				optional = true,
				default = true,
				description = "A flag which controls whether this effect is considered harmful and casting it can be considered as an attack."
			},
			{
				name = "nonRecastable",
				type = "boolean",
				optional = true,
				default = true,
				description = "A flag which controls whether this effect can be recast while it already is in duration."
			},
			{
				name = "targetsAttributes",
				type = "boolean",
				optional = true,
				default = true,
				description = "A flag which controls whether this effect targets a certain attribute or attributes."
			},
			{
				name = "targetsSkills",
				type = "boolean",
				optional = true,
				default = true,
				description = "A flag which controls whether this effect targets a certain skill or skills."
			},
			{
				name = "unreflectable",
				type = "boolean",
				optional = true,
				default = true,
				description = "A flag which controls whether this effect can be reflected."
			},
			{
				name = "usesNegativeLighting",
				type = "boolean",
				optional = true,
				default = true,
				description = "A flag which controls whether this effect uses negative lighting."
			},
			{
				name = "onTick",
				type = "function",
				optional = true,
				description = [[A function which will be called on each tick of a spell containing this effect. Following table will be passed to the callback function:
- `effectId` (number)
- `sourceInstance` ((tes3magicSourceInstance)[https://mwse.github.io/MWSE/types/tes3magicSourceInstance/])
- `deltaTime (number): The time passed from the last tick of the spell.`
- `effectInstance` ((tes3magicEffectInstance)[https://mwse.github.io/MWSE/types/tes3magicEffectInstance/])
- `effectIndex (number): The index of the effect in the spell.`

In addition, a function registerd as onTick can also call the following methods:

- trigger(`params`)
**Parameters:**
- `params` (table)
	- `negateOnExpiry` (boolean): *Optional. Default:* `true`.
	- `isUncapped` (boolean): *Optional.*
	- `attribute` (number): *Optional.*
	- `type` (number): *Optional. Default:* `0`.
	- `value` (number): *Optional. Default:* `0`.
	- `resistanceCheck` (function):

- triggerBoundWeapon(`id`): Performs weapon summoning logic.
**Parameters:**
- `id` (string): The ID of the weapon object to summon.

- triggerBoundWeapon(`params`): Performs armor summoning logic. It can summon one or two armor objects.
**Parameters:**
- `params` (table)
- `id` (string): The ID of the armor object to summon.
- `id2` (string): *Optional.* The ID of the weapon object to summon.

- triggerSummon(`id`): Performs creature summoning logic.
**Parameters:**
- `id` (string): The ID of the creature object to summon.
	]],
			},
			{
				name = "onCollision",
				type = "function",
				optional = true,
				description = "A function which will be called when a spell containing this spell effect collides with something."
			},
		},
	}},
	returns = "effect",
	valuetype = "tes3effect"
}
