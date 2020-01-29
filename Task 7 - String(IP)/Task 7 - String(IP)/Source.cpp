#include<iostream>
#include<string>
using namespace std;

void CheckToken(string token) {
	int number = stoi(token);
	for (int i = 0; i < token.length(); i++) {
		if (int(token[i]) <= 45 && int(token[i]) >= 58)
		{
			throw exception("Ip not correct");
		}

	}
	if (number == 0 && token.length() > 1) { throw exception("Ip not correct"); }
	if (number < 0 || number > 255 || token.length() > 3) { throw exception("Ip not correct"); }
}

int main() {
	string ip;
	string token;

	int prevIndex = 0;
	int tokenCounter = 0;

	cout << "Enter Ip" << endl;
	cin >> ip;

	for (int i = 0; i < ip.length(); i++) {
		if (ip[i] == '.') {
			token = ip.substr(prevIndex, i - prevIndex);
			tokenCounter++;
			prevIndex = i + 1;

			if (tokenCounter > 3) {
				cout << "Error( invalid IP )" << endl;
				break;
			}

			try {
				CheckToken(token);
			}
			catch (...) {
				cout << "Error( invalid IP )" << endl;
				break;
			}
		}
		if (i == ip.length() - 1) {
			token = ip.substr(prevIndex, i - prevIndex + 1);
			CheckToken(token);
			cout << "Ip correct" << endl;
		}
	}
	system("pause");
	return 0;
}