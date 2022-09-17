return {
	type = "class",
	description = [[

### Collision Basics:

Collidion detection means the detecting of the intersection of two objects. The collision detection is split in narrow and broad phase. The during narrow phase the actuall collision intersection test are done. The broad phase it is determined if two object should be tested for a potential collision. For example, there is no need to check for collision between two static, non-movable objects.

The `niCollisionGroup` class is used to group the object into two main groups, based on whether the objects move or not:

 - colliders - The objects that are expected to move. Each time the collision system starts finding collisions, it checks for collisions between each of the colliders. It tests every collider against every collidee as well.
 - collidees - The objects that don't move. These objects are never tested for collision agains other collidees, making them less computationally expensive.
]],
	experimental = true,
}