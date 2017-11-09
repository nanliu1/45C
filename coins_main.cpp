 #include "Coins.h"
const int CENTS_FOR_CHIPS = 68;
const int CENTS_FOR_TRANSFER = 205;

int main()
{
	Coins pocket( 5, 3, 6, 8 );
	cout << "I started with " << pocket << " in my pocket" << endl;
	Coins piggyBank ( 50, 50, 50, 50 );
	Coins payForChips = pocket.extract_exact_change( coins_required_for_cents ( CENTS_FOR_CHIPS ));
	cout << "I bought a bag of chips for " << CENTS_FOR_CHIPS << " cents using " << payForChips << endl;
	cout << "Now I still have " << pocket << " in my pocket " << endl;
	Coins transfer = piggyBank.extract_exact_change( coins_required_for_cents( CENTS_FOR_TRANSFER ));

	pocket.deposit_coins( transfer );
	cout << "After I transferred some money from piggyBank, now my pocket " << pocket << endl;
	cout << "piggyBank has " << piggyBank << endl; 
	
	Coins deposit_coins( 10, 10, 10, 10 );
	piggyBank.deposit_coins( deposit_coins );
	cout << "After saving the money found in the sofa, piggyBank has " << piggyBank << endl;
	
	double money = piggyBank.total_value_in_cents() / 100.0; 
	cout << "piggyBank has " << "$ " << money << endl;
}

