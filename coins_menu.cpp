 #include <iostream>
 #include "Coins.h"
 #include <cstdlib>

void presentMenu()
{
   cout << "   * * * * * * * * * * * * * * * * * * * * * * *\n"
     << "   *		 myCoins  MENU			*\n"
     << "   *						*\n"
     << "   * OPTION				ENTER	*\n"
     << "   *						*\n"
     << "   *   Show Balance (in $)		B or b	*\n"
     << "   *   Show Coins 			C or c	*\n"
     << "   *   Deposit Change			D or d	*\n"
     << "   *   Get Coins for Purchase		P or p	*\n"
     << "   *						*\n"
     << "   *   Quit				Q or q	*\n"
     << "   *						*\n"
     << "   * * * * * * * * * * * * * * * * * * * * * * *\n";
}

char getChoice( const char * prompt )
{
	char ch;
	cout << prompt << " (followed by enter): ";
	cin >> ch;
	return ch;
}

void evaluateCommand( Coins & c, char choice )
{
	switch ( choice )
	{
		case 'B': case 'b':
		{
			cout << "Blance is $ " << c.total_value_in_cents() / 100.0 << endl;
		}
		break;
	
		case 'C': case 'c':
		{
			cout << c << endl;
		}
		break;
		
		case 'D': case 'd':
		{
			int q, d, n, p;
			cout << "How many quarters you want to save: ";
			cin >> q;
			cout << "How many dimes you want to save: ";
			cin >> d;
			cout << "How many nickels you want to save: ";
			cin >> n;
			cout << "How many pennies you want to save: ";
			cin >> p;
			Coins deposit = Coins( q, d, n, p );
			c.deposit_coins( deposit );
		}
		break;
		
		case 'P': case 'p':
		{
			int q, d, n, p;
			cout << "How many quarters you want to extract:  ";
			cin >> q;
			cout << "How many dimes you want to extract: ";
			cin >> d;
			cout << "How many nickels you want to extract: ";
			cin >> n;
			cout << "How many pennies you want to extract: ";
			cin >> p;
			
			Coins expense = Coins( q, d, n, p );
			if (c.has_exact_change_for_coins( expense ))
			{
				c.extract_exact_change( expense );
			}
			else
				cout << "You don't have enough money " << endl;
		}	
		break;
		
		case 'Q': case 'q':
		{
			cout << "Done with myCoins. \n\n";
			exit(0);
		}
		default:
			cout << "Invalid command " << choice << endl;
			break;
	}
}

int main ()
{
	int q, d, n, p;
	cout << "Quarters you have: ";
	cin >> q;
	cout << "Dimes you have: ";
	cin >> d;
	cout << "Nickels you have: ";
	cin >> n;
	cout << "Pennies you have: ";
	cin >> p;
	
	Coins myCoins( q, d, n, p );
	while ( true )
	{
		presentMenu();
		char command = getChoice("Enter a command character: ");
		evaluateCommand ( myCoins, command);
	}

	

}
	
