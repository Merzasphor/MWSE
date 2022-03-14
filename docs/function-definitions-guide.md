# Function Definitions Guide

Function definitions can be found in autocomplete\definitions\global. Some functions are exposed in global namespace and have their definitions in that folder, while some are exposed as libraries. Those have their own folders.


## Library Definitions

Each library definition is just a regular Lua table. The following fields are available:
| Field | Type | Description |
| ----- | ---- | ----------- |
| type  | `string` |  This flag is used when generating syntax highlighting files. The type should always be `"lib"` for library definitions. |
| deprecated | `boolean` | Passing `true` here will mark all the functions and values exposed by the library as deprecated in a IDE and the documentation page. |
| description | `string` | The description for the library. You can pass a string with `""` or `[[]]`. |
| link | `string` | If present, the generated autocomplete files will allow the IDEs to provide the link to the documentation for that library. |

For example, the table library definition looks like this:

```Lua
-- autocomplete\definitions\global\table.lua
return {
	type = "lib",
	description = "This library provides generic functions for table manipulation. It provides all its functions inside the table table.",
	link = "https://www.lua.org/manual/5.1/manual.html#5.5",
}
```

All the function definitions of a certain library are found in the folder of the same name. For example, all the function definitions for `tes3ui` API are found inside `tes3ui` folder.


## Function Definitions

Each function definition is just a regular Lua table. The following fields are available:
| Field | Type | Description |
| ----- | ---- | ----------- |
| type  | `string` |  This flag is used when generating syntax highlighting files. The type should always be `"function"` for function definitions. |
| description | `string` | The description for the function. You can pass a string with `""` or `[[]]`. |
| arguments | `table` | The arguments the function accepts. |
| examples | `table` | A table with entries that are the names of the files included as examples. Each entry is a table itself with one available field, `title`. The title will be shown as the title of the example on the documentation page. |
| returns | `table` | The table with return values. |


`examples` table looks like this:
| Field |   Type  | Description |
| ----- | ------- | ----------- |
| entry | `table` | Each entry in examples table should be the file name of the file used as an example. The example file should just be regular Lua code. All the example files need to be inside the folder of the same name as the function these examples are for. Look at the last example in this page for reference. |


`returns` table has entries which are nested tables for each of the returned values, with the following fields:
| Field | Type | Description |
| ----- | ---- | ----------- |
| name  | `string` | The name of the argument. |
| type  | `string` | This allows to specify the type of the value in evenData. You can put string names for basic Lua types: `number`, `boolean` and `string`, or objects exposed by MWSE, such as `tes3reference`. If the value can be of two or more types, then you should pass all the types split by `|`. For example, `tes3mobileCreature|tes3mobileNPC|nil`. |
| description | `string` | The description for the argument. |

An example of a function with multiple return values is `tes3.checkMerchantOffersService()`. Its definition looks like this:
```Lua
-- autocomplete\definitions\global\tes3\checkMerchantOffersService.lua
return {
	type = "function",
	description = [[Checks if a merchant will offer a service to you, including dialogue checks like disposition and faction membership. A specific service can be checked, or if no service is given, a generic dialogue check is made. If the service is refused, the dialogue reply for the refusal may also be returned (it may be nil, as there may not always be a reply available).]],
	arguments = {
		{ name = "reference", type = "tes3reference|tes3mobileActor|string" },
		{ name = "service", type = "number", optional = true, description = "The specific service to check for availability. Uses the [`tes3.merchantService`](https://mwse.github.io/MWSE/references/merchant-service-types/) constants." },
	},
	returns = {
		{ name = "offersService", type = "boolean" },
		{ name = "refusalReply", type = "tes3dialogueInfo" },
	},
}
```


Some functions accept multiple arguments. In that case the arguments table should have a nested table for each argument.
| Field | Type | Description |
| ----- | ---- | ----------- |
| name  | `string` | The name of the argument. |
| type  | `string` | This allows to specify the type of the value in evenData. You can put string names for basic Lua types: `number`, `boolean` and `string`, or objects exposed by MWSE, such as `tes3reference`. If the value can be of two or more types, then you should pass all the types split by `|`. For example, `tes3mobileCreature|tes3mobileNPC|nil`. |
| description | `string` | The description for the argument. |

An example of such function is `tes3.claimSpellEffectId()`. This is the definition for that function:

```Lua
-- autocomplete\definitions\global\tes3\claimSpellEffectId.lua
return {
	type = "function",
	description = [[This function is used to claim a unique spell effect name and id. This is needed before actually creating a new effect by calling `tes3.addMagicEffect()`. A claimed effect id is then available as: `tes3.effect.effectName` (just like any other spell effect). For examples of this function in practice see [`tes3.addMagicEffect()`](https://mwse.github.io/MWSE/apis/tes3/#tes3addmagiceffect) example.]],
	arguments = {
		{ name = "name", type = "string", description = "The name of the new spell effect. Must be unique. An error will be thrown if it's non-unique." },
		{ name = "id", type = "number", description = "A unique number representing the new spell effect. An error will be thrown if it's non-unique." },
	},
}
```

Some other functions accept a table called `params`. In that case you can follow this convention (the function definition for `tes3.addItem()`):

```Lua
-- autocomplete\definitions\global\tes3\cast.lua
return {
	type = "function",
	description = [[Casts a spell from a given reference to a target reference. Touch effects will hit the target at any range, while target effects will create a projectile. By default, the spell always casts successfully and does not consume magicka. By default, an actor casting will stop and perform its cast animation, but the 'instant' flag can start the cast instantly, and allow more control over the spell.

When the caster is the player, the target parameter is optional; without a target, the player's touch effects will only hit targets in front of them, and target effects will create a projectile in the direction the player is facing. Currently as a limitation, instant must be true to allow the player to cast spells.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The caster reference." },
			{ name = "target", type = "tes3reference|tes3mobileActor|string", description = "The target reference. Optional only if the caster is the player." },
			{ name = "spell", type = "tes3spell|string", description = "The spell the caster uses." },
			{ name = "instant", type = "boolean", default = false, description = "When true, the spell is cast instantly. No animation is performed." },
			{ name = "alwaysSucceeds", type = "boolean", default = true, description = "When true, the spell cannot fail and does not consume magicka. When false, it is cast using the actor's spell skill, and requires and takes enough magicka to cast. Only applies when 'instant' is true." },
			{ name = "bypassResistances", type = "boolean", default = false, description = "The spell will bypass the target's resistances. Only applies when 'instant' is true." },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
	examples = {
		-- autocomplete\definitions\global\tes3\cast\imitateExplodeSpell.lua
		["imitateExplodeSpell"] = {
			title = "This is an example of how to use tes3.cast instead of mwscript.explodeSpell",
		},
	},
}
```
