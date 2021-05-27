tes3mobileProjectile
====================================================================================================

A mobile object for a spell or ammo projectile.

Properties
----------------------------------------------------------------------------------------------------

`boundSize`_ (`tes3vector3`_)
    A vector that shows the size of the bounding box in each direction.

`cellX`_ (`number`_)
    The X grid coordinate of the cell the mobile is in.

`cellY`_ (`number`_)
    The Y grid coordinate of the cell the mobile is in.

`disposition`_ (`number`_)
    No description available.

`expire`_ (`number`_)
    No description available.

`firingMobile`_ (`tes3mobileActor`_)
    The mobile that fired this projectile.

`firingWeapon`_ (`tes3weapon`_)
    The weapon that fired this projectile.

`flags`_ (`number`_)
    Access to the root mobile object flags, represented as an integer. Should not be accessed directly.

`height`_ (`number`_)
    The height of the mobile above the ground.

`impulseVelocity`_ (`tes3vector3`_)
    A vector that represents the 3D acceleration of the object.

`movementCollision`_ (`boolean`_)
    Controls if the mobile has movement collision active. When false, the mobile can move through any object, but can still block other mobiles, and can still be hit in combat. Actors will still follow pathgrids, ramps and stairs when navigating.

`movementFlags`_ (`number`_)
    Access to the root mobile object movement flags, represented as an integer. Should not be accessed directly.

`objectType`_ (`number`_)
    The type of mobile object. Maps to values in tes3.objectType.

`position`_ (`tes3vector3`_)
    A vector that represents the 3D position of the object.

`prevMovementFlags`_ (`number`_)
    Access to the root mobile object movement flags from the previous frame, represented as an integer. Should not be accessed directly.

`reference`_ (`tes3reference`_)
    Access to the reference object for the mobile, if any.

`velocity`_ (`tes3vector3`_)
    A vector that represents the 3D velocity of the object.

.. toctree::
    :hidden:

    tes3mobileProjectile/boundSize
    tes3mobileProjectile/cellX
    tes3mobileProjectile/cellY
    tes3mobileProjectile/disposition
    tes3mobileProjectile/expire
    tes3mobileProjectile/firingMobile
    tes3mobileProjectile/firingWeapon
    tes3mobileProjectile/flags
    tes3mobileProjectile/height
    tes3mobileProjectile/impulseVelocity
    tes3mobileProjectile/movementCollision
    tes3mobileProjectile/movementFlags
    tes3mobileProjectile/objectType
    tes3mobileProjectile/position
    tes3mobileProjectile/prevMovementFlags
    tes3mobileProjectile/reference
    tes3mobileProjectile/velocity

.. _`boundSize`: tes3mobileProjectile/boundSize.html
.. _`cellX`: tes3mobileProjectile/cellX.html
.. _`cellY`: tes3mobileProjectile/cellY.html
.. _`disposition`: tes3mobileProjectile/disposition.html
.. _`expire`: tes3mobileProjectile/expire.html
.. _`firingMobile`: tes3mobileProjectile/firingMobile.html
.. _`firingWeapon`: tes3mobileProjectile/firingWeapon.html
.. _`flags`: tes3mobileProjectile/flags.html
.. _`height`: tes3mobileProjectile/height.html
.. _`impulseVelocity`: tes3mobileProjectile/impulseVelocity.html
.. _`movementCollision`: tes3mobileProjectile/movementCollision.html
.. _`movementFlags`: tes3mobileProjectile/movementFlags.html
.. _`objectType`: tes3mobileProjectile/objectType.html
.. _`position`: tes3mobileProjectile/position.html
.. _`prevMovementFlags`: tes3mobileProjectile/prevMovementFlags.html
.. _`reference`: tes3mobileProjectile/reference.html
.. _`velocity`: tes3mobileProjectile/velocity.html

.. _`boolean`: ../../lua/type/boolean.html
.. _`number`: ../../lua/type/number.html
.. _`tes3mobileActor`: ../../lua/type/tes3mobileActor.html
.. _`tes3reference`: ../../lua/type/tes3reference.html
.. _`tes3vector3`: ../../lua/type/tes3vector3.html
