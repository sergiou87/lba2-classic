//--------------------------------------------------------------------------//
#include <SYSTEM/ADELINE.H>
#include <SYSTEM/FILES.H>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//--------------------------------------------------------------------------//
S32 OpenMode(const char *name, int mode)
{
	S32 handle;

	handle = open(name, mode, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

	return handle == -1 ? 0 : handle;
}

//--------------------------------------------------------------------------//
U32 FileSize(const char *name)
{
	int handle;
	S32 fsize;

	handle = OpenRead(name);
	if (!handle)
		return (0);

	fsize = lseek(handle, 0, SEEK_END);
	Close(handle);

	return (U32)(fsize == -1 ? 0 : fsize);
}

//--------------------------------------------------------------------------//
