--- @param e dialogueEnvironmentCreatedEventData
local function onDialogueEnvironmentCreated(e)
	-- Cache the environment variables outside the function for easier access.
	-- Dialogue scripters shouldn't have to constantly pass these to the functions anyway.
	local env = e.environment
	local reference = env.reference --- @type tes3reference
	local mobile = reference.mobile --- @type tes3mobileActor
	local dialogue = env.dialogue --- @type tes3dialogue
	local info = env.info --- @type tes3dialogueInfo

	-- These are default environment functions available to dialogue scripters.
	-- They should be designed in a way that is easy for them to be called.

	function env.CloseDialogue()
		error("Not yet implemented.")
	end

	function env.FollowPlayer()
		error("Not yet implemented.")
	end

	function env.WaitHere()
		error("Not yet implemented.")
	end

	function env.OpenAlchemyMenu()
		error("Not yet implemented.")
	end

	function env.OpenBarterMenu()
		error("Not yet implemented.")
	end

	function env.OpenClassMenu()
		error("Not yet implemented.")
	end

	function env.OpenCompanionInventory()
		error("Not yet implemented.")
	end

	function env.OpenEnchantMenu()
		error("Not yet implemented.")
	end

	function env.OpenPersuasionMenu()
		error("Not yet implemented.")
	end

	function env.OpenRaceMenu()
		error("Not yet implemented.")
	end

	function env.OpenRepairMenu()
		error("Not yet implemented.")
	end

	function env.OpenSpellmakingMenu()
		error("Not yet implemented.")
	end

	function env.OpenSpellMenu()
		error("Not yet implemented.")
	end

	function env.OpenTrainingMenu()
		error("Not yet implemented.")
	end

	function env.OpenTravelMenu()
		error("Not yet implemented.")
	end
end
event.register(tes3.event.dialogueEnvironmentCreated, onDialogueEnvironmentCreated, { priority = 100 })
