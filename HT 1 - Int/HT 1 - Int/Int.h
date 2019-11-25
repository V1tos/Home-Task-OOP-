#pragma once
#include <iostream>
using namespace std;


class Int
{
private:
	int value;

	/*void GetPoint()*/
public:
	Int();
	Int(int value);
	Int(Int &object);
	void SetValue(int &value);
	int GetValue();
	Int Sum(Int &Int);
	Int Dif(Int &Int);
	Int Mult(Int &Int);
	Int Div(Int &Int);
	void ShowInt();
	~Int();
};

