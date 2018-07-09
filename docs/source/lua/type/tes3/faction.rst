
Faction
========================================================

This interface represents a faction. It includes information about the faction, such as rank requirements and names, and also includes the player's current rank and other player-specific info.

Properties
--------------------------------------------------------

**attributes** (`number`_)
    The faction's favored attributes.

**name** (`string`_)
    The faction name.

**playerRank** (`number`_)
    The player's rank in this faction. Note that this can be 0 before and after joining a faction. Use **playerJoined** to check for membership of a faction.

**playerReputation** (`number`_)
    The player's reputation in this faction.

**playerJoined** (`boolean`_)
    True if the player has joined this faction.

**playerExpelled** (`boolean`_)
    True if the player has been expelled from this faction.

**ranks** (`rank`_)
    A list of the ranks in the faction.

**reactions** (`reactions`_)
    The disposition change for faction members from a given faction.

**skills** (`number`_)
    The faction's favored skills.


.. _`boolean`: ../lua/boolean.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`rank`: ../lua/tes3/rank.html
.. _`reactions`: ../lua/tes3/reactions.html
