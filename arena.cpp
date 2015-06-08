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
		vector <bot> boty; 
		int unikalnyNumer; 
		
		int nadajNazwe(int a);
		void tura();
		void inicjalizacja();
		void licytujPrzedmiot(int wartosc);
		
	public:
		int pozostalePrzedmioty; 
		
		arena();
		arena(int l);
		arena(vector<bot> bots);
		
		void dodajBota(bot a, int b);
		vector <bot> ranking();
		void licytacja();
};

int arena::nadajNazwe(int a = 0)
{
	if(!a) return unikalnyNumer++; 
	return a;
}

void arena::inicjalizacja()
{
	unikalnyNumer = 0;
	boty.resize(0);
	srand(time(0));
}

void arena::dodajBota(bot a, int b = 0)
{
	boty.push_back(a);
	boty[boty.size() - 1].nazwa = nadajNazwe(b);
}

arena::arena()  // tworzenie podstawowej areny
{
	inicjalizacja();
}

arena::arena(int l) // tworzenie areny i l losowych botow
{
	inicjalizacja();
	for(int i = 0; i < l; i++) 
	{
		dodajBota(bot((double)(rand()%100)/100.0,(double)(rand()%100)/100.0,(double)(rand()%100)/100.0, 1000));
	}
}

arena::arena(vector<bot> boty2) // tworzenie areny i botow z vektora
{
	inicjalizacja();
	for(unsigned int i = 0; i < boty2.size(); i++) dodajBota(boty2[i]);
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
	
	//Wypisywanie przebiegu licytacji: 
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

vector <bot> arena::ranking()
{
	sort(boty.begin(), boty.end());
	return boty;
}
