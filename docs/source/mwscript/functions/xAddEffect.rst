
xAddEffect
========================================================

:Parameters:

    - :code:`long` **type**: Record type to target. See `Record Types`.
    - :code:`string` **id**: ID of the spell or enchantment to modify.
    - :code:`long` **effectId**: ID of the effect to add.
    - :code:`long` **skillAttributeId**: ID of the skill or attribute to use (only used by drain/absorb/damage/fortify/restore skill/attribute effects - ignored otherwise).
    - :code:`long` **rangeType**: New range type. 0 = SELF, 1 = TOUCH, 2 = TARGET.
    - :code:`long` **area**: Area of effect.
    - :code:`long` **duration**: Duration in seconds.
    - :code:`long` **magMin**: Minimum magnitude.
    - :code:`long` **magMax**: Maximum magnitude.

:Returned:

    - :code:`long` **success**: 1 if the effect was added, or 0 if it wasn't.

Adds a new effect to the given spell or enchantment.


Example
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

::

  begin test_xAddEffect
  
  long id
  long type
  long effect
  long skill
  long range
  long area
  long duration
  long min_mag
  long max_mag
  
  long i
  long magic_types
  
  short pass
  
  StopScript test_xAddEffect
  
  set magic_types to test_magic_types
  
  setx i to xGetArraySize magic_types
  whilex ( i )
      set i to i - 1
  
      setx type to xGetArrayValue magic_types i
      setx id to xStringBuild "test_%L" type
  
      ; specify effect info
      set effect to 17
      set skill to 1
      set range to 2
      set area to 3
      set duration to 4
      set min_mag to 5
      set max_mag to 6
  
      ; add the effect
      setx pass to xAddEffect type id effect skill range area duration min_mag max_mag
      ifx ( pass )
          ; verify effect info
          setx effect skill range area duration min_mag max_mag to xGetEffectInfo type id 2
  
          set pass to 0
          if ( effect != 17 )
          elseif ( skill != 1 )
          elseif ( range != 2 )
          elseif ( area != 3 )
          elseif ( duration != 4 )
          elseif ( min_mag != 5 )
          elseif ( max_mag != 6 )
          else
              set pass to 1
          endif
      endif
      xLogMessage "[PASS=%d] test_xAddEffect -> xAddEffect %L" pass type
  
      ; clear the added effect
      setx pass to xDeleteEffect type id 2
      ifx ( pass )
          setx effect to xGetEffectInfo type id 2
          if ( effect != -1 )
              set pass to 0
          endif
      endif
      xLogMessage "[PASS=%d] test_xAddEffect -> xDeleteEffect %L" pass type
  endwhile
  
  end
