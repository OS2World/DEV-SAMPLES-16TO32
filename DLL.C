/**************************************************************
*																				  *
*	Sample 32-bit code callable from a 16 bit application.     *
*	There is a bug in the IBM C Set/2 compiler (PMR 6x060)     *
*	that does not properly handle pointer thunks from 16-bit   *
*	code.  This 32-bit sample shows the work around.           *
*                                                             *
*	Author: David Moskotiwz, Productivity Solutions            *
*	                                                           *
*	Thanks to Hae Shung Ju and Dave Mooney of IBM to find      *
*	the work-around.                                           *
*	                                                           *
**************************************************************/

#define INCL_DOS
#define INCL_NOPMAPI
#include <os2.h>

#include <stdio.h>

/*
**	According to the documentation, all 16-bit pointers must be declared with
**	the _Seg16 keyword.  Note the prototype below. We don't have to do
**	anything with the non-pointer values (the 2nd parameter).
**
**	However, because the third parameter is a function, we have to
** use the _Seg16 to make sure the compiler generates the proper
** thunk.  THe example in the documentation (without the _Seg16, fails).
*/

int _Far16 _Pascal DoFiles(char * _Seg16, ULONG, void (* _Seg16 _Far16 _Pascal fn)(FILEFINDBUF3 * _Seg16 ));

int _Far16 _Pascal DoFiles(char * _Seg16 pattern, ULONG Attribute, void (* _Seg16  _Far16 _Pascal fn)(FILEFINDBUF3 * _Seg16 ))
{
   FILEFINDBUF3 flist;
   ULONG       count = 1;
   HDIR        hdir = (HDIR) HDIR_CREATE;
   int         NumberDone = 0;
	APIRET		rc;

	/*
	**	This is a bit of magic.  The compiler "knows" that _pattern_
	**	is a 16-bit pointer.  However, it does not generate the pointer
	**	thunk unless we explicitly assign the contents to a 32-bit pointer.
	*/

	char 	*pat = pattern;


	printf("\nwe're here... in the 32 bit DLL\n");
/*
** The following line fails for a couple of reasons, first, the printf
** family doesn't recognize the need to thunk the paramter, second, the
** compiler doesn't do it.
**
**	printf(" character string passed: %s \n", pattern);
*/
	printf(" character string passed: %s \n", pat);

   rc = DosFindFirst(pat, &hdir, Attribute
					, &flist, sizeof(flist), &count, FIL_STANDARD);
   if (!rc)
   {
      do
      {
        (*fn)(&flist);
         NumberDone++;				// keep track of how many we did
      }
      while(!(DosFindNext(hdir, &flist, sizeof(flist),&count)) );
   }

   DosFindClose(hdir);				// close the directory
   return(NumberDone);				// let 'em know how many we did
}
