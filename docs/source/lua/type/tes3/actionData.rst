
Action Data
========================================================

This represents an action being taken by a `Mobile Creature`_, `Mobile NPC`_, or `Mobile Player`_.


Properties
--------------------------------------------------------

.. toctree::
   :hidden:

   actionData/aiBehaviorState
   actionData/animationAttackState
   actionData/attackDirection
   actionData/attackSwing
   actionData/currentAnimationGroup
   actionData/hitTarget
   actionData/lastBarterHoursPassed
   actionData/nockedProjectile
   actionData/physicalDamage
   actionData/stolenFrom
   actionData/target
   actionData/walkDestination
    
`aiBehaviorState <actionData/aiBehaviorState.html>`_ (`Number`_)
    The behavior state of the action.
    
`animationAttackState <actionData/animationAttackState.html>`_ (`Number`_)
    This field still needs research. Please feel free to play with it, and modify the documentation.
    
`attackDirection <actionData/attackDirection.html>`_ (`Number`_)
    When attacking, the direction swung with the weapon. This shows if the actor was thrusting, swinging, or chopping.
    
`attackSwing <actionData/attackSwing.html>`_ (`Number`_)
    When attacking, this value represents how much the weapon has been pulled back.
    
`currentAnimationGroup <actionData/currentAnimationGroup.html>`_ (`Number`_)
    This field still needs research. Please feel free to play with it, and modify the documentation.
    
`hitTarget <actionData/hitTarget.html>`_ (`Mobile Creature`_, `Mobile NPC`_, or `Mobile Player`_)
    This field still needs research. Please feel free to play with it, and modify the documentation.
    
`lastBarterHoursPassed <actionData/lastBarterHoursPassed.html>`_ (`Number`_)
    This field still needs research. Please feel free to play with it, and modify the documentation.
    
`nockedProjectile <actionData/nockedProjectile.html>`_ (`Weapon`_)
    The currently knocked projectile the associated actor is using.
    
`physicalDamage <actionData/physicalDamage.html>`_ (`Number`_)
    When attacking, this is the value of the weapon damage that was rolled. This value doesn't take into account the actor's strength, or other additional damage.
    
`stolenFrom <actionData/stolenFrom.html>`_ (`Faction`_ or `NPC`_)
    This field still needs research. Please feel free to play with it, and modify the documentation.
    
`target <actionData/target.html>`_ (`Mobile Creature`_, `Mobile NPC`_, or `Mobile Player`_)
    This field still needs research. Please feel free to play with it, and modify the documentation.
    
`walkDestination <actionData/walkDestination.html>`_ (`Vector3`_)
    If moving to a location, this is the position to be walked to.


.. _`Boolean`: ../lua/boolean.html
.. _`Number`: ../lua/number.html
.. _`String`: ../lua/string.html
.. _`Table`: ../lua/table.html

.. _`Faction`: faction.html
.. _`Mobile Creature`: mobileCreature.html
.. _`Mobile NPC`: mobileNPC.html
.. _`Mobile Player`: mobilePlayer.html
.. _`NPC`: npc.html
.. _`Weapon`: weapon.html
.. _`Vector3`: vector3.html

.. _`Object Type`: ../../../mwscript/references.html#object-types
