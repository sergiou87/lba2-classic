//--------------------------------------------------------------------------
#include <SYSTEM/ADELINE.H>
#include <SYSTEM/EXIT.H>
#include <SYSTEM/A_MALLOC.H>
#include <SYSTEM/LOGPRINT.H>
#include <SYSTEM/CMDLINE.H>
#include <POLYGON/POLY.H>
#include <SVGA/CLIP.H>
#include <SVGA/LOGPHYS.H>
#include <SVGA/INITMODE.H>

#include <ctype.h>

//--------------------------------------------------------------------------
#include <SVGA/DDRAW.H>

//--------------------------------------------------------------------------
U32 ModeDesiredX;
U32 ModeDesiredY;
U32 ModeDesiredDepth;
U32 ModeDesiredSize;
U32 ModePages;

//--------------------------------------------------------------------------
// TODO: delete??
// U32 VESAMemory = VESA_LINEAR_OR_WINDOWED;

//--------------------------------------------------------------------------
void *PhysHard;
void *MemoLog;
void *MemoScreen;

//----------------------------------------------------------------------------
S32 ParamsSvga()
{
	// TODO: Implement
	/*
	char str[256];
	char *ptr;
	S32 result;
	S32 i;

	str[256] = 0;
	result = FALSE;

	i = 1;
	while (i < ArgC)
	{
		strncpy(str, ArgV[i], 255);
		if (strnicmp("/SVGA", str, 5))
		{
			i++;
			continue;
		}

		RemoveParam(i);

		ptr = str + 5;

		if (!strnicmp("Linear=", ptr, 7))
		{
			if (atoi(ptr + 7))
			{
				VESAMemory |= VESA_LINEAR;
			}
			else
			{
				VESAMemory &= ~VESA_LINEAR;
			}

			result = TRUE;
		}
		else if (!strnicmp("Windowed=", ptr, 9))
		{
			if (atoi(ptr + 9))
			{
				VESAMemory |= VESA_WINDOWED;
			}
			else
			{
				VESAMemory &= ~VESA_WINDOWED;
			}
			result = TRUE;
		}
		else
		{
			LogPrintf("Unsupported SVGA override: %s", str);
		}
	}

	return result;
	*/
	return TRUE;
}

//--------------------------------------------------------------------------
void ClearGraphSvga()
{
	// TODO: Implement
	/*
	if (MemoLog)
	{
		Free(MemoLog);
		Log = MemoLog = NULL;
	}
	if (MemoScreen)
	{
		Free(MemoScreen);
		Screen = MemoScreen = NULL;
	}
	*/
}

//--------------------------------------------------------------------------
/*static S32 InitDesiredMode()
{
	S32 res;
	S32 i, off;

	if (ModeDesiredY > MAX_SCREEN_Y_RES)
	{
		return -1;
	}

	res = DetectInitVESAMode(ModeDesiredX, ModeDesiredY, ModeDesiredDepth, VESAMemory);

#ifndef _WIN32
	CopyBoxVESA = CopyBoxVESAInit; // check gain for linear buffer
#endif													 //_WIN32

	ModeDesiredSize = ModeDesiredX * ModeDesiredY;

	SetClipWindow(0, 0, ModeDesiredX - 1, ModeDesiredY - 1);
	SetClip(0, 0, ModeDesiredX - 1, ModeDesiredY - 1);

	off = 0; // fill the full phys table anyway
	for (i = 0; i < MAX_SCREEN_Y_RES; i++)
	{
		TabOffPhysLine[i] = off;
		off += BytesScanLine;
	}

	off = 0; // fill the full log table anyway
	for (i = 0; i < MAX_SCREEN_Y_RES; i++)
	{
		TabOffLine[i] = off;
		off += ModeDesiredX;
	}

	SetScreenPitch(TabOffLine);

	return res;
}*/

//--------------------------------------------------------------------------
S32 InitGraphSvga(U32 resx, U32 resy, U32 depth)
{
	// TODO: Implement
	/*
	static S32 flag = 0;

	if (!flag)
	{
		if (!InitVESA())
		{
			LogPrintf("Error: Cannot initialize DirectDraw\n");
			return 1;
		}

		atexit((PTR_VOID_FUNC)EndVESA);

		flag = 1;
	}

	ModeDesiredX = resx;
	ModeDesiredY = resy;
	ModeDesiredDepth = depth;

	LogPrintf("\nDesired resolution: %i*%i*%i\n", ModeDesiredX, ModeDesiredY, ModeDesiredDepth);

	if (!InitDesiredMode())
	{
		LogPuts("Error initializing video mode\n");
		return 1;
	}

	LogPrintf("Best Mode Found   : %i*%i*%i\n", ModeResX, ModeResY, ModeDesiredDepth);
	LogPrintf("Frame buffer type : %sLinear\n",
						ModeMemory == 2 ? "" : "Virtual ");

	if (!Log)
	{
		Log = Malloc(resx * resy + 512);
		if (!Log)
		{
			LogPuts("Error: Not Enought Memory to allocate Log");
			return 2;
		}
		memset(Log, 0, resx * resy + 512);
	}

	MemoLog = Log;

	if (!Screen)
	{
		Screen = Malloc(resx * resy + 512);
		if (!Screen)
		{
			LogPuts("Error: Not Enought Memory to allocate Screen");
			Free(Log);
			Log = NULL;
			return 2;
		}
		memset(Screen, 0, resx * resy + 512);
	}

	MemoScreen = Screen;

	return 0;
	*/

	return 0;
}

//--------------------------------------------------------------------------
