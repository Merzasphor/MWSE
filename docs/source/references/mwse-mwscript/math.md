# Math Functions

--8<-- "mwse-deprecated.md"


## `xArcCos`

**Parameters:**

- `float` **angle**: The angle to take the trigonometric function of.

**Returned:**

- `float` **result**: Result of the function.

Provides the inverse trigonometric function arccosine on the given **angle**.


***

## `xArcSin`

**Parameters:**

- `float` **angle**: The angle to take the trigonometric function of.

**Returned:**

- `float` **result**: Result of the function.

Provides the inverse trigonometric function arcsine on the given **angle**.


***

## `xArcTan`

**Parameters:**

- `float` **angle**: The angle to take the trigonometric function of.

**Returned:**

- `float` **result**: Result of the function.

Provides the inverse trigonometric function arctangent on the given **angle**.


***

## `xArcTan2`

**Parameters:**

- `float` **x**: The angle to take the trigonometric function of.
- `float` **y**: The angle to take the trigonometric function of.

**Returned:**

- `float` **result**: Result of the function.

Provides the inverse trigonometric function arctan2 on **y**/**x**.


***

## `xBitAnd`

**Parameters:**

- `long` **leftValue**: First value for the bitwise operation.
- `long` **rightValue**: Second value for the bitwise operation.

**Returned:**

- `long` **result**: 1 if the bitwise operation returns true.

This function performs an AND bitwise operation, and returns its result.

A    | B    | `xBitAnd A B`
---- | ---- | -------------
0000 | 0000 | 0000
0101 | 1010 | 0000
1100 | 1111 | 1100
1111 | 0000 | 0000


***

## `xBitNot`

**Parameters:**

- `long` **leftValue**: Value for the bitwise operation.

**Returned:**

- `long` **result**: 1 if the bitwise operation returns true.

This function performs a NOT bitwise operation, and returns its result.

A    | `xBitNot A`
---- | -----------
0000 | 1111
0101 | 1010
1100 | 0011
1111 | 0000


***

## `xBitOr`

**Parameters:**

- `long` **leftValue**: First value for the bitwise operation.
- `long` **rightValue**: Second value for the bitwise operation.

**Returned:**

- `long` **result**: 1 if the bitwise operation returns true.

This function performs an OR bitwise operation, and returns its result.

A    | B    | `xBitOr A B`
---- | ---- | ------------
0000 | 0000 | 0000
0101 | 1010 | 1111
1100 | 1111 | 1111
1111 | 0000 | 1111


***

## `xBitXor`

**Parameters:**

- `long` **leftValue**: First value for the bitwise operation.
- `long` **rightValue**: Second value for the bitwise operation.

**Returned:**

- `long` **result**: 1 if the bitwise operation returns true.

This function performs an XOR bitwise operation, and returns its result.

A    | B    | `xBitXor A B`
---- | ---- | -------------
0000 | 0000 | 0000
0101 | 1010 | 1111
1100 | 1111 | 0011
1111 | 0000 | 1111


***

## `xCos`

**Parameters:**

- `float` **angle**: The angle to take the trigonometric function of.

**Returned:**

- `float` **result**: Result of the function.

Provides the trigonometric function cosine on the given **angle**.


***

## `xDegRad`

**Parameters:**

- `float` **angle**: An angle, in degrees.

**Returned:**

- `float` **result**: The value of **angle** in radians.

This simple function converts from degrees to radians.


***

## `xFloatsToLong`

**Parameters:**

- `float` **value1**: First value. Order doesn't matter.
- `float` **value2**: Second value. Order doesn't matter.

**Returned:**

- `long` **result**: Merged value from **value1** and **value2**.

This function retrieves a long value using a pair of floats. It is intended to work around the issue that all globals are really floats.

This work by splitting the long 32-bit value into two 16-bit values and adding a flag to indicate which value maps to the high 16 bits. Argument order doesn't matter.

!!! warning
	MWEdit doesn't like to compile these functions with globals as arguments, and temporary locals will need to be used instead.

??? example
	```
	long lVal1
	long lVal2
	float fVal1
	float fVal2

	set lVal1 to 2147483647
	setx fVal1 fVal2 to xLongToFloats lVal1
	setx lVal2 to xFloatsToLong fVal1 fVal2

	if ( lVal1 == lVal2 )
		MessageBox "Success!"
	else
		MessageBox "Failure!"
	endif
	```


***

## `Hypot`

**Parameters:**

- `float` **x**:
- `float` **y**:

**Returned:**

- `float` **hypotenuse**:


`xHypot` returns the hypotenuse for sides a and b, c = sqrt(a*a + b*b). Unlike `xSqrt` this is more efficient than calculating the formula inside the script.


***

## `xLongToFloats`

**Parameters:**

- `long` **value**: Value to split.

**Returned:**

- `float` **result1**: First half of the split **value**.
- `float` **result2**: Second half of the split **value**.

This function stores a long value using a pair of floats. It is intended to work around the issue that all globals are really floats.

This work by splitting the long 32-bit value into two 16-bit values and adding a flag to indicate which value maps to the high 16 bits. Argument order doesn't matter.

!!! warning
	MWEdit doesn't like to compile these functions with globals as arguments, and temporary locals will need to be used instead.

??? example
	```
	long lVal1
	long lVal2
	float fVal1
	float fVal2

	set lVal1 to 2147483647
	setx fVal1 fVal2 to xLongToFloats lVal1
	setx lVal2 to xFloatsToLong fVal1 fVal2

	if ( lVal1 == lVal2 )
		MessageBox "Success!"
	else
		MessageBox "Failure!"
	endif
	```

***

## `xPow`

**Parameters:**

- `float` **base**: Base value.
- `float` **exponent**: Exponent to calculate.

**Returned:**

- `float` **result**: Result of the function.

Calculates the value of **base** raised to **exponent**.


***

## `xDegRad`

**Parameters:**

- `float` **angle**: An angle, in radians.

**Returned:**

- `float` **result**: The value of **angle** in degrees.

This simple function converts from radians to degrees.


***

## `xRandomFloat`

**Parameters:**

- `float` **minimum**: Lowest value to return.
- `float` **maximum**: Highest value to return.

**Returned:**

- `float` **result**: A random value between **minimum** and **maximum**.

This function returns a random `float` value.


***

## `xRandomLong`

**Parameters:**

- `long` **minimum**: Lowest value to return.
- `long` **maximum**: Highest value to return.

**Returned:**

- `long` **result**: A random value between **minimum** and **maximum**.

This function returns a random `long` value.


***

## `xShift`

**Parameters:**

- `long` **value**: The value to shift.
- `long` **magnitude**: The number of bits to shift. If negative, the bits will be reverse-shifted.

**Returned:**

- `long` **result**: **value**, shifted **magnitude** bits.

This function allows shifting a **value** by a number of bits equal to **magnitude**.


***

## `xSin`

**Parameters:**

- `float` **angle**: The angle to take the trigonometric function of.

**Returned:**

- `float` **result**: Result of the function.

Provides the trigonometric function sine on the given **angle**.


***

## `xSqrt`

**Parameters:**

- `float` **value**: Value to take the square root of.

**Returned:**

- `float` **result**: Result of the function.

Calculates the square root of **value**.


***

## `xTan`

**Parameters:**

- `float` **angle**: The angle to take the trigonometric function of.

**Returned:**

- `float` **result**: Result of the function.

Provides the trigonometric function tangent on the given **angle**.