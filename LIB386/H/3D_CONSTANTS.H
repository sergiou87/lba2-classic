#define NORMAL_UNIT 16384
#define LIB_NORMAL_UNIT 15360 /* INT(15*256*4) */
/*LIB_NORMAL_UNIT	equ	16381	; INT(4095.49*65536/16384)
					;       MAX  *shift/ colinearity case
					; 16382 is too big, bcoz we can get 4095.5
					; that's bounded up to 4096=>overflow
*/
#define TYPE_3D 0
#define TYPE_ISO 1
