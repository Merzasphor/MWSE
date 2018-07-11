
Element
========================================================

A UI element, the main building block of the UI system. Elements can have custom data attached using their `Property`_ key-value store. Has many accessible layout features.


Properties
----------------------------------------------------------------------------------------------------

**id** (`UI_ID`_, read-only)
    The element's ID.  The element can be later accessed by ``ancestor:findChild(id)``.

**name** (`string`_, read-only)
    The element's name, taken from the name registered for the ID.

**parent** (`Element`_, read-only)
    A reference to the parent `Element`_.

**children** (`Element`_ array, read-only)
    A table containing references to children `Element`_ s. This is a copy that does not track changes.

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

**red** (`number`_, float)
    ..

**green** (`number`_, float)
    ..

**blue** (`number`_, float)
    ..

**alpha** (`number`_, float)
    Element RGBA colour, using range 0.0-1.0. For blocks, it sets the background colour. For text, it sets the text colour.

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
    The setting for repeating text input when keys are held down. ``true`` by default.

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
    
`Element`_ **createImageButton** {id = `UI_ID`_ ``optional``, idle = `string`_, over = `string`_, pressed = `string`_}  ``Uses table arguments.``
    Returns:
        A **block** with responsive images.

    Creates a clickable button composed of images for the **idle**, **over** and **pressed** states. The texture must have power-of-2 dimensions (i.e. 16, 32, 64, 128, 256, 512, 1024); the final display size can be trimmed by setting width and height. Each image path is relative to ``Data Files``.

`Element`_ **createFillBar** {id = `UI_ID`_ ``optional``}  ``Uses table arguments.``
    Returns:
        The newly created fillbar.

    Creates a horizontal quantity indicator bar.

    Custom properties used with setProperty:
        | bool ``"Part_Fillbar_show_text"``: If text of the format "current/max" is shown.
        | float ``"Part_Fillbar_current"``: Current (filled) value.
        | float ``"Part_Fillbar_max"``: Maximum value.
        | float ``"Part_Fillbar_red"``: Colour of filled area.
        | float ``"Part_Fillbar_green"``
        | float ``"Part_Fillbar_blue"``
        | float ``"Part_Fillbar_alpha"``

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

`Element`_ **createSlider** {id = `UI_ID`_ ``optional``}  ``Uses table arguments.``
    Returns:
        The newly created slider.

    Creates a horizontal slider.

    Custom properties used with setProperty:
        | int ``"Part_ScrollBar_step_x"``: Amount changed by left and right arrow buttons.
        | int ``"Part_ScrollBar_jump_x"``: Amount changed by clicking inside the slider area.
        | int ``"Part_ScrollBar_current"``: Current value.
        | int ``"Part_ScrollBar_max"``: Max value.

    Custom events used with register:
        | ``"Part_ScrollBar_changed"``: Triggers on value change.

`Element`_ **createSliderVertical** {id = `UI_ID`_ ``optional``}  ``Uses table arguments.``
    Returns:
        The newly created slider.

    Creates a vertical slider.

    Custom properties used with setProperty:
        | int ``"Part_ScrollBar_step_x"``: Amount changed by up and down arrow buttons.
        | int ``"Part_ScrollBar_jump_x"``: Amount changed by clicking inside the slider area.
        | int ``"Part_ScrollBar_current"``: Current value.
        | int ``"Part_ScrollBar_max"``: Max value.

    Custom events used with register:
        | ``"Part_ScrollBar_changed"``: Triggers on value change.

`Element`_ **createTextInput** {id = `UI_ID`_ ``optional``}  ``Uses table arguments.``
    Returns:
        The newly created text input element.

    Creates a single line text input element. Read the input with the ``text`` property.

    Custom properties used with setProperty:
        | bool ``"Part_TextInput_erase_on_first_key"``: Clears the initial value if the first keypress is not an edit action.
        | bool ``"Part_TextInput_no_limit"``: Set if no length limit is enforced.
        | int ``"Part_TextInput_length_limit"``: Maximum input length. The engine limits most identifiers to 31 characters.

`Element`_ **createTextSelect** {id = `UI_ID`_ ``optional``}  ``Uses table arguments.``
    Returns:
        The newly created x.

    Creates a selectable line of text, with configurable hover, click, and disabled colours. Can be used to create a list box by placing them in a ScrollPane.

    To be documented.

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

.. _`Element`: element.html
.. _`event`: events.html
.. _`Property`: property.html
.. _`UI_ID`: ui_id.html

.. _`tes3ui.acquireTextInput`: ../../api/tes3ui/acquireTextInput.html