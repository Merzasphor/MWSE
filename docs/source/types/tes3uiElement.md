# tes3uiElement

A UI element, the main building block of the UI system. All elements are created with methods on a parent Element.  Elements are very configurable, and have many HTML-like layout features. All layout properties can be set to `nil` to reset them to the default value, which will deactivate any related layout mode.

Elements can have custom data attached using their `Property`_ key-value store, and specific Elements have specific `element.widget` accessors to control behaviour.

## Properties

### `absolutePosAlignX`

Sets element position to a point relative to the parent element. 0.0 = left/top content edge, 1.0 = right/bottom content edge. The positioning is absolute, which frees the element from the standard flow layout and allows overlapping elements.
    
    Bug note: Elements may not respond to widthProportional/heightProportional sizing after either of these properties are set. If you need to use both you should consider testing if it works first.

**Returns**:

* `result` (number)

***

### `absolutePosAlignY`

See absolutePosAlignX.

**Returns**:

* `result` (number)

***

### `alpha`

Element alpha colour, using range [0.0, 1.0]. Used to composite elements. If you wish to hide an element completely, use `disable` instead.

**Returns**:

* `result` (number)

***

### `autoHeight`

When `true`, automatically expands element dimensions to fit child elements. Dimensions are restricted by minWidth, minHeight, maxWidth and maxHeight properties.

**Returns**:

* `result` (boolean)

***

### `autoWidth`

When `true`, automatically expands element dimensions to fit child elements. Dimensions are restricted by minWidth, minHeight, maxWidth and maxHeight properties.

**Returns**:

* `result` (boolean)

***

### `borderAllSides`

Integer number. Border size in pixels. Border is the extra empty space around an element. Individual border sizes default to using the borderAllSides setting.

**Returns**:

* `result` (number)

***

### `borderBottom`

Integer number. Bottom border size in pixels. When this is set to -1, the borderAllSides setting is used for this side instead.

**Returns**:

* `result` (number)

***

### `borderLeft`

Integer number. Left border size in pixels. When this is set to -1, the borderAllSides setting is used for this side instead.

**Returns**:

* `result` (number)

***

### `borderRight`

Integer number. Left border size in pixels. When this is set to -1, the borderAllSides setting is used for this side instead.

**Returns**:

* `result` (number)

***

### `borderTop`

Integer number. Top border size in pixels. When this is set to -1, the borderAllSides setting is used for this side instead.

**Returns**:

* `result` (number)

***

### `childAlignX`

Sets alignment of child elements inside its parent, though it only works in specific conditions. 0.0 = left/top edge touches left/top edge of parent, 0.5 = centred, 1.0 = right/bottom edge touches right/bottom edge of parent. For negative values, there is a special case behaviour: all children but the last will be left-aligned/top-aligned, the last child will be right-aligned/bottom-aligned.
    
    Child alignment only works if the element has proportional sizing (using widthProportional/heightProportional) and all children use non-proportional sizing (widthProportional and heightProportional are nil).

**Returns**:

* `result` (number)

***

### `childAlignY`

See childAlignX.

**Returns**:

* `result` (number)

***

### `childOffsetX`

Integer number. View offset in pixels, applied to the position of child nodes. Used in scroll panes.

**Returns**:

* `result` (number)

***

### `childOffsetY`

See childOffsetX.

**Returns**:

* `result` (number)

***

### `children`

*Read-only*. A table containing references to child elements. This is a copy that does not track changes.

**Returns**:

* `result` (table)

***

### `color`

Element RGB colour, an array of 3 floats with value range [0.0, 1.0]. For menus and rects, it sets the background colour. For text, it sets the text colour. For images, it multiplies the image by the colour.

**Returns**:

* `result` (table)

***

### `consumeMouseEvents`

When `true`, mouse events over this element are sent to event handlers, or discarded if there is no handler. When `false`, mouse events go upwards to the first ancestor that can consume mouse events. Useful to set on widget sub-elements. `true` by default.

**Returns**:

* `result` (boolean)

***

### `disabled`

Disables user actions on this element. Widgets may stop accepting mouse and keyboard input while disabled.

**Returns**:

* `result` (boolean)

***

### `flowDirection`

Can have values `"left_to_right"` or `"top_to_bottom"`. Indicates which direction child elements are laid out.

**Returns**:

* `result` (string)

***

### `font`

