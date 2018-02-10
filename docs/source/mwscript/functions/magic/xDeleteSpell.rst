
xDeleteSpell
========================================================

**Parameters:**

- ``long`` **type**: The `Object Type`_ to delete an effect from. Must be an alchemy, spell, or enchantment object.
- ``string`` **id**: The object ID to remove an effect from.
- ``long`` **index**: The index of the effect to remove. Must be between (inclusive) 1 and 8.

**Returned:**

- ``long`` **result**: 1 if the spell was deleted.

Deletes a spell from the master spell list. It will no longer persist in save games.

Notes: Be very careful using this command.
The effect of deleting a spell originating from the CS is undefined.
The effect of deleting a spell referenced by other entities (player, npcs, traps, etc.) in undefined.
Do not attempt to add a deleted spell with AddSpell. AddSpell will succeed, but leave the game in an
indeterminate state. It's not yet clear why this happens, but I hope to fix it in the future.

.. _`Object Type`: ../reference.html#record-types




xDeleteSpell
result (long): xDeleteSpell spell_id (long | string)

spell_id: spell to delete
result: 1 on success, 0 on failure
This function will fail if spell_id does not exist.