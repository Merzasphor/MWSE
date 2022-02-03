# tes3uiScrollPane

A structure containing properties specific to scroll panes.

## Properties

### `contentPane`

*Read-only*. The content element of this pane.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `positionX`

The horizontal scroll offset in pixels.

**Returns**:

* `result` (number)

***

### `positionY`

The vertical scroll offset in pixels.

**Returns**:

* `result` (number)

***

### `scrollbarVisible`

If `true`, the scrollbar will be visible.

**Returns**:

* `result` (boolean)

***

## Methods

### `contentsChanged`

Updates the scrollbar slider and scrollbar limits after adding or removing elements to the content container. Because content size depends on layout, this must be run after calling `updateLayout` on the widget element. Only required if the content size changes.

```lua
tes3uiScrollPane:contentsChanged()
```

***

