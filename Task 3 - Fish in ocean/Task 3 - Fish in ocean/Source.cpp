#include "Fish.h"
#include "Algae.h"




int main() {
	int fishCount = 5;
	int algaeX[ALGAECOUNT], algaeY[ALGAECOUNT];
	Fish *fish = new Fish[fishCount];

	for (int i = 0; i < fishCount; i++)
	{
		fish[i];
	}

	for (int i = 0; i < ALGAECOUNT; i++)
	{
		algaeX[i] = rand() % 33 + 1;
		algaeY[i] = rand() % 18 + 1;
	}

	Fish::DrawOcean(fish, fishCount, algaeX, algaeY, ALGAECOUNT);


	
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < fishCount; j++)
		{
			fish[j].RandCoords();
		}
		Fish::DrawOcean(fish, fishCount, algaeX, algaeY, ALGAECOUNT);
	}

	
	
	
	system("pause");
	return 0;
}