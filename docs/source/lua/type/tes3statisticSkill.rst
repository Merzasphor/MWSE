tes3statisticSkill
====================================================================================================

A structure that holds statistical information relating to the current and base values of a skill statistic.

Morrowind statistics do not track buffs and debuffs separately. Instead, total buff or debuff values can be calculated with the tes3.getEffectMagnitude function, using the appropriate buff or debuff magic effect for the statistic.

Properties
----------------------------------------------------------------------------------------------------

`base`_ (`number`_)
    The base value of the statistic. For example, for a mobile with a normal health amount of 100, fortified by 50, and having taken damage of 25, the base value would be 100, the normal health amount.

`base`_ (`number`_)
    The base value of the skill statistic. Damage, and fortify spell effects don't change base skill value.

`baseRaw`_ (`number`_)
    The base value of the skill statistic, as stored in memory. Prefer to use .base unless you know what you're doing.

`baseRaw`_ (`number`_)
    The base value of the statistic, as stored in memory. Prefer to use .base unless you know what you're doing.

`current`_ (`number`_)
    The current value of the skill statistic.

`current`_ (`number`_)
    The current value of the statistic. For example, for a mobile with a normal health amount of 100, fortified by 50, and having taken damage of 25, the current value would be 125, the health amount after all buffs and debuffs have been accounted for.

`currentRaw`_ (`number`_)
    The current value of the skill statistic, as stored in memory. Prefer to use .current unless you know what you're doing.

`currentRaw`_ (`number`_)
    The current value of the statistic, as stored in memory. Prefer to use .current unless you know what you're doing.

`normalized`_ (`number`_)
    The normalized value of the skill statistic.

`normalized`_ (`number`_)
    The normalized value of the statistic. For example, for an account with current health of 50 and base health of 100, the normalized value would be equal to current divided by base. 50 (current) / 100 (base) = .5 (normalized). This is useful for quickly calculating percentages for statistics.

`type`_ (`number`_)
    No description available.

.. toctree::
    :hidden:

    tes3statisticSkill/base
    tes3statisticSkill/base
    tes3statisticSkill/baseRaw
    tes3statisticSkill/baseRaw
    tes3statisticSkill/current
    tes3statisticSkill/current
    tes3statisticSkill/currentRaw
    tes3statisticSkill/currentRaw
    tes3statisticSkill/normalized
    tes3statisticSkill/normalized
    tes3statisticSkill/type

.. _`base`: tes3statisticSkill/base.html
.. _`base`: tes3statisticSkill/base.html
.. _`baseRaw`: tes3statisticSkill/baseRaw.html
.. _`baseRaw`: tes3statisticSkill/baseRaw.html
.. _`current`: tes3statisticSkill/current.html
.. _`current`: tes3statisticSkill/current.html
.. _`currentRaw`: tes3statisticSkill/currentRaw.html
.. _`currentRaw`: tes3statisticSkill/currentRaw.html
.. _`normalized`: tes3statisticSkill/normalized.html
.. _`normalized`: tes3statisticSkill/normalized.html
.. _`type`: tes3statisticSkill/type.html

.. _`number`: ../../lua/type/number.html
