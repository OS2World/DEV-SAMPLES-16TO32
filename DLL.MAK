# IBM Developer's Workframe/2 Make File Creation run at 12:00:56 on 02/07/92

# Make File Creation run in directory:
#   D:\CLASS\DLL;

.SUFFIXES:

.SUFFIXES: .c

dll.dll:  \
  DLL.OBJ \
  dll.DEF \
  DLL.MAK
   @REM @<<DLL.@0
     /DE /PM:VIO +
     DLL.OBJ
     dll.dll


     dll.DEF;
<<
   LINK386.EXE @DLL.@0
  IMPLIB dll.LIB dll.DEF

{.}.c.obj:
   ICC.EXE /Ss /Kboa /Ti /Ge- /C .\$*.c

!include DLL.DEP
