#ifndef classGra
#define classGra

#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <random>
#include "arena.cpp"
using namespace std;

class gra
{
	private:
		int iloscTur;
		vector<bot> boty;
		void inicjalizacja();
		
	public:
		gra();
		gra(int a);
		gra(vector<bot> a, int b);
		
		vector <bot> wynik();
};

// -------------------------- Konstruktory ----------------------------
gra::gra()
{
	inicjalizacja();
}

gra::gra(int a)
{
	inicjalizacja();
	iloscTur = a;
}

gra::gra(vector<bot> a, int b)
{
	inicjalizacja();
	iloscTur = b;
	boty = a;
}

// ----------------------- Funkcje prywatne ---------------------------
void gra::inicjalizacja()
{
	iloscTur = 0;
}


// ----------------------- Funkcje publiczne --------------------------



#endif
