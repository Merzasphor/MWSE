
Weather
====================================================================================================

A weather is attached to a region and provides shifts to color and sounds to accentuate the feel of the area.


Properties
----------------------------------------------------------------------------------------------------

**ambientDayColor** (`tes3vector3`_, read-only)
    The weather's ambient color during the day. Available for all weathers.

**ambientLoopSound** (`tes3sound`_)
    The sound used for the weather. Available for all weathers.

**ambientLoopSoundId** (`string`_)
    The sound ID used for the weather. Available for all weathers.

**ambientNightColor** (`tes3vector3`_, read-only)
    The weather's ambient color during the night. Available for all weathers.

**ambientPlaying** (`boolean`_, read-only)
    Determines if the weather's ambient sound is playing. Available for all weathers.

**ambientSunriseColor** (`tes3vector3`_, read-only)
    The weather's ambient color during sunrise. Available for all weathers.

**ambientSunsetColor** (`tes3vector3`_, read-only)
    The weather's ambient color during sunset. Available for all weathers.

**blightDiseaseChance** (`number`_)
    The chance of contracting a blight disease. Available only for the *blight* weather.

**blightDiseases** (`tes3iterator`_ of `tes3spell`_, read-only)
    A list of potential blight diseases. Available only for the *blight* weather.

**cloudsMaxPercent** (`number`_)
    The maximum percentage used for cloud cover. Available for all weathers.

**cloudsSpeed** (`number`_)
    The movement speed for clouds. Available for all weathers.

**cloudTexture** (`string`_)
    The texture used for the clouds. Available for all weathers.

**controller** (`tes3weatherController`_)
    The movement speed for clouds. Available for all weathers.

**flashDecrement** (`number`_)
    Research required. Available for the *thunder* weather.

**fogDayColor** (`tes3vector3`_, read-only)
    The weather's fog color during the day. Available for all weathers.

**fogNightColor** (`tes3vector3`_, read-only)
    The weather's fog color during the night. Available for all weathers.

**fogSunriseColor** (`tes3vector3`_, read-only)
    The weather's fog color during sunrise. Available for all weathers.

**fogSunsetColor** (`tes3vector3`_, read-only)
    The weather's fog color during sunset. Available for all weathers.

**glareView** (`number`_)
    Requires research. Available for all weathers.

**index** (`number`_, read-only)
    The index for the weather. Relates to the values in ``tes3.weather``. Available for all weathers.

**landFogDayDepth** (`number`_)
    Requires research. Available for all weathers.

**landFogNightDepth** (`number`_)
    Requires research. Available for all weathers.

**maxParticles** (`number`_)
    The max number of rain or snow particles. Available for the *rain*, *snow*, and *thunder* weathers.

**particleEntranceSpeed** (`number`_)
    How fast the particles enter the scene. Available for the *rain*, *snow*, and *thunder* weathers.

**particleHeightMax** (`number`_)
    How high the particles are when they enter the scene. Available for the *rain*, *snow*, and *thunder* weathers.

**particleHeightMin** (`number`_)
    How low the particles are when they exit the scene. Available for the *rain*, *snow*, and *thunder* weathers.

**particleRadius** (`number`_)
    How wide out the particles are generated. Available for the *rain*, *snow*, and *thunder* weathers.

**rainActive** (`boolean`_, read-only)
    Determines if it is actively raining. Available for the *rain* and *thunder* weathers.

**rainLoopSound** (`tes3sound`_)
    The sound used, determined by **rainLoopSoundId**. Available for the *rain* and *thunder* weathers.

**rainLoopSoundId** (`string`_)
    The sound ID used for the **rainLoopSound**. Available for the *rain* and *thunder* weathers.

**skyDayColor** (`tes3vector3`_, read-only)
    The weather's sky color during the day. Available for all weathers.

**skyNightColor** (`tes3vector3`_, read-only)
    The weather's sky color during the night. Available for all weathers.

**skySunriseColor** (`tes3vector3`_, read-only)
    The weather's sky color during sunrise. Available for all weathers.

**skySunsetColor** (`tes3vector3`_, read-only)
    The weather's sky color during sunset. Available for all weathers.

**soundAmbientLoops** (`boolean`_)
    Determines if ambient sound loops. Available for all weathers.

**sunDayColor** (`tes3vector3`_, read-only)
    The weather's sun color during the day. Available for all weathers.

**sundiscSunsetColor** (`tes3vector3`_, read-only)
    The weather's sun disc color. Available for all weathers.

**sunNightColor** (`tes3vector3`_, read-only)
    The weather's sun color during the night. Available for all weathers.

**sunSunriseColor** (`tes3vector3`_, read-only)
    The weather's sun color during sunrise. Available for all weathers.

**sunSunsetColor** (`tes3vector3`_, read-only)
    The weather's sun color during sunset. Available for all weathers.

**threshold** (`number`_)
    A threshold for triggering a weather effect. Available for the *ash*, *blight*, *blizzard*, *rain*, *snow*, and *thunder* weathers.

**thunderFrequency** (`number`_)
    How often a thunder storm will trigger. Available for the *thunder* weather.

**thunderSound1** (`tes3sound`_)
    The sound used, determined by **thunderSound1Id**. Available for the *thunder* weather.

**thunderSound1Id** (`string`_)
    The sound ID used for the **thunderSound1**. Available for the *thunder* weather.

**thunderSound2** (`tes3sound`_)
    The sound used, determined by **thunderSound2Id**. Available for the *thunder* weather.

**thunderSound2Id** (`string`_)
    The sound ID used for the **thunderSound2**. Available for the *thunder* weather.

**thunderSound3** (`tes3sound`_)
    The sound used, determined by **thunderSound3Id**. Available for the *thunder* weather.

**thunderSound3Id** (`string`_)
    The sound ID used for the **thunderSound3**. Available for the *thunder* weather.

**thunderSound4** (`tes3sound`_)
    The sound used, determined by **thunderSound4Id**. Available for the *thunder* weather.

**thunderSound4Id** (`string`_)
    The sound ID used for the **thunderSound4**. Available for the *thunder* weather.

**thunderSoundCount** (`number`_)
    The number of sound effects used for a thunder storm. Available for the *thunder* weather.

**thunderThreshold** (`number`_)
    A threshold for triggering a thunder effect. Available for the *thunder* weather.

**transitionDelta** (`number`_)
    Provides timing information for transitions between day, night, sunrise, and sunset. Available for all weathers.

**underwaterSoundState** (`boolean`_, read-only)
    Determines underwater sound state. Available for all weathers.

**windSpeed** (`number`_)
    The movement speed for the weather's wind. Available for all weathers.


.. _`boolean`: ../lua/boolean.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html
.. _`userdata`: ../lua/userdata.html

.. _`tes3iterator`: iterator.html
.. _`tes3sound`: sound.html
.. _`tes3spell`: spell.html
.. _`tes3vector3`: vector3.html
.. _`weatherController`: weatherController.html
