
Element
========================================================

A UI element, the main building block of the UI system. Elements can have custom data attached using their `Property`_ key-value store. Has many accessible layout features.


Properties
----------------------------------------------------------------------------------------------------

**id** (`UI_ID`_, read-only)
    The element's ID.  The element can be later accessed by ``ancestor:findChild(id)``. Note that multiple elements may have the same ID, such as subparts of a widget, or list items. Therefore you may see this as an element class identifier.

**name** (`string`_, read-only)
    The element's name, taken from the name registered for the ID.

**parent** (`Element`_, read-only)
    A reference to the parent `Element`_.

**children** (`Element`_ array, read-only)
    A table containing references to children `Element`_ s. This is a copy that does not track changes.

**widget** (`table`_)
    Access to custom properties specific to a widget. These properties are documented in the widget ``create\*`` function descriptions.

**visible** (`boolean`_)
    If the element is visible.

**disabled** (`boolean`_)
    Disables user actions on this element. May change text colour to communicate the disabled state.

**positionX** (`number`_, integer)
    ..

**positionY** (`number`_, integer)
    Element position. 0, 0 is the centre of the screen.

**alignX** (`number`_, float)
    ..

**alignY** (`number`_, float)
    Sets alignment of the element inside its parent. 0.0 = left edge touches left edge of parent, 0.5 = centred, 1.0 = right edge touches right edge of parent.

**layoutOriginFractionX** (`number`_, float)
    ..

**layoutOriginFractionY** (`number`_, float)
    Sets element position to a point relative to the parent element. 0.0 = left content edge, 1.0 = right content edge.

**width** (`number`_, integer)
    ..

**height** (`number`_, integer)
    Element dimensions in pixels.

**minWidth** (`number`_, integer)
    ..

**minHeight** (`number`_, integer)
    Minimum dimensions for auto-size layout and resizeable frames.

**maxWidth** (`number`_, integer)
    ..

**maxHeight** (`number`_, integer)
    Maximum dimensions for auto-size layout and resizeable frames.

**autoWidth** (`boolean`_)
    ..

**autoHeight** (`boolean`_)
    When ``true``, automatically expands element dimensions to fit child elements. Dimensions are restricted by minWidth, minHeight, maxWidth and maxHeight properties.

**layoutWidthFraction** (`number`_, float)
    ..

**layoutHeightFraction** (`number`_, float)
    Sets element dimensions using a proportional sizer. The sizer starts with the parent dimension in the flow direction, subtracts any fixed dimension children leaving the proptional sizer space. Each proportionally sized element then gets an equal division of the space, multiplied by this member.
    
    Overrides fixed, minimum and maximum sizes unless this value is -1.0 (default).

**color** (`table`_, float[3])
    Element RGB colour, an array of 3 floats with value range [0.0, 1.0]. For menus and rects, it sets the background colour. For text, it sets the text colour. For images, it multiplies the image by the colour.

**alpha** (`number`_, float)
    Element alpha colour, using range [0.0, 1.0]. Used to composite elements. If you wish to hide an element completely, use ``disable`` instead.
    
**borderAllSides** (`number`_, integer)
    ..

**borderLeft** (`number`_, integer)
    ..

**borderRight** (`number`_, integer)
    ..

**borderBottom** (`number`_, integer)
    ..

**borderTop** (`number`_, integer)
    Border size in pixels. Border is the blank space around an element. Individual border sizes default to -1, making it use the borderAllSides setting.

**paddingAllSides** (`number`_, integer)
    ..

**paddingLeft** (`number`_, integer)
    ..

**paddingRight** (`number`_, integer)
    ..

**paddingBottom** (`number`_, integer)
    ..

**paddingTop** (`number`_, integer)
    Padding size in pixels. Padding is the blank space between the edge of an element and its contents. Individual padding sizes default to -1, making it use the paddingAllSides setting.

**childOffsetX** (`number`_, integer)
    ..

**childOffsetY** (`number`_, integer)
    Offset applied to child nodes. Used in scrollpanes.

**flowDirection** (`string`_)
    Can have values ``"left_to_right"`` or ``"top_to_bottom"``. Indicates which direction child elements are laid out.

**text** (`string`_)
    The element's text. Text input can be read by accessing this property.

**repeatKeys** (`boolean`_)
    Controls if there is repeating text input when keys are held down. ``true`` by default.

**wrapText** (`boolean`_)
    Controls text wrapping. Setting this to ``true`` will also set ``layoutHeightFraction`` to ``1.0``, which is required for wrapping text to adjust to its container size.

**justifyText** (`string`_)
    Can have values ``"left"``, ``"center"``, or ``"right"``. Controls text justification.

**font** (`number`_, integer)
    Index of font to use for text.
        0 - Magic Cards (default)
        1 - Century Sans
        2 - Daedric

