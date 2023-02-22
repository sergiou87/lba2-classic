#include <3D/GETANG2D.H>
#include <3D/TANTAB.H>

/*
Implementation in assembly:
;*══════════════════════════════════════════════════════════════════════════*
		.386P

		.model SMALL, SYSCALL

;*══════════════════════════════════════════════════════════════════════════*
		.DATA

;*══════════════════════════════════════════════════════════════════════════*
		extrn	SYSCALL		TanTab	: DWORD

;*══════════════════════════════════════════════════════════════════════════*
		.CODE

;*══════════════════════════════════════════════════════════════════════════*
		PUBLIC  SYSCALL 	GetAngleVector2D

;*══════════════════════════════════════════════════════════════════════════*
;S32 	GetAngleVector2D( S32 x, S32 z)			;

;#pragma aux GetAngleVector2D	"*"			\
;	parm		[eax] [ebx]	 		\
;	modify 		[ecx edx esi]

GetAngleVector2D proc

		xor	esi, esi		; ESI = Bit field

		test	eax, eax
		jz	exit0

		jns	ok1

		neg	eax
		or	esi, 1			; ESI : bit 0 = 1 if x coord is negative
ok1:
		test	ebx, ebx
		jz	exit1

		jns	ok2

		neg	ebx
		or	esi, 2			; ESI : bit 1 = 1 if z coord is negative
ok2:
		cmp	eax, ebx
		jbe	noswap

		mov	edx, eax
		mov	eax, ebx

		mov	ebx, edx
		or	esi, 4			; ESI : bit 2 = 1 if |z|>|x|
noswap:
		mov	ecx, ebx x
		mov	edx, eax z

		shl	eax, 30 z << 30

		shr	ecx, 1 x >> 1

		shr	edx, 2 z >> 2
		add	eax, ecx

		adc	edx, 0

		div	ebx			; eax = 1.1.30 = tan(ß)

		mov	ebx, ((0+512)/2)*4	; = 0*2+512*2
		xor	edx, edx

		mov     ecx, 512*2
		cmp	eax, TanTab[ebx]
		jge	ga3
ga0:
		shr	ebx, 1

		mov	ecx, ebx
		add	ebx, edx
ga2:
		test	ebx, 2
		jnz	angle

		cmp	eax, TanTab[ebx]
		jl	ga0
ga3:
		shr	ebx, 1

		mov	edx, ebx
		add	ebx, ecx

		jmp	ga2
angle:
		mov	ebx, TanTab[edx*2]
		mov	ecx, TanTab[edx*2+4]

		shr	edx, 1
		sub	ecx, eax

		sub	eax, ebx

		cmp	eax, ecx
		jbe	ok

		inc	edx
ok:
		mov	eax, edx
		test	esi, 4

		jz	no2

		mov	eax, 1024
		sub	eax, edx
no2:
		mov	edx, eax
		test	esi, 2

		jz	no1

		mov	eax, 2048
		sub	eax, edx
no1:
		test	esi, 1
		jz	no0

		neg	eax
no0:
		and	eax, 4095
		ret
exit0:
		xor	eax, eax
		test	ebx, ebx

		jns	no4

		mov	eax, 2048
no4:
		ret
exit1:
		mov	eax, 1024
		test	esi, 1

		jz	no3

		mov	eax, 4096-1024
no3:
		ret

GetAngleVector2D endp

;*══════════════════════════════════════════════════════════════════════════*
		;The
		 End
*/

