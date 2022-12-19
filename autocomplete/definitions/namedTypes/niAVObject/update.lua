return {
	type = "method",
	description = [[Updates the world transforms of this node and its children, which makes changes visible for rendering. Use after changing any local rotation, translation, scale, bounds or after attaching and detaching nodes.

!!! tip	"Update Efficiency"
	It's best to "batch up" calls to this method. For example, when transform of an object its parent and grandparent are all changed during the same frame, it is much more efficient to call this method only on the grandparent object after all transforms have been changed. Also, consider calling this function as low as possible on a scene graph.
]],
	arguments = {{
			name = "args",
			optional = true,
			type = "table",
			tableParams = {
				{ name = "time", type = "number", optional = true, default = 0, description = "This parameter is the time-slice for transformation and bounds updates" },
				{ name = "controllers", type = "boolean", optional = true, default = false, description = "Update object's controllers?" },
				{ name = "bounds", type = "boolean", optional = true, default = true, description = "Update object's bounds?" },
			}
		},
	}
}