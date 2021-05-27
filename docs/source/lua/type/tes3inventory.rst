tes3inventory
====================================================================================================

An inventory composes of an iterator, and flags caching the state of the inventory.

Properties
----------------------------------------------------------------------------------------------------

`flags`_ (`number`_)
    Raw bit-based flags.

`iterator`_ (`tes3iterator`_)
    Direct acces to the container that holds the inventory's items.

.. toctree::
    :hidden:

    tes3inventory/flags
    tes3inventory/iterator

.. _`flags`: tes3inventory/flags.html
.. _`iterator`: tes3inventory/iterator.html

Methods
----------------------------------------------------------------------------------------------------

`addItem`_
    Adds an item into the inventory directly. This should not be used, in favor of the tes3 API function.

`calculateWeight`_ (`number`_)
    Calculates the weight of all items in the container.

`contains`_ (`boolean`_)
    Checks to see if the inventory contains an item.

`dropItem`_
    Checks to see if the inventory contains an item. This should not be used, in favor of tes3 APIs.

`removeItem`_
    Removes an item from the inventory directly. This should not be used, in favor of the tes3 API function.

`resolveLeveledItems`_
    Resolves all contained leveled lists and adds the randomized items to the inventory. This should generally not be called directly.

.. toctree::
    :hidden:

    tes3inventory/addItem
    tes3inventory/calculateWeight
    tes3inventory/contains
    tes3inventory/dropItem
    tes3inventory/removeItem
    tes3inventory/resolveLeveledItems

.. _`addItem`: tes3inventory/addItem.html
.. _`calculateWeight`: tes3inventory/calculateWeight.html
.. _`contains`: tes3inventory/contains.html
.. _`dropItem`: tes3inventory/dropItem.html
.. _`removeItem`: tes3inventory/removeItem.html
.. _`resolveLeveledItems`: tes3inventory/resolveLeveledItems.html

.. _`tes3iterator`: ../../lua/type/tes3iterator.html
.. _`boolean`: ../../lua/type/boolean.html
.. _`string`: ../../lua/type/string.html
.. _`number`: ../../lua/type/number.html
.. _`tes3mobileActor`: ../../lua/type/tes3mobileActor.html
.. _`tes3reference`: ../../lua/type/tes3reference.html
.. _`tes3vector3`: ../../lua/type/tes3vector3.html
.. _`tes3item`: ../../lua/type/tes3item.html
.. _`tes3itemData`: ../../lua/type/tes3itemData.html
