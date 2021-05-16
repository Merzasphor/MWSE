
-- Print a message if player's arrow knocks down its target
local function onDamaged(e)
    -- We only care if the player did the damage
    if e.attackerReference ~= tes3.player then
        return
    end

    -- Check if the damage was caused by a projectile, but not by a spell, so it must be an arrow or a bolt
    if e.projectile ~= nil and e.magicSourceInstance == nil then

        -- Did the damage knock down the target?
        if e.checkForKnockdown == true then
            tes3.messageBox("Your arrow knocked down its target!")
        end
    end
end
event.register("damaged", onDamaged)