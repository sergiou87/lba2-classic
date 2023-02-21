/*
Write this code in C:
;****************************************************************************

		.386p

		.model SMALL, SYSCALL

		include 3d.inc

;****************************************************************************
		.DATA

;****************************************************************************
		public	SYSCALL AlphaLight
		public	SYSCALL BetaLight
AlphaLight	dd	0000
BetaLight	dd	0000

		public	SYSCALL CameraXLight
		public	SYSCALL CameraYLight
		public	SYSCALL CameraZLight
CameraXLight	dd	LIB_NORMAL_UNIT
CameraYLight	dd	0000
CameraZLight	dd	0000

		public	SYSCALL NormalXLight
		public	SYSCALL NormalYLight
		public	SYSCALL NormalZLight
NormalXLight	dd	LIB_NORMAL_UNIT
NormalYLight	dd	0000
NormalZLight	dd	0000

		public	SYSCALL FactorLight
FactorLight	REAL4	1.52587890625E-5	;	1.0 / 65536.0

		public	SYSCALL PosXLight
		public	SYSCALL PosYLight
		public	SYSCALL PosZLight
PosXLight	dd	0000
PosYLight	dd	0000
PosZLight	dd	0000

		public	SYSCALL TargetXLight
		public	SYSCALL TargetYLight
		public	SYSCALL TargetZLight
TargetXLight	dd	0000
TargetYLight	dd	0000
TargetZLight	dd	0000

		public	SYSCALL LightNormalUnit
LightNormalUnit	dd	LIB_NORMAL_UNIT

;****************************************************************************
		extrn	SYSCALL	MatriceWorld:DWORD
		extrn	SYSCALL	MatrixLib2:DWORD

		extrn	SYSCALL	X0:DWORD
		extrn	SYSCALL	Y0:DWORD
		extrn	SYSCALL	Z0:DWORD

		extrn	SYSCALL	InitMatrixStd:DWORD
		extrn	SYSCALL	RotatePoint:DWORD
		extrn	SYSCALL	InverseRotatePoint:DWORD

;****************************************************************************
		.CODE

;****************************************************************************
		extrn	SYSCALL	GetAngleVector3D:PROC

;****************************************************************************
		public	SYSCALL SetPosLight
		public	SYSCALL SetTargetLight
		public	SYSCALL SetLightVector

;****************************************************************************
;void	SetPosLight(S32 x, S32 y, S32 z);

;#pragma aux SetPosLight	"*"		\
;	parm		[eax] [ebx] [ecx]	\
;	modify		[edx esi edi]

SetPosLight	proc

		mov	[PosXLight], eax
		mov	[PosYLight], ebx
		mov	[PosZLight], ecx

								mov     eax, [TargetXLight]
								mov     ebx, [TargetYLight]
								mov     ecx, [TargetZLight]

		jmp	ComputeLightVector

SetPosLight	endp

;****************************************************************************
;void	RecomputeLight();

;#pragma aux RecomputeLight	"*"		\
;	modify		[eax ebx ecx edx esi edi]

RecomputeLight	proc

		mov	eax, [NormalXLight]
		mov	ebx, [NormalYLight]

		mov	ecx, [NormalZLight]
		jmp	ComputeCameraLight


RecomputeLight	endp

;****************************************************************************
;void	SetTargetLight(S32 targetx, S32 targety, S32 targetz);

;#pragma aux SetTargetLight	"*"		\
;	parm		[eax] [ebx] [ecx]	\
;	modify		[edx esi edi]

SetTargetLight	proc

								mov     [TargetXLight], eax
								mov     [TargetYLight], ebx

								mov     [TargetZLight], ecx
ComputeLightVector::
		sub	eax, [PosXLight]

		sub	ebx, [PosYLight]
		sub	ecx, [PosZLight]

		call	GetAngleVector3D

		mov	eax, [X0]
		mov	ebx, [Y0]

;****************************************************************************
;void	SetLightVector( S32 alpha, S32 beta) ;

;#pragma aux SetLightVector	"*"		\
;	parm		[eax] [ebx]		\
;	modify		[ecx edx esi edi]

SetLightVector::
		and	eax, 4095
		and	ebx, 4095

		xor	ecx, ecx
		mov	[AlphaLight], eax

		mov	[BetaLight], ebx
		mov	edi, offset MatrixLib2

		call	[InitMatrixStd]

		xor	eax, eax
		xor	ebx, ebx

		mov	ecx, [LightNormalUnit]
		mov	esi, offset MatrixLib2

		call	[InverseRotatePoint]

		mov	eax, [X0]
		mov	ebx, [Y0]

		mov	ecx, [Z0]
		mov	[NormalXLight], eax

		mov	[NormalYLight], ebx
		mov	[NormalZLight], ecx
ComputeCameraLight::
		mov	esi, offset MatriceWorld
		call	[RotatePoint]

		mov	eax, [X0]
		mov	ebx, [Y0]

		mov	ecx, [Z0]
		mov	[CameraXLight], eax

		mov	[CameraYLight], ebx
		mov	[CameraZLight], ecx

		ret

SetTargetLight	endp

;****************************************************************************
;		The
		End
*/

