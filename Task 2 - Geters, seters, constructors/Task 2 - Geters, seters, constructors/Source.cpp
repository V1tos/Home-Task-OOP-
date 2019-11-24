#include "DiscountCard.h"
#include <ctime>


void Menu() {
	cout << "------------------------Menu---------------------" << endl;
	cout << "1 - Buy products with discount's card\n2 - Show discount's card information\n3 - Show your discount\n4 - Check price for discount\n0 - Exit\n";
	cout << "------------------------Menu---------------------" << endl;
	cout << "Your choice: " << endl;
}


int main() {
	srand(unsigned(time(NULL)));
	bool exit = false;

	DiscountCard test;


	while (!exit) {
		short choice = 0;
		unsigned int cost = 0;
		Menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter product's price: ";
			cin >> cost;
			test.BuyProductWithCard(cost);
			test.UpdateDiscount(cost);
			break;
		case 2:
			test.ShowCardInfo();
			break;
		case 3:
			test.ShowDiscount();
			break;
		case 4:
			test.Checking();
			break;
		case 0:
			exit = true;
			break;
		default:
			break;
		}





	}




	system("pause");
	return 0;
}