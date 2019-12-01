#pragma once
#include <iostream>
#include <ctime>
#include <string>
//#include "Algae.h"
using namespace std;

const int HEIGHT = 20;
const int WIDTH = 35;
const int ALGAECOUNT = 350;


class Fish
{
private:
	unsigned int x;
	unsigned int y;
	unsigned int health;
	char fishID;
	
	static int charKey;
	static char ocean[HEIGHT][WIDTH];

	
	
	
public:
	static void DrawOcean(Fish *&others, int &fishCount,int algaeX[],int algaeY[],const int ALGAECOUNT);
	static void DrawEmptyOcean();
	Fish();
	Fish(unsigned int x, unsigned int y);
	int GetX();
	int GetY();
	int GetHealth();
	void SetCoords(unsigned int x, unsigned int y);
	void RandCoords();
	void HideFish();
	void ShowFish();
	~Fish();
};

