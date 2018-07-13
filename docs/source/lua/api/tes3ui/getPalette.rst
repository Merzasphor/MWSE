
tes3ui.getPalette
====================================================================================================

Gets a standard palette colour.

.. code-block:: lua

    text.color = tes3ui.getPalette("answer_color")

**Parameters:**

- `string`_ **name**
    The name of the palette colour.
    
**Returns:**

- `table`_ (float[3])
    An array containing the RGB colour values, in the range [0.0, 1.0].

Standard colour names:
    - black_color
    - white_color
    - normal_color
    - normal_over_color
    - normal_pressed_color
    - active_color
    - active_over_color
    - active_pressed_color
    - disabled_color
    - disabled_over_color
    - disabled_pressed_color
    - link_color
    - link_over_color
    - link_pressed_color
    - journal_link_color
    - journal_link_over_color
    - journal_link_pressed_color
    - journal_topic_color
    - journal_topic_over_color
    - journal_topic_pressed_color
    - journal_finished_quest_color
    - journal_finished_quest_over_color
    - journal_finished_quest_pressed_color
    - answer_color
    - answer_over_color
    - answer_pressed_color
    - header_color
    - notify_color
    - big_normal_color
    - big_normal_over_color
    - big_normal_pressed_color
    - big_link_color
    - big_link_over_color
    - big_link_pressed_color
    - big_answer_color
    - big_answer_over_color
    - big_answer_pressed_color
    - big_header_color
    - big_notify_color
    - background_color
    - focus_color
    - health_npc_color
    - health_color
    - magic_color
    - fatigue_color
    - misc_color
    - weapon_fill_color
    - magic_fill_color
    - positive_color
    - negative_color
    - count_color
            

.. _`string`: ../../type/lua/string.html
.. _`table`: ../lua/table.html
