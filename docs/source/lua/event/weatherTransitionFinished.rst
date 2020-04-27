weatherTransitionFinished
====================================================================================================

The **weatherTransitionFinished** event occurs when the currently simulated weather finished transitioning to a new weather.

Weather will continue transitioning in interiors, and may finish while in an interior. The transition may be interrupted at any time by the weatherChangedImmediate event, and this finish event will not be triggered.

Event Data
----------------------------------------------------------------------------------------------------

to
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

tes3weather. The weather object that will be transitioned to.

.. _`bool`: ../../lua/type/boolean.html
.. _`nil`: ../../lua/type/nil.html
.. _`table`: ../../lua/type/table.html
.. _`string`: ../../lua/type/string.html
.. _`number`: ../../lua/type/number.html
.. _`boolean`: ../../lua/type/boolean.html
.. _`function`: ../../lua/type/function.html
