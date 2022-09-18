return {
	type = "value",
	description = [[The port on the backbuffer of the camera. Represents the rectangular portion of the rendering backbuffer to which the camera's view rectangle is drawn (purely 2D mapping). These values are called port settings. The ordering: X - left, Y - right, Z - top and W - bottom. All port settings must be in the unit interval [0, 1]. The left edge of the backbuffer is 0.0, the right edge is 1.0. The top edge of the backbuffer is 1.0, the bottom edge is 0.0.]],
	valuetype = "tes3vector4",
}