#ifndef __C_EXTERN_H__
#define __C_EXTERN_H__

#include <ctype.h>

#include <SYSTEM.H>
#include <SVGA.H>
#include <3D.H>

#include <FILEIO.H>

#include "ADDKEYS.H"
#include "INPUT.H"
#include "CONFIG.H"

#define MAX_BOXES 200

extern S32 MyKey;
extern U8 PtrPalNormal[768 + RECOVER_AREA];
extern U8 *PtrPal;

extern void FadePal(U8 r, U8 v, U8 b, U8 *ptrpal, S32 percent);
extern void FadeToBlack(U8 *ptrpal);
extern void FadeToPal(U8 *ptrpal);
extern void SetBlackPal();

extern void Beep();

#define FadeToBlackAndSamples FadeToBlack
#define FadeToPalAndSamples FadeToPal

#endif // __C_EXTERN_H__
