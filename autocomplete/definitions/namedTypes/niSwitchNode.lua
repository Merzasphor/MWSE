return {
	type = "class",
	description = [[An object that represents groups of multiple scene graph subtrees, only one of which (the "active child") is active (drawn) at any given time. They are useful for swapping different representations of the same object in and out (such as pristine, damaged or destroyed versions of a spaceship). They are also used as a base class for specific switch-like objects (such as geometric "flipbook" animations and level-of-detail switches. If you detach the "active child" the switch node will automatically set the active child to none (index = -1).]],
	inherits = "niNode",
}