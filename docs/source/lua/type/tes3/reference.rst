
Reference
========================================================

A *reference* is a sort of container structure for objects. It holds a base **object**, as well as various variables associated with that object that make it unique.

For example, many doors may share the same base object. However, each door reference might have a different owner, different lock/trap statuses, etc. that make the object unique.


Properties
--------------------------------------------------------

attachments
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Table`_. Read-only. Attachments are extra bits of data that are associated with the reference. This property returns a table with all attachments on the reference.

Read the `Attachments`_ section below for more information.

.. warning:: An attachment may not actually exist for the object, and might need to be created.

id
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`String`_. Read-only. The object's unique id.

isRespawn
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Boolean`_. Read-only. The object's unique id.

object
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Varies. Read-only. The base object that this reference contains.

objectType
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. Read-only. The object's `Object Type`_, which will always be 1380336978. This matches the constant ``TES3.ObjectType.Reference``.


Attachments
--------------------------------------------------------
*To do.* 


.. _`Attachments`: #attachments

.. _`Boolean`: ../lua/boolean.html
.. _`Number`: ../lua/number.html
.. _`String`: ../lua/string.html
.. _`Table`: ../lua/table.html

.. _`Object Type`: ../../../../mwscript/references.html#object-types
