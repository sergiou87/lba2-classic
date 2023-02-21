// ──────────────────────────────────────────────────────────────────────────
#include <SYSTEM/adeline.h>
#include <SVGA/logphys.h>
#include <SVGA/clip.h>
#include <SVGA/plot.h>

// ──────────────────────────────────────────────────────────────────────────
void Plot(S32 x0, S32 y0, S32 coul)
{
	if ((x0 < ClipXMin) ||
			(x0 > ClipXMax) ||
			(y0 < ClipYMin) ||
			(y0 > ClipYMax))
	{
		return;
	}

	((U8 *)Log)[y0 * ModeDesiredX + x0] = (U8)coul;
}

// ──────────────────────────────────────────────────────────────────────────
S32 GetPlot(S32 x0, S32 y0)
{
	if ((x0 < ClipXMin) ||
			(x0 > ClipXMax) ||
			(y0 < ClipYMin) ||
			(y0 > ClipYMax))
	{
		return 0;
	}

	return ((U8 *)Log)[y0 * ModeDesiredX + x0];
}

// ──────────────────────────────────────────────────────────────────────────
