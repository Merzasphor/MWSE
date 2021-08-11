# tes3mobilePlayer

A mobile object for a the player.

This type inherits the following: [tes3mobileNPC](../../types/tes3mobileNPC), [tes3mobileActor](../../types/tes3mobileActor), [tes3mobileObject](../../types/tes3mobileObject)
## Properties

### `acrobatics`

Direct access to the NPC's acrobatics skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `actionBeforeCombat`

Action data stored before the actor entered combat.

**Returns**:

* `result` ([tes3actionData](../../types/tes3actionData))

***

### `actionData`

Current action data. Pre-combat action data is stored in the actionBeforeCombat property.

**Returns**:

* `result` ([tes3actionData](../../types/tes3actionData))

***

### `activeAI`

Friendly access to the actor's flag that controls if AI is active.

**Returns**:

* `result` (boolean)

***

### `activeMagicEffectList`

The active magic effects on the actor, from which all others can be accessed. A table with tes3activeMagicEffect items.

**Returns**:

* `result` (table)

***

### `actorType`

The type of the mobile actor. 0 is a creature, 1 is an NPC, 2 is the player.

**Returns**:

* `result` (number)

***

### `agility`

Direct access to the actor's agility attribute statistic.

**Returns**:

* `result` ([tes3statistic](../../types/tes3statistic))

***

### `aiPlanner`

Access to the mobile's AI planner and AI package information.

**Returns**:

* `result` (tes3aiPlanner)

***

### `alarm`

The actor's alarm AI value.

**Returns**:

* `result` (number)

***

### `alchemy`

Direct access to the NPC's alchemy skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `alteration`

Direct access to the NPC's alteration skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `alwaysRun`

Toggle flag for if the player should always run.

**Returns**:

* `result` (boolean)

***

### `animationController`

No description yet available.

**Returns**:

* `result` ([tes3actorAnimationController](../../types/tes3actorAnimationController))

***

### `armorer`

Direct access to the NPC's armorer skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `armorRating`

The actor's current armour rating, taking equipment condition into account. Armour mitigation can be automatically applied to damage by using the applyDamage function.

Armour mitigation calculation:
x = damage / (damage + target.armorRating)
damage *= max(fCombatArmorMinMult, x)
if damage < 1 then damage = 1 end

**Returns**:

* `result` (number)

***

### `athletics`

Direct access to the NPC's athletics skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `attackBonus`

Direct access to the actor's attack bonus effect attribute.

**Returns**:

* `result` (number)

***

### `attackDisabled`

Toggle flag for if the player can attack.

**Returns**:

* `result` (boolean)

***

### `attacked`

Friendly access to the actor's flag that controls if the actor has been attacked.

**Returns**:

* `result` (boolean)

***

### `attributes`

Access to a table of 8 tes3statistic objects for the actor's attributes.

**Returns**:

* `result` (table)

***

### `autoRun`

Toggle flag for if the player should constantly run forward.

**Returns**:

* `result` (boolean)

***

### `axe`

Direct access to the NPC's axe skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `barterGold`

The current amount of gold that the actor has access to for bartering.

**Returns**:

* `result` (number)

***

### `birthsign`

The player's birthsign.

**Returns**:

* `result` ([tes3birthsign](../../types/tes3birthsign))

***

### `blind`

Direct access to the actor's blind effect attribute.

**Returns**:

* `result` (number)

***

### `block`

Direct access to the NPC's block skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `bluntWeapon`

Direct access to the NPC's blunt weapon skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `boundSize`

A vector that shows the size of the bounding box in each direction.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `bounty`

The player's current bounty.

**Returns**:

* `result` (number)

***

### `cameraHeight`

Access to the player camera height, used for both the first person and third person camera (specifically the orbit centre). It is normally placed at head height by the game, on loading, or when a race is selected. The camera height can be reset to its regular value by setting this property to nil.

**Returns**:

* `result` (number)

??? example "Example: Adjust the camera to match shrunken player scale"

	```lua
	local function shrink()
		-- Shrink player.
		tes3.player.scale = 0.5
		-- Reset camera height to default value.
		tes3.mobilePlayer.cameraHeight = nil
		-- Modify camera height to match scale.
		tes3.mobilePlayer.cameraHeight = tes3.player.scale * tes3.mobilePlayer.cameraHeight
	end
	
	local function unshrink()
		tes3.player.scale = 1
		tes3.mobilePlayer.cameraHeight = nil
	end

	```

