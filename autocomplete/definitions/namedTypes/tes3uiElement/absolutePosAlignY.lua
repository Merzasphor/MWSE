return {
	type = "value",
	description = [[The vertical alignment of the element relative to it's parent element. Can be `nil`. If `nil`, deactivates behaviour associated with this property. Valid values range from `0.0` to `1.0`. Sets the element's `positionY` to a point relative to the parent element. A value of `0.0` is equal to the parent element's top content edge, whereas a value of `1.0` is equal to the parent element's bottom content edge. The positioning is absolute, which frees the element from the standard flow layout and allows overlapping elements.
	
Incompatible with and will change the value of [`ignoreLayoutY`](https://mwse.github.io/MWSE/types/tes3uiElement/#ignorelayouty).

Elements may not respond to `heightProportional` sizing after this property is set. If you need to use both you should consider testing if it works first.]],
	valuetype = "number",
}
