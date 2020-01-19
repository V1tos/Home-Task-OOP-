#include <iostream>
#include <string>
#include <ctime>
using namespace std;


//������� ���� "Fortress" (�������).
//
//��� �������, �������� ���� "Shooter" (�������), ���� ���� ������ ��� ���� : ����� �������� �� �� �������.
//³� ���� �������� �� "������" � ��������� ��� ����� ������� �������, ����������� � �������, �� ���� ����������.
//� ����� ���� �������� �� "���� �������", ��� ��������������� ����� � ������� �������, ��������� �� ��� ����� ���������.
//
//������� �� ��� ������ ����� : "Archer" (������), "Ranger" (��������)�� "Catapult" (����������), �� �������� �� "������", 
//���������� ����������� � ������� ����������� ��� ��, ��� ���� � ��� ��������.����� ��� ������ ������� �������, � ���������� - ��������.
//
//³� ������ ���� ����������� ���� "ArcherTower" (C������� ����), 
//� ��� ����� ������� �� ���� ����(�������) ��� ���� : ������� � ���������
//(���������, ���� ������� ���������� ������������ ��� ����� �����������).
//
//³� ����� "�������� ����" � "����������" �� �������� ���� "Fortress".
//���� � �� ����������� ����� ������������ ����� ��� �������� ��� � ����� ��� ����������.
//������� �� ������� �� ����� ���� - ������� ���, ���� ���� � ��������, � �.�. - �� ������ ������� �� �����糿.
//
//������ ����� ��������� ������ �� ��'���� ���������� �� �������. 
//� ������� � ���� �� ������ � ��� �������� �� ���� ������������ ������������ ����� �������, 
//� ������������ �� ���������� �� �������-����������� �� ������� �������������� �������. 
//��� �����, ��� � main() ����� ���� �������� ��������: 
//
//- �������� ��'��� ������� 
//- ��������� ����� ��������, ���� ���������� � ��� � ����������
//����, ������ �� ���� 6 �����, ����� ������� � ��������� ����� ����� ��� � ���� "�������", 
//���� ���� ��'��� ��� ���� ��������. ������� �� �� ����� - 6 ����� �������, �� ����������������. ��� ��'��� � ��� ������� ����.
//
//���̲���!���� ���������������� �������, �������� � �������� ���� ���� 4 �����, 
//��� ���� ���� �����, �� �� ������ ������ ��������� ���� �� ���������, ������� ������ ����� ��� �������� 3 �� 4 - � ����.


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