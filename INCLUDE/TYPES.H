/* 
 * File:types.h
 */
/*
 * $PSLibId: Run-time Library Release 4.7$
 */

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

/*
 * Basic system types and major/minor device constructing/busting macros.
 */

/* major part of a device */
#define major(x) ((int)(((unsigned)(x) >> 8) & 0377))

/* minor part of a device */
#define minor(x) ((int)((x)&0377))

/* make a device number */
#define makedev(x, y) ((dev_t)(((x) << 8) | (y)))

#ifndef _BYTE
#define _BYTE
typedef unsigned char byte;
#endif
#ifndef _u_char_T
#define _u_char_T
typedef unsigned char u_char;
#endif
#ifndef _u_short_T
#define _u_short_T
typedef unsigned short u_short;
#endif
#ifndef _u_int_T
#define _u_int_T
typedef unsigned int u_int;
#endif
#ifndef _u_long_T
#define _u_long_T
typedef unsigned long u_long;
#endif
#ifndef _SYSIII_u_short
#define _SYSIII_u_short
typedef unsigned short u_short; /* sys III compat */
#endif
#ifndef __psx__
#ifndef _SYSV_u_int
#define _SYSV_u_int
typedef unsigned int u_int; /* sys V compat */
#endif
#ifndef _SYSV_u_long
#define _SYSV_u_long
typedef unsigned long u_long; /* sys V compat */
#endif
#endif /* ! __psx__ */

typedef struct _physadr
{
	int r[1];
} * physadr;
typedef struct label_t
{
	int val[12];
} label_t;

typedef struct _quad
{
	long val[2];
} quad;
typedef long daddr_t;
typedef char *caddr_t;
typedef long *qaddr_t; /* should be typedef quad * qaddr_t; */
typedef u_long ino_t;
typedef long swblk_t;

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned int size_t;
#endif

typedef long time_t;
typedef short dev_t;
typedef long off_t;
typedef u_short uid_t;
typedef u_short gid_t;

#define NBBY 8 /* number of bits in a byte */

#endif /* _SYS_TYPES_H */
