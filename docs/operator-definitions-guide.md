# Operator Definitions Guide

Operator overloads are documented similarly to the methods of their parent class. The operator oveload definition file is just a regular Lua table. The name of the needs to be the same as the Lua [operator metamethod](http://lua-users.org/wiki/MetatableEvents) name without the two leading underscores. The supported operators are:
- unm - unary minus
- add - addition
- sub - subtraction
- mul - multiplication
- div - division
- idiv - floor division (division with rounding down to nearest integer), the `//` operator.
- mod - the `%` operator
- pow - the `^` operator
- concat - the `..` operator.
- len - the `#` operator

The format of operator definition is:

| Field       | Type      | Description |
| ----------- | --------- | ----------- |
|  type       | `string`  | The type of the definition. This flag is used when generating syntax highlighting files. This should always be `"operator"` for operator overload defintions. |
| overloads   | `table`   | The table with the oveloads. |


The format of the `overloads` table:

| Field       | Type      | Description                                                                     |
| ----------- | --------- | ------------------------------------------------------------------------------- |
| rightType   | `string`  | *Optional.* The right operand type. Don't specify this for the unary operators. |
| resultType  | `string`  | The resulting type of the expression.                                           |

An example of a typical operator definition:

```Lua
-- autocomplete\definitions\namedTypes\niColor\mul.lua
return {
	type = "operator", -- Necessary for operator definitions
	overloads = {
		{ rightType = "niColor", resultType = "niColor" },
		{ rightType = "number", resultType = "niColor" },
	}
}
```

Here is an example of the unary length (`#`) operator definition:

```Lua
-- autocomplete\definitions\namedTypes\tes3vector3\len.lua
return {
	type = "operator",
	overloads = {
		{ resultType = "number" },
	}
}
```

## Why

Adding these definitions helps mod developers, because with these definitions VSCode can give proper type suggestions.


![Operator definitions](https://user-images.githubusercontent.com/41503714/185394230-91dc4020-0938-4efd-9e6f-893fdfbfbd7d.png)


