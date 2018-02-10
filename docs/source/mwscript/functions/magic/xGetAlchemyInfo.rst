
xGetAlchemyInfo
========================================================

**Parameters:**

- ``string`` **id**: ID of the alchemy item to get information for.

**Returned:**

- ``long`` **effectCount**: The number of effects on the alchemy item, between 1 and 8.
- ``long`` **flags**: 1 = autocalc, 2 = PC Start, 4 = Always Succeeds

Provides information important to a given alchemy object. Unlike the other related functions, there is no associated ability to set this information. The effects themselves can still be retrieved and modified using `xGetEffectInfo <xGetEffectInfo.html>`_ and `xSetEffectInfo <xSetEffectInfo.html>`_.

.. tip:: Use this function to determine the state of a potion before modifying it with `xAddEffect <xAddEffect.html>`_, `xDeleteEffect <xDeleteEffect.html>`_ or `xSetEffectInfo <xSetEffectInfo.html>`_.


Example
-------

::

  begin Example_xGetAlchemyInfo

  long numEffects
  long flags

  setx numEffects flags to xGetAlchemyInfo "potion_skooma_01"

  MessageBox "flags: %g" flags
  MessageBox "numEffects: %g" numEffects
  MessageBox "potion_skooma_01"

  end
