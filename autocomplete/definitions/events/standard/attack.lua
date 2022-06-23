return {
	type = "event",
	description = [[This event is invoked whenever an actor commits to an attack with their fists or a weapon, or a creature makes any attack. It occurs at the release time of the attack, such as the downstroke of a melee weapon or when an arrow is shot. For the player, it is when the attack button is released. A target is not required to be present for this event. For the actual moment the attack hits, use the `attackHit` event.

This event has specific combat mechanics occuring at this point. This is the time when the target has a chance to use its block skill, when on-strike enchantments may be applied, and when elemental shields do reflected damage. There is still a small period of time while the attack animation completes before the hit, so it is still possible for a target to move out of range (normally only seen with short weapons).

Lockpicks and probes do not invoke this event.]],
	related = { "attackStart", "attackHit" },
	eventData = {
		["mobile"] = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor making the attack.",
		},
		["reference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "A shortcut to the reference that is attacking.",
		},
		["targetMobile"] = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor being attacked. May be nil, e.g. if nothing was targeted.",
		},
		["targetReference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "A shortcut to the reference being attacked. May be nil, e.g. if nothing was targeted.",
		},
	},
	filter = "reference",
	examples = {
		["ShowPlayerAttack"] = {
			title = "Show a Message when the Player Attacks",
		},
	},
}