/* Wersja gdy (1) liczba tur jest znana, (2) standardowej wersji gry o dolara [brak oplaty za podbicie], (3) gra sekwencyjna, (4) kupione przedmioty nie sa dodawane do gotowki*/
#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include "bot.cpp"
using namespace std;

class arena
{
	private:
		void tura();
		vector <bot> boty;  
		
	public:
		int pozostalePrzedmioty;
		arena();
		arena(int l);
		arena(vector<bot> bots);
		double zapytaniePrawdopodobienstwo();
		vector <bot> ranking();
		int zapytanieWartosc();
		void licytacja();
		void licytujPrzedmiot(int wartosc);
};

arena::arena()
{
}

arena::arena(int l)
{
	srand(time(0));
	for(int i = 0; i < l; i++) 
	{
		boty.push_back(bot((double)(rand()%100)/100.0,(double)(rand()%100)/100.0,(double)(rand()%100)/100.0, 1000));
	}
}

arena::arena(vector<bot> boty)
{
}

double arena::zapytaniePrawdopodobienstwo()
{
	return -1.0;
}

int arena::zapytanieWartosc()
{
	return -1;
}

vector <bot> arena::ranking()
{
	sort(boty.begin(), boty.end());
	return boty;
}

void arena::licytujPrzedmiot(int wartosc)
{
	int ostatniLicytujacy = 0, licytujacy = 0, stanLicytacji = 1;
	vector <int> kwota;
	kwota.resize(boty.size(), 0);
	do
	{
		if(boty[licytujacy].wynik(stanLicytacji + 1, wartosc) && boty[licytujacy].sKonta >= stanLicytacji + 1) 
		{
			stanLicytacji++;
			kwota[licytujacy] = stanLicytacji;
			ostatniLicytujacy = licytujacy;
		}
		licytujacy++;
		licytujacy %= boty.size();
	}
	while(licytujacy != ostatniLicytujacy);
	boty[ostatniLicytujacy].sPrzedmioty += wartosc;
	for(unsigned int i = 0; i < boty.size(); i++) boty[i].sKonta -= kwota[i];
	
	printf("Sprzedano %d za %d\n", wartosc, stanLicytacji);
}

void arena::licytacja()
{
	while(pozostalePrzedmioty--)
	{
		licytujPrzedmiot(rand() % 200 + 100);
	}
}
