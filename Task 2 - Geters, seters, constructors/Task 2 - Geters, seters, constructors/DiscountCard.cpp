#include "DiscountCard.h"



DiscountCard::DiscountCard()
{
	DCNumber = rand() % 99000 + 10000;
	discount = 1;
	SavePrice = 0;
}

void DiscountCard::ShowCardInfo() {
	cout << "Card's number: " << DCNumber << "\nDiscount: " << discount << " %\nSuma product's price: " << SavePrice << " UAH" << endl;

}

void DiscountCard::UpdateDiscount(unsigned int cost) {
	bool exit = false;
	while (!exit) {
		if (cost >= 1000) {
			discount++;
			cost -= 1000;
		}
		else
		{
			exit = true;
		}
	}

}


void DiscountCard::SaveBoughtProduct(unsigned int cost) {
	SavePrice += cost;
}

void DiscountCard::BuyProductWithCard(unsigned int cost) {
	SaveBoughtProduct(cost);
}

void DiscountCard::ShowDiscountProduct(unsigned int cost) {
	cout << "Price with discount: " << cost - (cost*discount) / 100;
}

void DiscountCard::ShowDiscount() {
	cout << "Your discount: " << discount << endl;
}

void DiscountCard::Checking() {
	if (SavePrice % 1000 != 0) {
		cout << "Buy products for price: " << 1000 - SavePrice % 1000 << " UAH and get discount 1%" << endl;
	}
	else {
		cout << "Buy products for price: " << 1000 << " UAH and get discount 1%" << endl;
	}

}