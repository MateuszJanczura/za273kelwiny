#ifndef classGra
#define classGra

#include "arena.cpp"

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

#endif