***

### `castReady`

Toggle flag for if the player has casting ready.

**Returns**:

* `result` (boolean)

***

### `cell`

Fetches the cell that the actor is in.

**Returns**:

* `result` ([tes3cell](../../types/tes3cell))

***

### `cellX`

The X grid coordinate of the cell the mobile is in.

**Returns**:

* `result` (number)

***

### `cellY`

The Y grid coordinate of the cell the mobile is in.

**Returns**:

* `result` (number)

***

### `chameleon`

Direct access to the actor's chameleon effect attribute.

**Returns**:

* `result` (number)

***

### `clawMultiplier`

Quick access to the ClawMultiplier global variable.

**Returns**:

* `result` ([tes3globalVariable](../../types/tes3globalVariable))

***

### `collidingReference`

The reference that the mobile has collided with this frame.

**Returns**:

* `result` ([tes3reference](../../types/tes3reference))

***

### `combatSession`

Combat session data. This exists while the actor is in combat to provide memory for AI combat decisions.

**Returns**:

* `result` ([tes3combatSession](../../types/tes3combatSession))

***

### `conjuration`

Direct access to the NPC's conjuration skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `controlsDisabled`

Toggle flag for if the player's controls are disabled.

**Returns**:

* `result` (boolean)

***

### `corpseHourstamp`

No description yet available.

**Returns**:

* `result` (number)

***

### `currentEnchantedItem`

The currently equipped enchanted item that the actor will use.

**Returns**:

* `result` ([tes3equipmentStack](../../types/tes3equipmentStack))

***

### `currentSpell`

The currently equipped spell that the actor will use.

**Returns**:

* `result` ([tes3spell](../../types/tes3spell))

***

### `destruction`

Direct access to the NPC's destruction skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `dialogueList`

Access to the collection that holds what dialogue topics the player has access to.

**Returns**:

* `result` ([tes3iterator](../../types/tes3iterator))

***

### `effectAttributes`

Access to a table of 24 numbers for the actor's effect attributes.

**Returns**:

* `result` (table)

***

### `enchant`

Direct access to the NPC's enchant skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `encumbrance`

Access to the actor's encumbrance statistic.

**Returns**:

* `result` ([tes3statistic](../../types/tes3statistic))

***

### `endurance`

Direct access to the actor's endurance attribute statistic.

**Returns**:

* `result` ([tes3statistic](../../types/tes3statistic))

***

### `facing`

The facing of the actor, in radians.

**Returns**:

* `result` (number)

***

### `fatigue`

Access to the actor's fatigue statistic.

**Returns**:

* `result` ([tes3statistic](../../types/tes3statistic))

***

### `fight`

The actor's fight AI value.

**Returns**:

* `result` (number)

***

### `firstPerson`

Quick access to the first person NPC.

**Returns**:

* `result` ([tes3npc](../../types/tes3npc))

***

### `firstPersonReference`

Quick access to the first person NPC's reference.

**Returns**:

* `result` ([tes3reference](../../types/tes3reference))

***

### `flags`

Access to the root mobile object flags, represented as an integer. Should not be accessed directly.

**Returns**:

* `result` (number)

***

### `flee`

The actor's flee AI value.

**Returns**:

* `result` (number)

***

### `flySpeed`

The calculated fly movement speed.

**Returns**:

* `result` (number)

***

### `forceJump`

Toggle flag for if the NPC jumps.

**Returns**:

* `result` (boolean)

***

### `forceMoveJump`

Toggle flag for if the NPC moves and jumps.

**Returns**:

* `result` (boolean)

***

### `forceRun`

Toggle flag for if the NPC runs.

**Returns**:

* `result` (boolean)

***

### `forceSneak`

Toggle flag for if the NPC sneaks.

**Returns**:

* `result` (boolean)

***

### `friendlyActors`

A collection of other tes3mobileActors that this actor considers friendly.

**Returns**:

* `result` ([tes3iterator](../../types/tes3iterator))

***

### `greetDuration`

No description yet available.

**Returns**:

* `result` (number)

***

### `greetTimer`

No description yet available.

**Returns**:

* `result` (number)

***

### `handToHand`

Direct access to the NPC's hand to hand skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `health`

Access to the actor's health statistic.

**Returns**:

* `result` ([tes3statistic](../../types/tes3statistic))

***

### `heavyArmor`

Direct access to the NPC's heavy armor skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `height`

The height of the mobile above the ground.

**Returns**:

