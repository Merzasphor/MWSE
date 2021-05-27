tes3.loadAnimation
====================================================================================================

Loads an animation and uses it to override existing animations on an actor. Animation groups present in the file will replace the actor's animation groups. The actor's model must be already loaded into memory to have its animations modified. The overridden animations only persist until the actor is unloaded.
    
    Calling this multiple times will remove the previous animation override before loading the new animation. Calling this without a file argument will just reset the animations to base.

Parameters
----------------------------------------------------------------------------------------------------

Accepts parameters through a table with the given keys:

reference (`tes3mobileActor`_, `tes3reference`_, `string`_)
    The reference to the actor that is having its animations modified.

file (`string`_)
    Optional. The specified animation base file that will be loaded. e.g. For an animation composed of files anim.nif, xanim.nif and xanim.kf, you should pass file="anim.nif". The animation target skeleton must match the skeleton of the actor to work.

.. _`string`: ../../../lua/type/string.html
.. _`tes3mobileActor`: ../../../lua/type/tes3mobileActor.html
.. _`tes3reference`: ../../../lua/type/tes3reference.html
