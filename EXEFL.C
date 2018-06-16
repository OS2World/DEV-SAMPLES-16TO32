#include <stdio.h>
#include <stdlib.h>
#include "filefind.h"	// the code in this header defines the structs for
                        //   FILEFINDBUF3.

void far pascal dbmprint(PFILEFINDBUF3);

long far pascal DoFiles(char far *pattern, ULONG Attribute, void (far pascal *fn)(PFILEFINDBUF3));

void main (void)
{
   char far *pat = "*.*";
   ULONG   attrib = FILE_NORMAL;
   long      num;

	printf("Hello from %s line %d before DoFiles call\n",__FILE__, __LINE__);
   num = DoFiles(pat, attrib, dbmprint);
   printf("\ndone %d printed\n",num);
   exit(0);
}

void far pascal dbmprint(PFILEFINDBUF3 fl)
{
   printf("\n%s \t %ld",fl->achName, fl->cbFileAlloc);
}