* `result` (number)

***

### `hello`

The actor's hello AI value.

**Returns**:

* `result` (number)

***

### `holdBreathTime`

No description yet available.

**Returns**:

* `result` (number)

***

### `hostileActors`

A collection of other tes3mobileActors that this actor considers hostile.

**Returns**:

* `result` ([tes3iterator](../../types/tes3iterator))

***

### `idleAnim`

Friendly access to the actor's flag that controls if the actor is using their idle animation.

**Returns**:

* `result` (boolean)

***

### `illusion`

Direct access to the NPC's illusion skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `impulseVelocity`

A vector that represents the 3D acceleration of the object.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `inactivityTime`

The time that the player has spent inactive.

**Returns**:

* `result` (number)

***

### `inCombat`

Friendly access to the actor's flag that controls if the actor is in combat.

**Returns**:

* `result` (boolean)

***

### `inJail`

Toggle flag for if the player is currently in jail.

**Returns**:

* `result` (boolean)

***

### `intelligence`

Direct access to the actor's intelligence attribute statistic.

**Returns**:

* `result` ([tes3statistic](../../types/tes3statistic))

***

### `invisibility`

Direct access to the actor's invisibility effect attribute.

**Returns**:

* `result` (number)

***

### `is3rdPerson`

Shows if the player's camera is currently in 3rd person view.

**Returns**:

* `result` (boolean)

***

### `isCrittable`

Friendly access to the actor's flag that controls if the actor can be critically hit.

**Returns**:

* `result` (boolean)

***

### `isDead`

True if the actor is dead.

**Returns**:

* `result` (boolean)

***

### `isFalling`

Direct access to the actor's current movement flags, showing if the actor is falling. This is when the actor is falling without having jumped, e.g. if they walked off a ledge.

**Returns**:

* `result` (boolean)

***

### `isFlying`

Direct access to the actor's current movement flags, showing if the actor is flying.

**Returns**:

* `result` (boolean)

***

### `isJumping`

Direct access to the actor's current movement flags, showing if the actor is jumping.

**Returns**:

* `result` (boolean)

***

### `isMovingBack`

Direct access to the actor's current movement flags, showing if the actor is moving backwards.

**Returns**:

* `result` (boolean)

***

### `isMovingForward`

Direct access to the actor's current movement flags, showing if the actor is moving forwards.

**Returns**:

* `result` (boolean)

***

### `isMovingLeft`

Direct access to the actor's current movement flags, showing if the actor is moving left.

**Returns**:

* `result` (boolean)

***

### `isMovingRight`

Direct access to the actor's current movement flags, showing if the actor is moving right.

**Returns**:

* `result` (boolean)

***

### `isPlayerDetected`

Direct access to the actor's flag showing the player was detected on the last detection check.

**Returns**:

* `result` (boolean)

***

### `isPlayerHidden`

Direct access to the actor's flag showing the player was hidden on the last detection check.

**Returns**:

* `result` (boolean)

***

### `isRunning`

Direct access to the actor's current movement flags, showing if the actor is running.

**Returns**:

* `result` (boolean)

***

### `isSneaking`

Direct access to the actor's current movement flags, showing if the actor is sneaking.

**Returns**:

* `result` (boolean)

***

### `isSwimming`

Direct access to the actor's current movement flags, showing if the actor is swimming.

**Returns**:

* `result` (boolean)

***

### `isTurningLeft`

Direct access to the actor's current movement flags, showing if the actor is turning left.

**Returns**:

* `result` (boolean)

***

### `isTurningRight`

Direct access to the actor's current movement flags, showing if the actor is turning right.

**Returns**:

* `result` (boolean)

***

### `isWalking`

Direct access to the actor's current movement flags, showing if the actor is walking.

**Returns**:

* `result` (boolean)

***

### `jump`

Direct access to the actor's jump effect attribute.

**Returns**:

* `result` (number)

***

### `jumpingDisabled`

Toggle flag for if the player can jump.

**Returns**:

* `result` (boolean)

***

### `knownWerewolf`

Quick access to the KnownWerewolf global variable.

**Returns**:

* `result` ([tes3globalVariable](../../types/tes3globalVariable))

***

### `lastGroundZ`

No description yet available.

**Returns**:

* `result` (number)

***

### `lastUsedAlembic`

The last used alchemy alembic.

**Returns**:

* `result` ([tes3apparatus](../../types/tes3apparatus))

***

### `lastUsedAmmoCount`

