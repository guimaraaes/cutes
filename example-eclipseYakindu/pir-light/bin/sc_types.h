/** Generated by YAKINDU Statechart Tools code generator. */

#ifndef SC_TYPES_H_
#define SC_TYPES_H_

/* As <cstdint> is not available on all platforms we choose to include <stdint.h>. You can switch to <cstdint> by commenting and uncommenting the lines below.*/
// #include <cstdint>
#include <stdint.h>

#ifndef sc_string
#define sc_string      char*
#endif

typedef int_fast16_t   sc_short;
typedef uint_fast16_t  sc_ushort;
typedef int32_t        sc_integer;
typedef int16_t		   sc_errorCode;
typedef double         sc_real;
typedef bool           sc_boolean;

typedef intptr_t       sc_eventid;

#ifndef sc_null
	#ifdef __cplusplus
		#if __cplusplus >= 201103L || (defined(_MSC_VER) && _MSC_VER >= 1900)
	  		#define sc_null nullptr
		#else
			#define sc_null 0
		#endif
	#else
		#define sc_null ((void *)0)
	#endif
#endif

#endif /* SC_TYPES_H_ */