Index of font to use for text.
        0 - Magic Cards (default)
        1 - Century Sans
        2 - Daedric

**Returns**:

* `result` (number)

***

### `height`

Element dimensions in pixels. Integer number.

**Returns**:

* `result` (number)

***

### `heightProportional`

Sets element dimensions using a proportional sizer. The sizer starts with the parent dimension in the flow direction, subtracts any fixed dimension children leaving the proportional sizer space. Each proportionally sized element then gets an equal division of the space, multiplied by this member. Values above 1.0 are permissible.
    
    Bug note: If widthProportional is used without heightProportional, an element may not respond to changes in parent size. It is recommended to set heightProportional, or have a fixed size sibling element if dynamic reflow is required.
    
    Overrides fixed, minimum and maximum sizes unless this value is `nil` (default).

**Returns**:

* `result` (boolean)

***

### `id`

*Read-only*. The element's ID.  The element can be later accessed by `ancestor:findChild(id)`. Note that multiple elements may have the same ID, such as subparts of a widget, or list items. Therefore, you may think of ids as an element class identifier.

**Returns**:

* `result` (number)

***

### `imageScaleX`

Image scaling multipliers. Only applies to image elements.

**Returns**:

* `result` (number)

***

### `imageScaleY`

Image scaling multipliers. Only applies to image elements.

**Returns**:

* `result` (number)

***

### `justifyText`

Can have values `"left"`, `"center"`, or `"right"`. Controls text justification. To work correctly for center/right justification,  `wrapText` must be `true`.

**Returns**:

* `result` (string)

***

### `maxHeight`

Maximum dimensions for auto-size layout and resizable frames. Integer number.

**Returns**:

* `result` (number)

***

### `maxWidth`

Maximum dimensions for auto-size layout and resizable frames. Integer number.

**Returns**:

* `result` (number)

***

### `minHeight`

Minimum dimensions for auto-size layout and resizable frames. Integer number.

**Returns**:

* `result` (number)

***

### `minWidth`

Minimum dimensions for auto-size layout and resizable frames. Integer number.

**Returns**:

* `result` (number)

***

### `name`

*Read-only*. The element's name, taken from the name registered for the ID.

**Returns**:

* `result` (string)

***

### `paddingAllSides`

Integer number. Padding size in pixels. Padding is the blank space between the edge of an element and its contents. Individual padding sizes default to -1, making it use the paddingAllSides setting.

**Returns**:

* `result` (number)

***

### `paddingBottom`

Integer number. Bottom padding size in pixels. When this is set to -1, the paddingAllSides setting is used for this side instead.

**Returns**:

* `result` (number)

***

### `paddingLeft`

Integer number. Left padding size in pixels. When this is set to -1, the paddingAllSides setting is used for this side instead.

**Returns**:

* `result` (number)

***

### `paddingRight`

Integer number. Right padding size in pixels. When this is set to -1, the paddingAllSides setting is used for this side instead.

**Returns**:

* `result` (number)

***

### `paddingTop`

Integer number. Top padding size in pixels. When this is set to -1, the paddingAllSides setting is used for this side instead.

**Returns**:

* `result` (number)

***

### `parent`

*Read-only*. A reference to the parent element.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `positionX`

Integer number. Element X position relative to its parent's top-left content area. For top-level menus there is a difference: (0, 0) is the centre of the screen.

**Returns**:

* `result` (number)

***

### `positionY`

Integer number. Element Y position relative to its parent's top-left content area. For top-level menus there is a difference: (0, 0) is the centre of the screen.

**Returns**:

* `result` (number)

***

### `rawText`

The raw value of the element's text. This, unlike the normal text property, will not directly read widget information or handle the removal of the positional cursor.

**Returns**:

* `result` (string)

***

### `repeatKeys`

Controls if there is repeating text input when keys are held down. `true` by default.

**Returns**:

* `result` (boolean)

***

### `scaleMode`

When set to `true` on image and NIF elements, they are scaled to fit `width` and `height`.

**Returns**:

* `result` (boolean)

***

### `text`

The element's text. Text input can be read by accessing this property.

**Returns**:

* `result` (string)

***

### `visible`

Controls if the element is visible.

**Returns**:

* `result` (boolean)

***

### `widget`

Access to custom properties specific to a widget. These properties are documented in the widget create* function descriptions.

**Returns**:

* `result` (table)

***

### `width`

Element dimensions in pixels. Integer number.