The amount of ammo for the ranged weapon that that was last equipped.

**Returns**:

* `result` (number)

***

### `lastUsedCalcinator`

The last used alchemy calcinator.

**Returns**:

* `result` ([tes3apparatus](../../types/tes3apparatus))

***

### `lastUsedMortar`

The last used alchemy mortar.

**Returns**:

* `result` ([tes3apparatus](../../types/tes3apparatus))

***

### `lastUsedRetort`

The last used alchemy retort.

**Returns**:

* `result` ([tes3apparatus](../../types/tes3apparatus))

***

### `levelupPerSpecialization`

Array-style table access to how many skill levels there have been for each of the 3 specializations.

**Returns**:

* `result` (table)

***

### `levelUpProgress`

The progress the player has made towards leveling up.

**Returns**:

* `result` (number)

***

### `levelupsPerAttribute`

Array-style table access to how many skill levels there have been for each of the 8 attributes.

**Returns**:

* `result` (table)

***

### `levitate`

Direct access to the actor's levitate effect attribute.

**Returns**:

* `result` (number)

***

### `lightArmor`

Direct access to the NPC's light armor skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `longBlade`

Direct access to the NPC's long blade skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `luck`

Direct access to the actor's luck attribute statistic.

**Returns**:

* `result` ([tes3statistic](../../types/tes3statistic))

***

### `magicDisabled`

Toggle flag for if the player can use magic.

**Returns**:

* `result` (boolean)

***

### `magicka`

Access to the actor's magicka statistic.

**Returns**:

* `result` ([tes3statistic](../../types/tes3statistic))

***

### `magickaMultiplier`

Access to the actor's magicka multiplier statistic.

**Returns**:

* `result` ([tes3statistic](../../types/tes3statistic))

***

### `markLocation`

Access to the structure that holds the player's current mark/recall location.

**Returns**:

* `result` ([tes3markData](../../types/tes3markData))

***

### `marksman`

Direct access to the NPC's marksman skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `mediumArmor`

Direct access to the NPC's medium armor skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `mercantile`

Direct access to the NPC's mercantile skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `mobToMobCollision`

Allows modifying if this actor will collide with other actors. When true (default), the actor cannot move through other actors. When false, the actor is allowed to move through other actors, and other actors can move through it.

May be useful when free movement is required in crowded situations, or to temporarily let the player move past an actor.

**Returns**:

* `result` (boolean)

***

### `mouseLookDisabled`

Toggle flag for if the player's mouse look controls are disabled.

**Returns**:

* `result` (boolean)

***

### `movementCollision`

Controls if the mobile has movement collision active. When false, the mobile can move through any object, but can still block other mobiles, and can still be hit in combat. Actors will still follow pathgrids, ramps and stairs when navigating.

**Returns**:

* `result` (boolean)

***

### `movementFlags`

Access to the root mobile object movement flags, represented as an integer. Should not be accessed directly.

**Returns**:

* `result` (number)

***

### `moveSpeed`

The calculated base movement speed.

**Returns**:

* `result` (number)

***

### `mysticism`

Direct access to the NPC's mysticism skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `nextActionWeight`

No description yet available.

**Returns**:

* `result` (number)

***

### `object`

The actor object that maps to this mobile.

**Returns**:

* `result` ([tes3npcInstance](../../types/tes3npcInstance))

***

### `objectType`

The type of mobile object. Maps to values in tes3.objectType.

**Returns**:

* `result` (number)

***

### `paralyze`

Direct access to the actor's paralyze effect attribute.

**Returns**:

* `result` (number)

***

### `personality`

Direct access to the actor's personality attribute statistic.

**Returns**:

* `result` ([tes3statistic](../../types/tes3statistic))

***

### `playerDistance`

The distance to the player. Updated every frame when the mobile is in an active cell.

**Returns**:

* `result` (number)

***

### `position`

A vector that represents the 3D position of the object.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `prevMovementFlags`

Access to the root mobile object movement flags from the previous frame, represented as an integer. Should not be accessed directly.

**Returns**:

* `result` (number)

***

### `readiedAmmo`

The currently equipped ammo.

**Returns**:

* `result` ([tes3equipmentStack](../../types/tes3equipmentStack))

***

### `readiedAmmoCount`

The number of ammo equipped for the readied ammo.

**Returns**:

* `result` (number)

***

### `readiedShield`

The currently equipped shield.

**Returns**:

* `result` ([tes3equipmentStack](../../types/tes3equipmentStack))

