#include <iostream>
#include <string>

using namespace std;

//В програмі - грі, розробленій на минулих заняттях додати можливість
//створення різних типів юнітів.До кожного з юнітів додати можливість модифікації в різні
//типи юнітів : броньованого юніта, прискореного юніта, влучного юніта.Використати
//патерн Декоратор.


class Unit abstract 
{
protected:
	string name;
	short hp;
	unsigned short damage;
	unsigned short dodge;
public:
	Unit(string name = "Unit", short hp = 0,short damage = 0,short dodge = 0) : name(name), hp(hp), damage(damage) , dodge(dodge) {};

	string GetName() {
		return name; 
	}
	void SetName(string name) {
		this->name = name;
	}


	short  GetHp() { 
		return hp; 
	}
	void SetHp(short hp) {
		this->hp = hp;
	}


	unsigned short GetDamage() { 
		return damage; 
	}
	void SetDamage(unsigned short damage) {
		this->damage = damage;
	}


	unsigned short GetDodge() {
		return dodge; 
	}

	void SetDodge(unsigned short dodge) { 
		this->dodge = dodge; 
	}

	virtual void Upgrade()=0;
	~Unit() {};

};

class Swordsman : public Unit
{
public:
	Swordsman(){
		name = "Swordsman";
		hp = 15;
		damage = 5;
		dodge = 6;
	};
	void Upgrade() {};
	~Swordsman(){};
};

class Archer : public Unit
{
public:
	Archer() {
		name = "Archer";
		hp = 12;
		damage = 4;
		dodge = 4;
	};
	void Upgrade() {};
	~Archer() {};
};

class Mage : public Unit
{
public:
	Mage() {
		name = "Mage";
		hp = 8;
		damage = 10;
		dodge = 3;
	};
	void Upgrade() {};
	~Mage() {};
};


class Decorator : public Unit
{
protected:
	Unit* unit;
public:
	Decorator(Unit* unit) : unit(unit) {};
	void UpgradeDamage() {
		unit->SetDamage(unit->GetDamage() + 5);
	}
	void UpgradeHp() {
		unit->SetHp(unit->GetHp() + 5);
	}
	void UpgradeDodge() {
		unit->SetDodge(9);
	}
	
	~Decorator() { delete unit; }
};

class UpDamageUnit : public Decorator
{
public:
	UpDamageUnit(Unit* unit) : Decorator(unit) {};
	void Upgrade() {
		Decorator::UpgradeDamage();
	}
	~UpDamageUnit() {};

};

class UpHpUnit : public Decorator
{
public:
	UpHpUnit(Unit* unit) : Decorator(unit) {};
	void Upgrade() {
		Decorator::UpgradeHp();
	}
	~UpHpUnit() {};

};

class UpDodgeUnit : public Decorator
{
public:
	UpDodgeUnit(Unit* unit) : Decorator(unit) {};
	void Upgrade() {
		Decorator::UpgradeDodge();
	}
	~UpDodgeUnit() {};

};


void ClientCode(Unit* unit) {
	unit->Upgrade();
}


int main() {
	Unit *s = new Swordsman();
	Unit *decorator = new UpDamageUnit(s);
	

	cout <<"Damage before upgrade: " << s->GetDamage() << endl;
	ClientCode(decorator);
	cout <<"Damage after upgrade: " << s->GetDamage() << endl;

	Unit *decorator1 = new UpHpUnit(s);
	
	cout <<"Hp before upgrade: " << s->GetHp() << endl;
	ClientCode(decorator1);
	cout <<"Hp after upgrade: " << s->GetHp() << endl;

	Unit *decorator2 = new UpDodgeUnit(s);
	cout << "Dodge before upgrade: " << s->GetDodge() << endl;
	ClientCode(decorator2);
	cout << "Dodge before upgrade: " << s->GetDodge() << endl;

	
	system("pause");
	return 0;
}