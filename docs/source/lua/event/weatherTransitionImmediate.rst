weatherTransitionImmediate
====================================================================================================

The **weatherChangedImmediate** event occurs when the currently simulated weather is changed without transition. This can occur when going from an interior to an exterior in a new region, or while resting.

This can interrupt weather transitions, which means the weatherTransitionFinished event will not be triggered.

Event Data
----------------------------------------------------------------------------------------------------

to
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

tes3weather. The weather object that is the new current weather.

.. _`bool`: ../../lua/type/boolean.html
.. _`nil`: ../../lua/type/nil.html
.. _`table`: ../../lua/type/table.html
.. _`string`: ../../lua/type/string.html
.. _`number`: ../../lua/type/number.html
.. _`boolean`: ../../lua/type/boolean.html
.. _`function`: ../../lua/type/function.html
