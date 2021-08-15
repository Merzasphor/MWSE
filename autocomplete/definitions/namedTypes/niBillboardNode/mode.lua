return {
	type = "value",
    description = [[The orientation mode.
`0` Always face camera. Local z-axis becomes parallel to the camera. Minimizes rotation difference from the previous frame for smoother motion.
`1` Rotate about up vector. The object is rotated around its local y-axis so that its z-axis is pointing towards the camera.
`2` Rigid face camera. Local z-axis becomes parallel to the camera. Does not depend on previous frame.
]],
	valuetype = "number",
}