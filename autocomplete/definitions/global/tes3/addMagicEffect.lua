return {
	type = "function",
	description = [[This function creates a new custom magic effect. The effect can be scripted through lua. This function should be used inside [`magicEffectsResolved`](https://mwse.github.io/MWSE/events/magicEffectsResolved/) event callback.]],
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
				description = "The size scale for the spells containing this magic effect."
			},
			{
				name = "sizeCap",
				type = "number",
				optional = true,
				default = 1.0,
				description = "The maximum possible size of the projectile."
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
				description = "Path to the effect icon. Must be a string no longer than 31 characters long. Use double \\ as path separator."
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
				description = "The visual played when a spell with this effect is cast."
			},
			{
				name = "boltVFX",
				type = "tes3physicalObject",
				optional = true,
				description = "The visual played when a spell with this effect is in flight."
			},
			{
				name = "hitVFX",
				type = "tes3physicalObject",
				optional = true,
				description = "The visual played when a spell with this effect hits something."
			},
			{
				name = "areaVFX",
				type = "tes3physicalObject",
				optional = true,
				description = "The visual played when a spell with this effect, with area of effect hits something."
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
				description = "A flag which controls whether the effect's visual is continuously played during the whole duration of the effect."
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
				description = [[A function which will be called on each tick of a spell containing this effect. A table `tickParams` will be passed to the callback function. Note: `dt`(frame time) scaling is handled automatically.
		- `tickParams` (table)
		- `effectId` (number)
		- `sourceInstance` ([tes3magicSourceInstance](https://mwse.github.io/MWSE/types/tes3magicSourceInstance/)): Access to the magic source of the effect instance. 
		- `deltaTime` (number): The time passed since the last tick of the spell.
		- `effectInstance` ([tes3magicEffectInstance](https://mwse.github.io/MWSE/types/tes3magicEffectInstance/)): Access to the magic effect instance.
		- `effectIndex` (number): The index of the effect in the spell.

		In addition, a function registerd as `onTick` can also call the following methods:
	
		- trigger(`triggerParams`): Allows the effect to run through the normal spell event system.
			**Parameters:**
			- `triggerParams` (table)
			- `negateOnExpiry` (boolean): *Optional. Default:* `true` If this flag is `true`, the effect will be negated on expiry.
			- `isUncapped` (boolean): *Optional.*
			- `attribute` (number): *Optional. Default:* `tes3.effectAttribute.nonResistable` The attribute used in resistance calculations agains this effect. Maps to values in [`tes3.effectAttribute`](https://mwse.github.io/MWSE/references/effect-attributes/) namespace.
			- `type` (number): *Optional. Default:* `tes3.effectEventType.boolean`. This flag controls how the effect behaves. For example, `tes3.effectEventType.modStatistic` will make the effect work as calling `tes3.modStatistic`. Maps to values in [`tes3.effectEventType`](https://mwse.github.io/MWSE/references/effect-event-types/) namespace.
			- `value` (number): *Optional. Default:* `0`. The variable this effect changes.
			- `resistanceCheck(resistParams)` (function): *Optional.* The function passed as `resistanceCheck` will be used on any of the game's spell resistance checks. For example, the only effect in vanilla Morrowind that implements this function is Water Walking. It disallows using a spell with Water Walking when the player is deep underwater, by setting it as expired. So, returning `true` from this function will set your effect to expired, and depending on your trigger code may stop processing. The function passed here must returns boolean values.
				**Parameters**
				- `resistParams` (table)
				- `sourceInstance` ([tes3magicSourceInstance](https://mwse.github.io/MWSE/types/tes3magicSourceInstance/)): Access to the magic source of the effect instance. 
				- `effectInstance` ([tes3magicEffectInstance](https://mwse.github.io/MWSE/types/tes3magicEffectInstance/)): Access to the magic effect instance.
				- `effectIndex` (number): The index of the effect in the spell.

		- triggerBoundWeapon(`id`): Performs vanilla weapon summoning logic. It will create a summoned version of the weapon with provided ID. 
			**Parameters:**
			- `id` (string): The ID of the weapon object to summon.

		- triggerBoundArmor(`params`): Performs vanilla armor summoning logic. It can summon one or two armor objects with provided ID(s).
			**Parameters:**
			- `params` (table)
			- `id` (string): The ID of the armor object to summon.
			- `id2` (string): *Optional.* The ID of the additional armor object to summon.

		- triggerSummon(`id`): Performs vanilla creature summoning logic. It will create a summoned version of a creature with provided ID.
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
	examples = {
		["fireEffect"] = {
			title = "Fire Damage effect",
			description = "An implementation of the vanilla Fire Damage effect. Also, three spells are constructed with newly created magic effect, which are added to the player. You can test this in-game.",
		}
	},
	returns = {{ name = "effect", type = "tes3effect"}},
}
