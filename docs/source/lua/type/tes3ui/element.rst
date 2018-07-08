
Element
========================================================

A UI element. The main building block of the UI system. Has many accessible layout features.


Properties
----------------------------------------------------------------------------------------------------

**id** (`UI_ID`_, read-only)
    The element's ID.

**name** (`string`_, read-only)
    The element's name, taken from the name registered for the ID.

**parent** (`Element`_, read-only)
    A reference to the parent `Element`_.

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
    Sets alignment of element inside its parent. 0.0 = left edge touches left edge of parent, 0.5 = centred, 1.0 = right edge touches right edge of parent.

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
    Sets element dimensions to a multiplier of parent element dimensions. 1.0 = equal dimension to parent.

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
    Controls text wrapping.

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

**createBlock** {id=`UI_ID`_ [optional]}  ``Uses table arguments.``
    Creates an empty block container. Used to group and layout elements.

**createButton** {id=`UI_ID`_ [optional]}  ``Uses table arguments.``
    Creates a clickable button. Register the "mouseClick" event to capture a button press.

**createFillBar** {id=`UI_ID`_ [optional]}  ``Uses table arguments.``
    Creates a horizontal quantity indicator bar.

    Custom properties used with setProperty:
        bool ``"Part_Fillbar_show_text"`` - If text of the format "current/max" is shown.
        float ``"Part_Fillbar_current"`` - Current (filled) value.
        float ``"Part_Fillbar_max"`` - Maximum value.
        float ``"Part_Fillbar_red"`` - Colour of filled area.
        float ``"Part_Fillbar_green"``
        float ``"Part_Fillbar_blue"``
        float ``"Part_Fillbar_alpha"``

**createHorizontalScrollPane** {id=`UI_ID`_ [optional]}  ``Uses table arguments.``
    Creates a horizontally scrolling pane.
    To be documented.

**createHypertext** {id=`UI_ID`_ [optional]}  ``Uses table arguments.``
    Creates a text area with clickable words as links.
    To be documented.

**createImage** {id=`UI_ID`_ [optional], path=`string`_}  ``Uses table arguments.``
    Creates an image element from a texture file. The path is relative to ``Data Files``.
    To be documented.

**createLabel** {id=`UI_ID`_ [optional], text=`string`_}  ``Uses table arguments.``
    Creates a single line text label.

**createNif** {id=`UI_ID`_ [optional], path=`string`_}  ``Uses table arguments.``
    Creates a NIF model from a file. The path is relative to ``Data Files``.
    To be documented.

**createParagraphInput** {id=`UI_ID`_ [optional]}  ``Uses table arguments.``
    Creates a multi-line text input element.
    To be documented.

**createSlider** {id=`UI_ID`_ [optional]}  ``Uses table arguments.``
    Creates a horizontal slider.

    Custom properties used with setProperty:
        int ``"Part_ScrollBar_step_x"`` - Amount changed by left and right arrow buttons.
        int ``"Part_ScrollBar_jump_x"`` - Amount changed by clicking inside the slider area.
        int ``"Part_ScrollBar_current"`` - Current value.
        int ``"Part_ScrollBar_max"`` - Max value.

    Custom events used with register:
        ``"Part_ScrollBar_changed"`` - Triggers on value change.

**createSliderVertical** {id=`UI_ID`_ [optional]}  ``Uses table arguments.``
    Creates a vertical slider.

    Custom properties used with setProperty:
        int ``"Part_ScrollBar_step_x"`` - Amount changed by up and down arrow buttons.
        int ``"Part_ScrollBar_jump_x"`` - Amount changed by clicking inside the slider area.
        int ``"Part_ScrollBar_current"`` - Current value.
        int ``"Part_ScrollBar_max"`` - Max value.

    Custom events used with register:
        ``"Part_ScrollBar_changed"`` - Triggers on value change.

**createTextInput** {id=`UI_ID`_ [optional]}  ``Uses table arguments.``
    Creates a single line text input element. Read the input with the ``text`` property.

    Custom properties used with setProperty:
        bool ``"Part_TextInput_erase_on_first_key"`` - Clears the initial value if the first keypress is not an edit action.
        bool ``"Part_TextInput_no_limit"`` - Set if no length limit is enforced.
        int ``"Part_TextInput_length_limit"`` - Maximum input length. The engine limits most identifiers to 31 characters.

**createTextSelect** {id=`UI_ID`_ [optional]}  ``Uses table arguments.``
    Creates a selectable line of text, with configurable hover, click, and disabled colours. Can be used to create a list box by placing them in a ScrollPane.

    To be documented.

**createThinBorder** {id=`UI_ID`_ [optional]}  ``Uses table arguments.``
    Creates a styled thin border. Any content should be created as children of this border.

**createVerticalScrollPane** {id=`UI_ID`_ [optional]}  ``Uses table arguments.``
    Creates a vertically scrolling pane.
    To be documented.

**destroy** ()
    Deletes an element and all its child elements. If any element is bound to text input by `tes3ui.acquireTextInput`_, the input is automatically released.

`Element`_ **findChild** (`UI_ID`_ id)
    Finds a child element matching the ``id`` argument. Searches children recursively.

`boolean`_ **getPropertyBool** (`Property`_ prop)

..

`number`_ **getPropertyFloat** (`Property`_ prop)

..

`number`_ **getPropertyInt** (`Property`_ prop)
    Gets a property value with ``prop`` as the property key. Useful for element class-specific properties.

**register** (`string`_ eventID, `function`_ callback)
    Sets an event handler. Can be a standard event name, or an event specific to an element class.

**setPropertyBool** (`Property`_ prop, `boolean`_ value)

..

**setPropertyFloat** (`Property`_ prop, `number`_ value)

..

**setPropertyInt** (`Property`_ prop, `number`_ value)
    Sets a property value with ``prop`` as the property key. Useful for element class-specific properties.
    
**unregister** (`string`_ eventID)
    Unregisters an event handler.

**updateLayout** ()
    Updates an element layout and all child elements. Needs to be called when elements are added or moved.


.. _`boolean`: ../lua/boolean.html
.. _`function`: ../lua/function.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html

.. _`Element`: element.html
.. _`Property`: property.html
.. _`UI_ID`: ui_id.html

.. _`tes3ui.acquireTextInput`: ../../api/tes3ui/acquireTextInput.html