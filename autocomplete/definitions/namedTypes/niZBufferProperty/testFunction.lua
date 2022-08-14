return {
	type = "value",
	description = [[The Z-buffer test function.

Note that "less than" means closer to the camera and "greater than" means further from the camera, regardless of the low-level hardware representation of Z values.
Value | Mode                | Description
----- | ------------------- | -----------------
0     | ZCOMP_ALWAYS        | Test will allways succeed. The Z Buffer value is ignored.
1	  | ZCOMP_LESS          | The test will only succeed if the pixel is nearer than the previous pixel.
2     | ZCOMP_EQUAL         | Test will only succeed if the Z value of the pixel to be drawn is equal to the value of the previous drawn pixel.
3     | ZCOMP_LESS_EQUAL    | Test will succeed if the Z value of the pixel to be drawn is smaller than or equal to the value in the Z Buffer.
4     | ZCOMP_GREATER       | Opposite of TEST_LESS
5     | ZCOMP_NOT_EQUAL     | Test will succeed if the Z value of the pixel to be drawn is NOT equal to the value of the previously drawn pixel.
6     | ZCOMP_GREATER_EQUAL | Opposite of TEST_LESS_EQUAL.
7     | ZCOMP_NEVER         | Test will allways return false. Nothing is drawn at all.]],
	valuetype = "integer",
}