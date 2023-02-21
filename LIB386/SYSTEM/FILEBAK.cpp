//--------------------------------------------------------------------------//
#include 	<SYSTEM/adeline.h>
#include 	<SYSTEM/filename.h>
#include 	<SYSTEM/filecopy.h>
#include 	<SYSTEM/filebak.h>

#include	<stdlib.h>
#include	<string.h>

//--------------------------------------------------------------------------//
S32	CopyBak( char *name )
{
	char	bakfname[_MAX_PATH] 	;

	strcpy( bakfname, name ) 	;
	AddExt( bakfname, ".BAK" ) 	;

	return Copy( name, bakfname ) 	;
}


//--------------------------------------------------------------------------//
