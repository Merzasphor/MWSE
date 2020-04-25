local tes3iterator = tes3.player.object.equipment
for _, tes3iteratorNode in pairs(tes3iterator) do
    -- tes3iteratorNode is type tes3equipmentStack, as tes3.player.object.equipment is a list of tes3equipmentStack.
    mwse.log("Object ID: %s", tes3iteratorNode.object.id)
end