#include "fixed.h"
#include <cstring>
#include <cassert>

using namespace std;
using namespace DaniM::Math::Types;


int test_1()
{
	fixed64_t f = 0xFFFFFFFF80000000; // -0.5
	string s = f.to_string( );
	cout << f << '\n';	
	return !( s == "-1.+(1/2)" );
}

int test_2()
{
	fixed64_t f = 0xFFFFFFFFC0000000; // -0.25
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "-1.+(1/2)+(1/4)" );
}


int test_3()
{
	fixed64_t f = 0xFFFFFFFF60000000; // -1.625
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "-1.+(1/4)+(1/8)" );
}

int test_4()
{
	fixed64_t f = 0x0000000180000000; // 1.5
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "1.+(1/2)" );
}

int test_5()
{
	fixed64_t f = 0x00000010C0000000; // 16.75
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "16.+(1/2)+(1/4)" );
}

int test_add_1()
{
	// -1.5 + 1.5
	fixed64_t a =  0xFFFFFFFE80000000; // -2 + 0.5
	fixed64_t b =  0x0000000180000000; // 1 + 0.5
	fixed64_t f = a + b;
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "0." );
}

int test_add_2()
{
	// 14.5 + 1.5
	fixed64_t a = 0x0000000E80000000; // 14 + 0.5
	fixed64_t b = 0x0000000180000000; // 1 + 0.5
	fixed64_t f =  a + b;
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "16." );
}

int test_add_3()
{
	fixed64_t a = 0xFFFFFFF0C0000000; // -16 + 0.5 + 0.25
	fixed64_t b = 0xFFFFFFFF60000000; // -1 + 0.25 + 0.125
	fixed64_t f = a + b;
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "-16.+(1/8)" );
}

int test_sub_1()
{
	fixed64_t a = 0xFFFFFFFE80000000; // -2 + 0.5
	fixed64_t b = 0x0000000180000000; // 1 + 0.5
	fixed64_t f = a - b;
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "-3." );
}

int test_sub_2()
{
	// 14.5 + 1.5
	fixed64_t a = 0x0000000E80000000; // 14 + 0.5
	fixed64_t b = 0x0000000180000000; // 1 + 0.5
	fixed64_t f = a - b;
	string s = f.to_string();
	cout << f << '\n';
	return !( s == "13." );
}

int test_sub_3()
{
	fixed64_t a = 0xFFFFFFF0C0000000; // -16 + 0.5 + 0.25
	fixed64_t b = 0xFFFFFFFF60000000; // -1 + 0.25 + 0.125
	fixed64_t f = a - b;
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "-15.+(1/4)+(1/8)" );
}


int test_mul_1()
{
	fixed64_t a = 0xFFFFFFFE80000000; // -2 + 0.5
	fixed64_t b = 0x0000000180000000; // 1 + 0.5
	fixed64_t f = a * b;
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "-3.+(1/2)+(1/4)" );
}

int test_mul_2()
{
	// 14.5 + 1.5
	fixed64_t a = 0x0000000E80000000; // 14 + 0.5
	fixed64_t b = 0x0000000180000000; // 1 + 0.5
	fixed64_t f = a * b;
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "21.+(1/2)+(1/4)" );
}

int test_mul_3()
{
	fixed64_t a = 0xFFFFFFF0C0000000; // -16 + 0.5 + 0.25
	fixed64_t b = 0xFFFFFFFF60000000; // -1 + 0.25 + 0.125
	fixed64_t f = a * b;
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "9.+(1/2)+(1/32)" );
}

int test_div_1()
{
	fixed64_t a = 0xFFFFFFFE80000000; // -2 + 0.5
	fixed64_t b = 0x0000000180000000; // 1 + 0.5
	fixed64_t f = a / b;
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "-1." );
}

int test_div_2()
{
	// 14.5 + 1.5
	fixed64_t a = 0x0000000E80000000; // 14 + 0.5
	fixed64_t b = 0x0000000180000000; // 1 + 0.5
	fixed64_t f = a / b;
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "9.+(1/2)+(1/8)+(1/32)+(1/128)+(1/512)+(1/2048)+(1/8192)+(1/32768)+(1/131072)+(1/524288)+(1/2097152)+(1/8388608)+(1/33554432)+(1/134217728)+(1/536870912)+(1/2147483648)" );
}

