return {
	type = "value",
	description = [[The stencil buffer test function used to test the reference value against the buffer value.

Value | Mode               | Description
----- | ------------------ | -------------
0     | TEST_NEVER         | Test will allways return false. Nothing is drawn at all.
1	  | TEST_LESS          | The test will only succeed if the pixel is nearer than the previous pixel.
2	  | TEST_EQUAL         | Test will only succeed if the z value of the pixel to be drawn is equal to the value of the previous drawn pixel.
3	  | TEST_LESS_EQUAL    | Test will succeed if the z value of the pixel to be drawn is smaller than or equal to the value in the Stencil Buffer.
4     | TEST_GREATER       | Opposite of TEST_LESS
5     | TEST_NOT_EQUAL     | Test will succeed if the z value of the pixel to be drawn is NOT equal to the value of the previously drawn pixel.
6     | TEST_GREATER_EQUAL | Opposite of TEST_LESS_EQUAL.
7	  | TEST_ALWAYS        | Test will allways succeed. The Stencil Buffer value is ignored.
]],
	valuetype = "integer",
}