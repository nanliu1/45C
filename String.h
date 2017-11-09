 #define MAXLEN 128
 #include <iostream>
using namespace std;

class String
{
private:
    char buf[MAXLEN];
    
    void error ( char *msg )
    {
	cerr << "Error: " << msg << endl;
    }


    bool inBounds( int i )
    {
	return i >= 0 && i < strlen( buf );
    }

    static int strlen( const char *s )
    {
	int len = 0;
	for ( int i = 0; s[i] != '\0'; ++i )
	    ++len;
	return len;
    }
    
    static char * strcpy( char *dst, const char *src )
    {
	int i;
	for ( i = 0; src[i] != '\0'; ++i )
	    dst[i] = src[i];
	dst[i] = src[i];
	return dst;
    }

    static char * strcat( char *dst, const char *src )
    {
	strcpy( dst + strlen( dst ), src );
	return dst;
    }

    static int strcmp( const char *left, const char *right )
    {
	int i = 0;
	while ( left[i] == right[i] )
	{
	    if ( left[i] == '\0' && right[i] == '\0' )
	        return 0;
	    ++i; 
	}
	return left[i] - right[i];
	        
    }
   
    static int strncmp( const char *left, const char *right, int n )
    {
	int i = 0;
 
	while ( left[i] == right[i] && i < n )
	{
	    if ( i == n-1 )
		return 0;
	    ++i;
	}
		
	return left[i] - right[i];
    }

    static char * strchr( char *str, int c )
    {
	int i;
	for ( i = 0; str[i] != c ; ++i )
	    if ( str[i] == '\0' )
		return 0;
	return &str[i];	
    }     

    static const char * strstr( const char *haystack, const char *needle )
    {
	int i;
	int n = strlen( needle ); 
	int m = strlen( haystack);
	for ( i = 0; i < m; ++i )
	    if ( strncmp ( haystack, needle, n ) == 0 )
	 	{
		    return haystack;
		}
	    else
		{
		    ++haystack;
		} 
		    
	return 0; 
		      
    }
	
    static char * strstr( char *haystack, const char *needle )
    {
    	int i;
	int n = strlen( needle );
 	int m = strlen( haystack );
	for ( i = 0; i < m; ++i )
	    if ( strncmp ( haystack, needle, n ) == 0 )
		{
		    return haystack;
		}
	    else
	        {
		    ++haystack;
		}
	return 0;
    }
	

    static void reverse_cpy( char *dest, const char *src )
    {
  	int n = strlen( src );
	int i;
	for ( i = n - 1; i >= 0; --i )
	    {
	        dest[n-i-1] = src[i];  
	    }
    	dest[n] = '\0';
    }
		
           
   




public:
    explicit String( const char * s = "")
    {
	int len = strlen( s );
	if ( len > MAXLEN )
	{
	    cout << "It exceeds 128 limit, and the string was initized to empty..." << endl;
            strcpy( buf, "" );
	}
	else
	{
	    strcpy( buf, s );
 	}
    }
    
    String( const String & s )
    {
	strcpy( buf, s.buf );
    }

    String operator = ( const String & s )
    {
    	strcpy( buf, s.buf );
    }
	

    char & operator [] ( int index )
    {
	if ( inBounds( index ) )
	{    
	    return buf[index];
	}
        else
	{
	    cout << "Out of Bounds" << endl;
	    return buf[0];
	}
    }

    int size() const
    {
	return strlen( buf );
    }
	
    String reverse()
    {
	String result("");
	reverse_cpy( result.buf, buf );
	return result;
    }
       

    int indexOf( const char c )
    {
	if ( strchr( buf, c ) )
	    {
		return strchr( buf, c ) - buf;
	    }
	else
	    {
		return -1;
	    }
    }  
	


    int indexOf( const String pattern )
    {
	if ( strstr ( buf, pattern.buf ) != 0 )
	    {
		return strstr( buf, pattern.buf ) - buf;
	    }
	else
	    {
		return -1;
	    }
    }


    bool operator == ( const String s )
    {
	if ( strcmp(this -> buf, s.buf ) == 0)
	    {
		return true;
	    }
	else
	    {
		return false;
	    }
    }


    bool operator != ( const String s )
    {
	return !( *this == s );
    }

    bool operator > ( const String s )
    {
	if ( strcmp( this -> buf, s.buf ) > 0 )
	    {
		return true;
	    }
	else
	    {
		return false;
	    }

    }
        
    bool operator < ( const String s )
    {
	if ( strcmp ( this -> buf, s.buf ) < 0 )
	    {
		return true;
	    }
	else
	    {
		return false;
	    }
    }

    bool operator <= ( const String s )
    {
	return !( *this > s );
    } 

    bool operator >= ( const String s )
    {
	return !( *this < s );
    }

    String operator + ( const String s )
    {
	String cpy1 = *this;
	String cpy2 = s;
	return String( strcat( cpy1.buf, cpy2.buf ) );
    }

    String operator += ( const String s )
    {
         
	char *a = strcat( buf, s.buf );
	return String( a );

    }

    void print( ostream & out )
    {
	    out << buf;
    }

    void read ( istream & in )
    {
	    in.getline( buf, MAXLEN );
    }

    ~String()
    {
    }
};

istream & operator >> ( istream & in, String & str )
{
    str.read( in );
    return in;
}

ostream & operator << ( ostream & out, String str )
{
    str.print( out );
    return out;
}