**Returns**:

* `result` (number)

***

### `widthProportional`

Sets element dimensions using a proportional sizer. The sizer starts with the parent dimension in the flow direction, subtracts any fixed dimension children leaving the proportional sizer space. Each proportionally sized element then gets an equal division of the space, multiplied by this member. Values above 1.0 are permissible.
    
    Bug note: If widthProportional is used without heightProportional, an element may not respond to changes in parent size. It is recommended to set heightProportional, or have a fixed size sibling element if dynamic reflow is required.
    
    Overrides fixed, minimum and maximum sizes unless this value is `nil` (default).

**Returns**:

* `result` (boolean)

***

### `wrapText`

Controls text wrapping. Setting this to `true` will also set `layoutHeightFraction` to `1.0`, which is required for wrapping text to adjust to its container size.

**Returns**:

* `result` (boolean)

***

## Methods

### `createBlock`

Creates an empty block container inside the element. Used to group and layout elements.

```lua
local result = tes3uiElement:createBlock(id)
```

**Parameters**:

* `id` (number): *Optional*. A registered identifier to help find this element later.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `createButton`

Creates a clickable button. Register the "mouseClick" event to capture a button press.
    
    Custom widget properties:
        | `number`_ `element.widget.state`: Interaction state. 1 = normal, 2 = disabled, 4 = active. Controls which colour set to use for text.
        | `table`_ (float[3]) `element.widget.idle`: Text colour for normal state, no mouse interaction.
        | `table`_ (float[3]) `element.widget.over`: Text colour for normal state, on mouseOver.
        | `table`_ (float[3]) `element.widget.pressed`: Text colour for normal state, on mouseDown.
        | `table`_ (float[3]) `element.widget.idleDisabled`: Text colour for disabled state, no mouse interaction.
        | `table`_ (float[3]) `element.widget.overDisabled`: Text colour for disabled state, on mouseOver.
        | `table`_ (float[3]) `element.widget.pressedDisabled`: Text colour for disabled state, on mouseDown.
        | `table`_ (float[3]) `element.widget.idleActive`: Text colour for active state, no mouse interaction.
        | `table`_ (float[3]) `element.widget.overActive`: Text colour for active state, on mouseOver.
        | `table`_ (float[3]) `element.widget.pressedActive`: Text colour for active state, on mouseDown.

```lua
local result = tes3uiElement:createButton(id)
```

**Parameters**:

* `id` (number): *Optional*. A registered identifier to help find this element later.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `createDivider`

Creates a textured horizontal divider line, as used in the magic and stat menus. Scales automatically to the container width.

```lua
local result = tes3uiElement:createDivider(id)
```

**Parameters**:

* `id` (number): *Optional*. A registered identifier to help find this element later.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `createFillBar`

Creates a horizontal quantity indicator bar.

    Custom widget properties:
        | `number`_ (integer) `element.widget.current`: Current (filled) value.
        | `number`_ (integer) `element.widget.max`: Maximum value.
        | `boolean`_ `element.widget.showText`: If text of the format "current/max" is shown. Default is `true`.
        | `table`_ (float[3]) `element.widget.fillColor`: Colour of filled area.
        | `number`_ (float) `element.widget.fillAlpha`: Alpha transparency of filled area.

```lua
local result = tes3uiElement:createFillBar(id, current, max)
```

**Parameters**:

* `id` (number): *Optional*. A registered identifier to help find this element later.
* `current` (number): *Optional*. The initial current value.
* `max` (number): *Optional*. The initial maximum value.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `createHorizontalScrollPane`

Creates a horizontally scrolling pane.

    Custom widget properties:
        | `number`_ `element.widget.positionX`: Horizontal scroll offset in pixels.
        | `boolean`_ `element.widget.scrollbarVisible`: Set if the scrollbar is displayed.

    Custom widget methods:
        | `element.widget:contentsChanged()`: Call to update scroll bar slider and limits after adding or removing elements to the content container. Because content size depends on layout, this must be run after a menu:updateLayout(). Only required if the content size changes.

```lua
local result = tes3uiElement:createHorizontalScrollPane(id)
```

**Parameters**:

* `id` (number): *Optional*. A registered identifier to help find this element later.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `createHypertext`

Creates a text area with clickable words as links. Usage is still under research.

```lua
local result = tes3uiElement:createHypertext(id)
```

**Parameters**:

