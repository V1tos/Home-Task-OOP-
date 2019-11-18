#include <iostream>
#include <string>
#include <ctime>
using namespace std;






class Account
{
private:
	unsigned int number;
	unsigned int countCosts;

public:



	void OpenAccount() {
		number = rand() % 99000 + 10000;
		cout << "Account's number: " << number << endl;
		cout << "Enter cost (UAH): ";
		cin >> countCosts;
	}
	void AddCost(unsigned int value) {
		countCosts += value;
	}

	void PullCost(unsigned int value) {
		countCosts -= value;
	}

	void GetTrans(unsigned int exNumber, unsigned int value) {
		if (exNumber == number) {
			PullCost(value);
		}
	}
	void SetTrans(unsigned int imNumber, unsigned int value) {
		if (imNumber == number) {
			AddCost(value);
		}
	}

	void ShowAccount() {
		cout << "Account's number: " << number << "\nCount costs: " << countCosts << " UAH\n";
	}


};


void AddAccount(Account *&account, int &size) {
	Account *newAccount = new Account[size + 1];


	for (int i = 0; i < size + 1; i++)
	{
		if (i >= size) {
			newAccount[i].OpenAccount();
		}
		else {
			newAccount[i] = account[i];
		}
	}


	size++;

	delete account;
	account = newAccount;


}

void AccountList(Account *account, int size) {

	for (int i = 0; i < size; i++) {
		cout << "Account N" << i + 1 << endl;
		account[i].ShowAccount();
		cout << endl;
	}
}

void PlusCost(Account *account, int size) {
	AccountList(account, size);
	int number = 0;
	unsigned int value = 0;

	cout << "Enter account's number: ";
	cin >> number;
	cout << "Enter value: ";
	cin >> value;
	account[number - 1].AddCost(value);
}

void MinusCost(Account *account, int size) {
	AccountList(account, size);
	int number = 0;
	unsigned int value = 0;

	cout << "Enter account's number: ";
	cin >> number;
	cout << "Enter value: ";
	cin >> value;

	account[number - 1].PullCost(value);
}

void TransferCosts(Account *account, int size) {
	AccountList(account, size);
	unsigned int exNumber = 0, imNumber = 0, outCost = 0;
	cout << "Enter export account's number: ";
	cin >> exNumber;
	cout << "Enter import account's number: ";
	cin >> imNumber;
	cout << "Enter cost: ";
	cin >> outCost;
	for (int i = 0; i < size; i++) {
		account[i].GetTrans(exNumber, outCost);
		account[i].SetTrans(imNumber, outCost);
	}
	cout << "Operation has done" << endl;

}



int main() {
	srand(unsigned(time(NULL)));

	int size = 0;
	Account *account = new Account[size];

	bool exit = false;

	while (!exit) {
		system("cls");

		int choice = 0;
		cout << "1 - Create account\n2 - Add cost\n3 - Pull cost\n4 - Transfer costs\n5 - Show account info\n0 - Exit\nYour choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			AddAccount(account, size);
			cout << "Opened\n";
			system("pause");
			break;
		case 2:
			system("cls");
			PlusCost(account, size);
			cout << "Added" << endl;
			system("pause");
			break;
		case 3:
			system("cls");
			MinusCost(account, size);
			cout << "Pulled" << endl;
			system("pause");
			break;
		case 4:
			system("cls");
			TransferCosts(account, size);
			system("pause");
			break;
		case 5:
			system("cls");
			AccountList(account, size);
			system("pause");
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