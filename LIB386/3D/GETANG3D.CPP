/*
Write this code in C:
;*══════════════════════════════════════════════════════════════════════════*
		.386p

		.model SMALL, SYSCALL

;*══════════════════════════════════════════════════════════════════════════*
		.DATA

;*══════════════════════════════════════════════════════════════════════════*
		extrn	SYSCALL	X0			:DWORD
		extrn	SYSCALL	Y0			:DWORD

;*══════════════════════════════════════════════════════════════════════════*
		.CODE

;*══════════════════════════════════════════════════════════════════════════*
		extrn	SYSCALL	GetAngleVector2D	:PROC
		extrn	SYSCALL	QSqr			:PROC

;*══════════════════════════════════════════════════════════════════════════*
		public	SYSCALL	GetAngleVector3D

;*══════════════════════════════════════════════════════════════════════════*
;void	GetAngleVector3D(S32 x, S32 y, S32 z)	;

;#pragma aux GetAngleVector3D	"*"		\
;	parm		[eax] [ebx] [ecx]	\
;	modify		[edx esi edi]

GetAngleVector3D proc

		push	ebx		; Y
		push	eax		; X

		mov	ebx, ecx	; Z
		mov	edi, ecx

		call	GetAngleVector2D

		xor	eax, -1
		pop	ecx		; X

		lea	ebx, [eax+2048+1]
		mov	eax, edi	; Z

		imul	eax		; Z^2

		mov	esi, eax; Z^2
		mov	edi, edx

		and	ebx, 4095
		mov	eax, ecx	; X

		imul	eax		; X^2

		add	eax, esi
		mov	[Y0], ebx

		adc	edx, edi
		call	QSqr

		mov	ebx, eax
		pop	eax

		call	GetAngleVector2D

		neg	eax

		and	eax, 4095

		mov	[X0], eax

		ret

GetAngleVector3D endp

;*══════════════════════════════════════════════════════════════════════════*
;		The
		END
*/

#include <3D/GETANG3D.H>
#include <3D/GETANG2D.H>
#include <3D/SQRROOT.H>
#include <3D/CAMERA.H>

S32 GetAngleVector3D(S32 x, S32 y, S32 z)
{
	// push ebx
	S32 temp1 = y; // save y on stack
	// push eax
	S32 temp2 = x; // save x on stack
	// mov ebx, ecx
	y = z; // use y as z
	// mov edi, ecx
	S32 edi = z; // save z in edi
	// call GetAngleVector2D
	S32 eax = GetAngleVector2D(x, y); // get angle between x and y (z)
	// xor eax, -1
	eax = ~eax; // bitwise complement of eax
	// pop ecx
	x = temp2; // restore x from stack
	// lea ebx, [eax+2048+1]
	y = eax + 2049; // use y as intermediate value (eax + offset)
	// mov eax, edi
	z = edi; // restore z from edi
	// imul eax
	z *= z; // square of z
	// mov esi, eax
	S32 esi = z; // save square of z in esi
	S32 edx = 0; // edx has something from doing z*z (because the result is tored in edx:eax)
	// mov edi, edx
	edi = edx; // save edx in edi
	// and ebx, 4095
	y &= 4095; // bitwise and of y with mask
	// mov eax, ecx
	x = x; // use x as x (redundant)
	// imul eax
	x *= x; // square of x
	// add eax, esi
	x += esi; // sum of squares of x and z
	// mov [Y0], ebx
	Y0 = y; // store y in global variable Y0
	// adc edx, edi
	S32 CF = 0;			 // TODO: calculate carry flag or do something
	edx += edi + CF; // add edx and edi with carry flag
	// call QSqr
	// TODO: the second parameter should be edx... eax = QSqr(x); // get square root of x
	// mov ebx, eax
	y = eax; // use y as square root of x
	// pop eax
	x = temp1; // restore x from stack (original y)
	// call GetAngleVector2D
	eax = GetAngleVector2D(x, y); // get angle between x and y (original y and square root of x)
	// neg eax
	eax = -eax; // negate eax
	// and eax, 4095
	eax &= 4095; // bitwise and of eax with mask
	// mov [X0], eax
	X0 = eax; // store eax in global variable X0
	// ret
	return eax; // return from function
}