***

### `readiedWeapon`

The currently equipped weapon.

**Returns**:

* `result` ([tes3equipmentStack](../../types/tes3equipmentStack))

***

### `reference`

Access to the reference object for the mobile, if any.

**Returns**:

* `result` ([tes3reference](../../types/tes3reference))

***

### `resistBlightDisease`

Direct access to the actor's blight disease resistance effect attribute.

**Returns**:

* `result` (number)

***

### `resistCommonDisease`

Direct access to the actor's common disease resistance effect attribute.

**Returns**:

* `result` (number)

***

### `resistCorprus`

Direct access to the actor's corprus disease resistance effect attribute.

**Returns**:

* `result` (number)

***

### `resistFire`

Direct access to the actor's fire resistance effect attribute.

**Returns**:

* `result` (number)

***

### `resistFrost`

Direct access to the actor's frost resistance effect attribute.

**Returns**:

* `result` (number)

***

### `resistMagicka`

Direct access to the actor's magicka resistance effect attribute.

**Returns**:

* `result` (number)

***

### `resistNormalWeapons`

Direct access to the actor's normal weapon resistance effect attribute.

**Returns**:

* `result` (number)

***

### `resistParalysis`

Direct access to the actor's paralysis resistance effect attribute.

**Returns**:

* `result` (number)

***

### `resistPoison`

Direct access to the actor's poison resistance effect attribute.

**Returns**:

* `result` (number)

***

### `resistShock`

Direct access to the actor's shock resistance effect attribute.

**Returns**:

* `result` (number)

***

### `restHoursRemaining`

How many hours are left while resting.

**Returns**:

* `result` (number)

***

### `restoration`

Direct access to the NPC's restoration skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `runSpeed`

The calculated run movement speed.

**Returns**:

* `result` (number)

***

### `sanctuary`

Direct access to the actor's sanctuary effect attribute.

**Returns**:

* `result` (number)

***

### `scanInterval`

No description yet available.

**Returns**:

* `result` (number)

***

### `scanTimer`

No description yet available.

**Returns**:

* `result` (number)

***

### `security`

Direct access to the NPC's security skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `shield`

Direct access to the actor's shield effect attribute.

**Returns**:

* `result` (number)

***

### `shortBlade`

Direct access to the NPC's short blade skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `silence`

Direct access to the actor's silence effect attribute.

**Returns**:

* `result` (number)

***

### `skillProgress`

Array-style table access to skill progress for each of the 27 skills.

**Returns**:

* `result` (table)

***

### `skills`

An array-style table with access to the twenty seven NPC skill statistics.

**Returns**:

* `result` (table)

***

### `sleeping`

Toggle flag for if the player is currently sleeping.

**Returns**:

* `result` (boolean)

***

### `sneak`

Direct access to the NPC's sneak skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `sound`

Direct access to the actor's sound effect attribute.

**Returns**:

* `result` (number)

***

### `spear`

Direct access to the NPC's spear skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `speechcraft`

Direct access to the NPC's speechcraft skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `speed`

Direct access to the actor's speed attribute statistic.

**Returns**:

* `result` ([tes3statistic](../../types/tes3statistic))

***

### `spellReadied`

Friendly access to the actor's flag that controls if the actor has a spell readied.

**Returns**:

* `result` (boolean)

***

### `strength`

Direct access to the actor's strength attribute statistic.

**Returns**:

* `result` ([tes3statistic](../../types/tes3statistic))

***

### `swiftSwim`

Direct access to the actor's swift swim effect attribute.

**Returns**:

* `result` (number)

***

### `swimRunSpeed`

The calculated swim movement speed while running.

**Returns**:

* `result` (number)

***

### `swimSpeed`

The calculated swim movement speed.

**Returns**:

* `result` (number)

***

### `talkedTo`

Direct access to the actor's flag that shows it was recently talked to.

**Returns**:

* `result` (boolean)

***

### `telekinesis`

Direct access to the player's telekinesis effect attribute.

**Returns**:

* `result` (number)

***

### `torchSlot`

The currently equipped light.

**Returns**:

* `result` ([tes3equipmentStack](../../types/tes3equipmentStack))

***

### `travelling`

Toggle flag for if the player is currently travelling.

**Returns**:

* `result` (boolean)

***

### `unarmored`

Direct access to the NPC's unarmored skill statistic.

**Returns**:

* `result` (tes3skillStatistic)

***

### `underwater`

