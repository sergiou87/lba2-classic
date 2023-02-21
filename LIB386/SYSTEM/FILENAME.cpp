//-------------------------------------------------------------------------//
#include <SYSTEM/ADELINE.H>
#include <SYSTEM/FILENAME.H>

#include <stdlib.h>
#include <string.h>
#include <libgen.h>

#define PATH_MAX 4096

//-------------------------------------------------------------------------//
char *AddExt(char *path, const char *ext)
{
	char name[PATH_MAX];

	strncpy(name, path, PATH_MAX); // copy path to name
	basename(name);								 // get file name component of name
	strcat(name, ext);						 // append ext to name
	strcpy(path, name);						 // copy name back to path

	return (path);
}

//-------------------------------------------------------------------------//
char *AddExtIfNot(char *path, const char *ext)
{
	char name[PATH_MAX];
	char *dot;

	strncpy(name, path, PATH_MAX); // copy path to name
	basename(name);								 // get file name component of name
	dot = strrchr(name, '.');			 // find last dot in name

	if (!dot) // if no dot found
	{
		strcat(name, ext);	// append ext to name
		strcpy(path, name); // copy name back to path
	}

	return (path);
}

//-------------------------------------------------------------------------//
char *GetFileName(const char *pathname)
{
	static char name[PATH_MAX];

	strncpy(name, pathname, PATH_MAX); // copy pathname to name
	basename(name);										 // get file name component of name

	return (name);
}

//--------------------------------------------------------------------------//
