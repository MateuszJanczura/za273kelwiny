#ifndef classArena
#define classArena

/* Wersja gdy (1) maksymalna liczba tur jest znana i prawdopodobienstow kolejnej licytacji znane, (2) standardowej wersji gry o dolara [brak oplaty za podbicie], (3) gra sekwencyjna lub jednoczesna, (4) kupione przedmioty nie sa dodawane do gotowki, a ranking zalezy od wartosci kupionych przedmiotow*/

#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <random>
#include "class.cpp"
#include "bot.cpp"
using namespace std;



Arena::Arena()
{
	unikalnyNumer = 0;
	gloup.clear();
	srand(time(0));
}

// ----------------------- Funkcje prywatne ------------------------------------

int Arena::nadajNazwe(int a = 0)
{
	if(!a) return unikalnyNumer++;
	return a;
}

/*void Arena::licytujPrzedmiot(int wartosc)
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
}*/



// ----------------------- Funkcje publiczne -----------------------------------


bool Arena::czyNastepny()
{
	int los = rand() % 1000 + 1;
	pozostalePrzedmiotyMax--;
	if((prawdopodobienstwoNastepnego * 1000 > los) && (pozostalePrzedmiotyMax > -1)) return true;
	return false;
}


void Arena::ustawieniaLicytacji(int a, double b)
{
	pozostalePrzedmiotyMax = a;
	prawdopodobienstwoNastepnego = b;
}

void Arena::dodajBota(Bot a, int b)
{
	boty.push_back(a);
	boty[boty.size() - 1].nazwa = nadajNazwe(b);
}

void Arena::licytacja()
{
	while(czyNastepny())
	{
		licytujPrzedmiot(rand() % 200 + 100);
	}
}


#endif
