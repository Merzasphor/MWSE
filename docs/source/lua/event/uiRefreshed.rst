
uiRefreshed
====================================================================================================

This event is invoked after a UI menu has been created or recreated. This can be useful for when important game subcomponents are destroyed and remade, without the entire UI being activated.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
----------------------------------------------------------------------------------------------------

element
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`UI Element`_. The menu element that was recreated or refreshed. The event is filtered on ``element.name``. Read-only.


Filter
----------------------------------------------------------------------------------------------------
This event may be filtered by **element**'s ``.name`` property.

Supported menus:
    - MenuStat_scroll_pane


.. _`Event Guide`: ../guide/events.html

.. _`boolean`: ../type/lua/boolean.html
.. _`UI Element`: ../type/tes3ui/element.html
