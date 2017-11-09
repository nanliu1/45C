#include "String.h"


bool String :: inBounds( int i )
{	
	return i >= 0 && i < size();
}

String :: ListNode :: ListNode( char newInfo, ListNode * newNext )
	:info( newInfo ), next( newNext )
{
}


String :: ListNode * String :: ListNode :: stringToList( const char *s )
{
    return !*s ? nullptr : new ListNode( *s, stringToList( s+1 ) );	
}



String :: ListNode * String :: ListNode :: copy( String :: ListNode * L )
{
	return !L ? nullptr : new ListNode( L->info, copy( L->next ) );	
}
          

           
String :: ListNode * String :: ListNode :: reverse ( String :: ListNode * L)
{
	ListNode * result = nullptr;
	for ( ListNode * p = L; p != nullptr; p = p->next )
		result = new ListNode( p->info, result );
	return result;
		
}




String :: ListNode * String :: ListNode :: append( String :: ListNode * L1, String :: ListNode * L2 )
{
	return L1 == nullptr ? copy( L2 ) : new ListNode( L1->info, append( L1->next, L2 ) );
}



int String :: ListNode :: compare ( String :: ListNode * L1, String :: ListNode * L2 )

{
	if ( L1 == nullptr && L2 == nullptr )
		return 0;
	else if ( L1 != nullptr && L2 == nullptr )
		return 1;
	else if ( L1 == nullptr && L2 != nullptr )
		return -1;
	else if ( L1->info != L2->info )
		return L1->info - L2->info;
	else
		return compare( L1->next, L2->next );   
       
}
         
void String :: ListNode :: ListNode :: deleteList ( String :: ListNode * L )
{
	if ( L != nullptr )
	{
		deleteList( L->next );
		delete L;
	}
}


int String :: ListNode :: ListNode :: length ( String :: ListNode * L )
{

	return !L ? 0 : 1 + length( L->next );

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

void String :: print( ostream & out ) const
{
	for ( String :: ListNode * p = head; p != nullptr; p = p->next )
		out << p->info;
}

void String :: read ( istream & in )
{
	char temp[256];
	in.getline( temp, 255 );
	ListNode :: deleteList( head );
	head = ListNode :: stringToList( temp );	
}


String :: ~String()
{
	ListNode :: deleteList( head );
}




String :: String( const char * s )
	:head( ListNode :: stringToList( s ) )
{
}

String :: String( const String & s )
	:head( ListNode :: copy( s.head ) )
{
}

String String :: operator = ( const String & s )
{
	ListNode :: deleteList( head );
	head = ListNode :: copy( s.head );
	return *this;
}

char & String :: operator [] ( const int index )
{
	
	if ( !inBounds( index ) )
	{	
		cout << "Out of bounds" << endl;
		return head->info;
	}
	else
	{
		ListNode * cpyptr = head;
		for ( int i = 0; i < index; ++i )
		{
			cpyptr = cpyptr->next;
		}
		return cpyptr->info;
	}
}
		

int String :: size() const
{
	return ListNode :: length( head );
}

int String :: indexOf( char c ) const
{
	int i = 0;
	for ( ListNode * p = head; p != nullptr; p = p->next )
	{
		if ( p->info == c )
		{	
			return i;
		}
		++i;
	} 
	return -1;
}

bool String :: operator == ( const String & s ) const
{
	if ( ListNode :: compare( head, s.head ) == 0 )
		return true;
	return false;
}

bool String :: operator < ( const String & s ) const
{
	if ( ListNode :: compare( head, s.head ) < 0 )
		return true;
	return false;
}


String String :: operator + ( const String & s ) const
{
	String result;	
	ListNode :: deleteList( result.head );
	result.head = ListNode :: append( head, s.head );
	return result;
}


String String :: operator += ( const String & s )
{
	ListNode *newHead = ListNode :: append( head, s.head );
	ListNode :: deleteList( head );
	head = newHead;
	return *this; 
}


String String :: reverse() const
{
	String result;	
	ListNode *newHead = ListNode :: reverse( head );
	ListNode :: deleteList( result.head );
	result.head = newHead;
	return result;
}
	

