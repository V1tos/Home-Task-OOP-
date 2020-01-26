#include <iostream>
#include <string>
#include <vector>
using namespace std;



//Реализовать базу данных ГАИ по штрафным квитанциям
//с помощью бинарного дерева.Ключом будет служить
//номер автомашины, значением узла — список правонарушений.Если квитанция добавляется в первый раз,
//то в дереве появляется новый узел, а в списке данные по
//правонарушению; если нет, то данные заносятся в существующий список.Необходимо также реализовать
//следующие операции :
//•	 Полная распечатка базы данных(по номерам машин
//	и списку правонарушений, числящихся за ними);
//•	 Распечатка данных по заданному номеру;
//•	 Распечатка данных по диапазону номеров.

class Mulcts
{
	string name;
	unsigned int sum;
	unsigned short count;

public:
	
	Mulcts(){};
	Mulcts(string name, int sum) {
		this->name = name;
		this->sum = sum;
		this->count = 1;
	}

	string GetName() { return this->name; }
	void PlusCount() { this->count++; }

	void ShowInfo() {
		cout << "Name: "  << this->name << "\nSum: " << this->sum <<"\nCount: " <<this->count << endl;
	}
	~Mulcts() {};



};




struct Ticket {
	unsigned int auto_Number;
	vector <Mulcts> mulcts;
	struct Ticket *left;
	struct Ticket *right;
	static int counter;
	int TicetID;
	

	void ShowMulcts() {
		if (this->mulcts.size() > 0)
		{
			cout << "Number: " << auto_Number << "\n";
			for (int i = 0; i < this->mulcts.size(); i++)
			{

				cout << "Mulct N" << i + 1 << endl;
				this->mulcts.at(i).ShowInfo();
			}

		}
		else
		{
			cout << "Auto hasn't got mulcts\n";
		}
		
	
	}

	



};


Ticket *CreateNewTicket(int auto_Number, Mulcts mulct) {


	Ticket *newTicket = new Ticket();
	Ticket::counter++;
	newTicket->TicetID = Ticket::counter;
	newTicket->auto_Number = auto_Number;
	newTicket->mulcts.push_back(mulct);
	newTicket->left = newTicket->right = nullptr;


	return newTicket;
}

Ticket *Insert(Ticket *root,int auto_Number, Mulcts mulct) {
	
	if (root == 0)
	{
		root = CreateNewTicket(auto_Number, mulct);
	}

	else if (root->auto_Number == auto_Number) {
		
		
			int checker = 0;
			for (int i = 0; i < root->mulcts.size(); i++)
			{
				if (root->mulcts.at(i).GetName() == mulct.GetName())
				{
					root->mulcts.at(i).PlusCount();
					checker++;
				}
			}
			if (checker == 0)
			{
				root->mulcts.push_back(mulct);
			}
		
		
	} 

	
	else if(auto_Number<=root->auto_Number)
	{
		root->left = Insert(root->left, auto_Number, mulct);
	}
	else
	{
		root->right = Insert(root->right, auto_Number, mulct);
	}

	return root;
}

void ShowAll(Ticket *root) {
	
	

	if(root!=0)
	{
		
		cout << "Auto N" << root->TicetID << ": \n";
		root->ShowMulcts();
		cout << endl;

		ShowAll(root->left);
		ShowAll(root->right);
		
	}


	

}

bool CheckNumber(Ticket *root, int auto_Number) {

	if (root==0)
	{
		return false;
	}
	if (root->auto_Number==auto_Number)
	{
		return true;
	}
	else if(auto_Number<=root->auto_Number)
	{
		return CheckNumber(root->left,auto_Number);
	}
	else
	{
		return CheckNumber(root->right, auto_Number);
	}


}

bool CheckDiapasone(Ticket *root, int start, int finish) {

	

	if (root != 0)
	{

		if (root->auto_Number >= start&&root->auto_Number <= finish)
		{
			return true;
		}
		else if(root->auto_Number >! start && root->auto_Number <! finish)
		{
			return CheckDiapasone(root->left, start, finish);
			return CheckDiapasone(root->right, start, finish);
		}
		else
		{
			return false;
		}


	}

}

void FindByNumber(Ticket *root, int auto_Number) {

	
		if (root->auto_Number == auto_Number)
		{
			root->ShowMulcts();
		}
		else if (auto_Number <= root->auto_Number)
		{
			FindByNumber(root->left, auto_Number);
		}
		else if (auto_Number >= root->auto_Number)
		{
			FindByNumber(root->right, auto_Number);
		}
		
	

}

void FindByDiapasone(Ticket *root,int start,int finish) {

	

		if (root != 0)
		{
			if (root->auto_Number > start&&root->auto_Number < finish)
			{
				cout << "Auto N" << root->TicetID << ": \n";
				root->ShowMulcts();
				cout << endl;

			}


			FindByDiapasone(root->left, start, finish);
			FindByDiapasone(root->right, start, finish);

		}

	

}

int Ticket::counter = 0;

int main() {

	Ticket *root=0;
	int number = 0;
	int start = 0, finish = 0;
	
	root = Insert(root, 4267, Mulcts("Over speed", 5000));
	root = Insert(root, 4267, Mulcts("Over speed", 5000));
	root = Insert(root, 5421, Mulcts("Alcodrive", 25000));
	root = Insert(root, 5421, Mulcts("Alcodrive", 25000));
	root = Insert(root, 9501, Mulcts("Not use belt", 2000));
	root = Insert(root, 9501, Mulcts("Over speed", 5000));
	root = Insert(root, 9501, Mulcts("Alcodrive", 25000));
	root = Insert(root, 4267, Mulcts("Not use belt", 2000));


	

	ShowAll(root);
	

	cout << "-------------Find by number-------------\n";
	cout << "Enter find number: ";
	cin >> number;
	if (CheckNumber(root,number))
	{
		FindByNumber(root, number);
	}
	else
	{
		cout << "Dind't find anything!!\n";
	}
	cout << "-------------Find by number-------------\n\n\n";
	

	cout << "-------------Find by diapasone-------------\n";
	cout << "Enter start of diapasone: ";
	cin >> start;
	cout << "Enter end of diapasone: ";
	cin >> finish;

	if (CheckDiapasone(root,start,finish))
	{
		FindByDiapasone(root, start, finish);
	}
	else
	{
		cout << "Incorrect diapasone!!\n";
	}
	
	cout << "-------------Find by diapasone-------------\n\n\n";
	
	

	

	system("pause");
	return 0;
}