#include <3D/LIGHT.H>
#include <3D_CONSTANTS.H>

S32 AlphaLight = 0;
S32 BetaLight = 0;

S32 CameraXLight = LIB_NORMAL_UNIT;
S32 CameraYLight = 0;
S32 CameraZLight = 0;

S32 NormalXLight = LIB_NORMAL_UNIT;
S32 NormalYLight = 0;
S32 NormalZLight = 0;

double FactorLight = 1.52587890625E-5; //	1.0 / 65536.0

S32 PosXLight = 0;
S32 PosYLight = 0;
S32 PosZLight = 0;

S32 TargetXLight = 0;
S32 TargetYLight = 0;
S32 TargetZLight = 0;

S32 LightNormalUnit = LIB_NORMAL_UNIT;

//		-----------------------------------------------------------------------

void SetPosLight(S32 x, S32 y, S32 z)
{
	PosXLight = x;
	PosYLight = y;
	PosZLight = z;

	// ComputeLightVector();
}

//		-----------------------------------------------------------------------

void RecomputeLight()
{
	// ComputeCameraLight();
}

//		-----------------------------------------------------------------------

void SetTargetLight(S32 targetx, S32 targety, S32 targetz)
{
	TargetXLight = targetx;
	TargetYLight = targety;
	TargetZLight = targetz;

	// ComputeLightVector();
}

//		-----------------------------------------------------------------------

void ComputeLightVector()
{
	S32 x, y, z;

	x = TargetXLight - PosXLight;
	y = TargetYLight - PosYLight;
	z = TargetZLight - PosZLight;

	/*GetAngleVector3D(x, y, z);

	NormalXLight = X0;
	NormalYLight = Y0;
	NormalZLight = Z0;*/

	// ComputeCameraLight();
}

//		-----------------------------------------------------------------------

void ComputeCameraLight()
{
	S32 x, y, z;

	x = NormalXLight;
	y = NormalYLight;
	z = NormalZLight;

	/* RotatePoint(x, y, z, MatrixLib2);

	CameraXLight = X0;
	CameraYLight = Y0;
	CameraZLight = Z0;*/
}

//		-----------------------------------------------------------------------

void SetLightVector(S32 alpha, S32 beta)
{
	AlphaLight = alpha & 4095;
	BetaLight = beta & 4095;
	/*
	InitMatrixStd(AlphaLight, BetaLight, 0, MatrixLib2);

	InverseRotatePoint(LightNormalUnit, 0, 0, MatrixLib2);

	NormalXLight = X0;
	NormalYLight = Y0;
	NormalZLight = Z0;
	*/

	ComputeCameraLight();
}

void ComputeLightVector(S32 x, S32 y, S32 z)
{
	/*
	ComputeLightVector::
		sub	eax, [PosXLight]

		sub	ebx, [PosYLight]
		sub	ecx, [PosZLight]

		call	GetAngleVector3D

		mov	eax, [X0]
		mov	ebx, [Y0]
*/
	NormalXLight = x - PosXLight;
	NormalYLight = y - PosYLight;
	NormalZLight = z - PosZLight;

	/*GetAngleVector3D(NormalXLight, NormalYLight, NormalZLight);

	NormalXLight = X0;
	NormalYLight = Y0;
	NormalZLight = Z0;
*/
	ComputeCameraLight();
}