// GetAngleVector2D proc
S32 GetAngleVector2D(S32 x, S32 z)
{
	return 0;

	// TODO: Implement
	/*
	// xor	esi, esi		; ESI = Bit field
	S32 esi = 0; // Bit field
	// test	eax, eax
	// jz	exit0
	if (x == 0)
	{
		goto exit0;
	}
	// jns	ok1
	if (x < 0)
	{
		// neg	eax
		x = -x;
		// or	esi, 1			; ESI : bit 0 = 1 if x coord is negative
		esi |= 1; // ESI : bit 0 = 1 if x coord is negative
	}
ok1:
	// test	ebx, ebx
	// jz	exit1
	if (z == 0)
	{
		goto exit1;
	}
	// jns	ok2
	if (z < 0)
	{
		// neg	ebx
		z = -z;
		// or	esi, 2			; ESI : bit 1 = 1 if z coord is negative
		esi |= 2; // ESI : bit 1 = 1 if z coord is negative
	}
ok2:
	// cmp	eax, ebx
	// jbe	noswap
	if (x > z)
	{
		// mov	edx, eax
		S32 edx = x;
		// mov	eax, ebx
		x = z;
		// mov	ebx, edx
		z = edx;
		// or	esi, 4			; ESI : bit 2 = 1 if |z|>|x|
		esi |= 4; // ESI : bit 2 = 1 if |z|>|x|
	}
noswap:
	// mov	ecx, ebx x
	S32 ecx = z; // x
	// mov	edx, eax z
	edx = x; // z
	// shl	eax, 30 z << 30
	x <<= 30; // z << 30
	// shr	ecx, 1 x >> 1
	ecx >>= 1; // x >> 1
	// shr	edx, 2 z >> 2
	edx >>= 2; // z >> 2
	// add	eax, ecx
	// adc	edx, 0
	x = x + ecx + (edx < 0); // edx < 0 is the carry flag
	// div	ebx			; eax = 1.1.30 = tan(ß)
	x /= z; // x = 1.1.30 = tan(ß)
	// mov	ebx, ((0+512)/2)*4	; = 0*2+512*2
	S32 ebx = ((0 + 512) / 2) * 4; // = 0*2+512*2
	// xor	edx, edx
	edx = 0;
	// mov     ecx, 512*2
	ecx = 512 * 2;
	// cmp	eax, TanTab[ebx]
	// jge	ga3
	if (x < TanTab[ebx])
	{
		do
		{
		ga0:
			// shr	ebx, 1
			ebx >>= 1;
			// mov	ecx, ebx
			ecx = ebx;
			// add	ebx, edx
			ebx += edx;
		ga2:
			// test	ebx, 2
			// jnz	angle
			if (ebx & 2)
			{
				goto angle;
			}
			// cmp	eax, TanTab[ebx]
			// jl	ga0
		} while (x < TanTab[ebx])
	}
ga3:
	// shr	ebx, 1
	ebx >>= 1;
	// mov	edx, ebx
	edx = ebx;

	// add	ebx, ecx
	ebx += ecx;
	// jmp	ga2
	goto ga2;
angle:
	// mov	ebx, TanTab[edx*2]
	ebx = TanTab[edx * 2];
	// mov	ecx, TanTab[edx*2+4]
	ecx = TanTab[edx * 2 + 4];
	// shr	edx, 1
	edx >>= 1;
	// sub	ecx, eax
	ecx -= x;
	// sub	eax, ebx
	x -= ebx;
	// cmp	eax, ecx
	// jbe	ok
	if (x > ecx)
	{
		// inc	edx
		edx++;
	}
ok:
	// mov	eax, edx
	x = edx;

	// test	esi, 4
	// jz	no2
	if ((esi & 4) != 0)
	{
		// mov	eax, 1024
		x = 1024;
		// sub	eax, edx
		x -= edx;
	}
no2:
	// mov	edx, eax
	edx = x;
	// test	esi, 2
	// jz	no1
	if ((esi & 2) != 0)
	{
		// mov	eax, 2048
		x = 2048;
		// sub	eax, edx
		x -= edx;
	}
no1:
	// test esi, 1
	// jz no0
	if ((esi & 1) != 0)
	{
		// neg eax
		x = -x; // negate x
	}

no0:
	// and eax, 4095
	x &= 4095; // bitwise and x with 4095
	// ret
	return x; // return x

exit0:
	// xor eax, eax
	x = 0; // set x to zero
	// test ebx, ebx
	// jns no4
	if (z < 0)
	{
		// mov eax, 2048
		x = 2048; // set x to 2048
	}

no4:
	// ret
	return x; // return x

exit1:
	// mov eax, 1024
	x = 1024; // set x to 1024
	// test esi, 1
	// jz no3
	if ((esi & 1) != 0)
	{
		// mov eax, 4096-1024
		x = 4096 - 1024; // set x to 3072
	}

no3:
	// ret
	return x; // return x
						// GetAngleVector2D endp
						*/
}
