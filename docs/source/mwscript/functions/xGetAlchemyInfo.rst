
xGetAlchemyInfo
========================================================

:Parameters:

    - ``string`` **id**: ID of the alchemy item to get information for.

:Returned:

    - ``long`` **effectCount**: The number of effects on the alchemy item, between 1 and 8.
    - ``long`` **flags**: 1 = autocalc, 2 = PC Start, 4 = Always Succeeds

Provides information important to a given alchemy record. Unlike the other related functions, there is no associated ability to set this information. The effects themselves can still be retrieved and modified using `xGetEffectInfo <xGetEffectInfo.html>`_ and `xSetEffectInfo <xSetEffectInfo.html>`_.
