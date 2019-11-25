#include "Int.h"



Int::Int()
{
}

Int::Int(int value)
{
	this->value = value;
}

Int::Int(Int & object)
{
	this->value = object.value;
}

Int Int::Sum(Int &clas)
{
	Int tmp;
	int tmp1 = 0;

	tmp1 = this->value + clas.value;

	tmp.SetValue(tmp1);

	return tmp;
}

Int Int::Dif(Int &clas)
{
	Int tmp;
	int tmp1 = 0;

	tmp1 = this->value - clas.value;

	tmp.SetValue(tmp1);

	return tmp;
}

Int Int::Mult(Int &clas)
{
	Int tmp;
	int tmp1 = 0;

	tmp1 = this->value * clas.value;

	tmp.SetValue(tmp1);

	return tmp;
}

Int Int::Div(Int &clas)
{
	if (this->value>0&& clas.value > 0) {

		Int tmp;
		int tmp1 = 0;

		tmp1 = this->value / clas.value;

		tmp.SetValue(tmp1);

		return tmp;
	}
	else
	{
		cout << "Can't divide on 0!" << endl;
		return 0;
	}
}

void Int::ShowInt()
{
	cout << this->value;
}

void Int::SetValue(int &value)
{
	this->value=value;
}

int Int::GetValue()
{
	return this->value;
}


Int::~Int()
{
}