Friendly access to the actor's flag that controls if the actor is under water.

**Returns**:

* `result` (boolean)

***

### `vanityDisabled`

Toggle flag for if the player's vanity camera is disabled.

**Returns**:

* `result` (boolean)

***

### `velocity`

A vector that represents the 3D velocity of the object.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `viewSwitchDisabled`

Toggle flag for if the player can switch between first person and vanity cameras.

**Returns**:

* `result` (boolean)

***

### `visionBonus`

Direct access to the player's vision bonus effect attribute.

**Returns**:

* `result` (number)

***

### `waiting`

Toggle flag for if the player is currently waiting.

**Returns**:

* `result` (boolean)

***

### `walkSpeed`

The calculated walk movement speed.

**Returns**:

* `result` (number)

***

### `waterBreathing`

Direct access to the actor's water breathing effect attribute.

**Returns**:

* `result` (number)

***

### `waterWalking`

Direct access to the actor's water walking effect attribute.

**Returns**:

* `result` (number)

***

### `weaponDrawn`

Friendly access to the actor's flag that shows if the weapon model is visible. When readying a weapon, there is a short period of time at the start of the animation, where the weapon is not visible yet. This flag will only be set after this initial stage is done. This flag is still set with hand-to-hand even though it doesn't use a model. Setting this to false while a weapon is drawn will normally cause the actor to play its weapon draw animation again.

**Returns**:

* `result` (boolean)

***

### `weaponReady`

Toggle flag for if the player has a weapon ready. Setting it to true will cause the player to take out their weapon. Setting it to false will cause them to put it away.

**Returns**:

* `result` (boolean)

***

### `werewolf`

Friendly access to the actor's flag that controls if the actor in werewolf form.

**Returns**:

* `result` (boolean)

***

### `width`

No description yet available.

**Returns**:

* `result` (number)

***

### `willpower`

Direct access to the actor's willpower attribute statistic.

**Returns**:

* `result` ([tes3statistic](../../types/tes3statistic))

***

## Methods

### `applyDamage`

Damages the actor, with options to control mitigation and difficulty scaling. Invokes the 'damage' and 'damaged' events, with 'script' source. Returns the actual damage done after armor mitigation and resistance, but before difficulty scaling.

```lua
local result = tes3mobileActor:applyDamage({ damage = ..., applyArmor = ..., resistAttribute = ..., applyDifficulty = ..., playerAttack = ..., doNotChangeHealth = ... })
```

**Parameters**:

* `params` (table)
	* `damage` (number): The amount of damage to apply.
	* `applyArmor` (boolean): If armor should mitigate the incoming damage. If the player is the target, armor experience will be gained.
	* `resistAttribute` (number): The resistance attribute that is applied to the damage. It can reduce damage or exploit weakness. Uses values from tes3.effectAttributes.
	* `applyDifficulty` (boolean): If the game difficulty modifier should be applied. Must be used with the 'playerAttack' argument to apply the correct modifier.
	* `playerAttack` (boolean): If the attack came from the player. Used for difficulty calculation.
	* `doNotChangeHealth` (boolean): If all armor effects except the health change should be applied. These include hit sounds, armor condition damage, and player experience gain from being hit.

**Returns**:

* `result` (number)

***

### `applyFatigueDamage`

Damages the actor's fatigue, with accompanying reaction from the reciever. Invokes the 'damageHandToHand' and 'damagedHandToHand' events, with 'script' source. Returns the actual fatigue damage done.

```lua
local result = tes3mobileActor:applyFatigueDamage(fatigueDamage, swing, alwaysPlayHitVoice)
```

**Parameters**:

* `fatigueDamage` (number): The amount of fatigue damage to apply.
* `swing` (number): The attack swing magnitude, range 0-1. Only modifies hit volume.
* `alwaysPlayHitVoice` (boolean): Always play the hit reaction voiceover.

**Returns**:

* `result` (number)

***

### `applyHealthDamage`

**Deprecated, please use applyDamage instead.**

Damages the actor.

```lua
local result = tes3mobileActor:applyHealthDamage(damage, isPlayerAttack, scaleWithDifficulty, doNotChangeHealth)
```

**Parameters**:

* `damage` (number): The amount of damage to apply.
* `isPlayerAttack` (boolean): Used to calculate difficulty scaling.
* `scaleWithDifficulty` (boolean): Apply difficulty scaling to the damage.
* `doNotChangeHealth` (boolean): Do all the audiovisual effects of damage without the health change.

