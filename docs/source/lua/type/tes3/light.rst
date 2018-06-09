
Light
========================================================

This interface represents an light game object.

Properties
--------------------------------------------------------

.. list-table::
   :widths: 1 1 99
   :header-rows: 1

   * - **Property**
     - **Type**
     - **Description**
   *  - id
      - `string`_ (read-only)
      - The object's unique id.
   *  - objectType
      - `number`_ (read-only)
      - The object's `objectType`_
   *  - sourceMod
      - `string`_ (read-only)
      - The mod that this object is from.
   *  - model
      - `string`_ (writeable)
      - The object's model path, relative to 'Data Files/Meshes'.
   *  - boundingBox
      - `table`_ (read-only)
      - The two points representing the object's bounding box.
   *  - icon
      - `string`_ (writable)
      - The object's icon path, relative to 'Data Files/Icons'.
   *  - name
      - `string`_ (writable)
      - The object's name.
   *  - script
      - `userdata`_ (read-only)
      - The object's script id.
   *  - value
      - `number`_ (writeable)
      - The object's value in gold.
   *  - weight
      - `number`_ (writeable)
      - The object's weight.
   *  - time
      - `number`_ (read-only)
      - The time this light will last while equipped by the player.
   *  - sound
      - `number`_ (read-only)
      - The sound that loops while the light is equipped.
   *  - radius
      - `number`_ (read-only)
      - The radius in which the light will affect other objects.
   *  - canCarry
      - `boolean`_ (read-only)
      - Description Here
   *  - flickers
      - `boolean`_ (read-only)
      - Description Here
   *  - flickersSlowly
      - `boolean`_ (read-only)
      - Description Here
   *  - isDynamic
      - `boolean`_ (read-only)
      - Description Here
   *  - isFire
      - `boolean`_ (read-only)
      - Description Here
   *  - isNegative
      - `boolean`_ (read-only)
      - Description Here
   *  - isOffByDefault
      - `boolean`_ (read-only)
      - Description Here
   *  - pulses
      - `boolean`_ (read-only)
      - Description Here
   *  - pulsesSlowly
      - `boolean`_ (read-only)
      - Description Here

--------------------------------------------------------

.. _`boolean`: ../lua/boolean.rst
.. _`number`: ../lua/number.rst
.. _`string`: ../lua/string.rst
.. _`table`: ../lua/table.rst
.. _`userdata`: ../lua/userdata.rst
.. _`objectType`: _hidden/objectType.rst
