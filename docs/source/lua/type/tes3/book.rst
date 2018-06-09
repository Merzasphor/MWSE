
Book
========================================================

This interface represents an book game object.

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
   *  - enchantCapacity
      - `number`_ (writeable)
      - The object's maximum enchantment capacity.
   *  - enchantment
      - `userdata`_ (read-only)
      - The object's enchantment.
   *  - skill
      - `userdata`_ (read-only)
      - The skill this book teaches.
   *  - text
      - `string`_ (read-only)
      - The text of the book, including HTML tags.
   *  - type
      - `number`_ (read-only)
      - The object's bookType.

--------------------------------------------------------

.. _`boolean`: ../lua/boolean.rst
.. _`number`: ../lua/number.rst
.. _`string`: ../lua/string.rst
.. _`table`: ../lua/table.rst
.. _`userdata`: ../lua/userdata.rst
.. _`objectType`: _hidden/objectType.rst
