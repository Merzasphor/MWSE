/*
Copyright Ryan Kluzak

This file is part of mxsc.

    mxsc is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    mxsc is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with mxsc.  If not, see <http://www.gnu.org/licenses/>.
*/

.import("enki.BaseParser");
.import("enki.types");
.import("enki.IParser");
.import("compiler");
.import("std.conv");
.define("String","any","true","any");

Newline
	::= #0A | #0D;

Tab
	::= #09;

Space
	::= #20;
WS
	::= (Space | Tab) {WS};


SmallLetter
	::= "a" | "b" | "c" | "d" | "e" | "f" | "g" | "h" | "i" | "j" | "k" | "l" | "m" | "n" | "o" |
		"p" | "q" | "r" | "s" | "t" | "u" | "v" | "w" | "x" | "y" | "z";

LargeLetter
	::= "A" | "B" | "C" | "D" | "E" | "F" | "G" | "H" | "I" | "J" | "K" | "L" | "M" | "N" | "O" |
		"P" | "Q" | "R" | "S" | "T" | "U" | "V" | "W" | "X" | "Y" | "Z";


Digit
	::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9";


Label 
	= int newLabel(labelId)
	::= {Newline | Space | Tab}  Identifier:labelId ":" {Space | Tab | Newline};


Comment
	= int foundComment()
	::= {Newline | Space | Tab}  ";" {any} Newline;


Stringvalue
	= char[] string
	::= ("\"" {any} "\""):string;


StringParameter
	= Parameter newStringParameter(param)
	::= Stringvalue:param | Identifier:param;


LongParameter
	= Parameter newLongParameter(param)
	::= Longstring:param | Identifier:param;


FloatParameter
	= Parameter newFloatParameter(param)
	::= Floatstring:param | Identifier:param;



Longstring
	= char[] longValue
	::= (["-"](Digit {Digit})):longValue;


Floatstring
	= char[] floatVal
	::= (["-"]((Digit {Digit}) "." (Digit {Digit}))):floatVal;


Longvalue
	= int toLong(longValue)
	::= (["-"](Digit {Digit})):longValue;

Floatvalue
	= float toFloat(floatValue)
	::= (["-"] ((Digit {Digit}) "." (Digit {Digit}))):floatValue |
  		(["-"] ("." (Digit {Digit}))):floatValue;


Identifier
	= char[] ident
	::=  ((SmallLetter | LargeLetter)  {("_" (SmallLetter | LargeLetter | Digit)) | (SmallLetter | LargeLetter | Digit)}):ident;


Script
	::= ( [Comment] Header {Comment  | Label | ([Label] Code)} Footer [Comment]) {Newline | Space | Tab} {Script};


Header
	= int beginScript(scriptName,startScript)
	::= {Newline | Space | Tab}  "Begin" WS Identifier:scriptName [WS "start"]:startScript [WS] Newline {Newline};



Footer
	= int endScript()
	::= {Newline | Space | Tab} "End";


Code
	::= {Newline | Space | Tab} (Set | Add | Mul | Comp | Jump | Function | Inc) [Comment] {WS} Newline {Newline};


Comp
	::= (Compvarvar | Compvarfloat | Compvarlong | Compvarstring);




Jump
	::= JNE | JMP | JE | JG | JL;

JNE
	= int MATCH_jne(labelName)
	::= "jne" WS Identifier:labelName;


JG
	= int MATCH_jg(labelName)
	::= "jg" WS Identifier:labelName;


JL
	= int MATCH_jl(labelName)
	::= "jl" WS Identifier:labelName;


JE
	= int MATCH_je(labelName)
	::= "je" WS Identifier:labelName;

JMP
	= int MATCH_jmp(labelName)
	::= "jmp" WS Identifier:labelName;



Compvarvar
	= int MATCH_compVarVar(ident1,ident2)
	::= "comp" WS Identifier:ident1 [WS] "," [WS] Identifier:ident2;

Compvarstring
	= int MATCH_compVarString(ident1,stringVal)
	::= "comp" WS Identifier:ident1 [WS] "," [WS] Stringvalue:stringVal;

Compvarlong
	= int MATCH_compVarLong(ident1,longVal)
	::= "comp" WS Identifier:ident1 [WS] "," [WS] Longvalue:longVal;


Compvarfloat
	= int MATCH_compVarFloat(ident1,floatVal)
	::= "comp" WS Identifier:ident1 [WS] "," [WS] Floatvalue:floatVal;


Set
	::= ( SetToResult | SetToVar | SetToFloat | SetToLong | SetToString);

SetToLong
	= int MATCH_setToLong(ident,longVal)
	::= "set" WS Identifier:ident WS "to" WS Longvalue:longVal;

