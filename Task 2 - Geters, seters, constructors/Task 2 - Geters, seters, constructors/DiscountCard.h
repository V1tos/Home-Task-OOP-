#pragma once
#include <iostream>
#include <ctime>
using namespace std;


class DiscountCard
{
private:
	unsigned int DCNumber;
	unsigned int discount;
	unsigned int SavePrice;
	void SaveBoughtProduct(unsigned int cost);


public:
	void UpdateDiscount(unsigned int cost);
	DiscountCard();
	void BuyProductWithCard(unsigned int cost);
	void ShowDiscountProduct(unsigned int cost);
	void Checking();
	void ShowDiscount();
	void ShowCardInfo();


};