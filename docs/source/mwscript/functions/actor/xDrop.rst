
xDrop
========================================================

**Parameters:**

- ``string`` **objectID**: The object ID of the item to drop.
- ``long`` **count**: The number of items to drop.

**Returned:**

- *None*

This is a wrapper for the vanilla Drop function that can take variable input.

Note: xdrop N+1 items will leave 1 phantom icon plus N real items in the dropping actors inventory.  xgetitemcount will not report the 1 phantom icon.  However, xremoveitem will remove the phantom safely.  So "safe" procedure for xdrop seems to be to follow up with xremoveitem of the same count.  Additionally for non-player actors in menumode, exit and re-entry to menumode is needed to refresh the icons and avoid phantom icon interaction that could result in permanent item doubling or CTD.  This also applies to the standard drop function.
