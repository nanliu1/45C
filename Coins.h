 #include <iostream>
 #include <string>
using namespace std;

const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKEL = 5;
class Coins
{
private:
	int quarters, dimes, nickels, pennies;

public:
	Coins( int q, int d, int n, int p )
		: quarters( q ), dimes ( d ), nickels ( n ), pennies ( p )
	{
	}
	
	void deposit_coins( Coins & c )
	{
		quarters += c.quarters;
		dimes += c.dimes;
		nickels += c.nickels;
		pennies += c.pennies;	
		c.quarters = 0;
		c.dimes = 0;
		c.nickels = 0;
		c.pennies = 0;

	}

	bool has_exact_change_for_coins( Coins c )
	{
		return (quarters >= c.quarters and dimes >= c.dimes and nickels >= c.nickels and pennies >= c.pennies);
	}
	
	Coins extract_exact_change( Coins c)
	{
		if (has_exact_change_for_coins( c ))
		{
			quarters -= c.quarters;
			dimes -= c.dimes;
			nickels -= c.nickels;			
			pennies -= c.pennies;
			return c;	
		}
		
	}
	
	int total_value_in_cents()
 	{
		return (quarters * CENTS_PER_QUARTER + dimes * CENTS_PER_DIME + nickels * CENTS_PER_NICKEL + pennies * 1);
	}
	
	void print( ostream & out )
	{
		out << quarters << " quarters" << ", " << dimes << " dimes" << ", " << nickels << " nickels" << ", " << pennies << " pennies";
	}
	~Coins()
	{
	}
};	

ostream & operator << ( ostream & out, Coins c)
{
	c.print( out );
	return out;
}

Coins coins_required_for_cents( int amount_in_cents )
{
	int q = amount_in_cents/CENTS_PER_QUARTER;
	int d = (amount_in_cents - q * CENTS_PER_QUARTER)/CENTS_PER_DIME;
	int n = (amount_in_cents - q * CENTS_PER_QUARTER - d * CENTS_PER_DIME)/CENTS_PER_NICKEL;
	int p = amount_in_cents - q * CENTS_PER_QUARTER - d * CENTS_PER_DIME - n * CENTS_PER_NICKEL;

	return Coins( q, d, n, p );
}

	