int test_div_3()
{
	fixed64_t a = 0xFFFFFFF0C0000000; // -16 + 0.5 + 0.25
	fixed64_t b = 0xFFFFFFFF60000000; // -1 + 0.25 + 0.125
	fixed64_t f = a / b;
	string s = f.to_string( );
	cout << f << '\n';
	return ! ( s =="24.+(1/4)+(1/8)+(1/64)+(1/128)+(1/1024)+(1/2048)+(1/16384)+(1/32768)+(1/262144)+(1/524288)+(1/4194304)+(1/8388608)+(1/67108864)+(1/134217728)+(1/1073741824)+(1/2147483648)" );
}

int test_cast_1()
{
	fixed64_t n = 0xFFFFFFFF60000000; // -1 + 0.25 + 0.125
	ufixed64_t c = cast<ufixed64_t>( n );
	return ( n.number ^ c.number );
}

int test_cast_2()
{
	fixed64_t n = 0xFFFFFFFF60000000; // -1 + 0.25 + 0.125
	fixed32_t c = cast<fixed32_t>( n );
	string s1 = n.to_string( );
	string s2 = c.to_string( );
	
	return !(s1 == s2);
}

int test_cast_3()
{
	fixed64_t n = 0xFFFFFFFF60000000; // -1 + 0.25 + 0.125
	fixed16_t c = cast<fixed16_t>( n );
	string s1 = n.to_string( );
	string s2 = c.to_string( );
	
	return !(s1 == s2);
}

int test_f32_1()
{
	fixed32_t f = 0xFFFF8000; // -0.5
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "-1.+(1/2)" );
}

int test_f32_2()
{
	fixed32_t f =  0xFFFFC000 ; // -0.25
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "-1.+(1/2)+(1/4)" );
}

int test_f32_3()
{
	fixed32_t f = 0xFFFF6000; // -1.625
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "-1.+(1/4)+(1/8)" );
}

int test_f32_4()
{
	fixed32_t f = 0x00018000; // 1.5
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "1.+(1/2)" );
}

int test_f32_5()
{
	fixed32_t f = 0x0010C000; // 16.75
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "16.+(1/2)+(1/4)" );
}

int test_f32_add_1()
{
	// -1.5 + 1.5
	fixed32_t a = 0xFFFE8000; // -2 + 0.5
	fixed32_t b = 0x00018000; // 1 + 0.5
	fixed32_t f = ( a + b );
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "0." );
}

int test_f32_add_2()
{
	// 14.5 + 1.5
	fixed32_t a = 0x000E8000; // 14 + 0.5
	fixed32_t b = 0x00018000; // 1 + 0.5
	fixed32_t f = ( a + b );
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "16." );
}

int test_f32_add_3()
{
	fixed32_t a = 0xFFF0C000; // -16 + 0.5 + 0.25
	fixed32_t b = 0xFFFF6000; // -1 + 0.25 + 0.125
	fixed32_t f = ( a + b );
	string s = f.to_string( );
	cout << f << '\n';
	return !( s == "-16.+(1/8)" );
}

