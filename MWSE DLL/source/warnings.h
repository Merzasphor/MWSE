//Warnings.h
//this file disables a lot of warnings
#pragma once

#pragma warning(disable:4311) //lots of warnings...
#pragma warning(disable:4312) //lots of warnings...
#pragma warning(disable:4244) //possible data loss warning
#pragma warning(disable:4267) //possible data loss warning

//#pragma warning(disable:4018) //signed/unsigned warning, is solved
//#pragma warning(disable:4101) //unused variables warning, is solved
#pragma warning(disable:4305) //potential data loss, float's cannot hold more than 7 digits precisions, just an WARNING
#pragma warning(disable:4313) //C4313: '%x' in format string conflicts with argument 1 of type  'VPSCRIPT'
#pragma warning(disable:4800)

//#pragma warning(disable:4996) //depreciated command warning