**Returns**:

* `result` (boolean)

***

### `calcEffectiveDamage`

Calculates the damage that would be inflicted to an actor after armor and/or resistance. Returns the actual damage done after armor mitigation and resistance, but before difficulty scaling.

```lua
local result = tes3mobileActor:calcEffectiveDamage({ damage = ..., applyArmor = ..., resistAttribute = ... })
```

**Parameters**:

* `params` (table)
	* `damage` (number): The amount of damage to apply.
	* `applyArmor` (boolean): If armor should mitigate the incoming damage.
	* `resistAttribute` (number): The resistance attribute that is applied to the damage. It can reduce damage or exploit weakness. Uses values from tes3.effectAttributes.

**Returns**:

* `result` (number)

***

### `equip`

Equips an item, optionally adding the item if needed. If the best match is already equipped, it does not perform an unequip-equip cycle, but does return true.

```lua
local itemEquipped = tes3mobileNPC:equip({ item = ..., itemData = ..., addItem = ..., selectBestCondition = ..., selectWorstCondition = ... })
```

**Parameters**:

* `params` (table)
	* `item` ([tes3item](../../types/tes3item), string): The item to equip.
	* `itemData` ([tes3itemData](../../types/tes3itemData)): The item data of the specific item to equip.
	* `addItem` (boolean): If true, the item will be added to the actor's inventory if needed.
	* `selectBestCondition` (boolean): If true, the item in the inventory with the best condition and best charge will be selected.
	* `selectWorstCondition` (boolean): If true, the item in the inventory with the worst condition and worst charge will be selected. Can be useful for selecting tools.

**Returns**:

* `itemEquipped` (boolean)

***

### `exerciseSkill`

Exercises a skill, providing experience in it.

```lua
tes3mobilePlayer:exerciseSkill(skill, progress)
```

**Parameters**:

* `skill` (number): The skill index to give experience to.
* `progress` (number): The amount of experience to grant.

***

### `getActiveMagicEffects`

Fetches a filtered list of the active magic effects on the actor. Returns a table with tes3activeMagicEffect items.

```lua
local result = tes3mobileActor:getActiveMagicEffects({ effect = ..., serial = ... })
```

**Parameters**:

* `params` (table)
	* `effect` (number): The magic effect ID to search for.
	* `serial` (number): The magic instance serial to search for.

**Returns**:

* `result` (table)

***

### `getBootsWeight`

Gets the weight of the boots equipped on the actor, or 0 if no boots are equipped.

```lua
local result = tes3mobileActor:getBootsWeight()
```

**Returns**:

* `result` (number)

***

### `getFatigueTerm`

Gets the fatigue-based skill scaling term used by many game mechanics, based on the actor's current and maximum fatigue. It is equal to ``max(0, fFatigueBase - fFatigueMult * max(0, 1 - fatigue.current/fatigue.base))``

```lua
local result = tes3mobileActor:getFatigueTerm()
```

**Returns**:

* `result` (number)

***

### `getPowerUseTimestamp`

Finds the timestamp a recharging power was used. Powers recharge 24 hours after this timestamp. The timestamp units are hours. The current time as a timestamp can be accessed at tes3.getSimulationTimestamp().

```lua
local timestamp = tes3mobileActor:getPowerUseTimestamp(power)
```

**Parameters**:

* `power` ([tes3spell](../../types/tes3spell)): The spell object for the power.

**Returns**:

* `timestamp` (number)

***

### `getSkillStatistic`

Fetches the statistic object of a skill with a given index. This is the way to access skills for any type of actor, as creatures have a limited version of the skill system. Note that creatures share a statistic between multiple skills (they only have combat, magic, and stealth stats), so many values will be the same.

```lua
local result = tes3mobileActor:getSkillStatistic(skillId)
```

**Parameters**:

* `skillId` (number): The index of the skill statistic to fetch.

**Returns**:

* `result` (tes3skillStatistic)

***

### `getSkillValue`

Fetches the current value of a skill with a given index. This is the way to access skills for any type of actor, as creatures have a limited version of the skill system. Note that creatures share a statistic between multiple skills (they only have combat, magic, and stealth stats), so many values will be the same.

```lua
local result = tes3mobileActor:getSkillValue(skillId)
```

**Parameters**:

* `skillId` (number): The index of the skill statistic's value to fetch.

**Returns**:

* `result` (number)

***

### `getViewToActor`

No description yet available.

```lua
local result = tes3mobileActor:getViewToActor()
```

