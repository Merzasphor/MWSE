return {
	description = [[This event is triggered just before magic absorption gives magicka to the target, and after the absorb chance test. It can control the amount of magicka restored. It can also be blocked, though the absorb visual effect will remain.

This event occurs once per effect restored, so a multi-effect spell may trigger this multiple times. The default amount restored is equal to the casting cost of the entire spell, which is the vanilla behaviour.]],
	eventData = {
		["target"] = {
			type = "tes3reference",
			readOnly = true,
			description = "The actor absorbing the spell.",
		},
		["mobile"] = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor absorbing the spell.",
		},
		["absorb"] = {
			type = "number",
			description = "The amount of magicka to restore to the actor.",
		},
		["source"] = {
			type = "tes3alchemy|tes3enchantment|tes3spell",
			readOnly = true,
			description = "The magic source.",
		},
		["sourceInstance"] = {
			type = "tes3magicSourceInstance",
			readOnly = true,
			description = "The unique instance of the magic source.",
		},
	},
	filter = "target",
}