* `id` (number): *Optional*. A registered identifier to help find this element later.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `createImage`

Creates an image element from a texture file. The texture must have power-of-2 dimensions (i.e. 16, 32, 64, 128, 256, 512, 1024); the final display size can be trimmed by setting width and height.

```lua
local result = tes3uiElement:createImage(id, path)
```

**Parameters**:

* `id` (number): *Optional*. A registered identifier to help find this element later.
* `path` (string): An image path. This path is relative to `Data Files`.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `createImageButton`

Creates an interactive button composed of images for the **idle**, **over**, and **pressed** states. The texture must have power-of-2 dimensions (i.e. 16, 32, 64, 128, 256, 512, 1024); the final display size can be trimmed by setting width and height.

```lua
local result = tes3uiElement:createImageButton(id, idle, over, path)
```

**Parameters**:

* `id` (number): *Optional*. A registered identifier to help find this element later.
* `idle` (string): The path to the idle image. This path is relative to `Data Files`.
* `over` (string): The path to the mouse hover image. This path is relative to `Data Files`.
* `path` (string): The path to the mouse pressed image. This path is relative to `Data Files`.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `createLabel`

Creates a text label. It defaults to displaying all text on a single line. To get a multi-line label, set `wrap_text` to `true`. The element is created with `autoWidth` and `autoHeight` turned on.

```lua
local result = tes3uiElement:createLabel(id, text)
```

**Parameters**:

* `id` (number): *Optional*. A registered identifier to help find this element later.
* `text` (string): The text to display.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `createNif`

Creates a NIF model from a file. Still under research.

```lua
local result = tes3uiElement:createNif(id, text)
```

**Parameters**:

* `id` (number): *Optional*. A registered identifier to help find this element later.
* `text` (string): A model path. This path is relative to `Data Files`.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `createParagraphInput`

Creates a multi-line text input element, with line wrapping on. To receive input the keyboard must be captured with `tes3ui.acquireTextInput(element)`. Read the input with the `text` property. Write an initial value to edit by setting the `text` property.

    Custom widget properties:
        | `number`_ (integer) `element.widget.lengthLimit`: Maximum input length. Default is `1023`.

```lua
local result = tes3uiElement:createParagraphInput(id)
```

**Parameters**:

* `id` (number): *Optional*. A registered identifier to help find this element later.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `createRect`

Creates a filled rectangle. The rectangle is displayed as filled with the element's colour. It supports alpha compositing.

```lua
local result = tes3uiElement:createRect(id, color)
```

**Parameters**:

* `id` (number): *Optional*. A registered identifier to help find this element later.
* `color` (table): *Optional*. The fill colour for the element.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `createSlider`

Creates a horizontal slider.

    Custom widget properties:
        | `number`_ (integer) `element.widget.current`: Current value.
        | `number`_ (integer) `element.widget.max`: Maximum value.
        | `number`_ (integer) `element.widget.step`: Amount changed by left and right arrow buttons.
        | `number`_ (integer) `element.widget.jump`: Amount changed by clicking inside the slider area.

    Custom events used with register:
        | `"PartScrollBar_changed"`: Triggers on value change; moving the slider is not enough if the value is the same.

```lua
local result = tes3uiElement:createSlider(id, current, max, step, jump)
```

**Parameters**:

* `id` (number): *Optional*. A registered identifier to help find this element later.
* `current` (number): The initial value for the slider.
* `max` (number): The maximum value for the slider.
* `step` (number): *Optional*. Amount changed by left and right arrow buttons.
* `jump` (number): *Optional*. Amount changed by clicking inside the slider area.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `createSliderVertical`

Creates a vertical slider.

    Custom widget properties:
        | `number`_ (integer) `element.widget.current`: Current value.
        | `number`_ (integer) `element.widget.max`: Maximum value.
        | `number`_ (integer) `element.widget.step`: Amount changed by up and down arrow buttons.
        | `number`_ (integer) `element.widget.jump`: Amount changed by clicking inside the slider area.

    Custom events used with register:
        | `"PartScrollBar_changed"`: Triggers on value change; moving the slider is not enough if the value is the same.

```lua
local result = tes3uiElement:createSliderVertical(id, current, max, step, jump)
```

**Parameters**:

