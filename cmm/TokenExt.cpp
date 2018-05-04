
#ifdef __CONSOLE__
#include <windows.h>
#else
#include <wchar.h> 
#endif


#include "tok.h"



static int nxtlab = 1;
void getlabel() {
	++nxtlab;
}
 
unsigned int  TokenMlable(ITOK* p, ITOK* p2)
{
	unsigned char bufrun[255];
	unsigned char* buf = &input[inptr - 1];
	if (tok2 == tk_at && buf[0] == ':')
	{
		getlabel();
		sprintf((char*)bufrun, "lab__%d:", nxtlab);
		RunBuffer(bufrun);
		return true;
	}
	if (tok == tk_at && (tok2 == tk_id || tok2 == tk_ID) && !stricmp((char*)string2, "f"))
	{
		sprintf((char*)bufrun, "lab__%d;", nxtlab + 1);
		RunBuffer(bufrun);
		return true;
	}
	if (tok == tk_at && (tok2 == tk_id || tok2 == tk_ID) && !stricmp((char*)string2, "b"))
	{
		sprintf((char*)bufrun, "lab__%d;", nxtlab);
		RunBuffer(bufrun);
		return true;
	}
	return false;
}
