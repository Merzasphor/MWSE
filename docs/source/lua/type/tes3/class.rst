
Class
========================================================

This interface represents a class. Classes are assigned to an `NPC`_ and the player.


Properties
--------------------------------------------------------

**attributes** (`table`_ of `number`_)
    The minor **skills** for this class.

**bartersAlchemy** (`boolean`_)
    Friendly access into the **services** property. Determines if the class allows buying and selling alchemy items.

**bartersApparatus** (`boolean`_)
    Friendly access into the **services** property. Determines if the class allows buying and selling apparatus items.

**bartersArmor** (`boolean`_)
    Friendly access into the **services** property. Determines if the class allows buying and selling armor items.

**bartersBooks** (`boolean`_)
    Friendly access into the **services** property. Determines if the class allows buying and selling books items.

**bartersClothing** (`boolean`_)
    Friendly access into the **services** property. Determines if the class allows buying and selling clothing items.

**bartersEnchantedItems** (`boolean`_)
    Friendly access into the **services** property. Determines if the class allows buying and selling enchanted items.

**bartersIngredients** (`boolean`_)
    Friendly access into the **services** property. Determines if the class allows buying and selling ingredients items.

**bartersLights** (`boolean`_)
    Friendly access into the **services** property. Determines if the class allows buying and selling lights items.

**bartersLockpicks** (`boolean`_)
    Friendly access into the **services** property. Determines if the class allows buying and selling lockpicks items.

**bartersMiscItems** (`boolean`_)
    Friendly access into the **services** property. Determines if the class allows buying and selling miscellaneous items.

**bartersProbes** (`boolean`_)
    Friendly access into the **services** property. Determines if the class allows buying and selling probes items.

**bartersRepairTools** (`boolean`_)
    Friendly access into the **services** property. Determines if the class allows buying and selling repair tools.

**bartersWeapons** (`boolean`_)
    Friendly access into the **services** property. Determines if the class allows buying and selling weapons items.

**description** (`string`_)
    The description of the class. Really only shown to the player.

**id** (`string`_)
    The object's unique id.

**majorSkills** (`table`_ of `number`_)
    The major **skills** for this class.

**minorSkills** (`table`_ of `number`_)
    The minor **skills** for this class.

**name** (`string`_)
    The user-friendly name for the class.

**objectType** (`number`_, read-only)
    The object's `objectType`_.

**offersEnchanting** (`boolean`_)
    Friendly access into the **services** property. Determines if the class offers enchanting services.

**offersRepairs** (`boolean`_)
    Friendly access into the **services** property. Determines if the class offers repair services.

**offersSpellmaking** (`boolean`_)
    Friendly access into the **services** property. Determines if the class offers spellmaking services.

**offersSpells** (`boolean`_)
    Friendly access into the **services** property. Determines if the class sells spells.

**offersTraining** (`boolean`_)
    Friendly access into the **services** property. Determines if the class offers training services.

**playable** (`boolean`_)
    A flag that determines if the player can choose this class.

**skills** (`table`_ of `number`_)
    A list of skills that the class has assigned to it. Odd-indexed skills are major, while even-indexed skills are major.

**sourceMod** (`string`_)
    The object's originating plugin filename.

**specialization** (`number`_)
    The specialization of the class, be it combat, stealth, or magic.


.. _`boolean`: ../lua/boolean.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html
.. _`userdata`: ../lua/userdata.html

.. _`boundingBox`: physicalObject/boundingBox.html
.. _`NPC`: npc.html
.. _`objectType`: baseObject/objectType.html
