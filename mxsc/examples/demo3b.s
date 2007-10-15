Begin demoMain44 start


main:


set isSneaking to GetPCSneaking()

comp stillWaiting,1
je waitForInput
	comp isSneaking,1
	jne done
		ShowInputBox("Type in demo1 or demo2","Ok")
		set stillWaiting to 1

waitForInput:
	set buttonPressed to GetButtonPressed()
		comp buttonPressed,0
		jne done
			comp testedInput,1
			je noMatch
			set testedInput to 1
			set result to GetTextInput()
	    	comp result,"demo1"
			jne testForDemo2
                set thisScript to GetScript("demoMain44")
				set demo1Script to GetScript("weaponCreationDemo44")
				StartScript(demo1Script,1)
                StopScript(thisScript,1)
				jmp done
			testForDemo2:
				comp result,"demo2"
				jne noMatch
                set thisScript to GetScript("demoMain44")
    			set demo2Script to GetScript("keyPressDemo44")
   				StartScript(demo2Script,1)
				StopScript(thisScript,1)
				jmp done
			noMatch:
				comp isSneaking,0
				jne done
				set stillWaiting to 0
				set testedInput to 0
done:
End