**scaleMode** (`boolean`_)
    Controls if images and NIFs are scaled to fit the element dimensions.

**imageScaleX** (`number`_, float)
    ..

**imageScaleY** (`number`_, float)
    Image scaling multipliers. Only applies to Image elements.

**nodeMinX** (`number`_, integer)
    ..

**nodeMaxX** (`number`_, integer)
    ..

**nodeMinY** (`number`_, integer)
    ..

**nodeMaxY** (`number`_, integer)
    Unknown. May be scenegraph node related.

**nodeOffsetX** (`number`_, integer)
    ..

**nodeOffsetY** (`number`_, integer)
    Unknown. May be scenegraph node related.


Methods
----------------------------------------------------------------------------------------------------

`Element`_ **createBlock** {id = `UI_ID`_ ``optional``}  ``Uses table arguments.``
    Returns:
        The newly created block element.

    Creates an empty block container. Used to group and layout elements.
    
`Element`_ **createButton** {id = `UI_ID`_ ``optional``}  ``Uses table arguments.``
    Returns:
        The newly created button.

    Creates a clickable button. Register the "mouseClick" event to capture a button press.
    
    Custom widget properties:
        | `number`_ ``element.state``: Interaction state. 1 = normal, 2 = disabled, 4 = active. Controls which colour set to use for text.
        | `table`_ (float[3]) ``element.widget.idle``: Text colour for normal state, no mouse interaction.
        | `table`_ (float[3]) ``element.widget.over``: Text colour for normal state, on mouseOver.
        | `table`_ (float[3]) ``element.widget.pressed``: Text colour for normal state, on mouseDown.
        | `table`_ (float[3]) ``element.widget.idleDisabled``: Text colour for disabled state, no mouse interaction.
        | `table`_ (float[3]) ``element.widget.overDisabled``: Text colour for disabled state, on mouseOver.
        | `table`_ (float[3]) ``element.widget.pressedDisabled``: Text colour for disabled state, on mouseDown.
        | `table`_ (float[3]) ``element.widget.idleActive``: Text colour for active state, no mouse interaction.
        | `table`_ (float[3]) ``element.widget.overActive``: Text colour for active state, on mouseOver.
        | `table`_ (float[3]) ``element.widget.pressedActive``: Text colour for active state, on mouseDown.

`Element`_ **createImageButton** {id = `UI_ID`_ ``optional``, idle = `string`_, over = `string`_, pressed = `string`_}  ``Uses table arguments.``
    Returns:
        A **block** with responsive images.

    Creates a clickable button composed of images for the **idle**, **over** and **pressed** states. The texture must have power-of-2 dimensions (i.e. 16, 32, 64, 128, 256, 512, 1024); the final display size can be trimmed by setting width and height. Each image path is relative to ``Data Files``.

`Element`_ **createDivider** {id = `UI_ID`_ ``optional``}  ``Uses table arguments.``
    Returns:
        A full-width divider element.

    Creates a textured horizontal divider line, as used in the magic and stat menus. Scales automatically to the container width.

`Element`_ **createFillBar** {id = `UI_ID`_ ``optional``, current = `number`_ ``integer, optional``, max = `number`_ ``integer, optional``}  ``Uses table arguments.``
    Returns:
        The newly created fillbar.

    Creates a horizontal quantity indicator bar.

    Custom widget properties:
        | `number`_ (integer) ``element.widget.current``: Current (filled) value.
        | `number`_ (integer) ``element.widget.max``: Maximum value.
        | `boolean`_ ``element.widget.showText``: If text of the format "current/max" is shown. Default is ``true``.
        | `table`_ (float[3]) ``element.widget.fillColor``: Colour of filled area.
        | `number`_ (float) ``element.widget.fillAlpha``: Alpha transparency of filled area.

`Element`_ **createHorizontalScrollPane** {id = `UI_ID`_ ``optional``}  ``Uses table arguments.``
    Returns:
        The newly created scroll pane.

    Creates a horizontally scrolling pane.
    To be documented.

`Element`_ **createHypertext** {id = `UI_ID`_ ``optional``}  ``Uses table arguments.``
    Returns:
        The newly created hypertext element.

    Creates a text area with clickable words as links.
    To be documented.

`Element`_ **createImage** {id = `UI_ID`_ ``optional``, path = `string`_}  ``Uses table arguments.``
    Returns:
        The newly created image element.

    Creates an image element from a texture file. The texture must have power-of-2 dimensions (i.e. 16, 32, 64, 128, 256, 512, 1024); the final display size can be trimmed by setting width and height. The path is relative to ``Data Files``.