* `id` (number): *Optional*. A registered identifier to help find this element later.
* `current` (number): The initial value for the slider.
* `max` (number): The maximum value for the slider.
* `step` (number): *Optional*. Amount changed by left and right arrow buttons. The default is 1.
* `jump` (number): *Optional*. Amount changed by clicking inside the slider area. The default is 5.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `createTextInput`

Creates a single line text input element. To receive input the keyboard must be captured with `tes3ui.acquireTextInput(element)`. Read the input with the `text` property. Write an initial value to display by setting the `text` property; that value will be cleared on the first keypress.

    Custom widget properties:
        | `boolean`_ `element.widget.eraseOnFirstKey`: Clears the initial value if the first keypress is not an edit action. Default is `true`.
        | `number`_ (integer) `element.widget.lengthLimit"`: Maximum input length, or `nil` for no limit. If you are setting names, the engine limits most identifiers to 31 characters. Default is `nil`.

```lua
local result = tes3uiElement:createTextInput(id)
```

**Parameters**:

* `id` (number): *Optional*. A registered identifier to help find this element later.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `createTextSelect`

Creates a selectable line of text, with configurable hover, click, and disabled colours. Can be used to create a list box by placing them in a ScrollPane. `state` sets the initial interaction state.

```lua
local result = tes3uiElement:createTextSelect(id, text, state)
```

**Parameters**:

* `id` (number): *Optional*. A registered identifier to help find this element later.
* `text` (string): *Optional*. The text to display.
* `state` (number): *Optional*. The initial interaction state. Defaults to normal.

**Returns**:

* `result` (tes3uiWidgetTextSelect)

***

### `createThinBorder`

Creates a styled thin border element. Any content should be created as children of this border.

```lua
local result = tes3uiElement:createThinBorder(id)
```

**Parameters**:

* `id` (number): *Optional*. A registered identifier to help find this element later.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `createVerticalScrollPane`

Creates a vertically scrolling pane. Useful as a list box.

    Custom widget properties:
        | `number`_ `element.widget.positionY`: Vertical scroll offset in pixels.
        | `boolean`_ `element.widget.scrollbarVisible`: Set if the scrollbar is displayed.

    Custom widget methods:
        | `element.widget:contentsChanged()`: Call to update scroll bar slider and limits after adding or removing elements to the content container. Because content size depends on layout, this must be run after a menu:updateLayout(). Only required if the content size changes.

```lua
local result = tes3uiElement:createVerticalScrollPane(id)
```

**Parameters**:

* `id` (number): *Optional*. A registered identifier to help find this element later.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `destroy`

Deletes an element and all its child elements. If any element is bound to text input by `tes3ui.acquireTextInput`_, the input is automatically released.

```lua
tes3uiElement:destroy()
```

***

### `destroyChildren`

Deletes all the child elements of this element. If any element is bound to text input by `tes3ui.acquireTextInput`_, the input is automatically released.

```lua
tes3uiElement:destroyChildren()
```

***

### `findChild`

Finds a child element matching the `id` argument. Searches children recursively. Returns the first child element with a matching id, or `nil` if no match found.

```lua
local result = tes3uiElement:findChild(id)
```

**Parameters**:

* `id` (number): The id to search for.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `forwardEvent`

Forwards an event to the original Morrowind event handler, using this element as a source. This may be optionally called at any point in a callback. Note that handler may or may not destroy the event widget or the menu, so you should know how it behaves before accessing any elements after a callback. 

```lua
tes3uiElement:forwardEvent(id)
```

**Parameters**:

* `id` (tes3uiEvent): The original UI event.

***

### `getContentElement`

Returns the descendant element that creation functions used on this element will place children into, or the calling element if there is no specific descendant for children.

    Some widgets like ScrollPanes are built of multiple layers of elements. When an element is created in a complex widget, it is automatically placed as a child of a content element, but other functions do not access this content element directly. This function finds this content container for any element, so that changing layout and accessing children is possible. For simple elements, the calling element will be returned so that there is always a valid container element.

```lua
local result = tes3uiElement:getContentElement()
```

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `getPropertyBool`

Properties are named variables attached to an element. Gets a property value with `propName` as the property key. Morrowind uses these to bind variables to the UI. Useful for element class-specific properties. Returns `false` if the property key did not have data.

```lua
local result = tes3uiElement:getPropertyBool(propName)
```

**Parameters**:

* `propName` (string): The property name.

**Returns**:

* `result` (boolean)

***

### `getPropertyFloat`

