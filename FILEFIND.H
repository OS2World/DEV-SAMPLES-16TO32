/* File time and date types */
#ifdef __IBMC__
typedef struct _FTIME           /* ftime */
{
	UINT   twosecs : 5;
	UINT   minutes : 6;
	UINT   hours   : 5;
} FTIME;
typedef FTIME *PFTIME;

#else

typedef struct _FTIME           /* ftime */
{
	USHORT   twosecs : 5;
	USHORT   minutes : 6;
	USHORT   hours   : 5;
} FTIME;
typedef FTIME *PFTIME;
#endif

#ifdef __IBMC__
typedef struct _FDATE           /* fdate */
{
	UINT   day     : 5;
	UINT   month   : 4;
	UINT   year    : 7;
} FDATE;
typedef FDATE   *PFDATE;

#else
typedef struct _FDATE           /* fdate */
{
	USHORT   day     : 5;
	USHORT   month   : 4;
	USHORT   year    : 7;
} FDATE;
typedef FDATE   *PFDATE;
#endif

typedef struct _FILEFINDBUF3                 /* findbuf3 */
{
	ULONG   oNextEntryOffset;            /* new field */
	FDATE   fdateCreation;
	FTIME   ftimeCreation;
	FDATE   fdateLastAccess;
	FTIME   ftimeLastAccess;
	FDATE   fdateLastWrite;
	FTIME   ftimeLastWrite;
	ULONG   cbFile;
	ULONG   cbFileAlloc;
	ULONG   attrFile;                    /* widened field */
	UCHAR   cchName;
	CHAR    achName[CCHMAXPATHCOMP];
} FILEFINDBUF3;
typedef FILEFINDBUF3 *PFILEFINDBUF3;