`Element`_ **createLabel** {id = `UI_ID`_ ``optional``, text = `string`_}  ``Uses table arguments.``
    Returns:
        The newly created text label element.

    Creates a text label. It defaults to displaying all text on a single line. To get a multi-line label, set ``wrap_text`` to ``true``. The element is created with ``autoWidth`` and ``autoHeight`` turned on.

`Element`_ **createNif** {id = `UI_ID`_ ``optional``, path = `string`_}  ``Uses table arguments.``
    Returns:
        The newly created NIF element.

    Creates a NIF model from a file. The path is relative to ``Data Files``.
    To be documented.

`Element`_ **createParagraphInput** {id = `UI_ID`_ ``optional``}  ``Uses table arguments.``
    Returns:
        The newly created paragraph input element.

    Creates a multi-line text input element.
    To be documented.

`Element`_ **createRect** {id = `UI_ID`_ ``optional``, color = `table`_ ``float[3]``}  ``Uses table arguments.``
    Returns:
        The newly created rect element.

    Creates a filled rect. The rect is displayed as filled with the element's colour. It supports alpha compositing.
    
`Element`_ **createSlider** {id = `UI_ID`_ ``optional``, current = `number`_ ``integer``, max = `number`_ ``integer``, step = `number`_ ``integer, optional``, jump = `number`_ ``integer, optional``}  ``Uses table arguments.``
    Returns:
        The newly created slider.

    Creates a horizontal slider. ``current`` is the initial value, ``max`` is the maximum value, ``step`` is the amount changed by the arrow buttons (default = 1), ``jump`` is the amount changed by clicking inside the slider area (default = 5).

    Custom widget properties:
        | `number`_ (integer) ``element.widget.current``: Current value.
        | `number`_ (integer) ``element.widget.max``: Maximum value.
        | `number`_ (integer) ``element.widget.step``: Amount changed by left and right arrow buttons.
        | `number`_ (integer) ``element.widget.jump``: Amount changed by clicking inside the slider area.

    Custom events used with register:
        | ``"PartScrollBar_changed"``: Triggers on value change; moving the slider is not enough if the value is the same.

`Element`_ **createSliderVertical** {id = `UI_ID`_ ``optional``, current = `number`_ ``integer``, max = `number`_ ``integer``, step = `number`_ ``integer, optional``, jump = `number`_ ``integer, optional``}  ``Uses table arguments.``
    Returns:
        The newly created slider.

    Creates a vertical slider.

    Custom widget properties:
        | `number`_ (integer) ``element.widget.current``: Current value.
        | `number`_ (integer) ``element.widget.max``: Maximum value.
        | `number`_ (integer) ``element.widget.step``: Amount changed by up and down arrow buttons.
        | `number`_ (integer) ``element.widget.jump``: Amount changed by clicking inside the slider area.

    Custom events used with register:
        | ``"PartScrollBar_changed"``: Triggers on value change; moving the slider is not enough if the value is the same.

`Element`_ **createTextInput** {id = `UI_ID`_ ``optional``}  ``Uses table arguments.``
    Returns:
        The newly created text input element.

    Creates a single line text input element. To receive input the keyboard must be captured with ``tes3ui.acquireTextInput(element)``. Read the input with the ``text`` property.

    Custom widget properties:
        | `boolean`_ ``element.widget.eraseOnFirstKey``: Clears the initial value if the first keypress is not an edit action. Default is ``true``.
        | `number`_ (integer) ``element.widget.lengthLimit"``: Maximum input length, or ``nil`` for no limit. If you are setting names, the engine limits most identifiers to 31 characters. Default is ``nil``.

`Element`_ **createTextSelect** {id = `UI_ID`_ ``optional``, text = `string`_ ``optional``, state = `number`_ ``optional``}  ``Uses table arguments.``
    Returns:
        The newly created text select element.

    Creates a selectable line of text, with configurable hover, click, and disabled colours. Can be used to create a list box by placing them in a ScrollPane. ``state`` sets the initial interaction state, documented below.

    Custom widget properties:
        | `number`_ ``element.state``: Interaction state. 1 = normal, 2 = disabled, 4 = active. Controls which colour set to use.
        | `table`_ (float[3]) ``element.widget.idle``: Colour for normal state, no mouse interaction.
        | `table`_ (float[3]) ``element.widget.over``: Colour for normal state, on mouseOver.
        | `table`_ (float[3]) ``element.widget.pressed``: Colour for normal state, on mouseDown.
        | `table`_ (float[3]) ``element.widget.idleDisabled``: Colour for disabled state, no mouse interaction.
        | `table`_ (float[3]) ``element.widget.overDisabled``: Colour for disabled state, on mouseOver.
        | `table`_ (float[3]) ``element.widget.pressedDisabled``: Colour for disabled state, on mouseDown.
        | `table`_ (float[3]) ``element.widget.idleActive``: Colour for active state, no mouse interaction.
        | `table`_ (float[3]) ``element.widget.overActive``: Colour for active state, on mouseOver.
        | `table`_ (float[3]) ``element.widget.pressedActive``: Colour for active state, on mouseDown.

