local function onDamaged(e)
    -- We only care if the player recieved the damage
    if e.reference ~= tes3.player then
        return
    end

    -- Does the damage come from drowining?
    if e.source ~= tes3.damageSource.suffocation then
        return
    end

    -- Is the player in Mudan Grotto?
    if tes3.mobilePlayer.cell.id:lower() == "mudan grotto" then

        -- Did the damage kill the player?
        if e.killingBlow == true then
            tes3.messageBox("You died diving for treasure!")
        end
    end
end
event.register("damaged", onDamaged)