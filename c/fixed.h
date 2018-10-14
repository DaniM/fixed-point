#ifndef __FIXED_H__
#define __FIXED_H__

#ifdef _WINDOWS

#include <windows.h>

typedef INT64 int64_t;
typedef INT32 int32_t;
typedef INT16 int16_t;
typedef INT8  int8_t;


typedef UINT64 uint64_t;
typedef UINT32 uint32_t;
typedef UINT16 uint16_t;
typedef UINT8  uint8_t;



#else

#include <stdint.h>

#endif


struct fixed_32_32_t
{

union
{

	int64_t number;

	struct {
#ifdef _BIGENDIAN
		int32_t integer; // msb
		int32_t frac; // lsb

#else
		int32_t frac; // lsb
		int32_t integer; // msb
#endif
	};
};

};

struct fixed_16_16_t
{
union
{
	int32_t number;

	struct {
#ifdef _BIGENDIAN
		int16_t integer; // msb
		int16_t frac; // lsb

#else
		int16_t frac; // lsb
		int16_t integer; // msb
#endif
	};
};
};

struct fixed_8_8_t
{
union
{
	int16_t number;

	struct {
#ifdef _BIGENDIAN
		int8_t integer; // msb
		int8_t frac; // lsb

#else
		int8_t frac; // lsb
		int8_t integer; // msb
#endif	
	};
};
};

struct ufixed_32_32_t
{
union
{
	uint64_t number;

	struct {
#ifdef _BIGENDIAN
		uint32_t integer; // msb
		uint32_t frac; // lsb

#else
		uint32_t frac; // lsb
		uint32_t integer; // msb
#endif	
	};
};

};

struct ufixed_16_16_t
{
union
{
	uint32_t number;

	struct {
#ifdef _BIGENDIAN
		uint16_t integer; // msb
		uint16_t frac; // lsb

#else
		uint16_t frac; // lsb
		uint16_t integer; // msb
#endif	
	};
};
};

struct ufixed_8_8_t
{
union
{
	uint16_t number;

	struct {
#ifdef _BIGENDIAN
		uint8_t integer; // msb
		uint8_t frac; // lsb

#else
		uint8_t frac; // lsb
		uint8_t integer; // msb
#endif	
	};
};
};

typedef struct fixed_32_32_t 	fixed64_t;
typedef struct ufixed_32_32_t 	ufixed64_t;
typedef struct fixed_16_16_t 	fixed32_t;
typedef struct ufixed_16_16_t 	ufixed32_t;
typedef struct fixed_8_8_t 	fixed16_t;
typedef struct ufixed_8_8_t 	ufixed16_t;
 


#define FIXEDADD( a, b ) { a.number + b.number } 
#define FIXEDSUB( a, b ) { a.number - b.number } 

#define F64MUL( a, b ) { ( a.number >> 16 ) * ( b.number >> 16 ) } 
#define F64DIV( a, b ) { ( a.number << 16 ) / ( b.number >> 16 ) } 

#define F32MUL( a, b ) { ( a.number >> 8 ) * ( b.number >> 8 ) } 
#define F32DIV( a, b ) { ( a.number << 8 ) / ( b.number >> 8 ) } 

#define F16MUL( a, b ) { ( a.number >> 4 ) * ( b.number >> 4 ) } 
#define F16DIV( a, b ) { ( a.number << 4 ) / ( b.number >> 4 ) } 

// the following arithmetic ops are just for adding a little type restriction
// it should be more than enough with the previous macros (if you know what you are doing)
fixed64_t fixed64_t_add( fixed64_t a, fixed64_t b );
fixed64_t fixed64_t_sub( fixed64_t a, fixed64_t b );
fixed64_t fixed64_t_mul( fixed64_t a, fixed64_t b );
fixed64_t fixed64_t_div( fixed64_t a, fixed64_t b );

ufixed64_t ufixed64_t_add( ufixed64_t a, ufixed64_t b );
ufixed64_t ufixed64_t_sub( ufixed64_t a, ufixed64_t b );
ufixed64_t ufixed64_t_mul( ufixed64_t a, ufixed64_t b );
ufixed64_t ufixed64_t_div( ufixed64_t a, ufixed64_t b );

fixed32_t fixed32_t_add( fixed32_t a, fixed32_t b );
fixed32_t fixed32_t_sub( fixed32_t a, fixed32_t b );
fixed32_t fixed32_t_mul( fixed32_t a, fixed32_t b );
fixed32_t fixed32_t_div( fixed32_t a, fixed32_t b );

ufixed32_t ufixed32_t_add( ufixed32_t a, ufixed32_t b );
ufixed32_t ufixed32_t_sub( ufixed32_t a, ufixed32_t b );
ufixed32_t ufixed32_t_mul( ufixed32_t a, ufixed32_t b );
ufixed32_t ufixed32_t_div( ufixed32_t a, ufixed32_t b );

fixed16_t fixed16_t_add( fixed16_t a, fixed16_t b );
fixed16_t fixed16_t_sub( fixed16_t a, fixed16_t b );
fixed16_t fixed16_t_mul( fixed16_t a, fixed16_t b );
fixed16_t fixed16_t_div( fixed16_t a, fixed16_t b );

ufixed16_t ufixed16_t_add( ufixed16_t a, ufixed16_t b );
ufixed16_t ufixed16_t_sub( ufixed16_t a, ufixed16_t b );
ufixed16_t ufixed16_t_mul( ufixed16_t a, ufixed16_t b );
ufixed16_t ufixed16_t_div( ufixed16_t a, ufixed16_t b );


void fixed64_t_tostring( fixed64_t n, char* str );

void ufixed64_t_tostring( ufixed64_t n, char* str );

void fixed32_t_tostring( fixed32_t n, char* str );

void ufixed32_t_tostring( ufixed32_t n, char* str );

void fixed16_t_tostring( fixed16_t n, char* str );

void ufixed16_t_tostring( ufixed16_t n, char* str );


// Converters
#define CASTSIGN( a, b ) { (b)a.number }

#define F16TOF32( a, b ) { .number = ((b)a.number) << 8 }
#define F16TOF64( a, b ) { .number = ((b)a.number) << 24 }

#define F32TOF16( a, b ) { .number=(b)( a.number >> 8 ) }
#define F32TOF64( a, b ) { .number=((b)a.number) << 16 }

#define F64TOF16( a, b ) { .number=(b)(a.number>>24) }
#define F64TOF32( a, b ) { .number=(b)(a.number>>16) }


#endif

