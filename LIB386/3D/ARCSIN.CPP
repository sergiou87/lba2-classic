/*
;*══════════════════════════════════════════════════════════════════════════*

		.386p

		.model SMALL, SYSCALL

;*══════════════════════════════════════════════════════════════════════════*

		.DATA

		extrn	SYSCALL	SinTab:WORD

;*══════════════════════════════════════════════════════════════════════════*

		.CODE

		public	SYSCALL	ArcSin

;*══════════════════════════════════════════════════════════════════════════*
;void	ArcSin(S32 sin)		;

;#pragma aux	ArcSin			\
;	parm		[eax]		\
;	modify		[ebx ecx edx]


ArcSin		proc
					; edx = 17.1.14
		test	eax, eax
		jz	exit0

		mov     ecx, 1024
		mov	ebx, 2048*2

		mov	edx, 3072
		cmp	ax, SinTab[ebx]

		jge	ga1
ga0:
		shr	ebx, 1
		mov	ecx, ebx

		add	ebx, edx
ga2:
		test	ebx, 1
		jnz	angle

		cmp	ax, SinTab[ebx]
		jl	ga0
ga1:
		shr	ebx, 1
		mov	edx, ebx

		add	ebx, ecx
		jmp	ga2
angle:
		movsx	ecx, SinTab[edx*2-2]

		movsx	ebx, SinTab[edx*2]

		sub	ecx, eax
		sub	eax, ebx

		cmp	eax, ecx
		mov	eax, 2048

		jbe	ok

		dec	edx
ok:
		sub	eax, edx
		and	eax, 4095
exit0:
		ret

ArcSin		endp

;*══════════════════════════════════════════════════════════════════════════*
;		The
		END
*/

#include <3D/ARCSIN.H>
#include <3D/SINTAB.H>

S32 ArcSin(S32 sin)
{
	S32 ebx, ecx, edx;

	if (sin == 0)
		return 0;

	ebx = 2048 * 2;
	ecx = 1024;
	edx = 3072;

	if (sin >= SinTab[ebx])
	{
	ga1:
		ebx >>= 1;
		ecx = ebx;
		ebx += edx;
	ga2:
		if (ebx & 1)
			goto angle;
		if (sin < SinTab[ebx])
			goto ga0;
	ga0:
		ebx >>= 1;
		edx = ebx;
		ebx += ecx;
		goto ga2;
	angle:
		ecx = SinTab[edx * 2 - 2];
		ebx = SinTab[edx * 2];
		ecx -= sin;
		sin -= ebx;
		if (sin <= ecx)
			goto ok;
		edx--;
	ok:
		sin = 2048 - edx;
	}
	else
	{
		ebx >>= 1;
		ecx = ebx;
		ebx += edx;
	ga3:
		if (ebx & 1)
			goto angle2;
		if (sin > SinTab[ebx])
			goto ga1;
	ga4:
		ebx >>= 1;
		edx = ebx;
		ebx += ecx;
		goto ga3;
	angle2:
		ecx = SinTab[edx * 2 - 2];
		ebx = SinTab[edx * 2];
		ecx -= sin;
		sin -= ebx;
		if (sin >= ecx)
			goto ok2;
		edx--;
	ok2:
		sin = 2048 - edx;
	}

	return sin & 4095;
}