/*
int test_f32_sub_1()
{
	fixed32_t a = { 0xFFFE8000 }; // -2 + 0.5
	fixed32_t b = { 0x00018000 }; // 1 + 0.5
	fixed32_t f = fixed32_t_sub( a, b );
	fixed32_t_tostring( f, str );
	printf("%s==-3.\n",str);
	return strcmp( str, "-3." );
}

int test_f32_sub_2()
{
	// 14.5 + 1.5
	fixed32_t a = { 0x000E8000 }; // 14 + 0.5
	fixed32_t b = { 0x00018000 }; // 1 + 0.5
	fixed32_t f = fixed32_t_sub( a, b );
	fixed32_t_tostring( f, str );
	printf("%s==13.\n",str);
	return strcmp( str, "13." );
}

int test_f32_sub_3()
{
	fixed32_t a = { 0xFFF0C000 }; // -16 + 0.5 + 0.25
	fixed32_t b = { 0xFFFF6000 }; // -1 + 0.25 + 0.125
	fixed32_t f = fixed32_t_sub( a, b );
	fixed32_t_tostring( f, str );
	printf("%s==-14.625\n",str);
	return strcmp( str, "-15.+(1/4)+(1/8)" );
}

int test_f32_mul_1()
{
	fixed32_t a = { 0xFFFE8000 }; // -2 + 0.5
	fixed32_t b = { 0x00018000 }; // 1 + 0.5
	fixed32_t f = fixed32_t_mul( a, b );
	fixed32_t_tostring( f, str );
	printf("%s==-2.25\n",str);
	return strcmp( str, "-3.+(1/2)+(1/4)" );
}

int test_f32_mul_2()
{
	// 14.5 + 1.5
	fixed32_t a = { 0x000E8000 }; // 14 + 0.5
	fixed32_t b = { 0x00018000 }; // 1 + 0.5
	fixed32_t f = fixed32_t_mul( a, b );
	fixed32_t_tostring( f, str );
	printf("%s==21.75\n",str);
	return strcmp( str, "21.+(1/2)+(1/4)" );
}

int test_f32_mul_3()
{
	fixed32_t a = { 0xFFF0C000 }; // -16 + 0.5 + 0.25
	fixed32_t b = { 0xFFFF6000 }; // -1 + 0.25 + 0.125
	fixed32_t f = fixed32_t_mul( a, b );
	fixed32_t_tostring( f, str );
	printf("%s==9.53125\n",str);
	return strcmp( str, "9.+(1/2)+(1/32)" );
}

int test_f32_div_1()
{
	fixed32_t a = { 0xFFFE8000 }; // -2 + 0.5
	fixed32_t b = { 0x00018000 }; // 1 + 0.5
	fixed32_t f = fixed32_t_div( a, b );
	fixed32_t_tostring( f, str );
	printf("%s==-1.\n",str);
	return strcmp( str, "-1." );
}

int test_f32_div_2()
{
	// 14.5 + 1.5
	fixed32_t a = { 0x000E8000 }; // 14 + 0.5
	fixed32_t b = { 0x00018000 }; // 1 + 0.5
	fixed32_t f = fixed32_t_div( a, b );
	fixed32_t_tostring( f, str );
	printf("%s~=9.66666667\n",str);
	return strcmp( str, "9.+(1/2)+(1/8)+(1/32)+(1/128)+(1/512)+(1/2048)+(1/8192)+(1/32768)" );
}

int test_f32_div_3()
{
	fixed32_t a = { 0xFFF0C000 }; // -16 + 0.5 + 0.25
	fixed32_t b = { 0xFFFF6000 }; // -1 + 0.25 + 0.125
	fixed32_t f = fixed32_t_div( a, b );
	fixed32_t_tostring( f, str );
	printf("%s~=24.4\n",str);
	return strcmp( str, "24.+(1/4)+(1/8)+(1/64)+(1/128)+(1/1024)+(1/2048)+(1/16384)+(1/32768)" );
}

int test_f32_cast_1()
{
	fixed32_t n = { 0xFFFF6000 }; // -1 + 0.25 + 0.125
	ufixed32_t c = CASTSIGN( n, uint32_t );
	return n.number ^ c.number;
}

int test_f32_cast_2()
{
	fixed32_t n = { 0xFFFF6000 }; // -1 + 0.25 + 0.125
	fixed16_t c = F32TOF16( n, int16_t );
	fixed32_t_tostring( n, str );
	fixed16_t_tostring( c, str2 );
	
	return strcmp( str, str2 );
}

int test_f32_cast_3()
{
	fixed32_t n = { 0xFFFF6000 }; // -1 + 0.25 + 0.125
	fixed64_t c = F32TOF64( n, int64_t );
	fixed32_t_tostring( n, str );
	fixed64_t_tostring( c, str2 );
	
	return strcmp( str, str2 );
}

int test_f16_1()
{
	fixed16_t f = { 0xFF80 }; // -0.5
	fixed16_t_tostring( f, str );
	printf("%s == -0.5\n",str);
	return strcmp( str, "-1.+(1/2)" );
}

int test_f16_2()
{
	fixed16_t f = { 0xFFC0 }; // -0.25
	fixed16_t_tostring( f, str );
	printf("%s == -0.25\n",str);
	return strcmp( str, "-1.+(1/2)+(1/4)" );
}

int test_f16_3()
{
	fixed16_t f = { 0xFF60 }; // -1.625
	fixed16_t_tostring( f, str );
	printf("%s == -1.625\n",str);
	return strcmp( str, "-1.+(1/4)+(1/8)" );
}

int test_f16_4()
{
	fixed16_t f = { 0x0180 }; // 1.5
	fixed16_t_tostring( f, str );
	printf("%s == 1.5\n",str);
	return strcmp( str, "1.+(1/2)" );
}

int test_f16_5()
{
	fixed16_t f = { 0x10C0 }; // 16.75
	fixed16_t_tostring( f, str );
	printf("%s==16.75\n",str);
	return strcmp( str, "16.+(1/2)+(1/4)" );
}

int test_f16_add_1()
{
	// -1.5 + 1.5
	fixed16_t a = { 0xFE80 }; // -2 + 0.5
	fixed16_t b = { 0x0180 }; // 1 + 0.5
	fixed16_t f = fixed16_t_add( a, b );
	fixed16_t_tostring( f, str );
	printf("%s==0.\n",str);
	return strcmp( str, "0." );
}

int test_f16_add_2()
{
	// 14.5 + 1.5
	fixed16_t a = { 0x0E80 }; // 14 + 0.5
	fixed16_t b = { 0x0180 }; // 1 + 0.5
	fixed16_t f = fixed16_t_add( a, b );
	fixed16_t_tostring( f, str );
	printf("%s==16.\n",str);
	return strcmp( str, "16." );
}

int test_f16_add_3()
{
	fixed16_t a = { 0xF0C0 }; // -16 + 0.5 + 0.25
	fixed16_t b = { 0xFF60 }; // -1 + 0.25 + 0.125
	fixed16_t f = fixed16_t_add( a, b );
	fixed16_t_tostring( f, str );
	printf("%s==-15.875\n",str);
	return strcmp( str, "-16.+(1/8)" );
}

int test_f16_sub_1()
{
	fixed16_t a = { 0xFE80 }; // -2 + 0.5
	fixed16_t b = { 0x0180 }; // 1 + 0.5
	fixed16_t f = fixed16_t_sub( a, b );
	fixed16_t_tostring( f, str );
	printf("%s==-3.\n",str);
	return strcmp( str, "-3." );
}

int test_f16_sub_2()
{
	// 14.5 + 1.5
	fixed16_t a = { 0x0E80 }; // 14 + 0.5
	fixed16_t b = { 0x0180 }; // 1 + 0.5
	fixed16_t f = fixed16_t_sub( a, b );
	fixed16_t_tostring( f, str );
	printf("%s==13.\n",str);
	return strcmp( str, "13." );
}

int test_f16_sub_3()
{
	fixed16_t a = { 0xF0C0 }; // -16 + 0.5 + 0.25
	fixed16_t b = { 0xFF60 }; // -1 + 0.25 + 0.125
	fixed16_t f = fixed16_t_sub( a, b );
	fixed16_t_tostring( f, str );
	printf("%s==-14.625\n",str);
	return strcmp( str, "-15.+(1/4)+(1/8)" );
}

int test_f16_mul_1()
{
	fixed16_t a = { 0xFE80 }; // -2 + 0.5
	fixed16_t b = { 0x0180 }; // 1 + 0.5
	fixed16_t f = fixed16_t_mul( a, b );
	fixed16_t_tostring( f, str );
	printf("%s==-2.25\n",str);
	return strcmp( str, "-3.+(1/2)+(1/4)" );
}

int test_f16_mul_2()
{
	// 14.5 + 1.5
	fixed16_t a = { 0x0E80 }; // 14 + 0.5
	fixed16_t b = { 0x0180 }; // 1 + 0.5
	fixed16_t f = fixed16_t_mul( a, b );
	fixed16_t_tostring( f, str );
	printf("%s==21.75\n",str);
	return strcmp( str, "21.+(1/2)+(1/4)" );
}

int test_f16_mul_3()
{
	fixed16_t a = { 0xF0C0 }; // -16 + 0.5 + 0.25
	fixed16_t b = { 0xFF60 }; // -1 + 0.25 + 0.125
	fixed16_t f = fixed16_t_mul( a, b );
	fixed16_t_tostring( f, str );
	printf("%s==9.53125\n",str);
	return strcmp( str, "9.+(1/2)+(1/32)" );
}

int test_f16_div_1()
{
	fixed16_t a = { 0xFE80 }; // -2 + 0.5
	fixed16_t b = { 0x0180 }; // 1 + 0.5
	fixed16_t f = fixed16_t_div( a, b );
	fixed16_t_tostring( f, str );
	printf("%s==-1.\n",str);
	return strcmp( str, "-1." );
}

int test_f16_div_2()
{
	// 14.5 + 1.5
	fixed16_t a = { 0x0E80 }; // 14 + 0.5
	fixed16_t b = { 0x0180 }; // 1 + 0.5
	fixed16_t f = fixed16_t_div( a, b );
	fixed16_t_tostring( f, str );
	printf("%s~=9.66666667\n",str);
	return strcmp( str, "9.+(1/2)+(1/8)+(1/32)+(1/128)" );
}

int test_f16_div_3()
{
	fixed16_t a = { 0xF0C0 }; // -16 + 0.5 + 0.25
	fixed16_t b = { 0xFF60 }; // -1 + 0.25 + 0.125
	fixed16_t f = fixed16_t_div( a, b );
	fixed16_t_tostring( f, str );
	printf("%s~=24.4\n",str);
	return strcmp( str, "24.+(1/4)+(1/8)+(1/64)+(1/128)" );
}

int test_f16_cast_1()
{
	fixed16_t n = { 0xFF60 }; // -1 + 0.25 + 0.125
	ufixed16_t c = CASTSIGN( n, uint16_t );
	uint16_t rc = ( n.number ^ c.number ); // avoid sign extension
	return rc;
}

int test_f16_cast_2()
{
	fixed16_t n = { 0xFF60 }; // -1 + 0.25 + 0.125
	fixed32_t c = F16TOF32( n, int32_t );
	fixed16_t_tostring( n, str );
	fixed32_t_tostring( c, str2 );
	
	return strcmp( str, str2 );
}

int test_f16_cast_3()
{
	fixed16_t n = { 0xFF60 }; // -1 + 0.25 + 0.125
	fixed64_t c = F16TOF64( n, int64_t );
	fixed16_t_tostring( n, str );
	fixed64_t_tostring( c, str2 );
	
	return strcmp( str, str2 );
}

*/

