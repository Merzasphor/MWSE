
xGetOwnerInfo
========================================================

**Parameters:**

- *None*

**Returned:**

- ``string`` **owner**: The object ID of the NPC or faction owner of the object.
- ``long`` or ``string`` **condition**: If owned by a faction, this is a ``long`` indicating the required rank. If this is an NPC this value is either 0, or a ``string`` for the global variable to check.
- ``long`` **type**: The `Object Type`_ of **owner**, either NPC or Faction.

Ownership of entities in the world in Morrowind is comprised of two parts: **owner** and **condition** (this can specify when the player being detected taking or using the entity is not considered a crime). These work in two modes:

1. The first is where **owner** is an NPC ID, and **condition** is a global variable - while the global var is set to a non-zero value, activating the entity is never considered a crime.

2. In the second mode, **owner** is a faction id, and **condition** is a rank within it. If the player has equal (or higher) rank in that faction, then he can be seen using or taking the entity without it being a crime. This is how supply chests and beds in guildhalls work (their rank requirement is the minimal rank).

This function allows getting full ownership information of an entity: both parts, whatever they may be (as well as what mode is used for the ownership). It is more in-depth than the `xGetOwner`_ function, which does not fully handle faction ownership or ownership with a global var requirement.

.. tip:: If the returned **condition** is a global variable, it can be used with `xGetGlobal`_ and `xSetGlobal`_.

Example: Boobytrapped Mages Guild and Telvanni faction containers
-----------------------------------------------------------------

::

  begin boobycontainers
  ;if the player tries to open a container owned by either MG or GHT that he
  ;doesn't have the required rank to legally take items from, then instead of
  ;the container opening, the player will be zapped.
  
  short framecount
  short temp
  short player_rank
  long pctarget
  long type
  long own_id
  long own_cond
  
  if ( MenuMode )
      return
  endif
  
  set framecount to ( framecount + 1 )
  if ( framecount < 30 )
      return
  endif
  set framecount to 0
  
  setx pctarget to xGetPCTarget
  ifx ( pctarget )
      setx type to pctarget->xRefType
      if ( type != 1414418243 ) ;if it's not a container ref type
          return
      endif
      setx type own_id own_cond to pctarget->xGetOwnerInfo
      if ( type != 1413693766 ) ;if it's not a faction ownership type
          return
      endif
  
      setx temp to xStringCompare own_id "Mages Guild" ;if the owner of the container is MG, temp will be 0
      ifx ( temp ) ;not MG
          setx temp to xStringCompare own_id "Telvanni"
          ifx ( temp )
              ;owner is not MG and not GHT, either
              return
          endif
          ;owner is GHT
          set player_rank to GetPCRank "Telvanni" ;doesn't hurt here, but remember 0 and -1 are both possible return values of this function
      else
          ;owner is MG
          set player_rank to GetPCRank "Mages Guild"
      endif
  
      set temp to 0
      if ( player_rank >= own_cond ) ;player is of the right rank in whichever faction to be able to claim the container's contents
          set temp to 1
      endif
      ifx ( temp )
          ;originally, there was only a return here.
          ;the following block is needed in case activation was already blocked by the OnActivate call (the 2nd instance of it, now) on a previous run, but the player since raised in rank enough; without this line, the player will no longer get the trap, but the container may not open (as it normally should), either
          xSetRef pctarget
          set temp to OnActivate
          ifx ( temp )
              pctarget->Activate
          endif
          return
      endif
  
      ;if reached here, player doesn't meet rank requirement
      xSetRef pctarget
      if ( OnActivate ) ;merely CALLING this function will block any further normal activation attempts. it makes the object's activation temporarily only possible through the Activate function
          MessageBox "A trap is sprung!"
          set temp to - ( player->GetFatigue + 1 )
          player->ModCurrentFatigue temp ;makes player fall down ("knocked out") briefly - causes current fatigue to be -1
          player->PlaySound "destruction hit"
      endif
  endif
  
  end

Example: World entity destruction with ownership penalty
--------------------------------------------------------

