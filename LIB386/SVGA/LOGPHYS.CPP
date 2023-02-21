/*
Write the following code in C:
;*══════════════════════════════════════════════════════════════════════════*

		.386p
		OPTION	LANGUAGE:SYSCALL
		OPTION	SCOPED

;*══════════════════════════════════════════════════════════════════════════*
MAX_SCREEN_Y_RES	equ	1024

;*══════════════════════════════════════════════════════════════════════════*
DGROUP		GROUP	_DATA

_DATA		SEGMENT USE32 PAGE PUBLIC 'DATA'

;*══════════════════════════════════════════════════════════════════════════*
		PUBLIC	SYSCALL	Phys
		PUBLIC	SYSCALL	Log
		PUBLIC	SYSCALL	Screen
		PUBLIC	SYSCALL	TabOffLine
		PUBLIC	SYSCALL	TabOffPhysLine

		PUBLIC	SYSCALL	ModeResX
		PUBLIC	SYSCALL	ModeResY
		PUBLIC	SYSCALL	ModeMemory

		PUBLIC	SYSCALL	BytesScanLine

;*══════════════════════════════════════════════════════════════════════════*
ALIGN	32					; already aligned

Phys		dd	0
Log		dd	0
Screen		dd	0

ModeResX	dd	0
ModeResY	dd	0
ModeMemory	dd	0

BytesScanLine	dd	0

TabOffLine	dd	MAX_SCREEN_Y_RES dup (?)

TabOffPhysLine	dd	MAX_SCREEN_Y_RES dup (?)

;*══════════════════════════════════════════════════════════════════════════*
_DATA		ENDS

;*══════════════════════════════════════════════════════════════════════════*
;		The
		END
*/

#include <SVGA/LOGPHYS.H>
#include <stddef.h>

void *Phys = NULL;
void *Log = NULL;
void *Screen = NULL;
U32 ModeResX = 0;
U32 ModeResY = 0;
U32 ModeMemory = 0;
U32 BytesScanLine = 0;
U32 TabOffLine[MAX_SCREEN_Y_RES];
U32 TabOffPhysLine[MAX_SCREEN_Y_RES];
