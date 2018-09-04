
tes3.playVoiceover
====================================================================================================

**Parameters:**

Uses named parameters.

- `Reference`_ or `Mobile Actor`_ **actor**:
    The actor that is to use the voiceover.

- `string`_ **voiceover**:
    The voiceover id to use. Accepts either a key or a value from the tes3.voiceover table.

**Returned:**

- `boolean`_: ``true`` if the input was valid, or ``false`` otherwise.

This function plays a voiceover on the given **actor**.


Example
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    -- Make the player say a greeting.
    tes3.playVoiceover({ actor = tes3.player, voiceover = "hello" })


.. _`boolean`: ../../type/lua/boolean.html
.. _`number`: ../../type/lua/number.html
.. _`string`: ../../type/lua/string.html

.. _`Mobile Actor`: ../../type/tes3/mobileActor.html
.. _`Reference`: ../../type/tes3/reference.html
