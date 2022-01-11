return {
	type = "function",
	description = [[Compares two key objects and returns their equality. Returns true if the objects are equal, false otherwise.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{
				name = "actual",
				type = "table",
				description = "The key object that is being compared.",
				tableParams = {
					{
						name = "keyCode",
						type = "number",
						default = false,
						description = "Value of the actual key scan code, such as the letter `p`. Maps to [`tes3.scanCode.*`](https://mwse.github.io/MWSE/references/scan-codes/)."
					},
					{
						name = "isShiftDown",
						type = "boolean",
						default = false,
						description = "Value of whether the shift key is pressed."
					},
					{
						name = "isControlDown",
						type = "boolean",
						default = false,
						description = "Value of whether the control key is pressed."
					},
					{
						name = "isAltDown",
						type = "boolean",
						default = false,
						description = "Value of whether the alt key is pressed."
					},
					{
						name = "isSuperDown",
						type = "boolean",
						default = false,
						description = "Value of whether the super (Windows key) key is pressed."
					},
				},
			},
			{
				name = "expected",
				type = "table",
				description = "The key object that is being compared against.",
				tableParams = {
					{
						name = "keyCode",
						type = "number",
						default = false,
						description = "Value of the expected key scan code, such as the letter `p`. Maps to [`tes3.scanCode.*`](https://mwse.github.io/MWSE/references/scan-codes/)."
					},
					{
						name = "isShiftDown",
						type = "boolean",
						default = false,
						description = "Value of whether the shift key is expected to be pressed."
					},
					{
						name = "isControlDown",
						type = "boolean",
						default = false,
						description = "Value of whether the control key is expected to be pressed."
					},
					{
						name = "isAltDown",
						type = "boolean",
						default = false,
						description = "Value of whether the alt key is expected to be pressed."
					},
					{
						name = "isSuperDown",
						type = "boolean",
						default = false,
						description = "Value of whether the super (Windows key) key is pressed."
					},
				},
			},
		},
	}},
	returns = "equal",
	valuetype = "boolean",
}