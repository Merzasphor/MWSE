
Dialogue
====================================================================================================

A **Dialogue** is a topic of conversation or journal entry that the player can have.


Properties
----------------------------------------------------------------------------------------------------

**id** (`string`_, read-only)
    The name of the dialogue.

**info** (`tes3iterator`_ of `tes3dialogueInfo`_, read-only)
    The potential responses for this dialogue topic.

**journalIndex** (`number`_, read-only)
    The current journal index for this entry. This is only valid when **type** is 4 (journal).

**objectType** (`number`_, read-only)
    The object's `Object Type`_.

**sourceMod** (`string`_, read-only)
    The object's originating plugin filename.

**type** (`number`_, read-only)
    The type of dialogue. A value of 0 is regular dialogue, 1 is voice, 2 is a greeting, 3 is persuasion, 4 is a journal entry.


Examples
----------------------------------------------------------------------------------------------------

Print List of Known Topics
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: lua

    -- Print a list of topics currently known by the player.
    for dialogue in tes3.iterate(tes3.mobilePlayer.dialogueList) do
        mwse.log("Topic: %s", dialogue.id)
    end


.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html

.. _`Object Type`: baseObject/objectType.html

.. _`tes3iterator`: iterator.html
.. _`tes3dialogueInfo`: dialogueInfo.html
