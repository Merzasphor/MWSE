# Mod Translations

MWSE provides means to translate mods using [an i18n library](https://github.com/kikito/i18n.lua). With this, users can write their mods with native support for other languages, or they can write their mods in such a way that other modders can provide translation files.


## Hello World, Translated

To begin, let's look at some source code that we want to enable translations for. It is a simple mod that displays a message when the player hits the Z key.

!!! example "**The Hello World Mod\\main.lua**"
	```lua linenums="1"
	local function onPressZ(e)
		tes3.messageBox("Hello world!")
	end
	event.register("keyDown", onPressZ, { filter = tes3.scanCode.z })
	```

Here we just want to allow translators to provide a different string instead of `"Hello world!"`. To do this, we need to make an **i18n** folder in our project to define our language files in. For example:

* The Hello World Mod
	* i18n
		* deu.lua
		* eng.lua
		* fra.lua
		* rus.lua
	* main.lua

!!! example "**The Hello World Mod\\i18n\\deu.lua**"
	```lua linenums="1"
	return {
		["Hello world!"] = "Hallo Welt!",
	}
	```

!!! example "**The Hello World Mod\\i18n\\eng.lua**"
	```lua linenums="1"
	return {
		["Hello world!"] = "Hello world!",
	}
	```

!!! example "**The Hello World Mod\\i18n\\fra.lua**"
	```lua linenums="1"
	return {
		["Hello world!"] = "Bonjour le monde!",
	}
	```

!!! example "**The Hello World Mod\\i18n\\rus.lua**"
	```lua linenums="1"
	return {
		["Hello world!"] = "Привет, мир!",
	}
	```

!!! example "**The Hello World Mod\\main.lua**"
	```lua linenums="1"
	local i18n = mwse.loadTranslations("The Hello World Mod")

	local function onPressZ(e)
		tes3.messageBox(i18n("Hello world!"))
	end
	event.register("keyDown", onPressZ, { filter = tes3.scanCode.z })
	```

This code looks pretty simple, but what is really happening here? `mwse.loadTranslations("The Hello World Mod")` loads content from **The Hello World Mod\\i18n\\eng.lua** as well as an optional additional file, based on the player's game language. This can be **deu.lua**, **fra.lua**, or **rus.lua**. When the `i18n` translation result is called, it returns the translation for the player's current language with the key `"Hello world!"`.


## Translation Files

The translation files available in the **i18n** folder follow a simple format, but it warrants description here. Each is a simple lua file that returns a table. The keys in that table can be passed to the `i18n` value returned from `mwse.loadTranslations` to get a translation for the player's language.

A translation value is typically a string, but it can also have support for different translations based on values fed.

!!! note "File Encoding"
	MWSE automatically handles encoding of language files. All language files should be written using UTF-8.

!!! warning "Dots in Translation Keys"
	When using dots to break apart translation keys, be careful of not to use a category as a value. For example, the following will create an error:
	```lua
	return = {
		["mcm.component.console"] = "Enable console component?",
		["mcm.component.console.description"] = "It's really cool, so you should.",
	}
	```
	Instead, use something like:
	```lua
	return = {
		["mcm.component.console.label"] = "Enable console component?",
		["mcm.component.console.description"] = "It's really cool, so you should.",
	}
	```

### Pluralization

i18n supports the [unicode.org plural rules](http://cldr.unicode.org/index/cldr-spec/plural-rules), to make translations more intelligent and context-sensitive. We will discuss feeding values for this shortly. Consider this example, handling how to display the number of iron daggers the player has:

!!! example "Pluralization"
	**i18n\\eng.lua**:
	```lua linenums="1"
	return = {
		itemCountNotification = {
			zero = "You have no %{item}s.",
			one = "You have 1 %{item}.",
			other = "You have %{count} %{item}s.",
		},
	}
	```
	**main.lua**:
	```lua linenums="1"
	local i18n = mwse.loadTranslations("Iron Dagger Counter")
	local function onPressZ(e)
		local dagger = tes3.getObject("iron dagger")
		local daggerCount = tes3.getItemCount({ reference = tes3.player, item = dagger })
		tes3.messageBox(i18n("itemCountNotification", { count = daggerCount, item = dagger.name }))
	end
	event.register("keyDown", onPressZ, { filter = tes3.scanCode.z })
	```

Here, the correct language will be chosen depending on the context of `daggerCount`. If the player has no iron daggers, `"You have no Iron Daggers."` will be displayed. If the player has exactly 1 iron dagger, `"You have 1 Iron Dagger."`. Finally, in any other case, the `other` key is used.

A few other pluralization fields are available: `few` and `many`. `few` is used when `value % 100` is between 3 and 10. `many` is used when `value % 100` is between 11 and 99.


## Interpolation

Values can be passed to translation strings in a few different ways:

!!! example "Named Style"
	**i18n\\eng.lua**:
	```lua linenums="1"
	return = {
		itemCountNotification = {
			zero = "You have no %{item}s.",
			one = "You have 1 %{item}.",
			other = "You have %{count} %{item}s.",
		},
	}
	```
	**main.lua**:
	```lua linenums="1"
	tes3.messageBox(i18n("itemCountNotification", { count = daggerCount, item = dagger.name }))
	```

!!! example "`string.format` Style"
	**i18n\\eng.lua**:
	```lua linenums="1"
	return = {
		itemCountNotification = {
			zero = "You have no %ss.",
			one = "You have 1 %s.",
			other = "You have %d %ss.",
		},
	}
	```
	**main.lua**:
	```lua linenums="1"
	if (daggerCount > 1) then
		tes3.messageBox(i18n("itemCountNotification", { daggerCount, dagger.name }))
	else
		tes3.messageBox(i18n("itemCountNotification", { dagger.name }))
	end
	```

!!! example "Named with `string.format` Style"
	**i18n\\eng.lua**:
	```lua linenums="1"
	return = {
		itemCountNotification = {
			zero = "You have no %<item>ss.",
			one = "You have 1 %<item>d.",
			other = "You have %<count>d %<item>ss.",
		},
	}
	```
	**main.lua**:
	```lua linenums="1"
	tes3.messageBox(i18n("itemCountNotification", { count = daggerCount, item = dagger.name }))
	```