SetToVar
	= int MATCH_setToVar(ident1,ident2)
	::= "set" WS Identifier:ident1 WS "to" WS Identifier:ident2;

SetToFloat
	= int MATCH_setToFloat(ident,floatVal)
	::= "set" WS Identifier:ident WS "to" WS Floatvalue:floatVal;


SetToString
	= int MATCH_setToString(ident,stringVal)
	::= "set" WS Identifier:ident WS "to" WS Stringvalue:stringVal;


SetToResult
	= int MATCH_setToResult(ident,type)
	::= "set" WS Identifier:ident WS "to" WS Function:type;


Inc 
	::= (IncVarByVar | IncVarByFloat | IncVarByLong);
	
	
IncVarByVar
	= int MATCH_incVarByVar(ident1,ident2)
	::= "inc" WS Identifier:ident1 [WS] "," [WS] Identifier:ident2;


IncVarByLong
	= int MATCH_incVarByLong(ident1,longVal)
	::= "inc" WS Identifier:ident1 [WS] "," [WS] Longvalue:longVal;


IncVarByFloat
	= int MATCH_incVarByFloat(ident1,floatVal)
	::= "inc" WS Identifier:ident1 [WS] "," [WS] Floatvalue:floatVal;



Add
	::= (Addvarvar | Addvarlong | Addvarfloat);


Mul
	::= (Mulvarvar | Mulvarlong | Mulvarfloat);




Mulvarvar
	= int MATCH_mulVarVar(ident1,ident2,ident3)
	::= "mul" WS Identifier:ident1 [WS] "," [WS] Identifier:ident2 [WS] "," [WS] Identifier:ident3;

Mulvarlong
	= int MATCH_mulVarLong(ident1,ident2,longVal)
	::= "mul" WS Identifier:ident1 [WS] "," [WS] Identifier:ident2 [WS] "," [WS] Longvalue:longVal;

Mulvarfloat
	= int MATCH_mulVarFloat(ident1,ident2,floatVal)
	::= "mul" WS Identifier:ident1 [WS] "," [WS] Identifier:ident2 [WS] "," [WS] Floatvalue:floatVal;

Addvarvar
	= int MATCH_addVarVar(ident1,ident2,ident3)
	::= "add" WS Identifier:ident1 [WS] "," [WS] Identifier:ident2 [WS] "," [WS] Identifier:ident3;



Addvarlong
	= int MATCH_addVarLong(ident1,ident2,longVal)
	::= "add" WS Identifier:ident1 [WS] "," [WS] Identifier:ident2 [WS] "," [WS] Longvalue:longVal;

Addvarfloat
	= int MATCH_addVarFloat(ident1,ident2,floatVal)
	::= "add" WS Identifier:ident1 [WS] "," [WS] Identifier:ident2 [WS] "," [WS] Floatvalue:floatVal;




Function
	= int type
	::= DisplayMessage:type | GetTemplate:type | CreateWeapon:type | CreateArmor:type |
	    CreateBook:type | CreateClothing:type | SetTemplateName:type | AddItem:type |
	    GetButtonPressed:type | GetTextInput:type | ShowInputBox:type | GetPCSneaking:type |
	    SetBookMultiplier:type | SetMiscMultiplier:type | SetArmorMultiplier:type | SetWeaponMultiplier:type |
	    SetClothingMultiplier:type | SetIngredientMultiplier:type | GetScript:type | StartScript:type |
	    StopScript:type | IsRunning:type | KeyPressed:type | EnterMenuMode:type | LeaveMenuMode:type | 
		SetSlashDamage:type | SetSlashMin:type | SetSlashMax:type | GetSlashMin:type | GetWeaponMultiplier:type | 
		GetSlashMax:type;


GetWeaponMultiplier
	= int MATCH_GetWeaponMultiplier()
	::= "GetWeaponMultiplier" [WS] "(" [WS] ")";


SetSlashDamage
	= int MATCH_SetSlashDamage(weaponTemplate,min,max)
	::= "SetSlashDamage" [WS] "(" [WS] LongParameter:weaponTemplate [WS] "," [WS] LongParameter:min [WS] "," [WS] LongParameter:max [WS] ")";


SetSlashMin
	= int MATCH_SetSlashMin(weaponTemplate,min)
	::= "SetSlashMin" [WS] "(" [WS] LongParameter:weaponTemplate [WS] "," [WS] LongParameter:min [WS] ")";

SetSlashMax
	= int MATCH_SetSlashMax(weaponTemplate,min)
	::= "SetSlashMax" [WS] "(" [WS] LongParameter:weaponTemplate [WS] "," [WS] LongParameter:min [WS] ")";


GetSlashMax
	= int MATCH_GetSlashMax(weaponTemplate)
	::= "GetSlashMax" [WS] "(" [WS] LongParameter:weaponTemplate [WS] ")";

