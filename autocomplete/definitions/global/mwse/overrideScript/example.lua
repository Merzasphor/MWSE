-- In this example, the vanilla "RaceCheck" script is overridden
-- with our own raceCheck() function that does the same thing.

local raceCheckScriptID = "RaceCheck"

local function raceCheck()
	-- This is almost always the desired behavior,
	-- since we are overriding the script.
	mwscript.stopScript({ script = raceCheckScriptID })

	local pcRaceID = tes3.player.object.race.id:lower()
	local PCRace = tes3.findGlobal("PCRace")

	if pcRaceID == "argonian" then
		PCRace.value = 1
	elseif pcRaceID == "breton" then
		PCRace.value = 2
	elseif pcRaceID == "dark elf" then
		PCRace.value = 3
	elseif pcRaceID == "high elf" then
		PCRace.value = 4
	elseif pcRaceID == "imperial" then
		PCRace.value = 5
	elseif pcRaceID == "khajiit" then
		PCRace.value = 6
	elseif pcRaceID == "nord" then
		PCRace.value = 7
	elseif pcRaceID == "orc" then
		PCRace.value = 8
	elseif pcRaceID == "redguard" then
		PCRace.value = 9
	elseif pcRaceID == "wood elf" then
		PCRace.value = 10
	end
end

-- Script overrides can be queued when initialited event triggers.
event.register(tes3.event.initialized, function()
	mwse.overrideScript(raceCheckScriptID, raceCheck)
end)
