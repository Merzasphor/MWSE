return {
	type = "class",
	description = [[A game object which contains information on actor's animations.

Animations are divided into three layers. The layer 0 is the base layer containing all the base animations for every humanoid in the game, including the player (when in third person). These animations come from `base_anim.nif`. Layer 1 is for female animations. Any animations present in `base_anim_female.nif` override their male counterparts for humanoid races. For beast races, layer 1 animations come from `base_anim_kna.nif`. Layer 2 are the custom animations assigned to the actor.]],
}