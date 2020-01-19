#include <iostream>
#include <string>
#include <ctime>
using namespace std;


//Описати клас "Fortress" (Фортеця).
//
//Для початку, напишіть клас "Shooter" (стрілець), який буде містити два поля : назва аммуніції та її кількість.
//Він може виконати дію "постріл" і витратити для цього одиницю амуніції, повідомляючи в консоль, як вона називалась.
//А також може здійснити дію "дати амуніцію", яка встановлюватиме назву і кількість амуніції, отримуючі ці дані через параметри.
//
//Стрілець має три дочірні класи : "Archer" (Лучник), "Ranger" (Рейнджер)та "Catapult" (Катапульта), які заміщають дію "постріл", 
//доповнюючи повідомлення в консоль інформацією про те, хто саме з них вистрілив.Перші два повинні стріляти стрілами, а катапульта - каменями.
//
//Від перших двох породжується клас "ArcherTower" (Cтрілкова вежа), 
//у якої запас амуніції має бути один(спільний) для обох : лучника і рейнджера
//(подумайте, який механізм множинного успадкування тут варто застосувати).
//
//Від класів "стрілкова вежа" і "катапульта" має походити клас "Fortress".
//Лише в її конструкторі мають поставлятись стріли для стрілкової вежі і камені для катапульти.
//Додайте до фортеці ще кілька полів - товщина стін, стан воріт у відсотках, і т.д. - по вашому бажанню та фантазії.
//
//Більше ніяких допоміжних методів чи об'єктів створювати не потрібно. 
//В кожного з полів чи методів у цій ієрархії має бути встановлений максимальний рівень захисту, 
//і успадкування має відбуватись по найвищо-допустимому по захисту специфікаторові доступу. 
//Але таким, щоб в main() можна було виконати наступне: 
//
//- створити об'єкт фортеці 
//- вистрілити тричі лучником, двічі рейнджером і раз з катапульти
//Отже, всього має бути 6 класів, вінцем творіння і фінальним дитям серед них є клас "Фортеця", 
//лише один об'єкт якої буде створено. Зверніть на це увагу - 6 класів описано, всі використовуються. Але об'єкт у всій програмі один.
//
//ПРИМІТКИ!Коли створюватиметься фортеця, доставте в стрілкову вежу лише 4 стріли, 
//тоді буде явно видно, що на другий постріл рейнджеру стріл не вистачить, оскільки лучник перед тим витратив 3 із 4 - х стріл.


 class  Shooter
{
	string ammunitions_name;
	unsigned short ammunitions_count;


public:

	void Set_Ammunitions_Name(string ammunitions_name)               { this->ammunitions_name = ammunitions_name; }
	string Get_Ammunitions_Name()                                    { return this->ammunitions_name; }

	void Set_Ammunitions_Count(unsigned short ammunitions_count)     { this->ammunitions_count = ammunitions_count; }
	unsigned short Get_Ammunitions_Count()                           { return this->ammunitions_count; }

	 Shooter(unsigned short ammunitions_count,string ammunitions_name=nullptr)
	{
		this->ammunitions_name = ammunitions_name;
		this->ammunitions_count = ammunitions_count;
	};
	 Shooter() {  };
	void Shot() {
		this->ammunitions_count--;
	}
	~Shooter() {};
};


class Archer : virtual public Shooter
{
public:
	
	Archer(unsigned short ammunitions_count=0) {
		this->Set_Ammunitions_Name("Arrow");
		this->Set_Ammunitions_Count(ammunitions_count);
	};
	void Shot() {
		if (this->Get_Ammunitions_Count() > 0 && this->Get_Ammunitions_Count() != 1)
		{
			cout << "Archer shot arrow N" << this->Get_Ammunitions_Count() << endl;
			this->Set_Ammunitions_Count(this->Get_Ammunitions_Count() - 1);

		}
		else if (this->Get_Ammunitions_Count() == 1)
		{
			cout << "Archer shot last arrow\n";;
			this->Set_Ammunitions_Count(this->Get_Ammunitions_Count() - 1);
		}
		else
		{
			cout << "Archer hasn't got arrows!!\n";
		}
	}
	~Archer() {};



};

class Ranger : virtual public Shooter
{
public:
	Ranger(unsigned short ammunitions_count = 0) {
		this->Set_Ammunitions_Name("Arrow");
		this->Set_Ammunitions_Count(ammunitions_count);
	};
	void Shot() {
		if (this->Get_Ammunitions_Count()>0&& this->Get_Ammunitions_Count()!=1)
		{
			cout << "Ranger shot arrow N" << this->Get_Ammunitions_Count() << endl;
			this->Set_Ammunitions_Count(this->Get_Ammunitions_Count() - 1);
			
		}
		else if (this->Get_Ammunitions_Count() == 1)
		{
			cout << "Ranger shot last arrow\n";;
			this->Set_Ammunitions_Count(this->Get_Ammunitions_Count() - 1);
		}
		else
		{
			cout << "Ranger hasn't got arrows!!\n";
		}
		
	}
	~Ranger() {};



};

class Catapult : public Shooter
{
public:
	Catapult(unsigned short ammunitions_count = 0) {
		this->Set_Ammunitions_Name("Stone");
		this->Set_Ammunitions_Count(ammunitions_count);
	};
	void Shot() {
		if (this->Get_Ammunitions_Count() > 0 && this->Get_Ammunitions_Count() != 1)
		{
			cout << "Catapult shot stone N" << this->Get_Ammunitions_Count() << endl;
			this->Set_Ammunitions_Count(this->Get_Ammunitions_Count() - 1);

		}
		else if (this->Get_Ammunitions_Count() == 1)
		{
			cout << "Catapult shot last stone\n";;
			this->Set_Ammunitions_Count(this->Get_Ammunitions_Count() - 1);
		}
		else
		{
			cout << "Catapult hasn't got stones!!\n";
		}
	}
	~Catapult() {};



};

class ArcherTower : public Archer, public Ranger
{
public:
	ArcherTower(unsigned short ammunitions_count=0)
	{
		this->Set_Ammunitions_Name("Archer tower");
		this->Set_Ammunitions_Count(ammunitions_count);
		for ( int i = 0; i < this->Get_Ammunitions_Count(); i++)
		{
			if (i < 4)
			{
				Archer::Set_Ammunitions_Count(this->Get_Ammunitions_Count());
			}
			else
			{
				Ranger::Set_Ammunitions_Count(this->Get_Ammunitions_Count());
			}
			
		}
		
		
	};
	
	~ArcherTower() {};



};


class Fortress : public ArcherTower, public Catapult
{
public:
	Fortress(unsigned short arrows_count = 0, unsigned short stone_count = 0) {
		
		ArcherTower::Set_Ammunitions_Count(arrows_count);
		Catapult::Set_Ammunitions_Count(stone_count);
	}

	~Fortress() {};
};






int main() {
	srand(unsigned(time(NULL)));

	Fortress fortress(4,1);
	
	fortress.Archer::Shot();
	fortress.Archer::Shot();
	fortress.Archer::Shot();
	fortress.Ranger::Shot();
	fortress.Catapult::Shot();




	fortress.Archer::Shot();
	fortress.Ranger::Shot();
	fortress.Catapult::Shot();
	




	system("pause");
	return 0;
}