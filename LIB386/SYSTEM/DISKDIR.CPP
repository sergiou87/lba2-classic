//--------------------------------------------------------------------------//
#include <SYSTEM/ADELINE.H>
#include <SYSTEM/DISKDIR.H>

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

//--------------------------------------------------------------------------//
void ChDiskDir(char *path)
{
	// unsigned int n;
	// char drive[_MAX_DRIVE];
	//
	// _splitpath(path, drive, NULL, NULL, NULL);
	// _dos_setdrive(toupper(drive[0]) - 'A' + 1, &n);
	chdir(path);
}

//--------------------------------------------------------------------------//
