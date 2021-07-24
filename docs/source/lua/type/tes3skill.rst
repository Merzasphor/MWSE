tes3skill
====================================================================================================

A skill object.

Properties
----------------------------------------------------------------------------------------------------

`actions`_ (`table`_)
    Read-only. A table with 4 values. The amount of experience an action (use of skill) awards.

`attribute`_ (`number`_)
    Read-only. Skill's governing attribute. Maps to tes3.attribute.* constants.

`blocked`_ (`boolean`_)
    The blocked state of the object.

`deleted`_ (`boolean`_)
    Read-only. The deleted state of the object.

`disabled`_ (`boolean`_)
    Read-only. The disabled state of the object.

`iconPath`_ (`string`_)
    Read-only. The path to the icon for the skill.

`id`_ (`string`_)
    Read-only. The unique identifier for the object.

`modified`_ (`boolean`_)
    The modification state of the object since the last save.

`name`_ (`string`_)
    Read-only. The player-facing name of the skill.

`objectFlags`_ (`number`_)
    Read-only. The raw flags of the object.

`objectType`_ (`number`_)
    Read-only. The type of object. Maps to values in tes3.objectType.

`persistent`_ (`boolean`_)
    The persistent flag of the object.

`sourceMod`_ (`string`_)
    Read-only. The filename of the mod that owns this object.

`sourceless`_ (`boolean`_)
    The soruceless flag of the object.

`specialization`_ (`number`_)
    The specialization in which the skill belongs. Maps to tes3.specialization.* constants.

`supportsLuaData`_ (`boolean`_)
    If true, references of this object can store temporary or persistent lua data.

.. toctree::
    :hidden:

    tes3skill/actions
    tes3skill/attribute
    tes3skill/blocked
    tes3skill/deleted
    tes3skill/disabled
    tes3skill/iconPath
    tes3skill/id
    tes3skill/modified
    tes3skill/name
    tes3skill/objectFlags
    tes3skill/objectType
    tes3skill/persistent
    tes3skill/sourceMod
    tes3skill/sourceless
    tes3skill/specialization
    tes3skill/supportsLuaData

.. _`actions`: tes3skill/actions.html
.. _`attribute`: tes3skill/attribute.html
.. _`blocked`: tes3skill/blocked.html
.. _`deleted`: tes3skill/deleted.html
.. _`disabled`: tes3skill/disabled.html
.. _`iconPath`: tes3skill/iconPath.html
.. _`id`: tes3skill/id.html
.. _`modified`: tes3skill/modified.html
.. _`name`: tes3skill/name.html
.. _`objectFlags`: tes3skill/objectFlags.html
.. _`objectType`: tes3skill/objectType.html
.. _`persistent`: tes3skill/persistent.html
.. _`sourceMod`: tes3skill/sourceMod.html
.. _`sourceless`: tes3skill/sourceless.html
.. _`specialization`: tes3skill/specialization.html
.. _`supportsLuaData`: tes3skill/supportsLuaData.html

Methods
----------------------------------------------------------------------------------------------------

`__tojson`_ (`string`_)
    Serializes the object to json.

.. toctree::
    :hidden:

    tes3skill/__tojson

.. _`__tojson`: tes3skill/__tojson.html

.. _`boolean`: ../../lua/type/boolean.html
.. _`number`: ../../lua/type/number.html
.. _`string`: ../../lua/type/string.html
.. _`table`: ../../lua/type/table.html