**Returns**:

* `result` (number)

***

### `getViewToPoint`

No description yet available.

```lua
local result = tes3mobileActor:getViewToPoint()
```

**Returns**:

* `result` (number)

***

### `getViewToPointWithFacing`

No description yet available.

```lua
local result = tes3mobileActor:getViewToPointWithFacing()
```

**Returns**:

* `result` (number)

***

### `getWeaponSpeed`

Fetches the weapon speed of the actor's currently equipped weapon, or 1.0 if no weapon is equipped.

```lua
local result = tes3mobileActor:getWeaponSpeed()
```

**Returns**:

* `result` (number)

***

### `hasFreeAction`

If true, the actor isn't paralyzed, dead, stunned, or otherwise unable to take action.

```lua
local result = tes3mobileActor:hasFreeAction()
```

**Returns**:

* `result` (boolean)

***

### `hasUsedPower`

Check if a power has been used and is recharging.

```lua
local result = tes3mobileActor:hasUsedPower(power)
```

**Parameters**:

* `power` ([tes3spell](../../types/tes3spell)): The spell object for the power.

**Returns**:

* `result` (boolean)

***

### `isAffectedByObject`

Determines if the actor is currently being affected by a given alchemy, enchantment, or spell.

```lua
local result = tes3mobileActor:isAffectedByObject(object)
```

**Parameters**:

* `object` ([tes3alchemy](../../types/tes3alchemy), [tes3enchantment](../../types/tes3enchantment), [tes3spell](../../types/tes3spell)): The magic to check for.

**Returns**:

* `result` (boolean)

***

### `levelSkill`

Checks to see if a skill is ready to be leveled up, and performs any levelup logic.

```lua
tes3mobilePlayer:levelSkill(skill)
```

**Parameters**:

* `skill` (number): The skill index to check for leveling.

***

### `rechargePower`

Makes a power immediately available for casting again.

```lua
local result = tes3mobileActor:rechargePower(power)
```

**Parameters**:

* `power` ([tes3spell](../../types/tes3spell)): The spell object for the power.

**Returns**:

* `result` (number)

***

### `setPowerUseTimestamp`

Sets the timestamp a recharging power was used. Powers recharge 24 hours after this timestamp.

```lua
tes3mobileActor:setPowerUseTimestamp(power, timestamp)
```

**Parameters**:

* `power` ([tes3spell](../../types/tes3spell)): The spell object for the power.
* `timestamp` (number): The timestamp of the moment the power was casted, or 24 hours before the recharge point. The timestamp units are hours. The current time as a timestamp can be accessed at tes3.getSimulationTimestamp().

***

### `startCombat`

Forces the actor into combat with another actor.

```lua
tes3mobileActor:startCombat(target)
```

**Parameters**:

* `target` ([tes3mobileActor](../../types/tes3mobileActor))

***

### `startDialogue`

Starts dialogue with this actor for the player.

```lua
tes3mobileActor:startDialogue()
```

***

### `stopCombat`

Ends combat for the actor.

```lua
tes3mobileActor:stopCombat(force)
```

**Parameters**:

* `force` (boolean): If false, the function won't stop combat if the actor has other valid hostile targets.

***

### `unequip`

Unequips one or more items from the actor.

```lua
local result = tes3mobileNPC:unequip({ item = ..., type = ..., armorSlot = ..., clothingSlot = ... })
```

**Parameters**:

* `params` (table)
	* `item` ([tes3item](../../types/tes3item), string): The item to unequip.
	* `type` (number): The item type to unequip. Only used if no other parameter is provided.
	* `armorSlot` (number): The armor slot to unequip.
	* `clothingSlot` (number): The clothing slot to unequip.

**Returns**:

* `result` (boolean)

***

### `updateDerivedStatistics`

Updates statistics derived from attributes, which are magicka, fatigue, and encumbrance. Will also update the UI if used on the player. Normally handled automatically when you use tes3.modStatistic.

```lua
tes3mobileActor:updateDerivedStatistics(attribute)
```

**Parameters**:

* `attribute` ([tes3statistic](../../types/tes3statistic)): Limits the update to statistics derived from this attribute.  e.g. ``mobile:updateDerivedStatistics(mobile.strength)``. If not present, all derived statistics will be updated.

***

### `updateOpacity`

Updates the actor's visual opacity. Used after modifying applied chameleon or invisiblity effects.

```lua
tes3mobileActor:updateOpacity()
```

***

