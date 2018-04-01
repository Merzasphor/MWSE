
Armor
========================================================

Armor objects include any equipment items shown under the Armor tab in the Construction Set. This includes shields, but not clothing.

As with any item, this is for *base* objects. Additional `ItemVariables`_ information is available either from an `ItemStack`_, `EquipmentStack`_ or a direct `Reference`_.


Properties
--------------------------------------------------------

armorRating
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. The unadjusted, raw armor rating for the item. This does not take into account the wearer's skills or GMSTs.

enchantCapacity
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. The number of points available for enchanting.

enchantment
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Enchantment`_. The current enchantment on the object, or ``nil`` if the item is not enchanted.

health
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. Read-only. The max condition of the item.

icon
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`String`_. Read-only. The path to the object's icon, under *Data Files/Textures*.

id
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`String`_. Read-only. The object's unique id.

isLeftPart
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Boolean`_. Read-only. For gauntlets, bracers, and pauldrons, this will return true if it is the left slot. This is functionally identical to checking to see if **slot** is 2, 6, or 9. Both right parts and slots that are not mirrored both return false.

model
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`String`_. Read-only. The path to the object's model, under *Data Files/Models*.

objectType
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. Read-only. The object's `Object Type`_, which will always be 1330467393. This matches the constant ``TES3.ObjectType.Armor``.

script
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Script`_. Read-only. The currently attached script on the object, or ``nil`` if the object is not scripted.

slot
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. Read-only. Returns the slot number of this piece of armor. See `Slots`_ for specific values.

slotName
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`String`_. Read-only. Returns the slot name of this piece of armor. See `Slots`_ for specific values.

value
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. Read-only. The monitary value of the item.

weight
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. Read-only. The weight of the item.

weightClass
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. Read-only. Returns what category of armor (e.g. light, medium, heavy) this armor falls under. Every time this property is referenced it checks against the associated GMSTs.

The weight classes are:

== =============
ID Weight Class
== =============
0  Light Armor
1  Medium Armor
2  Heavy Armor
== =============


Slots
--------------------------------------------------------

The following table explains the relationship between **slot** and **slotName**, and shows the possible values returned by those two properties.

==== ==========================
Slot Name
==== ==========================
0    Helmet
1    Cuirass
2    Left Pauldron
3    Right Pauldron
4    Greaves
5    Boots
6    Left Gauntlet
7    Right Gauntlet
8    Shield
9    Left Bracer
10   Right Bracer
==== ==========================

.. note:: These values do not match the ones exposed to mwscript. If passing values between the two scripting systems, you will need to adjust the slot to match. This can be done by simply adding or subtracting 1 from the value of **slot**.


.. _`Slots`: #slots

.. _`Boolean`: ../lua/boolean.html
.. _`Number`: ../lua/number.html
.. _`String`: ../lua/string.html
.. _`Table`: ../lua/table.html

.. _`Enchantment`: enchantment.html
.. _`EquipmentStack`: equipmentStack.html
.. _`ItemStack`: itemStack.html
.. _`ItemVariables`: itemVariables.html
.. _`Reference`: reference.html
.. _`Script`: script.html

.. _`Object Type`: ../../../mwscript/references.html#object-types
