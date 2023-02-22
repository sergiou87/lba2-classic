// ──────────────────────────────────────────────────────────────────────────
#include <SYSTEM/ADELINE.H>
#include <SYSTEM/N_MALLOC.H>

#include <stdlib.h>

// ──────────────────────────────────────────────────────────────────────────
#define MALLOC_MASK (~(MALLOC_ALIGN - 1))

// ──────────────────────────────────────────────────────────────────────────
void *NormMalloc(U32 size)
{
	S32 addr, temp;

	temp = (S32)malloc(size + MALLOC_ALIGN);

	if (!temp)
	{
		return NULL;
	}

	addr = (temp + MALLOC_ALIGN) & MALLOC_MASK;

	*((S8 *)addr - 2) = 0;
	*((S8 *)addr - 1) = (S8)(addr - temp);

	return (void *)addr;
}

// ──────────────────────────────────────────────────────────────────────────
void NormFree(void *addr)
{
	addr = (void *)((S32)addr - *((S8 *)addr - 1));
	free(addr);
}

// ──────────────────────────────────────────────────────────────────────────
void *NormMshrink(void *addr, U32 size)
{
	void *temp;

	temp = (void *)((S32)addr - *((S8 *)addr - 1));

	// TODO: delete?? or just return realloc(temp, (size_t)(size + MALLOC_ALIGN)) ?
	// if (!_expand(temp, (size_t)(size + MALLOC_ALIGN)))
	// {
	// 	addr = NULL;
	// }

	return addr;
}

// ──────────────────────────────────────────────────────────────────────────
