--- @meta

--- A game object which contains information on actor's current and assigned AI packages.
--- @class tes3aiPlanner
--- @field currentPackageIndex number *Read-only*. Access to index of currently active AI package in packages table.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The access to mobile actor this tes3aiPlanner object works on.
--- @field nextOpenPackageIndex number *Read-only*. 
--- @field packages table *Read-only*. The table with tes3aiPackage objects assigned to this mobile actor.
tes3aiPlanner = {}

--- Fetches currently active AI package.
--- @return tes3aiPackage|tes3aiPackageActivate|tes3aiPackageEscort|tes3aiPackageFollow|tes3aiPackageTravel|tes3aiPackageWander result No description yet available.
function tes3aiPlanner:getActivePackage() end

