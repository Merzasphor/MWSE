tes3.triggerCrime
====================================================================================================

Emulates the player committing a crime.

Returns
----------------------------------------------------------------------------------------------------

`boolean`_.

Parameters
----------------------------------------------------------------------------------------------------

Accepts parameters through a table with the given keys:

criminal (`tes3mobileActor`_, `tes3reference`_, `string`_)
    Default: ``tes3.mobilePlayer``. No description available.

forceDetection (`boolean`_)
    Default: ``false``. Can be set to true to ignore normal detection checks.

type (`number`_)
    Default: ``tes3.crimeType.stealing``. Maps to tes3.crimeType constants.

value (`number`_)
    Penalty for the crime. Defaults to 25 for pickpocketing.

victim (`tes3mobileActor`_, `tes3reference`_, `string`_)
    Default: ``tes3.mobilePlayer``. No description available.

.. _`bool`: ../../../lua/type/boolean.html
.. _`nil`: ../../../lua/type/nil.html
.. _`table`: ../../../lua/type/table.html
.. _`string`: ../../../lua/type/string.html
.. _`number`: ../../../lua/type/number.html
.. _`boolean`: ../../../lua/type/boolean.html
.. _`function`: ../../../lua/type/function.html
