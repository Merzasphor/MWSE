mwse.loadConfig
====================================================================================================

Loads a config table from Data Files\MWSE\config\{fileName}.json.
	
If the default values table is passed, empty keys in the config will be filled in using its values. Additionally, if no file exists, the function will return the default table.

Parameters
----------------------------------------------------------------------------------------------------

fileName (`string`_)
    The non-extensioned name of the config file.

defaults (`table`_)
    Optional. A table of default values.

.. _`bool`: ../../../lua/type/boolean.html
.. _`nil`: ../../../lua/type/nil.html
.. _`table`: ../../../lua/type/table.html
.. _`string`: ../../../lua/type/string.html
.. _`number`: ../../../lua/type/number.html
.. _`boolean`: ../../../lua/type/boolean.html
.. _`function`: ../../../lua/type/function.html
