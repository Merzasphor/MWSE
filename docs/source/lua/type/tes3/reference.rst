
Reference
========================================================

A *reference* is a sort of container structure for objects. It holds a base **object**, as well as various variables associated with that object that make it unique.

For example, many doors may share the same base object. However, each door reference might have a different owner, different lock/trap statuses, etc. that make the object unique.


Properties
--------------------------------------------------------

activationReference
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Reference`_. The reference that will activate this reference.

.. warning:: Needs confirmation.

attachments
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Table`_. Read-only. Attachments are extra bits of data that are associated with the reference. This property returns a table with all attachments on the reference.

Read the `Attachments`_ section below for more information.

.. warning:: An attachment may not actually exist for the object, and might need to be created.

data
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Table`_. This table represents persistent data that will be stored in the save, attached to the reference. The data in this table is serialized as a json string and stored as part of the save game.

destination
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Travel Destination`_. Read-only. The reference's associated travel destination node, if one is available. This is used on load doors.

id
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`String`_. Read-only. The object's unique id.

isRespawn
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Boolean`_. Read-only.

lockNode
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Lock Node`_. Read-only. The reference's associated lock node, if one is available.

mobile
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Mobile Actor`_. Read-only. The reference's associated mobile actor.

object
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Varies. Read-only. The base object that this reference contains.

objectType
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. Read-only. The object's `Object Type`_, which will always be 1380336978. This matches the constant ``tes3.objectType.reference``.

orientation
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Vector3`_. The object's orientation in the world.

position
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Vector3`_. The object's position in the world.


Attachments
--------------------------------------------------------
Attachments are how reference distinguish themselves.

.. warning:: TODO


.. _`Attachments`: #attachments

.. _`Boolean`: ../lua/boolean.html
.. _`Number`: ../lua/number.html
.. _`String`: ../lua/string.html
.. _`Table`: ../lua/table.html

.. _`Travel Destination`: travelDestination.html
.. _`Lock Node`: lockNode.html
.. _`Mobile Actor`: mobileActor.html
.. _`Vector3`: vector3.html

.. _`Object Type`: ../../../mwscript/references.html#object-types
