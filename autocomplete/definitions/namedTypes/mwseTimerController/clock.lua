return {
	type = "value",
	description = [[The current clock time for this timer controller. Timer Controller, responsible for `timer.game` type of timers, has clock equal to the game's simuation timestamp. Timer Controllers, responsible for `timer.real`, and `timer.simulate`, types of timers have their initial clock set to `0` on a new game, and their clock's progressions is equal to `deltaTime`. Timer Controller's, responsible for `timer.simulate` timers, clock only advances when the menu mode is off.]],
	valuetype = "number",
}