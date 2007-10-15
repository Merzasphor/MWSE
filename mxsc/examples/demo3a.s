Begin weaponCreationDemo44


comp weaponCreated,1
je waitingOnKeypress


comp startMessageDisplayed,1
je waitingOnButtonpress



ShowInputBox("What is the name of your new blade?","Ok")
set startMessageDisplayed to 1

waitingOnButtonpress:
set buttonPressed to GetButtonPressed()
comp buttonPressed,0
jne done



set weaponName to GetTextInput()
set oldWeapon to GetTemplate("steel saber")
set newWeapon to CreateWeapon(oldWeapon)
SetTemplateName(newWeapon,weaponName)
set playerTemplate to GetTemplate("player")
AddItem(playerTemplate,newWeapon,1)
DisplayMessage("Your new blade is in your inventory.  To increase it's slash damage, press the S key.  The neat thing about created items is that any stat changes made to them are permanent.  To end this demo, press B.  Then press the sneak key again to go back to the main menu.")
set weaponCreated to 1
set slashKeyControl to 1

waitingOnKeypress:
set keyPressed to KeyPressed(31)
comp keyPressed,1
jne nextTest

comp slashKeyControl,0
jne done
DisplayMessage("Slash damage increased")
set currentMin to GetSlashMin(newWeapon)
set currentMax to GetSlashMax(newWeapon)
inc currentMin,10
inc currentMax,10
SetSlashDamage(newWeapon,currentMin,currentMax)
set slashKeyControl to 1
jmp done



nextTest:
set keyPressed to KeyPressed(48)
comp keyPressed,1
jne keyNotPressed
comp doneKeyControl,0
jne done
DisplayMessage("Going back")
set mainScript to GetScript("demoMain44")
set thisScript to GetScript("weaponCreationDemo44")
StartScript(mainScript,1)
StopScript(thisScript,1)
set doneKeyControl to 1
jmp done



keyNotPressed:
set slashKeyControl to 0
set doneKeyControl to 0


done:
End




Begin keyPressDemo44
comp introShown,1
je getToIt
DisplayMessage("Press the U key to increase the prices of all weapons.  Price the L key to decrease the prices of all weapons.  Press the B key to end this demo")
set introShown to 1
getToIt:
;The user presses the "U" key
set uPressed to KeyPressed(22)
comp uPressed,1
jne nextCheck
comp uKeyControl,0
jne done
DisplayMessage("You pressed the U key...increasing weapon values")
set weaponValue to GetWeaponMultiplier()
inc weaponValue,.5
SetWeaponMultiplier(weaponValue)
set uKeyControl to 1
jmp done

nextCheck:
set lPressed to KeyPressed(38)
comp lPressed,1
jne nextTest
comp lKeyControl,0
jne done
DisplayMessage("You pressed the L key...lowering weapon values")
set weaponValue to GetWeaponMultiplier()
inc weaponValue,-.5
SetWeaponMultiplier(weaponValue)
set lKeyControl to 1
jmp done

nextTest:
set keyPressed to KeyPressed(48)
comp keyPressed,1
jne keyNotPressed
comp doneKeyControl,0
jne done
DisplayMessage("Going back")
set mainScript to GetScript("demoMain44")
set thisScript to GetScript("weaponCreationDemo44")
StartScript(mainScript,1)
StopScript(thisScript,1)
set doneKeyControl to 1
jmp done

keyNotPressed:
set doneKeyControl to 0
set uKeyControl to 0
set lKeyControl to 0

done:

End