`Element`_ **createThinBorder** {id = `UI_ID`_ ``optional``}  ``Uses table arguments.``
    Returns:
        The newly created container element with a border.

    Creates a styled thin border. Any content should be created as children of this border.

`Element`_ **createVerticalScrollPane** {id = `UI_ID`_ ``optional``}  ``Uses table arguments.``
    Returns:
        The newly created scroll pane.

    Creates a vertically scrolling pane.
    To be documented.

**destroy** ()
    Returns:
        none

    Deletes an element and all its child elements. If any element is bound to text input by `tes3ui.acquireTextInput`_, the input is automatically released.

**destroyChildren** ()
    Returns:
        none

    Deletes all the child elements of this element. If any element is bound to text input by `tes3ui.acquireTextInput`_, the input is automatically released.

`Element`_ **findChild** (`UI_ID`_ id)
    Returns:
        The first child element with a matching id, or ``nil`` if no match found.

    Finds a child element matching the ``id`` argument. Searches children recursively.

**forwardEvent** (`EventData`_ e)
    Returns:
        none
    
    Forwards an event to the original Morrowind event handler. This may be optionally called at any point in a callback. Note that handler may or may not destroy the event widget or the menu, so you should know how it behaves before accessing any elements after a callback. 
    
`Element`_ **getContentElement** ()
    Returns:
        The descendant element that newly created elements are placed into, or the calling element if there is no specific descendant for children.

    Some widgets like ScrollPanes are built of multiple layers of elements. When an element is created in a complex widget, it is automatically placed as a child of a content element, but other functions do not access this content element directly. This function finds this content container for any element, so that changing layout and accessing children is possible. For simple elements, the calling element will be returned so that there is always a valid containter element.

`Element`_ **getTopLevelMenu** ()
    Returns:
        The menu that the element is a descendant of.

    Finds the parent menu containing the element.

`boolean`_ **getPropertyBool** (`Property`_ prop)
    ..

`number`_ **getPropertyFloat** (`Property`_ prop)
    ..

`number`_ **getPropertyInt** (`Property`_ prop)
    Returns:
        The property value, or ``0`` / ``false`` if the property key did not have data.

    Gets a property value with ``prop`` as the property key. Useful for element class-specific properties.

**register** (`string`_ eventID, `function`_ callback)
    Returns:
        none

    Sets an `event`_ handler. Can be a standard `event`_ name, or an event specific to an element class. The callback receives an argument with the event data. Read the `event` page for event names and the callback signature.
    
    The original Morrowind callback is captured and can be invoked with the ``forwardEvent`` method. If there is an existing Lua callback, it is replaced.

`boolean`_ **reorderChildren** (`Element`_ ``or`` `number`_ insertBefore, `Element`_ ``or`` `number`_ moveFrom, `number`_ count)
    Returns:
        ``true`` if the operation succeeded, or ``false`` if at least one argument was invalid.
    
    Moves the layout order of the children of this element. ``count`` elements are taken from starting child `Element`_ or index (0-based) ``moveFrom``, and moved before the child `Element`_ or index (0-based) ``insertBefore``. If ``count`` is -1, all children after ``moveFrom`` are moved. If any index is a negative number, then the index represents a distance from the end of the child list. 
    
    e.g. ``reorderChildren(0, -3, 3)`` causes the last 3 children to be moved to the start of the order (before index 0).

**setPropertyBool** (`Property`_ prop, `boolean`_ value)
    ..

**setPropertyFloat** (`Property`_ prop, `number`_ value)
    ..

**setPropertyInt** (`Property`_ prop, `number`_ value)
    Returns:
        none

    Sets a property value with ``prop`` as the property key. Useful for element class-specific properties.
    
**triggerEvent** (`EventData`_ e)
    ..
    
**triggerEvent** (`string`_ eventName)
    Returns:
        none
    
    Triggers an event on an element, either using supplied event data, or by constructing new event data using ``eventName``. ``eventName`` is the same as used in ``register``.
    
**unregister** (`string`_ eventID)
    Returns:
        none

    Unregisters an `event`_ handler.

**updateLayout** ()
    Returns:
        none

    Updates an element layout and all child elements. Needs to be called when elements are added, moved or resized.


.. _`boolean`: ../lua/boolean.html
.. _`function`: ../lua/function.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html

.. _`Element`: element.html
.. _`event`: events.html
.. _`EventData`: events.html
.. _`Property`: property.html
.. _`UI_ID`: ui_id.html

.. _`tes3ui.acquireTextInput`: ../../api/tes3ui/acquireTextInput.html