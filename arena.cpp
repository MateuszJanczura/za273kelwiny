#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
#include "bot.cpp"
using namespace std;

class arena
{
	private:
		void tura();
		vector <bot> boty; // lista botow z 
		
	public:
		int pozostaleTury;
		arena();
		arena(int l);
		arena(vector<bot> bots);
		double zapytaniePrawdopodobienstwo();
		vector <bot> ranking();
		int zapytanieWartosc();
		void licytacja();
};

arena::arena()
{
}

arena::arena(int l)
{
	srand(time(0));
	for(int i = 0; i < l; i++) 
	{
		boty.push_back(bot((double)(rand()%100)/100.0,(double)(rand()%100)/100.0,(double)(rand()%100)/100.0));
	}
}

arena::arena(vector<bot> boty)
{
}

double arena::zapytaniePrawdopodobienstwo()
{
	return 1;
}

int arena::zapytanieWartosc()
{
	return 100;
}

vector <bot> arena::ranking()
{
	sort(boty.begin(), boty.end());
	return boty;
}

void arena::tura()
{
}

void arena::licytacja()
{
	
}