Properties are named variables attached to an element. Gets a property value with `propName` as the property key. Morrowind uses these to bind variables to the UI. Useful for element class-specific properties. Returns 0 if the property key did not have data.

```lua
local result = tes3uiElement:getPropertyFloat(propName)
```

**Parameters**:

* `propName` (string): The property name.

**Returns**:

* `result` (number)

***

### `getPropertyInt`

Properties are named variables attached to an element. Gets a property value with `propName` as the property key. Morrowind uses these to bind variables to the UI. Useful for element class-specific properties. Returns 0 if the property key did not have data.

```lua
local result = tes3uiElement:getPropertyInt(propName)
```

**Parameters**:

* `propName` (string): The property name.

**Returns**:

* `result` (number)

***

### `getPropertyObject`

Properties are named variables attached to an element. Gets a property value with `propName` as the property key. Morrowind uses these to bind variables to the UI. Useful for element class-specific properties. Returns `nil` if the property key did not have data, or if it could not guess the type of the property value.
    
    For `getPropertyObject`, an expected return value not derived from `tes3baseObject` requires the usertype to be provided as well. Currently accepted usertypes are:
	`tes3itemData`
	`tes3itemStack`
	`tes3gameFile`
	`tes3inventoryTile`
	`tes3uiElement`
	
	This is required because there is no identifying type information stored with the pointer. If the usertype is incorrect, there are no safety checks keeping the game from crashing.

```lua
local result = tes3uiElement:getPropertyObject(propName, expectedUsertype)
```

**Parameters**:

* `propName` (string): The property name.
* `expectedUsertype` (string): *Optional*. A Lua usertype name, if expecting a non-standard object type.

**Returns**:

* `result` ([tes3baseObject](../../types/tes3baseObject), [tes3mobileObject](../../types/tes3mobileObject), any)

***

### `getTopLevelMenu`

Finds the parent menu containing the element. Useful for finding the correct menu to run layout updates on.

```lua
local result = tes3uiElement:getTopLevelMenu()
```

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `loadMenuPosition`

Restores the menu's position and size information from the Morrowind.ini file. This may only be called on top-level parents.

```lua
tes3uiElement:loadMenuPosition()
```

***

### `register`

Sets an `event` handler, which can add or override an existing event handler. The use of `registerBefore` or `registerAfter` is recommended if you do not want to replace the existing event handler. The eventID can be a standard `event` name, or an event specific to an element class. The callback receives an argument with the event data. See below for details.
    
The original Morrowind callback is captured and can be invoked with the `forwardEvent` method on the event argument. If there is an existing Lua callback, it is replaced.



Lua UI event specification:

Events can be bound to elements via the `Element`_ `register` method, which takes an event name. Event names can be one of the standard events listed here, or a widget-specific event.

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
        Apparently not working in the engine. Mouse cursor positioned outside an element, after a mouseDown over the element. Triggers every frame.
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
        Just before another menu is clicked on, or a widget in that menu receives an event, or when the menu mode is toggled off. You may return false from this event to prevent the menu from being deselected, and to prevent leaving menu mode.
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

The original Morrowind event handler is saved when you first register an event. It may be optionally invoked with the `forwardEvent` method.  Note that handler may or may not destroy the event widget or the menu, so you should know how it behaves before accessing any elements after a callback. 

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
    Returns: `optional`
        Returning `false` may cancel an interaction for certain events. e.g. unfocus
   
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
            Event-specific raw data values. For mouse events, these are the screen X and Y coordinates of the pointer. For keyboard events, data0 is the `scan code`_.
        
        **relativeX** (`number`_)
            ..
            
        **relativeY** (`number`_)
            For mouse events only. X and Y coordinates of the pointer relative to the top-left of the element.

```lua
tes3uiElement:register(eventID, callback)
```

**Parameters**:

* `eventID` (string): The event id.
* `callback` (function): The callback function.

***

### `registerAfter`

Sets an `event` handler to run after any existing event handler on the element. Can be any event usable with `register`. The callback receives an argument with the event data. See `register` for details.

```lua
tes3uiElement:registerAfter(eventID, callback)
```

**Parameters**:

* `eventID` (string): The event id.
* `callback` (function): The callback function.

***

### `registerBefore`

Sets an `event` handler to run before any existing event handler on the element. Can be any event usable with `register`. The callback receives an argument with the event data. See `register` for details.

```lua
tes3uiElement:registerBefore(eventID, callback)
```

