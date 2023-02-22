// ──────────────────────────────────────────────────────────────────────────
#include <SYSTEM/ADELINE.H>

#include <SVGA/INITMODE.H>
#include <SVGA/DIRTYBOX.H>
#include <SVGA/INIMOUSE.H>
#include <SVGA/MOUSE.H>

// ──────────────────────────────────────────────────────────────────────────
// #ifdef _WIN32

// // ──────────────────────────────────────────────────────────────────────────
// #include <SYSTEM/winsys.h>

// ──────────────────────────────────────────────────────────────────────────
// #else //_WIN32

// ──────────────────────────────────────────────────────────────────────────
// #include <SYSTEM/EXIT.H>
// #include <AIL/MSS.H>

#include <stdlib.h>

// ──────────────────────────────────────────────────────────────────────────
static S32 Installed = FALSE;
static S32 LastFlagMouse = FALSE;

// ──────────────────────────────────────────────────────────────────────────
// #endif //_WIN32

// ──────────────────────────────────────────────────────────────────────────
volatile S32 Click = 0;

// ──────────────────────────────────────────────────────────────────────────
volatile S32 MouseX;
volatile S32 MouseY;

// ──────────────────────────────────────────────────────────────────────────
S32 MouseXDep = 0;
S32 MouseYDep = 0;

// ──────────────────────────────────────────────────────────────────────────
S32 FlagMouse = FALSE;

// ──────────────────────────────────────────────────────────────────────────
#ifdef __cplusplus
extern "C"
{
#endif

	extern U8 BinGphMouse;

#ifdef __cplusplus
}
#endif

// ──────────────────────────────────────────────────────────────────────────
// extern WINDOW_PROC_PTR OldMouseWindowProc;
// extern WINDOW_PROC MouseWindowProc;

// ──────────────────────────────────────────────────────────────────────────
void InitMouse()
{
	// OldMouseWindowProc = WindowProc;
	// WindowProc = MouseWindowProc;

	// SetMouseBox(0, 0, ModeDesiredX, ModeDesiredY);

	// GphSprite = &BinGphMouse;
	// DefSprite = 0;

	// Click = 0;
}

// ──────────────────────────────────────────────────────────────────────────
void ClearMouse()
{
	// WindowProc = OldMouseWindowProc;
}

// ──────────────────────────────────────────────────────────────────────────
