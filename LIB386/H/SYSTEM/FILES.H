//--------------------------------------------------------------------------//
#ifndef LIB_SYSTEM_FILES
#define LIB_SYSTEM_FILES

//--------------------------------------------------------------------------//
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utime.h>
#include <fcntl.h>
#include <unistd.h>

//--------------------------------------------------------------------------//
#ifdef __cplusplus
extern "C"
{
#endif

//--------------------------------------------------------------------------//
#define MODE_READ (O_RDONLY)
#define MODE_WRITE (O_WRONLY | O_CREAT | O_TRUNC)
#define MODE_READWRITE (O_RDWR | O_CREAT)

//--------------------------------------------------------------------------//
#define SEEK_START SEEK_SET
#define SEEK_CURRENT SEEK_CUR

	//--------------------------------------------------------------------------//
	extern S32 OpenMode(char *name, int mode);

	//--------------------------------------------------------------------------//
	// #define Delete	!remove

	extern U32 Delete(char *name);

#ifdef __SW_3R
#pragma aux Delete = \
		"	call	remove	"  \
		"	test	eax, eax" \
		"	mov	eax, 1	"   \
		"	jz	ok	"        \
		"	xor	eax, eax"  \
		"ok:			" parm caller[eax] value[eax]
#else //	__SW_3R
#pragma aux Delete = \
		"	call	remove	"  \
		"	test	eax, eax" \
		"	mov	eax, 1	"   \
		"	jz	ok	"        \
		"	xor	eax, eax"  \
		"ok:			" parm caller[] modify[eax ecx edx] value[eax]
#endif //__SW_3R

//--------------------------------------------------------------------------//
#define Read(handle, buffer, lenread) read(handle, buffer, lenread)
#define Write(handle, buffer, lenwrite) write(handle, buffer, lenwrite)
#define Close(handle) close(handle)
#define Seek(handle, position, mode) lseek(handle, position, mode)
#define Touch(filename) utime(filename, NULL)

//--------------------------------------------------------------------------//

//--------------------------------------------------------------------------//
#define OpenRead(name) OpenMode(name, MODE_READ)
#define OpenWrite(name) OpenMode(name, MODE_WRITE)
#define OpenReadWrite(name) OpenMode(name, MODE_READWRITE)

	//--------------------------------------------------------------------------//
	extern U32 FileSize(const char *name);

//--------------------------------------------------------------------------//
#ifdef __cplusplus
}
#endif

//--------------------------------------------------------------------------//
#endif // LIB_SYSTEM_FILES

//--------------------------------------------------------------------------//
