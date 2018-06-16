There are a couple of files in this ZIP.  DLL.c is code for a 32 bit DLL
that demonstrates how to set up 32-bit code that can be called from 
existing 16-bit applications or DLL's.

The procedure documented in the manual doesn't work.  The code presented
here is a work-around that should be transparent to the fix, when
available.

exefl.c is code for a 16-bit application compiled with MSC 5.1.

Just in case you didn't know, you CAN use IPMD to debug 16-bit applications
provided they have CodeView information.  This made it easy to debug this
"mixed mode" case.

If yu have any questions, please let me know.

David Moskowitz  76701,100
