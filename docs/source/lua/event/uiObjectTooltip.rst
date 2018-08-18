
uiObjectTooltip
========================================================

The **uiObjectTooltip** event triggers when a new tooltip is displayed for all in-world objects and items, and inventory tiles in all dialogues. The tooltip will be already be built.

Tooltips for inventory tiles are built on mouseover, while tooltips for in-world objects are rebuilt every frame.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
--------------------------------------------------------

tooltip
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Element`_. The newly created tooltip element. Due to timeouts and target changes, it may be destroyed at any time.

object
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3object`_. Read-only. The object being examined.

reference
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3reference`_. Read-only. The reference being examined. Only valid for in-world objects. For inventory tiles it will always be **nil**.

itemData
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3itemData`_. Read-only. The item data of **object**, if any.

count
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. Read-only. The number of items in the stack.


Filter
--------------------------------------------------------
This event does not support filters.


.. _`Event Guide`: ../guide/events.html

.. _`Number`: ../type/lua/number.html

.. _`Element`: ../type/tes3ui/element.html
.. _`tes3itemData`: ../type/tes3/itemData.html
.. _`tes3object`: ../type/tes3/baseObject.html
.. _`tes3reference`: ../type/tes3/reference.html
