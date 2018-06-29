
Region
====================================================================================================

A region is an area that helps to describe a collection of cells. Each exterior `Cell`_ can have an associated region.


Properties
----------------------------------------------------------------------------------------------------

**id** (`string`_, read-only)
    The object's unique id.

**name** (`string`_, read-only)
    The region's user-friendly name.

**objectType** (`number`_, read-only)
    The object's `objectType`_.

**sleepCreature** (`tes3leveledCreature`_, read-only)
    The creature that might ambush the player at this location.

**sounds** (`tes3iterator`_ of `tes3sound`_, read-only)
    The sounds attached to the region.

**sourceMod** (`string`_, read-only)
    The object's originating plugin filename.

**weather** (`tes3weather`_)
    The current weather in the region. Can be assigned a weather, or a weather index.

**weatherChanceAsh** (`number`_)
    Friendly access into **weatherChances** for ash weather.

**weatherChanceBlight** (`number`_)
    Friendly access into **weatherChances** for blight weather.

**weatherChanceBlizzard** (`number`_)
    Friendly access into **weatherChances** for blizzard weather.

**weatherChanceClear** (`number`_)
    Friendly access into **weatherChances** for clear weather.

**weatherChanceCloudy** (`number`_)
    Friendly access into **weatherChances** for cloudy weather.

**weatherChanceOvercast** (`number`_)
    Friendly access into **weatherChances** for overcast weather.

**weatherChanceRain** (`number`_)
    Friendly access into **weatherChances** for rain weather.

**weatherChances** (`table`_ of `number`_, read-only)
    A list of the 10 weather chances associated with the region.

**weatherChanceSnow** (`number`_)
    Friendly access into **weatherChances** for snow weather.

**weatherChanceThunder** (`number`_)
    Friendly access into **weatherChances** for thunder weather.


Functions
----------------------------------------------------------------------------------------------------

**changeWeather**
    Takes a weather index, and transitions weather to the new weather. This is equivalent of setting the **weather** property.

**randomizeWeather**
    Forces the region's weather to transition to a new weather, based on **weatherChances**.


.. _`boolean`: ../lua/boolean.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html
.. _`userdata`: ../lua/userdata.html

.. _`Cell`: cell.html

.. _`tes3leveledCreature`: leveledCreature.html
.. _`tes3iterator`: iterator.html
.. _`tes3sound`: sound.html
.. _`tes3weather`: weather.html
