
-- Print a message when the player is over-encumbered
local function onUpdate(e)
    -- We only care about the player
    if e.reference ~= tes3.player then
        return
    end

    -- Note: We now know e.mobile is tes3.mobilePlayer
    if e.mobile.encumbrance.normalized > 1 then --  Player is over-encumbered
        tes3.messageBox("I can't carry this much loot.")
    end
end
event.register("updatedDerivedStatistics", onUpdate, { filter = "encumbrance" })

-- Possible e.name values are:
-- agility, endurance, intelligence, luck, personality, speed, strength, willpower,
-- encumbrance, fatigue, health, magicka, magickaMultiplier,
-- combat, magic, stealth,
-- acrobatics, alchemy, alteration, armorer, athletics, axe, block, bluntWeapon,
-- conjuration, destruction, enchant, handToHand, heavyArmor, illusion, lightArmor,
-- longBlade, marksman, mediumArmor, mercantile, mysticism, restoration, security,
-- shortBlade, sneak, spear, speechcraft, unarmored.

-- So basically any attribute, any skill (including creature skills), health, magicka,
-- fatigue, and magickaMultiplier.