::

  begin entitydestruction
  
  ;allows the player to destroy objects in the world by striking at them with
  ;a weapon (or barehanded). but if the player wouldn't have been (legally) allowed to pick up that
  ;object, he gets a bounty as if he stole it (with respect to the GMST that controls the bounty amount for theft).
  
  ;the value of containers is assumed to be only the value of all the items within them.
  ;the value of doors is assumed to be 100 septims, and of activators, 200 septims.
  
  ;this script doesn't take into account whether player is detected (sneaking, invisible),
  ;etc. well, he's doing a loud and incriminating action, anyway.
  ;it doesn't do faction expulsion, either...
  
  short framecount
  short update_col
  long temp
  long pctarget
  long type
  long value
  long nextref
  long invvalue
  long invcount
  long ownerid
  long condition
  float glob
  ;note: in this script, existing vars are often reused, so that a bunch of
  ;vars are also used for other purposes than their name suggests.
  
  ;for example, because it is the only float and there's no problem with
  ;overwriting it, 'glob' is used to (temporarily) hold both the result of
  ;a reading of a global var, and also of reading a float GMST. 
  
  
  if ( MenuMode )
      return
  endif
  
  set framecount to ( framecount + 1 )
  if ( framecount < timing1 )
      return
  endif
  set framecount to 0
  
  if ( player->GetWeaponDrawn == 0 )
      return
  endif
  
  if ( player->GetWeaponType == 0 )
      return ;ignore lockpicks and probes; unfortuantely this also applies to Short Blades...
  endif
  
  setx temp to xKeyPressed 1 ;left mouse button
  setx pctarget to xGetPCTarget
  
  setx temp to xAnd temp pctarget;if player looking at something AND pressing LMB, temp will be 1
  
  if ( temp == 0 )
      return
  endif
  
  ;you should also be able to just use 'if ( player->GetSoundPlaying "weapon swish" )' instead, to check
  ;if the player is making a strike, at least on machines where GetSoundPlaying works fine.
  ;you'd also be able to automatically support all swinging weapons, then.
  
  setx type to pctarget->xRefType
  set value to 0
  set nextref to 0
  if ( type == 1598246990 ) ;NPC
      return
  elseif ( type == 1095062083 ) ;creature
      return
  elseif ( type == 1414418243 ) ;container
      set nextref to 1 ;flag that we need to tally the container's total value 
      set update_col to 1
  elseif ( type == 1380929348 ) ;door      (this script allows player to destroy load doors too, careful)
      set value to 100
      set update_col to 1
  elseif ( type == 1230259009 ) ;activator
      set value to 200
      set update_col to 1
  endif
  
  
  set invvalue to 0
  set invcount to 0
  setx type ownerid condition to pctarget->xGetOwnerInfo
  if ( type == 0 ) ;no owner
      set value to 1 ;in case 'value' wasn't determined yet - there's no need to calculate it below
  elseif ( type == 1598246990 ) ;NPC owner
      set invvalue to 1 ;(temp flag)
  elseif ( type == 1413693766 ) ;faction owner
      set invcount to 1 ;(temp flag)
  else
      MessageBox "ERROR?!" ;this should never happen
      return
  endif
  
  ifx ( invvalue ) ;NPC owner
      setx temp to xGetRef ownerid
      ifx ( temp )
          xSetRef temp
          set temp to GetHealth
      else
          set temp to 0 ;if can't find the owner, assume he's dead
      endif
      if ( temp <= 0 ) ;if he's dead, then it's all legal...
          set type to 0 ;no ownership
          set value to 1 ;no need to calculate 'value'
      else
          ifx ( condition )
              setx temp glob to xGetGlobal condition
              ifx ( temp ) ;got the global successfully
                  ifx ( glob ) ;if it had a true value
                      ;then player is allowed to take/use the target
                      set type to 0
                      set value to 1
                  endif
              else
                  MessageBox "Got a problem..."
              endif
          endif
      endif
  endif
  
  ifx ( invcount ) ;faction owner
      ;setx temp to xGetPCRank ownerid ;(this function doesn't exist yet)
      set temp to 0 ;temp filler since can't use above line. this makes the player count as of the lowest rank in the faction.
  
      if ( temp >= condition ) ;if player is of the required rank or above...
          ;then it's legal
          set type to 0
          set value to 1
      endif
  endif
  
  
  ifx ( value )
  else
      ;if value is still 0, we're looking at an item (or a container)
      
      ifx ( nextref ) ;container
          set nextref to 0
          setx temp invcount temp invvalue temp temp nextref to pctarget->xContentList nextref ;values we don't care about get stored in temp and overwritten
          whilex ( invcount ) ;might take a short... while, if container has tons of stacks in it
              set temp to ( invcount * invvalue )
              set value to ( value + temp )
              ifx ( nextref )
                  setx temp invcount temp invvalue temp temp nextref to pctarget->xContentList nextref
              else
                  set invcount to 0 ;break the loop
              endif
          endwhile
      else ;looking at an item
          setx value to pctarget->xGetValue
      endif
      
  endif
  
  pctarget->Disable ;'destroy' the target
  player->PlaySound "critical damage"
  if ( type ) ;if it was determined to be illegal...
      setx glob to xGetGS 1173 ;GMST fCrimeStealing (default: 1.0)
      set value to ( value * glob )
      ModPCCrimeLevel value
  endif
  
  if ( update_col )
      set update_col to 0
      ;in the event that that the player just disable'd a door or a large
      ;container or activator, its collision will normally remain until the
      ;cell is re-loaded, and the player won't be able to go through th
      ;space it used to occupy.
      ;this part of the script solves that issue, making use of the fact that
      ;the FixMe function also reloads some stuff in the active cell, such as
      ;object coliisions. 
  
      ;unfortunately, it also seems to always teleport the player, and,
      ;ironically, sometimes cause him to get stuck. therefore, this line is commented out.
  
      ;FixMe
  endif
  
  end

.. _`Object Type`: ../references.html#record-types
.. _`xGetOwner`: xGetOwner.html
.. _`xGetGlobal`: xGetGlobal.html
.. _`xSetGlobal`: xSetGlobal.html
