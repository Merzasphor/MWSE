
xGetSpell
========================================================

**Parameters:**

- ``string`` **spellID**: The spell ID to search for.

**Returned:**

- ``long`` **result**: 1 if the spell was found, otherwise 0.

Returns 1 if spellId is present, 0 otherwise. This is not a wrapper for GetSpell; it's a reimplementation. It only works for NPCs and the player.
