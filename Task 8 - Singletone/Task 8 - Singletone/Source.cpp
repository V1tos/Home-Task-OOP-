#include <iostream>
#include <string>

using namespace std;


class Logger
{
private:

	string login;
	string password;
	static Logger *account;
	Logger(string login, string password) : login(login), password(password){};
	

public:
	Logger()=delete;
	void operator=(const Logger&) = delete;
	static Logger *GetInstance(string login, string password);
	static bool checkAcc();
	static void ShowInfo();
	string GetLogin() { return login; };
	string GetPassword() { return password; };
	~Logger() {};

};

Logger *Logger::account = nullptr;


Logger *Logger::GetInstance(string login, string password) {

	if (account==nullptr)
	{
		Logger::account = new Logger(login,password);
	}
	
	return account;

}

bool Logger::checkAcc() {
	return account;
}



void Logger::ShowInfo() {

	if (Logger::checkAcc())
	{
		cout << "Login: " << Logger::account->login << "\nPassword: " << Logger::account->password << endl;
	}
	else
	{
		cout << "Empty profile!!\n";
	}
}

int main() {
	string login;
	string password;
	cout << "Enter login: ";
	cin >> login;
	cout << "Enter password: ";
	cin >> password;

	Logger::GetInstance(login,password);
	Logger::ShowInfo();
	

	

	system("pause");
	return 0;
}