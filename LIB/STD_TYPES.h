#ifndef STD_TYPES_H
#define STD_TYPES_H
	
/* Unsigned integer types */
typedef unsigned char           u8;     // 8-bit unsigned integer
typedef unsigned short int      u16;    // 16-bit unsigned integer
typedef unsigned long int       u32;    // 32-bit unsigned integer
typedef unsigned long long int  u64;    // 64-bit unsigned integer

/* Signed integer types */
typedef signed char             s8;     // 8-bit signed integer
typedef signed short int        s16;    // 16-bit signed integer
typedef signed long int         s32;    // 32-bit signed integer
typedef signed long long int    s64;    // 64-bit signed integer

/* Floating-point types */
typedef float                   f32;    // 32-bit floating-point number
typedef double                  f64;    // 64-bit floating-point number
typedef long double             f128;   // 128-bit floating-point number

/* Macros for success and failure */
#define STD_OK  1                       // Success
#define STD_NOK 0                       // Failure

/* Definition of NULL pointer */
#define NULL ((void*)0)

#endif /* STD_TYPES_H */
