// ──────────────────────────────────────────────────────────────────────────
#include <SYSTEM/ADELINE.H>
#include <SYSTEM/AVAILMEM.H>

// ──────────────────────────────────────────────────────────────────────────

U32 AvailableMem()
{
  return 0x7FFFFFFF;
  // TODO: this can be deleted, probably
  // MEMORYSTATUS	mem				;

  // GlobalMemoryStatus(&mem)			;

  // return mem.dwAvailPageFile+mem.dwAvailPhys	;
}

// ──────────────────────────────────────────────────────────────────────────
