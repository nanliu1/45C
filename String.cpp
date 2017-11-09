 #include <iostream>
 #include "String.h"
using namespace std;

int String :: allocations = 0;

void String :: error( const char *p )
{
    cerr << "Error ( class String ): " << p << endl;
}

void String :: final_report_on_allocations()
{
	if ( allocations > 0 ) error( "Memory Leak in class String" );
	if ( allocations < 0 ) error( "Too many delete[]s in class String" );
	if ( allocations == 0 )
		cout << "Number of new allocations minus number of delete deallocations is 0" << endl;
}

char* String :: new_char_array( int n_bytes )
{
	++allocations;
	return new char[n_bytes];
}

void String :: delete_char_array( char *p )
{
	--allocations;
	if ( allocations < 0 ) error("more delete[] than new[]");
	delete[] p;
}



bool String :: inBounds ( int i )
{
	return i >= 0 && i < strlen( buf );
}

int String :: strlen( const char *src )
{
	int len = 0;
	for (int i = 0; src[i] != '\0'; ++i )
		++len;
	return len;
}


char* String :: strdup( const char *src )
{
	int size = strlen(src) + 1;	
	return strcpy( new_char_array( size ), src );
}

char* String :: strcpy( char *dst, const char *src)
{
	int i;
	for (i = 0; src[i] != '\0'; ++i)
		dst[i] = src[i];
	dst[i] = src[i];
	return dst;
}


char* String :: strcat( char *dst, const char *src)
{
	strcpy( dst + strlen( dst ), src );
	return dst;
		
}



int String :: strcmp( const char *left, const char *right )
{
	int i = 0;
	while ( left[i] == right[i])
	{
		if (left[i] == '\0' && right[i] == '\0')
			return 0;
		++i;
	}
	return left[i] - right[i];
}

int String :: strncmp( const char *left, const char *right, int n )
{
	int i = 0;

	while (left[i] == right[i] && i < n)
	{
		if ( i == n-1)
			return 0;
		++i;
	}
	return left[i] - right[i];
}

char* String :: strchr( char*str, int c )
{
	int i;
	for ( i = 0; str[i] != c; ++i )
		if ( str[i] == '\0' )
			return 0;
	return &str[i];
}



char* String :: strstr( char *haystack, const char *needle )
{
	int i;
	int m = strlen( haystack );
	int n = strlen( needle );
	for ( i = 0; i < m; ++i )
		if ( strncmp( haystack, needle, n ) == 0 )
		{	
			return haystack;
		} 
		else
		{
			++haystack;
		}
	return 0;
}



void String :: print( ostream & out )
{
	out << buf;
}

void String :: read( istream & in )
{
	char temp[256];
	in.getline( temp, 255 );
	delete_char_array(buf);
	buf = strdup( temp );

}



ostream & operator << ( ostream & out, String str )
{
	str.print( out );
	return out;
}

istream & operator >> ( istream & in, String & str )
{
	str.read( in );
	return in;
}


String :: String( const char *s )
	:buf(strdup (s))
{
}

String :: String( const String & s )
	:buf(strdup (s.buf))
{
}

String String :: operator = ( const String & s )
{
	delete_char_array( buf );
	buf = strdup( s.buf );
	return *this;
}
	
char & String :: operator [] ( int index )
{
	if ( !inBounds( index ) )
	{
		cout << "Out of Bounds" << endl;
		return buf[0];
	}
	return buf[index];
}	
	
int String :: size()
{
	return strlen( buf );
}

String String :: reverse ()
{
	String rvs( buf );
	int n = strlen( buf );
	int i;

	for ( i = n-1; i >= 0; --i )
	{
		rvs.buf[n-i-1] = buf[i];
	}
	rvs.buf[n] = '\0';
	return rvs;
}

int String :: indexOf( const char c )
{
	if ( strchr( buf, c ) )
		return strchr( buf, c ) - buf;
	return -1;
}

int String :: indexOf( const String pattern )
{
	if ( strstr( buf, pattern.buf ) )
		return strstr( buf, pattern.buf ) - buf;
	return -1;
}
	
bool String :: operator == ( const String s )
{
	if ( !strcmp( buf, s.buf ) )
		return true;
	return false;
} 

bool String :: operator != ( const String s )
{
	return !(*this == s );
}

bool String :: operator > ( const String s )
{
	if ( strcmp( buf, s.buf ) > 0 ) 
		return true;
	return false;
}

bool String :: operator < ( const String s )
{
	if ( strcmp( buf, s.buf ) < 0 )
		return true;
	return false;
}

bool String :: operator <= ( const String s )
{
	return !( *this > s );
}

bool String :: operator >= ( const String s )
{
	return !( *this < s );
}

String String :: operator + ( const String s )
{
	char *dupbuf = strcpy(new_char_array(strlen(buf)+strlen(s.buf)+1), buf);
	char *cat = strcat( dupbuf, s.buf );
	String result = String( cat );
	delete_char_array( dupbuf );
	return result;
}


String String :: operator += ( const String s )
{
	char *dupbuf = strcpy(new_char_array(strlen(buf)+strlen(s.buf)+1), buf);
	delete_char_array( buf );
	buf = strcat( dupbuf, s.buf );
	return *this;
}
	
String ::~String ()
{
	delete_char_array(buf);
}









