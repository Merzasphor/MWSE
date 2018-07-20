
uiActivated
====================================================================================================

This event is invoked after a UI menu has been built or made visible, at the point that all menu elements contain updated data.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
----------------------------------------------------------------------------------------------------

element
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`UI Element`_. The menu element that was created. The event is filtered on ``element.name``. Read-only.

newlyCreated
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`boolean`_. ``true`` if the menu was created for the first time or destroyed and re-created; ``false`` if it was made visible after being hidden.

This can be used when adding custom elements to a menu, as elements previously added will still exist if the menu was hidden. If the menu was re-created, the elements will need to be added again.


Filter
----------------------------------------------------------------------------------------------------
This event may be filtered by **element**'s ``.name`` property.

Supported menus:
    - MenuAlchemy
    - MenuAttributes
    - MenuAttributesList (Enchanting/spellmaking effect attribute)
    - MenuAudio (Options, audio)
    - MenuBarter
    - MenuBirthSign
    - MenuBook
    - MenuChooseClass
    - MenuClassChoice
    - MenuClassMessage
    - MenuConsole
    - MenuContents (Container/NPC inventory)
    - MenuCreateClass
    - MenuCtrls (Options, controls)
    - MenuDialog
    - MenuEnchantment
    - MenuInput
    - MenuInputSave
    - MenuInventory (Player inventory)
    - MenuInventorySelect (Item selector)
    - MenuJournal
    - MenuLevelUp
    - MenuLoad
    - MenuLoading
    - MenuMagic (Spell/enchanted item selector)
    - MenuMagicSelect
    - MenuMap
    - MenuMapNoteEdit
    - MenuMessage
    - MenuMulti (Status bars, current weapon/magic, active effects and minimap)
    - MenuName
    - MenuOptions (Main menu)
    - MenuPersuasion
    - MenuPrefs (Options, prefs)
    - MenuQuantity
    - MenuQuick (Quick keys)
    - MenuRaceSex
    - MenuRepair
    - MenuRestWait
    - MenuSave
    - MenuScroll
    - MenuServiceRepair
    - MenuServiceSpells
    - MenuServiceTraining
    - MenuServiceTravel
    - MenuSetValues (Enchanting/spellmaking effect values)
    - MenuSkills
    - MenuSkillsList (Enchanting/spellmaking effect skill)
    - MenuSpecialization
    - MenuSpellmaking
    - MenuStat (Player attributes, skills, factions etc.)
    - MenuStatReview
    - MenuSwimFillBar
    - MenuTimePass
    - MenuTopic
    - MenuVideo (Options, video)


.. _`Event Guide`: ../guide/events.html

.. _`boolean`: ../type/lua/boolean.html
.. _`UI Element`: ../type/tes3ui/element.html
