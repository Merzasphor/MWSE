-- Claiming an ID is needed before actually
-- creating an effect with that ID
tes3.claimSpellEffectId("customFireDmg", 220)

local function onFireDmgTick(tickParams)
	-- This will print current health for any actor our spell hit
	tes3.messageBox("%s, health: %s", tickParams.effectInstance.target.object.id, tickParams.effectInstance.target.mobile.health.current)

	tickParams:trigger({
		type = tes3.effectEventType.modStatistic,
		-- The resistance attribute against Fire Damage should be Resist Fire
		attribute = tes3.effectAttribute.resistFire,
		value = tickParams.effectInstance.target.mobile.health,
		negateOnExpiry = false,
		isUncapped = true,
	})
end

event.register(tes3.event.magicEffectsResolved, function()
	tes3.addMagicEffect({
		-- The ID we claimed before is now available in tes3.effect namespace
		id = tes3.effect.customFireDmg,

		-- This information if just copied from the Construction Set --
		name = "Fire Damage",
		description = ("This spell effect produces a manifestation of elemental fire. Upon " ..
		"contact with an object, this manifestation explodes, causing damage."),
		baseCost = 5,
		school = tes3.magicSchool.destruction,
		size = 1.25,
		sizeCap = 50,
		speed = 1,
		lighting = { x = 0.99, y = 0.26, z = 0.53 },
		usesNegativeLighting = false,

		icon = "s\\Tx_S_fire_damage.tga",
		particleTexture = "vfx_firealpha00A.tga",
		castSound = "destruction cast",
		castVFX = "VFX_DestructCast",
		boltSound = "destruction bolt",
		boltVFX = "VFX_DestructBolt",
		hitSound = "destruction hit",
		hitVFX = "VFX_DestructHit",
		areaSound = "destruction area",
		areaVFX = "VFX_DestructArea",
		-- --

		appliesOnce = false,
		hasNoDuration = false,
		hasNoMagnitude = false,
		illegalDaedra = false,
		unreflectable = false,
		casterLinked = false,
		nonRecastable = false,
		targetsAttributes = false,
		targetsSkills = false,

		onTick = onFireDmgTick,
	})
end)

event.register(tes3.event.loaded, function()
	local spell1 = tes3.createObject({ objectType = tes3.objectType.spell })
	tes3.setSourceless(spell1)
	spell1.name = "TEST SPELL - self"
	spell1.magickaCost = 1

	local effect = spell1.effects[1]
	effect.id = tes3.effect.customFireDmg
	effect.rangeType = tes3.effectRange.self
	effect.min = 10
	effect.max = 10
	effect.duration = 10
	effect.radius = 0
	effect.skill = -1
	effect.attribute = -1

	local spell2 = tes3.createObject({ objectType = tes3.objectType.spell })
	tes3.setSourceless(spell2)
	spell2.name = "TEST SPELL - target"
	spell2.magickaCost = 1

	local effect = spell2.effects[1]
	effect.id = tes3.effect.customFireDmg
	effect.rangeType = tes3.effectRange.target
	effect.min = 3
	effect.max = 3
	effect.duration = 10
	effect.radius = 15
	effect.skill = -1
	effect.attribute = -1

	local spell3 = tes3.createObject({ objectType = tes3.objectType.spell })
	tes3.setSourceless(spell3)
	spell3.name = "TEST SPELL - touch"
	spell3.magickaCost = 1

	local effect = spell3.effects[1]
	effect.id = tes3.effect.customFireDmg
	effect.rangeType = tes3.effectRange.touch
	effect.min = 3
	effect.max = 3
	effect.duration = 10
	effect.radius = 0
	effect.skill = -1
	effect.attribute = -1

	tes3.addSpell({ reference = tes3.mobilePlayer, spell = spell1 })
	tes3.addSpell({ reference = tes3.mobilePlayer, spell = spell2 })
	tes3.addSpell({ reference = tes3.mobilePlayer, spell = spell3 })
end)
