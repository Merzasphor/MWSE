
xGetRace
========================================================

**Parameters:**

- ``short`` **returnType**: The return pattern desired. See below for details.

**Returned (returnType is 0):**

- ``string`` **raceID**: The object ID of the target's race.

**Returned (returnType is 1):**

- ``array`` **arrayID**: An array ID containing the values of the race.

This function fetches the objectID or complete details about the target's race.

.. warning:: The arrays returned by this function when **returnType** is 1 are volatile. They should not be used for custom storage. Whenever xGetRace is called, the arrays are cleared and refilled with up-to-date information.

If **returnType** is 0, the response is the race's object ID. Otherwise, the returned array contains the following values:

===== ========== ==========================
Index Type       Contents
===== ========== ==========================
0     ``string`` Object ID.
1     ``string`` Name.
2     ``array``  Skill bonuses.
3     ``array``  Starting attributes.
4     ``float``  Male height.
5     ``float``  Female height.
6     ``float``  Male weight.
7     ``float``  Female weight.
8     ``long``   Playable flag.
9     ``long``   Beast flag.
===== ========== ==========================

The skill bonuses array begins with index 0 holding the number of skill bonuses (a value between 0 and 7). Pairs of values are then returned. The odd indexes hold the `Skill`_ while the even indexes hold the bonus to the given skill.

The starting attributes array contains the following values:

===== ========== ==========================
Index Type       Contents
===== ========== ==========================
0     ``long``   Male strength.
1     ``long``   Female strength.
2     ``long``   Male intelligence.
3     ``long``   Female intelligence.
4     ``long``   Male willpower.
5     ``long``   Female willpower.
6     ``long``   Male agility.
7     ``long``   Female agility.
8     ``long``   Male speed.
9     ``long``   Female speed.
10    ``long``   Male endurance.
11    ``long``   Female endurance.
12    ``long``   Male personality.
13    ``long``   Female personality.
14    ``long``   Male luck.
15    ``long``   Female luck.
===== ========== ==========================

.. _`Skill`: ../references.html#skills
