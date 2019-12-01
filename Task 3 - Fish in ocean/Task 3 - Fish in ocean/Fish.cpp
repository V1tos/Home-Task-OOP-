#include "Fish.h"

int Fish::charKey = 65;
char Fish::ocean[HEIGHT][WIDTH];


void Fish::DrawOcean(Fish *&others, int &fishCount,int algaeX[], int algaeY[], const int ALGAECOUNT)
 {
	

	 for (int i = 0; i < HEIGHT; i++)
	 {
		 for (int j = 0; j < WIDTH; j++)
		 {
			 
			 if (i == 0 || i == HEIGHT -1) {
				 ocean[i][j] = '#';
			 }
			 
			 else if (j == 0 || j == WIDTH -1) {
				 ocean[i][j] = '#';
			 }
			 else
			 {
				 ocean[i][j]=' ';
			 }
			
		 }
	 } 

	

	 for (int i = 0; i < HEIGHT; i++)
	 {
		 for (int j = 0; j < WIDTH; j++)
		 {
			 for (int a = 0; a < fishCount; a++)
			 {
				 if (others[a].y == i && others[a].x == j&&others[a].health!=0) {
					 ocean[i][j] = others[a].fishID;
					
				 }
				 if (others[a].y == others[a + 1].y || others[a].x == others[a + 1].x) {
					 others[a].RandCoords();
					 others[a].health += 10;
				 }
				 
			 }
		 }
	 }

	

	 for (int i = 0; i < HEIGHT; i++)
	 {
		 for (int j = 0; j < WIDTH; j++)
		 {
			 for (int a = 0; a < ALGAECOUNT; a++)
			 {
				 if (algaeY[a] == i && algaeX[a] == j && ocean[i][j] == ' ') {
					 ocean[i][j] = '+';
				 }
				 

			 }
		 }
	 }
	  
	 for (int i = 0; i < ALGAECOUNT; i++)
	 {

		 for (int j = 0; j < fishCount; j++)
		 {
			 if (algaeX[i] == others[j].x&&algaeY[i] == others[j].y&&others[j].health!=0&&others[j].health<100) {
				 others[j].health += 10;
			 }
			 
		 }
	 }

	 for (int i = 0; i < HEIGHT; i++)
	 {
		 for (int j = 0; j < WIDTH; j++)
		 {
			 cout << ocean[i][j];
		 }
		 cout << endl;
	 }

	 for (int i = 0; i < fishCount; i++)
	 {
		 others[i].ShowFish();
	 }

	 for (int i = 0; i < ALGAECOUNT; i++)
	 {

		 for (int j = 0; j < fishCount; j++)
		 {
			 if (algaeX[i] == others[j].x&&algaeY[i] == others[j].y) {
				 algaeX[i] = rand() % 33 + 1;
				 algaeY[i] = rand() % 18 + 1;
			 }

		 }
	 }


 }

 void Fish::DrawEmptyOcean()
 {
	 for (int i = 0; i < HEIGHT; i++)
	 {
		 for (int j = 0; j < WIDTH; j++)
		 {

			 if (i == 0 || i == HEIGHT - 1) {
				 ocean[i][j] = '#';
			 }

			 else if (j == 0 || j == WIDTH - 1) {
				 ocean[i][j] = '#';
			 }
			 else
			 {
				 ocean[i][j] = ' ';
			 }

		 }
	 }

	 for (int i = 0; i < HEIGHT; i++)
	 {
		 for (int j = 0; j < WIDTH; j++)
		 {
			 cout << ocean[i][j];
		 }
		 cout << endl;
	 }
 }



 Fish::Fish()
{
	 this->x = rand()% 33 + 1;
	 this->y = rand()% 18 + 1;
	 this->health = 100;
	 this->fishID = charKey;
	 charKey++;
 }

Fish::Fish(unsigned int x, unsigned int y)
{
	this->x = x;
	this->y = y;
	this->health = 100;
	this->fishID = charKey;
	charKey++;
}

int Fish::GetX()
{
	return this->x;
}

int Fish::GetY()
{
	return this->y;
}

int Fish::GetHealth()
{
	return this->health;
}

void Fish::SetCoords(unsigned int x, unsigned int y)
{
	this->x = x;
	this->y = y;
}

void Fish::RandCoords()
{
	unsigned int x = rand() % 33 + 1;
	unsigned int y = rand() % 18 + 1;
	if (this->health >= 10) {
		this->health -= 10;
	}
	SetCoords(x, y);
}

void Fish::HideFish()
{

}

void Fish::ShowFish()
{
	if (this->health > 0) {
	cout << "Fish [" << this->fishID << "] - Health [" << this->health << "]\n";
	}
	else
	{
		cout << "Fish [" << this->fishID << "] - Health [" << this->health << "] - Dead\n";
	}
}


Fish::~Fish()
{
}

