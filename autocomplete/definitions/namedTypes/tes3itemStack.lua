return {
	type = "class",
	description = [[A complex container that holds a relationship between an item, and zero or more associated item datas.

Item stack represents all copies of an item with the same id. Some of those may have itemData and some may not. E.g. you might have two lockpicks and one of them has fewer uses remaining.
So `itemStack.variables` is a list of different itemData for each thing in the stack, not a single itemData.]],
	examples = {
		["..\\..\\tes3inventory\\items\\iteration"] = {
			title = "In the iterItems() function we can see that the an item stack can consist of items with itemData and items without it"
		}
	}
}