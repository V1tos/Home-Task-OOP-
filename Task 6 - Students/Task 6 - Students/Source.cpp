#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Student {
	string surname;
	int curse;
	int points;
public:
	Student() {
		cout << "Enter surname : "; cin >> this->surname;
		cout << "Enter curse : "; cin >> this->curse;
		cout << "Enter points : "; cin >> this->points;
	};
	Student(string stud, int curs, int point) {
		this->curse = curs;
		this->points = point;
		this->surname = stud;
	}

	void Fill() {

	}
	void Show() {
		cout << "------------------------" << endl;
		cout << "Surname : " << this->surname << endl;
		cout << "Curse : " << this->curse << endl;
		cout << "Points : " << this->points << endl;
		cout << "------------------------" << endl;
	}

	string GetSurmane() {
		return this->surname;
	}
	int GetMark() {
		return this->points;
	}
	int GetGroup() {
		return this->curse;
	}
	void SetSurname(string sur) {
		this->surname = sur;
	}

	~Student() {};
};



void SortByName(vector<Student> &students) {
	for (int j = 0; j < students.size() - 1; j++) {
		for (int i = 0; i < students.size() - 1; i++) {
			if (students[i].GetSurmane() > students[i + 1].GetSurmane()) {
				swap(students[i], students[i + 1]);
			};
		}
	}
}
vector<Student> GetGoodStudents(vector<Student> &students) {
	vector<Student> goodStudents;
	int count = 0;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].GetMark() > 76) {
			goodStudents.push_back(students[i]);
			count++;
		};
	}
	return goodStudents;
}

void ShowAll(vector<Student> magesine) {
	for (int i = 0; i < magesine.size(); i++) {
		magesine[i].Show();
	}
}



void WriteFile(vector<Student> magasine) {


	string path = "Test.txt";
	ofstream writeFile;

	writeFile.open(path);


	if (!writeFile.is_open()) {
		cout << "Can't open file!\n";
	}
	else
	{
		int i = 0;
		writeFile << magasine.size() << endl;
		while (i<magasine.size())
		{

			writeFile << magasine.at(i).GetSurmane() << endl;
			writeFile << magasine.at(i).GetGroup() << endl;
			writeFile << magasine.at(i).GetMark() << endl;
			i++;
		}

	}


	writeFile.close();
}



void ReadFile(vector<Student> &magasine) {

	string path = "Test.txt";
	ifstream readFile;
	char temp[255];

	readFile.open(path);


	if (!readFile.is_open()) {
		cout << "Can't open file!\n";
	}
	else
	{
		int i = 0;
		int size;
		string surname;
		int curse;
		int points;


		readFile.getline(temp, 255);
		size = atoi(temp);

		while (i < size) {
			readFile.getline(temp, 255);
			surname = temp;
			readFile.getline(temp, 255);
			curse = atoi(temp);
			readFile.getline(temp, 255);
			points = atoi(temp);

			magasine.push_back(Student(surname, curse, points));

			i++;
		}
	}

	readFile.close();


}




int main() {
	bool exit = false;
	vector<Student> magesine;
	vector<Student> students;
	int choise;
	while (!exit) {
		cout << "1. Add student" << endl;
		cout << "2. Show student" << endl;
		cout << "3. Sort by name student" << endl;
		cout << "4. Find and show good student" << endl;
		cout << "5. Write in file" << endl;
		cout << "6. Read from file" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
			magesine.push_back(Student());
			break;
		case 2:
			ShowAll(magesine);
			break;
		case 3:
			SortByName(magesine);
			break;
		case 4:
			students = GetGoodStudents(magesine);
			cout << "count good student " << students.size() << endl;
			ShowAll(students);
			break;
		case 5:
			WriteFile(magesine);
			break;
		case 6:
			ReadFile(magesine);
			break;
		case 0:
			exit = true;
			break;
		}

	}
	system("pause");
	return 0;
}