# tes3uiMenuController

The controller responsible for the menu system.

## Properties

### `fontColors`

*Read-only*. A 1-indexed table with 49 [`tes3uiFontColor`](https://mwse.github.io/MWSE/types/tes3uiFontColor/) objects for all different in-game uses for fonts.

Namely: `normal`, `normal_over`, `normal_pressed`, `active`, `active_over`, `active_pressed`, `disabled`, `disabled_over`, `disabled_pressed`, `link`, `link_over`, `link_pressed`, `journal`, `journal_over`, `journal_pressed`, `journal_topic`, `journal_topic_over`, `journal_topic_pressed`, `journal_finished_quest_topic`, `journal_finished_quest_topic_over`, `journal_finished_quest_topic_pressed`, `answer`, `answer_over`, `answer_pressed`, `header`, `notify`, `big_normal`, `big_normal_over`, `big_normal_pressed`, `big_link`, `big_link_over`, `big_link_pressed`, `big_answer`, `big_answer_over`, `big_answer_pressed`, `big_header`, `big_notify`, `background`, `focus`, `npc_health`, `health`, `magic`, `fatigue`, `misc`, `weapon_fill`, `magic_fill`, `positive`, `negative`, `count`.

**Returns**:

* `result` (table)

***

### `helpDelay`

*Read-only*. Delay in seconds before help tooltip appears. Corresponds to the Menu Help Delay slider in Options menu.

**Returns**:

* `result` (number)

***

### `helpRoot`

*Read-only*. 

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `inputController`

*Read-only*. Access to `tes3uiMenuInputController`.

**Returns**:

* `result` ([tes3uiMenuInputController](../../types/tes3uiMenuInputController))

***

### `inventoryMenuEnabled`

A flag that controls whether the inventory menu is enabled or disabled.

**Returns**:

* `result` (boolean)

***

### `magicMenuEnabled`

A flag that controls whether the magic menu is enabled or disabled. Magic menu is the menu used to select a spell for casting from available spells, scrolls and enchantments.

**Returns**:

* `result` (boolean)

***

### `mainRoot`

*Read-only*. 

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `mapMenuEnabled`

A flag that controls whether the map menu is enabled or disabled.

**Returns**:

* `result` (boolean)

***

### `scriptCompiler`

*Read-only*. Access to `tes3scriptCompiler` object.

**Returns**:

* `result` (tes3scriptCompiler)

***

### `statsMenuEnabled`

A flag that controls whether the stats menu is enabled or disabled. Stats menu lists all of the player's current skill and attribute values, level, race, class, health, magicka and fatigue.

**Returns**:

* `result` (boolean)

***

