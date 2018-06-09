
Container
========================================================

This interface represents an container game object.

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
   *  - name
      - `string`_ (writable)
      - The object's name.
   *  - script
      - `userdata`_ (read-only)
      - The object's script id.
   *  - capacity
      - `number`_ (writeable)
      - The maximum carrying capacity of the container.
   *  - clone
      - `userdata`_ (read-only)
      - Description Here
   *  - container
      - `userdata`_ (read-only)
      - Description Here
   *  - isInstance
      - `boolean`_ (read-only)
      - Description Here
   *  - isRespawn
      - `boolean`_ (read-only)
      - Description Here
   *  - organic
      - `boolean`_ (read-only)
      - Description Here
   *  - respawns
      - `boolean`_ (read-only)
      - Description Here

--------------------------------------------------------

.. _`boolean`: ../lua/boolean.rst
.. _`number`: ../lua/number.rst
.. _`string`: ../lua/string.rst
.. _`table`: ../lua/table.rst
.. _`userdata`: ../lua/userdata.rst
.. _`objectType`: _hidden/objectType.rst
