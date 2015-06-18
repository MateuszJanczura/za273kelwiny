#ifndef classGra
#define classGra

#include "arena.cpp"
using namespace std;

class gra
{
	private:
		int iloscTur;
	
	public:
		gra();
		gra(int a);
		gra(vector<bot> a);
		
		vector <bot> wynik();
};

// -------------------------- Konstruktory ----------------------------


// ----------------------- Funkcje prywatne ---------------------------


// ----------------------- Funkcje publiczne --------------------------



#endif
