
#ifdef __CONSOLE__
#include <windows.h>
#else
#include <wchar.h>
#endif

#include "tok.h"

/****************************************************************/
#define MaxExTokenCnt  100
typedef unsigned int (*ExTokenFunc)(ITOK*,ITOK*); 
ExTokenFunc ExTokenProc[MaxExTokenCnt];
static int  ExToken[100]={-1};
static int  ExTokenCnt=0;
extern ITOK itok,itok2,ptok;
extern int tok,tok2;

char *AppExePath (void)
{
 static char tmp[2048];
 register int i;
 i=GetModuleFileName(GetModuleHandle(0),tmp, 2048);
 while(i && tmp[i] != 0x5C)
   i--;
 tmp[i+1] = 0;
 return tmp;
}


int RegisterToken(const int tkn,ExTokenFunc proc)
{

    if( ExTokenCnt<MaxExTokenCnt)
    {
        ExToken[ExTokenCnt] = tkn;
        ExTokenProc[ExTokenCnt]=proc;
        ExTokenCnt++;
		//printf("Registered new Token =  %d \n",tkn);
        return TRUE;
    }
    else
     return FALSE;
}

int  DoTokenEvent()
{
	int i,ret = false;
    for( i=0; i<ExTokenCnt;i++)
    {
        if(tok==ExToken[i])
        {
            if(ExTokenProc[i])
             {
                ret = ExTokenProc[i](&itok,&itok2);
				if(ret==2) continue;
				break;
             }
        }
    }
    return ret;
}
