
Events
===============================================================================
Lua UI event specification.


Events
-------------------------------------------------------------------------------

Events can be bound to elements via the `Element`_ ``register`` method, which takes an event name. Event names can be one of the standard events listed here, or a widget-specific event.

Standard events:
    **mouseLeave**
        Mouse cursor moving outside an element. Triggers once.
    **mouseOver**
        Mouse cursor moving over an element. Triggers once.
    **mouseDown**
        Left mouse button down over an element.
    **mouseClick**
        Left mouse button up over an element, after a mouseDown over the element.
    **mouseScrollUp**
        ..
    **mouseScrollDown**
        Mouse wheel scrolling.
    **mouseDoubleClick**
        Standard double-click.
    **mouseStillIdle**
        Mouse cursor positioned outside an element. Triggers every frame.
    **mouseStillOver**
        Mouse cursor positioned over an element. Triggers every frame.
    **mouseStillPressed**
        Mouse cursor positioned over an element, after a mouseDown over the element. Triggers every frame.
    **mouseStillPressedOutside**
        Mouse cursor positioned outside an element, after a mouseDown over the element. Triggers every frame.
    **mouseRelease**
        Left mouse button up over an element.
    **keyPress**
        A raw key press.
    **keyEnter**
        The Return key is pressed.
    **help**
        On mouseover, but also marking the element as having a tooltip. Create a tooltip within the callback using the `tes3ui.createTooltipMenu`_ function.
    **focus**
        When a menu is clicked on, and moved on top of other menus.
    **unfocus**
        When another menu is clicked on. Also checked when the inventory menu is toggled.
    **preUpdate**
        Before the menu layout is updated.
    **update**
        After the menu layout is updated.
	**destroy**
        When the UI element is destroyed, before any data or children are destroyed.


**Widget-specific events**
    To be documented.


Event forwarding
-------------------------------------------------------------------------------

The original Morrowind event handler is saved when you first register an event. It may be optionally invoked with the ``forwardEvent`` method.  Note that handler may or may not destroy the event widget or the menu, so you should know how it behaves before accessing any elements after a callback. 

**Example**

.. code-block:: lua

    local function onClick(e)
        -- pre-event code
        e.source:forwardEvent(e)
        -- post-event code
    end
    
    local button = menu:findChild("MenuExample_Ok")
    button:register("mouseClick", onClick)


Event handler
-------------------------------------------------------------------------------

The standard type signature for events.

`boolean`_ eventHandler(**EventData** e)
    Returns: ``optional``
        Returning ``false`` may cancel an interaction for certain events. e.g. unfocus
   
    EventData:
        **source** (`Element`_)
            The source element of the event.
        
        **id** (`number`_)
            The numeric id of the event type.
    
        **widget** (`Element`_)
            The widget element that the source belongs to, if the element is a sub-part of a widget. May not be accurate if the element is not a sub-part.
        
        **data0** (`number`_)
            ..
            
        **data1** (`number`_)
            Event-specific data values. For mouse events, these are the X and Y coordinates of the pointer. For keyboard events, data0 is the scancode.


.. _`boolean`: ../lua/boolean.html
.. _`function`: ../lua/function.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html

.. _`tes3ui.createTooltipMenu`: ../../api/tes3ui/createTooltipMenu.html

.. _`Element`: element.html
.. _`Property`: property.html
.. _`UI_ID`: ui_id.html