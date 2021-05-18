return {
	type = "function",
	description = [[Loads an animation and uses it to override existing animations on an actor. Animation groups present in the file will replace the actor's animation groups. The actor's model must be already loaded into memory to have its animations modified. The overridden animations only persist until the actor is unloaded.
    
    Calling this multiple times will remove the previous animation override before loading the new animation. Calling this without a file argument will just reset the animations to base.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3mobileActor|tes3reference|string", description = "The reference to the actor that is having its animations modified." },
			{ name = "file", type = "string", optional = true, description = "The specified animation base file that will be loaded. e.g. For an animation composed of files anim.nif, xanim.nif and xanim.kf, you should pass file=\"anim.nif\". The animation target skeleton _must_ match the skeleton of the actor to work. i.e. 3rd person anims for NPCs and tes3.player, 1st person anims for firstPersonReference." },
		},
	}},
}