GetSlashMin
	= int MATCH_GetSlashMin(weaponTemplate)
	::= "GetSlashMin" [WS] "(" [WS] LongParameter:weaponTemplate [WS] ")";



EnterMenuMode
	= int MATCH_EnterMenuMode()
	::= "EnterMenuMode" [WS] "(" [WS] ")";


LeaveMenuMode
	= int MATCH_LeaveMenuMode()
	::= "LeaveMenuMode" [WS] "(" [WS] ")";


KeyPressed
	= int MATCH_KeyPressed(keyCode)
	::= "KeyPressed" [WS] "(" [WS] LongParameter:keyCode [WS] ")";


IsRunning
	= int MATCH_IsRunning(scriptAddress)
	::= "IsRunning" [WS] "(" [WS] LongParameter:scriptAddress [WS] ")";


GetScript
	= int MATCH_GetScript(scriptName)
	::= "GetScript" [WS] "(" [WS] StringParameter:scriptName [WS] ")";


StopScript
	= int MATCH_StopScript(scriptAddress,resetVars)
	::= "StopScript" [WS] "(" [WS] LongParameter:scriptAddress [WS] "," [WS] LongParameter:resetVars [WS] ")";


StartScript
	= int MATCH_StartScript(scriptAddress,resetVars)
	::= "StartScript" [WS] "(" [WS] LongParameter:scriptAddress [WS] "," [WS] LongParameter:resetVars [WS] ")";



GetPCSneaking
	= int MATCH_GetPCSneaking()
	::= "GetPCSneaking" [WS] "(" [WS] ")";


AddItem
	= int MATCH_AddItem(container,item,itemCount)
	::= "AddItem" [WS] "(" [WS] LongParameter:container [WS] "," [WS] LongParameter:item [WS] "," [WS] LongParameter:itemCount [WS] ")";



SetTemplateName
	= int MATCH_SetTemplateName(template,name)
	::= "SetTemplateName" [WS] "(" [WS] LongParameter:template [WS] "," [WS] StringParameter:name [WS] ")";


GetButtonPressed
	= int MATCH_GetButtonPressed()
	::= "GetButtonPressed" [WS] "(" [WS] ")";
	
GetTextInput
	= int MATCH_GetTextInput()
	::= "GetTextInput" [WS] "(" [WS] ")";

SetBookMultiplier
	= int MATCH_SetBookMultiplier(mult)
	::= "SetBookMultiplier" [WS] "(" [WS] FloatParameter:mult [WS] ")";

SetArmorMultiplier
	= int MATCH_SetArmorMultiplier(mult)
	::= "SetArmorMultiplier" [WS] "(" [WS] FloatParameter:mult [WS] ")";

SetWeaponMultiplier
	= int MATCH_SetWeaponMultiplier(mult)
	::= "SetWeaponMultiplier" [WS] "(" [WS] FloatParameter:mult [WS] ")";


SetClothingMultiplier
	= int MATCH_SetClothingMultiplier(mult)
	::= "SetClothingMultiplier" [WS] "(" [WS] FloatParameter:mult [WS] ")";

SetMiscMultiplier
	= int MATCH_SetMiscMultiplier(mult)
	::= "SetMiscMultiplier" [WS] "(" [WS] FloatParameter:mult [WS] ")";

SetIngredientMultiplier
	= int MATCH_SetIngredientMultiplier(mult)
	::= "SetIngredientMultiplier" [WS] "(" [WS] FloatParameter:mult [WS] ")";

ShowInputBox
	= int MATCH_ShowInputBox(dialogTitle,buttonText)
	::= "ShowInputBox" [WS] "(" [WS] StringParameter:dialogTitle [WS] "," [WS] StringParameter:buttonText [WS] ")";

CreateWeapon
	= int MATCH_CreateWeapon(templateAddress)
	::= "CreateWeapon" [WS] "(" [WS] LongParameter:templateAddress [WS] ")";



CreateArmor
	= int MATCH_CreateArmor(templateAddress)
	::= "CreateArmor" [WS] "(" [WS] LongParameter:templateAddress [WS] ")";


CreateBook
	= int MATCH_CreateBook(templateAddress)
	::= "CreateBook" [WS] "(" [WS] LongParameter:templateAddress [WS] ")";

CreateClothing
	= int MATCH_CreateClothing(templateAddress)
	::= "CreateClothing" [WS] "(" [WS] LongParameter:templateAddress [WS] ")";


GetTemplate
	= int MATCH_GetTemplate(templateString)
	::= "GetTemplate" [WS] "(" [WS] StringParameter:templateString [WS] ")";

DisplayMessage
	= int MATCH_DisplayMessage(message)
	::= "DisplayMessage" [WS] "(" [WS] StringParameter:message [WS] ")";