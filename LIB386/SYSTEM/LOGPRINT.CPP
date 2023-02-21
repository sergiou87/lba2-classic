//----------------------------------------------------------------------------
#include <SYSTEM/ADELINE.H>
#include <SYSTEM/LOGPRINT.H>

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>

// TODO: Fix this
#define _MAX_PATH 4096

//----------------------------------------------------------------------------
U32 QuietLog = FALSE;
static char LogName[_MAX_PATH] = "";
static char LogStr[256];

//----------------------------------------------------------------------------
void CreateLog(char *fname)
{
	char name[_MAX_PATH];
	FILE *logfile;

	strncpy(name, fname, _MAX_PATH); // copy fname to name
	dirname(name);									 // get directory component of name
	strcat(name, "/ADELINE.LOG");		 // append file name and extension to name
	strcpy(LogName, name);					 // copy name to LogName

	logfile = fopen(LogName, "wb"); // open LogName for writing
	if (!logfile)										// if failed
	{
		LogName[0] = 0; // clear LogName
	}
	else // if succeeded
	{
		fclose(logfile); // close logfile
	}
}

//----------------------------------------------------------------------------
void LogPrintf(const char *format, ...)
{
	char *ptr;
	va_list arglist;

	va_start(arglist, format);

	vsprintf(LogStr, format, arglist);

	for (ptr = LogStr; *ptr; ptr++)
	{
		if (*ptr == '\n')
		{
			memmove(ptr + 2, ptr + 1, strlen(ptr));
			*ptr++ = '\r';
			*ptr = '\n';
		}
	}

	va_end(arglist);

	if (!QuietLog)
	{
		printf("%s", LogStr);
	}

	if (*LogName)
	{
		FILE *logfile;

		logfile = fopen(LogName, "ab+");
		if (logfile)
		{
			fprintf(logfile, "%s", LogStr);
			fclose(logfile);
		}
	}
}

//----------------------------------------------------------------------------
void LogPuts(const char *string)
{
	LogPrintf("%s\n", string);
}

//----------------------------------------------------------------------------
