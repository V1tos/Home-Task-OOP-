#include <iostream>
#include <string>

using namespace std;

//Використати шаблон Абстрактна фабрика.Створити фабрики для створення кнопок та прапорців для ОС Windows, Macintosh  
//в залежності від вибору користувача.
//Створити клас Клієнт(Application) для перевірки роботи фабрик.


class Button abstract
{
public:
	Button() {};
	virtual void PaintButton() = 0;
	virtual ~Button() {};
};

class WinButton : public Button
{
public:
	WinButton() {};
	void PaintButton()override {
		cout << "Windows button\n";
	}
	~WinButton()override {};
};

class MacButton : public Button
{
public:
	MacButton() {};
	void PaintButton()override {
		cout << "MacOS button\n";
	}
	~MacButton()override {};
};



class CheckBox abstract
{
public:
	virtual ~CheckBox() {};
	virtual void PaintCheckBox() = 0;
};

class WinCheckBox : public CheckBox
{
public:
	WinCheckBox() {};
	void PaintCheckBox()override {
		cout << "Windows check box\n";
	}
	~WinCheckBox()override {};
};

class MacCheckBox : public CheckBox
{
public:
	MacCheckBox() {};
	void PaintCheckBox()override {
		cout << "MacOS check box\n";
	}
	~MacCheckBox()override {};
};




class GUIFactory abstract
{
public:
	virtual Button* CreateButton() = 0;
	virtual CheckBox* CreateCheckBox() = 0;

};

class WinFactory : public GUIFactory
{
public:
	Button* CreateButton() override {
		return new WinButton();
	}
	CheckBox* CreateCheckBox() override {
		return new WinCheckBox();
	}

};

class MacFactory : public GUIFactory
{
public:
	Button* CreateButton() override {
		return new MacButton();
	}
	CheckBox* CreateCheckBox() override {
		return new MacCheckBox();
	}

};


void ClientCode(GUIFactory &guiFactory) {
	Button *guiButton = guiFactory.CreateButton();
	CheckBox *guiCheckBox = guiFactory.CreateCheckBox();
	guiButton->PaintButton();
	guiCheckBox->PaintCheckBox();

	delete guiButton;
	delete guiCheckBox;
}



int main() {
	WinFactory *windows = new WinFactory();
	MacFactory *macOs = new MacFactory();
	int userChoice = 0;

	cout << "1 - Windows (button, check box)\n2 - Mac OS (button, check box)\nYour choice: ";
	cin >> userChoice;
	switch (userChoice)
	{
	case 1:
		ClientCode(*windows);
		break;
	case 2:
		ClientCode(*macOs);
		break;
	default:
		break;
	}

	system("pause");
	return 0;
}