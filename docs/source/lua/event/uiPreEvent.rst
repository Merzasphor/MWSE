
uiPreEvent
========================================================

**uiPreEvent** is triggered through various UI events. This includes scrolling through panes, clicking buttons, selecting icons, or a host of other UI-related activities.

This event fires before `uiEvent`_, and has the additional advantage of being able to be blocked.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.

.. attention:: UI events and dehardcoding will be more flushed out in MWSE 2.2. For now, this and the `uiEvent`_ event help to provide limited interaction with the game's user interface.


Event Data
--------------------------------------------------------

block
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3uiBlock`_. Read-only. The UI block that is firing this event.

parent
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3uiBlock`_. Read-only. **block**'s parent.

property
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. Read-only. One of three undefined variables related to the event.

var1
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. Read-only. One of three undefined variables related to the event.

var2
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. Read-only. One of three undefined variables related to the event.


Filter
--------------------------------------------------------
This event does not support filtering.


.. _`Event Guide`: ../guide/events.html

.. _`uiEvent`: uiEvent.html

.. _`Number`: ../type/lua/number.html

.. _`tes3uiBlock`: ../type/tes3/uiBlock.html
