string.multifind
====================================================================================================

Performs the logic of find, using a table of patterns.

If any of the available patterns match, the matching pattern is returned followed by the normal results of the find.

Parameters
----------------------------------------------------------------------------------------------------

s (`string`_)
    The string to perform finds on.

pattern (`table`_)
    An array-style table that contains pattern strings.

index (`number`_)
    Default: ``1``. Start index of the find.

plain (`boolean`_)
    Default: ``false``. If true, a normal search instead of a pattern search will be performed.

.. _`bool`: ../../../lua/type/boolean.html
.. _`nil`: ../../../lua/type/nil.html
.. _`table`: ../../../lua/type/table.html
.. _`string`: ../../../lua/type/string.html
.. _`number`: ../../../lua/type/number.html
.. _`boolean`: ../../../lua/type/boolean.html
.. _`function`: ../../../lua/type/function.html
