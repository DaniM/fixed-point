#include "fixed.h"
#include <stdio.h>

fixed64_t fixed64_t_add( fixed64_t a, fixed64_t b )
{
	fixed64_t result = FIXEDADD( a, b );
	return result;
}

fixed64_t fixed64_t_sub( fixed64_t a, fixed64_t b )
{
	fixed64_t result =  FIXEDSUB( a, b );
	return result;
}

fixed64_t fixed64_t_mul( fixed64_t a, fixed64_t b )
{
	fixed64_t result = F64MUL( a, b );
	return result;
}

fixed64_t fixed64_t_div( fixed64_t a, fixed64_t b )
{
	fixed64_t result = F64DIV( a, b );
	return result;
}

void fixed64_t_tostring( fixed64_t n, char* str )
{
	int chars_written = 0;
	int32_t _int = n.integer;
	uint32_t mask = 0x80000000;
	uint32_t exp = 0x00000002;

	chars_written += sprintf( str, "%i.", _int );
	
	for( int i = 0; i != 32; ++i )
	{
		if( n.frac & mask )
		{
			chars_written += sprintf( str + chars_written, "+(1/%u)", exp );
		}
		mask = mask >> 1;
		exp = exp << 1;
	}	
	*( str + chars_written ) = '\0';
}

ufixed64_t ufixed64_t_add( ufixed64_t a, ufixed64_t b )
{
	ufixed64_t result = FIXEDADD( a, b );
	return result;
}

ufixed64_t ufixed64_t_sub( ufixed64_t a, ufixed64_t b )
{
	ufixed64_t result = FIXEDSUB( a, b );
	return result;
}

ufixed64_t ufixed64_t_mul( ufixed64_t a, ufixed64_t b )
{
	ufixed64_t result = F64MUL( a, b );
	return result;
}

ufixed64_t ufixed64_t_div( ufixed64_t a, ufixed64_t b )
{
	ufixed64_t result = F64DIV( a, b );
	return result;
}

void ufixed64_t_tostring( ufixed64_t n, char* str )
{
	int chars_written = 0;
	uint32_t _int = n.integer;
	uint32_t mask = 0x80000000;
	uint32_t exp = 0x00000002;

	chars_written += sprintf( str, "%u.", _int );
	
	for( int i = 0; i != 32; ++i )
	{
		if( n.frac & mask )
		{
			chars_written += sprintf( str + chars_written, "+(1/%u)", exp );
		}
		mask = mask >> 1;
		exp = exp << 1;
	}	
	*( str + chars_written ) = '\0';
}


fixed32_t fixed32_t_add( fixed32_t a, fixed32_t b )
{
	fixed32_t result = FIXEDADD( a, b );
	return result;
}

fixed32_t fixed32_t_sub( fixed32_t a, fixed32_t b )
{
	fixed32_t result = FIXEDSUB( a, b );
	return result;
}

fixed32_t fixed32_t_mul( fixed32_t a, fixed32_t b )
{
	fixed32_t result = F32MUL( a, b );
	return result;
}

fixed32_t fixed32_t_div( fixed32_t a, fixed32_t b )
{
	fixed32_t result = F32DIV( a, b );
	return result;
}

void fixed32_t_tostring( fixed32_t n, char* str )
{
	int chars_written = 0;
	int16_t _int = n.integer;
	uint16_t mask = 0x8000;
	uint16_t exp = 0x0002;

	chars_written += sprintf( str, "%i.", _int );
	
	for( int i = 0; i != 16; ++i )
	{
		if( n.frac & mask )
		{
			chars_written += sprintf( str + chars_written, "+(1/%u)", exp );
		}
		mask = mask >> 1;
		exp = exp << 1;
	}	
	*( str + chars_written ) = '\0';
}

ufixed32_t ufixed32_t_add( ufixed32_t a, ufixed32_t b )
{
	ufixed32_t result = FIXEDADD( a, b );
	return result;
}

ufixed32_t ufixed32_t_sub( ufixed32_t a, ufixed32_t b )
{
	ufixed32_t result = FIXEDSUB( a, b );
	return result;
}

ufixed32_t ufixed32_t_mul( ufixed32_t a, ufixed32_t b )
{
	ufixed32_t result = F32MUL( a, b );
	return result;
}

ufixed32_t ufixed32_t_div( ufixed32_t a, ufixed32_t b )
{
	ufixed32_t result = F32DIV( a, b );
	return result;
}

void ufixed32_t_tostring( ufixed32_t n, char* str )
{
	int chars_written = 0;
	uint16_t _int = n.integer;
	uint16_t mask = 0x8000;
	uint16_t exp = 0x0002;

	chars_written += sprintf( str, "%u.", _int );
	
	for( int i = 0; i != 16; ++i )
	{
		if( n.frac & mask )
		{
			chars_written += sprintf( str + chars_written, "+(1/%u)", exp );
		}
		mask = mask >> 1;
		exp = exp << 1;
	}	
	*( str + chars_written ) = '\0';
}

fixed16_t fixed16_t_add( fixed16_t a, fixed16_t b )
{
	fixed16_t result = FIXEDADD( a, b );
	return result;
}

fixed16_t fixed16_t_sub( fixed16_t a, fixed16_t b )
{
	fixed16_t result = FIXEDSUB( a, b );
	return result;
}

fixed16_t fixed16_t_mul( fixed16_t a, fixed16_t b )
{
	fixed16_t result = F16MUL( a, b );
	return result;
}

fixed16_t fixed16_t_div( fixed16_t a, fixed16_t b )
{
	fixed16_t result = F16DIV( a, b );
	return result;
}

void fixed16_t_tostring( fixed16_t n, char* str )
{
	int chars_written = 0;
	int8_t _int = n.integer;
	uint8_t mask = 0x80;
	uint8_t exp = 0x02;

	chars_written += sprintf( str, "%i.", _int );
	
	for( int i = 0; i != 8; ++i )
	{
		if( n.frac & mask )
		{
			chars_written += sprintf( str + chars_written, "+(1/%u)", exp );
		}
		mask = mask >> 1;
		exp = exp << 1;
	}	
	*( str + chars_written ) = '\0';
}

ufixed16_t ufixed16_t_add( ufixed16_t a, ufixed16_t b )
{
	ufixed16_t result = FIXEDADD( a, b );
	return result;
}

ufixed16_t ufixed16_t_sub( ufixed16_t a, ufixed16_t b )
{
	ufixed16_t result = FIXEDSUB( a, b );
	return result;
}

ufixed16_t ufixed16_t_mul( ufixed16_t a, ufixed16_t b )
{
	ufixed16_t result = F16MUL( a, b );
	return result;
}

ufixed16_t ufixed16_t_div( ufixed16_t a, ufixed16_t b )
{
	ufixed16_t result = F16DIV( a, b );
	return result;
}

void ufixed16_t_tostring( ufixed16_t n, char* str )
{
	int chars_written = 0;
	uint16_t _int = n.integer;
	uint16_t mask = 0x80;
	uint16_t exp = 0x02;

	chars_written += sprintf( str, "%u.", _int );
	
	for( int i = 0; i != 16; ++i )
	{
		if( n.frac & mask )
		{
			chars_written += sprintf( str + chars_written, "+(1/%u)", exp );
		}
		mask = mask >> 1;
		exp = exp << 1;
	}	
	*( str + chars_written ) = '\0';
}
