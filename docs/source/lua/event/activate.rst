
activate
========================================================

**Event Data:**

- ``reference`` **activator**: Who or what triggered the activate event.
- ``reference`` **target**: The reference that was activated.

This event is invoked whenever something is activated, typically by the player. Activation is usually done with the associated activate/use key, but may also be triggered by scripts.
Non-player actors may also activate objects, such as when opening doors, or via MWSE functions like ``xActivate`` or ``tes3.activate()``.

Objects that invoke the ``"activate"`` event when used by the player include anything with a name tag, such as items, doors, and NPCs, but also objects that aren't strictly supposed to be interactable, like banners or animated boats.

**Returns:**

- ``false`` prevents the event from continuing, effectively disabling activation.

**Filters:**  

- May be filtered by the **target** reference.

Example:
::
	--event.register(eventKey, callbackFunction, optionsTable)

	--Show the id when the player activates an object.
	function myOnActivateCallback(e)
		if e.activator == tes3.getPlayerRef() then
			tes3.messageBox{message = "Activated " .. e.target.object.id}
		end
	end