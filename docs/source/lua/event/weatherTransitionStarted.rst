weatherTransitionStarted
====================================================================================================

The **weatherTransitionStarted** event occurs when the currently simulated weather has started to gradually transition to a new weather. This can occur when moving between regions, or when the weather cycles.

Weather will not start transitioning in interiors, but will continue transitioning, and may finish while in an interior. The transition may be interrupted at any time by the weatherChangedImmediate event, and the weatherTransitionFinished event will not occur.

Event Data
----------------------------------------------------------------------------------------------------

to
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

tes3weather. The weather object that will be transitioned to.

from
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

tes3weather. Read-only. The weather object that is the current weather.

.. _`bool`: ../../lua/type/boolean.html
.. _`nil`: ../../lua/type/nil.html
.. _`table`: ../../lua/type/table.html
.. _`string`: ../../lua/type/string.html
.. _`number`: ../../lua/type/number.html
.. _`boolean`: ../../lua/type/boolean.html
.. _`function`: ../../lua/type/function.html
