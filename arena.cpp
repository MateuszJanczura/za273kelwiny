/* Wersja gdy (1) liczba tur jest znana, (2) standardowej wersji gry o dolara [brak oplaty za podbicie], (3) gra sekwencyjna, (4) kupione przedmioty nie sa dodawane do gotowki, a ranking zalezy od wartosci kupionych przedmiotow*/

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
		int unikalnyNumer; 
		
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
		int id();
};

arena::arena()
{
	unikalnyNumer = 0;
}

int arena::id()
{
	return unikalnyNumer++; 
}

arena::arena(int l)
{
	unikalnyNumer = 0;
	srand(time(0));
	for(int i = 0; i < l; i++) 
	{
		boty.push_back(bot((double)(rand()%100)/100.0,(double)(rand()%100)/100.0,(double)(rand()%100)/100.0, 1000));
		boty[i].nazwa = id();
	}
}

arena::arena(vector<bot> boty2)
{
	unikalnyNumer = 0;
	for(unsigned int i = 0; i < boty2.size(); i++) 
	{
		boty.push_back(boty2[i]);
		boty[i].nazwa = id();
	}
}

vector <bot> arena::ranking()
{
	sort(boty.begin(), boty.end());
	return boty;
}

void arena::licytujPrzedmiot(int wartosc)
{
	int ostatniLicytujacy = rand() % boty.size(), licytujacy = (ostatniLicytujacy + 1) % boty.size(), stanLicytacji = 1;
	bool flaga = false;
	vector <int> kwota;
	kwota.resize(boty.size(), 0);
	do
	{
		if(boty[licytujacy].wynik(stanLicytacji + 1, wartosc) && boty[licytujacy].sKonta >= stanLicytacji + 1) 
		{
			stanLicytacji++;
			kwota[licytujacy] = stanLicytacji;
			ostatniLicytujacy = licytujacy;
			flaga = true;
		}
		licytujacy++;
		licytujacy %= boty.size();
	}
	while(licytujacy != ostatniLicytujacy);
	if(flaga) boty[ostatniLicytujacy].sPrzedmioty += wartosc;
	for(unsigned int i = 0; i < boty.size(); i++) boty[i].sKonta -= kwota[i];
	
	if(flaga)
	{
		printf("Sprzedano %d za %d dla %d\n", wartosc, stanLicytacji, boty[ostatniLicytujacy].nazwa);
		for(unsigned int i = 0; i < boty.size(); i++) if(kwota[i]) printf("\tBot %d zaplacil %d, stan konta bota: %d, przedmioty %d\n",boty[i].nazwa, kwota[i], boty[i].sKonta, boty[i].sPrzedmioty);
	}
	else printf("Nikt nie kupil %d\n", wartosc);
}

void arena::licytacja()
{
	while(pozostalePrzedmioty--)
	{
		licytujPrzedmiot(rand() % 200 + 100);
	}
}
