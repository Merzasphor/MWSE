barterOffer
====================================================================================================

This event is called when a potentially successful barter offer is made by the player. Potentially successful means both parties have the required funds to make the trade.

Event Data
----------------------------------------------------------------------------------------------------

mobile
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3mobileActor`_. Read-only. The mobile actor of the merchant the player is interacting with.

success
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`bool`_. Read-only. Whether the trade was accepted or not.

.. _`tes3mobileActor`: ../../lua/type/tes3mobileActor.html
.. _`bool`: ../../lua/type/boolean.html