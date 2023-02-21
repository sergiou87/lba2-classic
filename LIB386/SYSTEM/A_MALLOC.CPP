//──────────────────────────────────────────────────────────────────────────
#include	<SYSTEM/adeline.h>
#include	<SYSTEM/dosmallo.h>
#include	<SYSTEM/a_malloc.h>

#include	<malloc.h>

//──────────────────────────────────────────────────────────────────────────
void	*SmartMalloc(S32 size)
{
	void 	*addr ;

	addr = DosMalloc(size)		;
	if( !addr )
	{
		addr = Malloc(size)	;
	}

	return(addr)	;
}

//──────────────────────────────────────────────────────────────────────────