**Parameters**:

* `eventID` (string): The event id.
* `callback` (function): The callback function.

***

### `reorderChildren`

    Moves the layout order of the children of this element. `count` elements are taken from starting child `Element`_ or index (0-based) `moveFrom`, and moved before the child `Element`_ or index (0-based) `insertBefore`. If `count` is -1, all children after `moveFrom` are moved. If any index is a negative number, then the index represents a distance from the end of the child list.
    
    Returns `true` if the operation succeeded, or `false` if at least one argument was invalid.

```lua
local result = tes3uiElement:reorderChildren(insertBefore, moveFrom, count)
```

**Parameters**:

* `insertBefore` ([tes3uiElement](../../types/tes3uiElement), number): The insertion point (or its 0-based child index).
* `moveFrom` ([tes3uiElement](../../types/tes3uiElement), number): The first child (or 0-based child index) to be moved.
* `count` (number): The property name.

**Returns**:

* `result` (boolean)

***

### `saveMenuPosition`

Saves the menu's position and size information to the Morrowind.ini file. This may only be called on top-level parents. Note that most menus save their position automatically.

```lua
tes3uiElement:saveMenuPosition()
```

***

### `setPropertyBool`

Sets a property value with `prop` as the property key. Properties are named variables attached to an element. Gets a property value with `propName` as the property key. Morrowind uses these to bind variables to the UI. Useful for element class-specific properties.

```lua
tes3uiElement:setPropertyBool(propName, value)
```

**Parameters**:

* `propName` (string): The property name.
* `value` (boolean): The value to set.

***

### `setPropertyFloat`

Sets a property value with `prop` as the property key. Properties are named variables attached to an element. Gets a property value with `propName` as the property key. Morrowind uses these to bind variables to the UI. Useful for element class-specific properties.

```lua
tes3uiElement:setPropertyFloat(propName, value)
```

**Parameters**:

* `propName` (string): The property name.
* `value` (number): The value to set.

***

### `setPropertyInt`

Sets a property value with `prop` as the property key. Properties are named variables attached to an element. Gets a property value with `propName` as the property key. Morrowind uses these to bind variables to the UI. Useful for element class-specific properties.

```lua
tes3uiElement:setPropertyInt(propName, value)
```

**Parameters**:

* `propName` (string): The property name.
* `value` (number): The value to set.

***

### `setPropertyObject`

Sets a property value with `prop` as the property key. Properties are named variables attached to an element. Gets a property value with `propName` as the property key. Morrowind uses these to bind variables to the UI. Useful for element class-specific properties.

```lua
tes3uiElement:setPropertyObject(propName, value)
```

**Parameters**:

* `propName` (string): The property name.
* `value` (object): The value to set.

***

### `sortChildren`

Reorders the element's children given a sorting function.

```lua
tes3uiElement:sortChildren(sortFunction)
```

**Parameters**:

* `sortFunction` (function): The function to sort with. Like most sorting functions, this is given two arguments to compare.

***

### `triggerEvent`

Triggers a UI event on an element, either using supplied event data, or by constructing new event data using `eventName`. `eventName` is the same as used in `register`.

```lua
tes3uiElement:triggerEvent(eventID)
```

**Parameters**:

* `eventID` (tes3uiEvent, string): The event, or event ID.

***

### `unregister`

Unregisters an `event` handler.

```lua
local wasUnregistered = tes3uiElement:unregister(eventID)
```

**Parameters**:

* `eventID` (string): The event id.

**Returns**:

* `wasUnregistered` (boolean)

***

### `unregisterAfter`

Unregisters a function previously registered using `:registerAfter`.

```lua
local wasUnregistered = tes3uiElement:unregisterAfter(eventID, callback)
```

**Parameters**:

* `eventID` (string): The event id.
* `callback` (function): The callback function.

**Returns**:

* `wasUnregistered` (boolean)

***

### `unregisterBefore`

Unregisters a function previously registered using `:registerBefore`.

```lua
local wasUnregistered = tes3uiElement:unregisterBefore(eventID, callback)
```

**Parameters**:

* `eventID` (string): The event id.
* `callback` (function): The callback function.

**Returns**:

* `wasUnregistered` (boolean)

***

### `updateLayout`

Updates a menu's element layout and all child elements. Needs to be called on a top level menu when any elements contained in it are added, moved or resized.

```lua
tes3uiElement:updateLayout()
```

***