int main( int argc, const char* args[] )
{
	int rc = test_1();
	assert( !rc && "test 1 failed" );
	rc = test_2();
	assert( !rc && "test 2 failed" );

	rc = test_3();
	assert( !rc && "test 3 failed" );
	rc = test_4();
	assert( !rc && "test 4 failed" );
	rc = test_5();
	assert( !rc && "test 5 failed" );

	rc = test_add_1();
	assert( !rc && "test add 1 failed" );
	rc = test_add_2();
	assert( !rc && "test add 2 failed" );
	rc = test_add_3();
	assert( !rc && "test add 3 failed" );

	rc = test_sub_1();
	assert( !rc && "test sub 1 failed" );
	rc = test_sub_2();
	assert( !rc && "test sub 2 failed" );
	rc = test_sub_3();
	assert( !rc && "test sub 3 failed" );

	rc = test_mul_1();
	assert( !rc && "test mul 1 failed" );
	rc = test_mul_2();
	assert( !rc && "test mul 2 failed" );
	rc = test_mul_3();
	assert( !rc && "test mul 3 failed" );

	rc = test_div_1();
	assert( !rc && "test div 1 failed" );
	rc = test_div_2();
	assert( !rc && "test div 2 failed" );
	rc = test_div_3();
	assert( !rc && "test div 3 failed" );

	rc = test_cast_1();
	assert( !rc && "test cast 1 failed" );
	rc = test_cast_2();
	assert( !rc && "test cast 2 failed" );
	rc = test_cast_3();
	assert( !rc && "test cast 3 failed" );

	rc = test_f32_1();
	assert( !rc && "test f32 1 failed" );
	rc = test_f32_2();
	assert( !rc && "test f32 2 failed" );
	rc = test_f32_3();
	assert( !rc && "test f32 3 failed" );
	rc = test_f32_4();
	assert( !rc && "test f32 4 failed" );
	rc = test_f32_5();
	assert( !rc && "test f32 5 failed" );

	rc = test_f32_add_1();
	assert( !rc && "test f32 add 1 failed" );
	rc = test_f32_add_2();
	assert( !rc && "test f32 add 2 failed" );
	rc = test_f32_add_3();
	assert( !rc && "test f32 add 3 failed" );

/*
	rc = test_f32_sub_1();
	assert( !rc && "test f32 sub 1 failed" );
	rc = test_f32_sub_2();
	assert( !rc && "test f32 sub 2 failed" );
	rc = test_f32_sub_3();
	assert( !rc && "test f32 sub 3 failed" );

	rc = test_f32_mul_1();
	assert( !rc && "test f32 mul 1 failed" );
	rc = test_f32_mul_2();
	assert( !rc && "test f32 mul 2 failed" );
	rc = test_f32_mul_3();
	assert( !rc && "test f32 mul 3 failed" );

	rc = test_f32_div_1();
	assert( !rc && "test f32 div 1 failed" );
	rc = test_f32_div_2();
	assert( !rc && "test f32 div 2 failed" );
	rc = test_f32_div_3();
	assert( !rc && "test f32 div 3 failed" );

	rc = test_f32_cast_1();
	assert( !rc && "test f32 cast 1 failed" );
	rc = test_f32_cast_2();
	assert( !rc && "test f32 cast 2 failed" );
	rc = test_f32_cast_3();
	assert( !rc && "test f32 cast 3 failed" );


	rc = test_f16_1();
	assert( !rc && "test f16 1 failed" );
	rc = test_f16_2();
	assert( !rc && "test f16 2 failed" );
	rc = test_f16_3();
	assert( !rc && "test f16 3 failed" );
	rc = test_f16_4();
	assert( !rc && "test f16 4 failed" );
	rc = test_f16_5();
	assert( !rc && "test f16 5 failed" );

	rc = test_f16_add_1();
	assert( !rc && "test f16 add 1 failed" );
	rc = test_f16_add_2();
	assert( !rc && "test f16 add 2 failed" );
	rc = test_f16_add_3();
	assert( !rc && "test f16 add 3 failed" );

	rc = test_f16_sub_1();
	assert( !rc && "test f16 sub 1 failed" );
	rc = test_f16_sub_2();
	assert( !rc && "test f16 sub 2 failed" );
	rc = test_f16_sub_3();
	assert( !rc && "test f16 sub 3 failed" );

	rc = test_f16_mul_1();
	assert( !rc && "test f16 mul 1 failed" );
	rc = test_f16_mul_2();
	assert( !rc && "test f16 mul 2 failed" );
	rc = test_f16_mul_3();
	assert( !rc && "test f16 mul 3 failed" );

	rc = test_f16_div_1();
	assert( !rc && "test f16 div 1 failed" );
	rc = test_f16_div_2();
	assert( !rc && "test f16 div 2 failed" );
	rc = test_f16_div_3();
	assert( !rc && "test f16 div 3 failed" );

	rc = test_f16_cast_1();
	assert( !rc && "test f16 cast 1 failed" );
	rc = test_f16_cast_2();
	assert( !rc && "test f16 cast 2 failed" );
	rc = test_f16_cast_3();
	assert( !rc && "test f16 cast 3 failed" );

*/
	return 0;
}
