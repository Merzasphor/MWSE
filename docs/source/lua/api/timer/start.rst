timer.start
====================================================================================================

Creates a timer.

Returns
----------------------------------------------------------------------------------------------------

`mwseTimer`_.

Parameters
----------------------------------------------------------------------------------------------------

Accepts parameters through a table with the given keys:

type (`number`_)
    Optional. Defaults to timer.simulate.

duration (`number`_)
    Duration of the timer. The method of time passing depends on the timer type.

callback (`function`_)
    The callback function that will execute when the timer expires.

iterations (`number`_)
    Default: ``1``. The number of iterations to run.

Examples
----------------------------------------------------------------------------------------------------

Show a Countdown Message
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

In this example, whenever the player activates an item they will be shown a 10 second countdown. Because it is a simulation timer, it will not tick down while the menu is open, nor is it sensitive to the game timescale/clock.

.. code-block:: lua

    local timeLeft = 0;

    local function onTimerExpired() 
        timeLeft = timeLeft - 1;
        tes3.messageBox("%d seconds left", timeLeft);
    end

    local function onActivate(eventData)
        if (eventData.activator == tes3.player) then
            timeLeft = 10;
            timer.start{ duration = 1, iterations = 10, type = timer.simulate, callback = onTimerExpired }
        end
    end
    event.register("activate", onActivate)


.. _`bool`: ../../../lua/type/boolean.html
.. _`nil`: ../../../lua/type/nil.html
.. _`table`: ../../../lua/type/table.html
.. _`string`: ../../../lua/type/string.html
.. _`number`: ../../../lua/type/number.html
.. _`boolean`: ../../../lua/type/boolean.html
.. _`function`: ../../../lua/type/function.html
