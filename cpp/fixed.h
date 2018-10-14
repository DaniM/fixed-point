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

#include <iostream>
#include <sstream>

namespace DaniM
{
namespace Math
{
namespace Types
{

template<typename NUMBER> class FixedPoint;

template<typename NUMBER> std::ostream& operator<<(std::ostream& out, FixedPoint<NUMBER> f);

template<typename TO, typename FROM>
TO cast(const FROM& f)
{
	TO c;
	const size_t from_size = sizeof( typename FROM::type );
	const size_t to_size = sizeof( typename TO::type );

	if( from_size > to_size )
	{
		const size_t diff = (from_size - to_size) << 2;
		c.number = ( typename TO::type )( f.number >> diff );
	}
	else if( from_size < to_size )
	{
		// careful with losing the sign
		const size_t diff = (to_size - from_size) << 2;
		c.number = ( typename TO::type )( f.number );
		c.number = c.number << diff;
	}
	else
	{
		c.number = (typename TO::type)( f.number );
	}

	return c;
}

template<typename NUMBER>
class FixedPoint
{
public:
	typedef NUMBER type;

	FixedPoint() : number( 0 ) {}

	FixedPoint( NUMBER n ) : number( n ) {}

	FixedPoint( const FixedPoint& f ) : number( f.number ) {}

	template<typename FROM>
	explicit FixedPoint( const FixedPoint<FROM>& f )
	{
		number = cast<FixedPoint<NUMBER>,FixedPoint<FROM> >( f ).number;
	}


	NUMBER integer() const 
	{
		const size_t disp = sizeof(NUMBER) << 2;
		return number >> disp;
	}

	NUMBER fract() const
	{
		const size_t disp = sizeof(NUMBER) << 2;
		const NUMBER mask = (~(number ^ number)) >> disp;	
		return number & mask;
	}

	size_t prec() const
	{
		return sizeof( NUMBER ) << 2;
	}

	FixedPoint& operator+=( const FixedPoint f )
	{
		number += f.number;
		return *this;
	}

	FixedPoint& operator-=( const FixedPoint f )
	{
		number -= f.number;
		return *this;
	}

	FixedPoint& operator*=( const FixedPoint f )
	{
		const size_t disp = sizeof(NUMBER) << 1;
		number = ( number >> disp ) * ( f.number >> disp );
		return *this;
	}

	FixedPoint& operator/=( const FixedPoint f )
	{
		const size_t disp = sizeof(NUMBER) << 1;
		number = ( number << disp ) / ( f.number >> disp );
		return *this;
	}

	std::string to_string( )
	{
		std::ostringstream os;
		os << *this;
		return os.str();
	}

	NUMBER number;
};


template<typename NUMBER>
std::ostream& operator<<(std::ostream& out, FixedPoint<NUMBER> f)
{
	out << f.integer() << ".";
	NUMBER frac = f.fract();
	size_t p = f.prec();
	size_t mask = 1 << ( p - 1 );
	size_t exp = 2;
	for( size_t i = 0; i != p; ++i )
	{
		if( mask & frac )
		{
			out << "+(" << "1/"<< exp << ")";
		}

		mask = mask >> 1;
		exp = exp << 1;
	}

	return out;
}

template<typename NUMBER>
FixedPoint<NUMBER> operator+( FixedPoint<NUMBER> f1, FixedPoint<NUMBER> f2 )
{
	FixedPoint<NUMBER> f( f1 );
	return f += f2;
}

template<typename NUMBER>
FixedPoint<NUMBER> operator-( FixedPoint<NUMBER> f1, FixedPoint<NUMBER> f2 )
{
	FixedPoint<NUMBER> f( f1 );
	return f -= f2;
}

template<typename NUMBER>
FixedPoint<NUMBER> operator*( FixedPoint<NUMBER> f1, FixedPoint<NUMBER> f2 )
{
	FixedPoint<NUMBER> f( f1 );
	return f*=f2;	
}

template<typename NUMBER>
FixedPoint<NUMBER> operator/( FixedPoint<NUMBER> f1, FixedPoint<NUMBER> f2 )
{
	FixedPoint<NUMBER> f( f1 );
	return f/=f2;	
}


typedef FixedPoint<int64_t> 	fixed64_t;
typedef FixedPoint<uint64_t>	ufixed64_t;
typedef FixedPoint<int32_t> 	fixed32_t;
typedef FixedPoint<uint32_t> 	ufixed32_t;
typedef FixedPoint<int16_t> 	fixed16_t;
typedef FixedPoint<uint16_t> 	ufixed16_t;



}
}
}

#endif
