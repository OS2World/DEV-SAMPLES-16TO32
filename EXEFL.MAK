#   Makefile for 16 bit EXEFL and related support routines

CFLAGS=-W3 -Zpi -Gs2 -I$(INCLUDE)

exefl.exe: exefl.c dll.lib 
   cl $(CFLAGS) -Lp $*.c dll.lib
