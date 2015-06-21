#ifndef classBot
#define classBot

#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <random>
using namespace std;

class arena;
class bot;

class bot
{
	private:
		void inicjalizacja();
		void mutacja();
		
	public:
		double sA, sB, sC; //parametry bota
		int sKonta, sPrzedmioty, nazwa;
		
		bot();
		bot(bot* a); //konstruktor kopiujacy
		bot(bot* a, bot* b); //konstruktor krzyzowania
		bot(double x, double y, double z, int konto);
		
		bool wynik(arena* aren);
		bool operator< (bot const &q) const {return sPrzedmioty > q.sPrzedmioty;} // bot jest mniejszy od innego jesli posiada gorsze przedmioty
};

class arena
{
	private:
		vector <bot> boty; 
		int unikalnyNumer; 
		int pozostalePrzedmiotyMax; 
		double prawdopodobienstwoNastepnego;
		
		int nadajNazwe(int a);
		void tura();
		void inicjalizacja();
		void licytujPrzedmiot(int wartosc);
		
	public:
		arena();
		arena(int l);
		arena(vector<bot> bots);
		
		int stala;
		bool czyNastepny();
		void dodajBota(bot a, int b = 0);
		vector <bot> ranking();
		void ustawieniaLicytacji(int a, double b);
		void licytacja();
};

// ------------------------------------- Konstruktory ------------------------------------

bot::bot()
{
	inicjalizacja();
}

bot::bot(bot* a)
{
	inicjalizacja();
	sA = a -> sA;
	sB = a -> sB;
	sC = a -> sC;
}

bot::bot(bot* a, bot* b)
{
	inicjalizacja();
	mutacja();
}

bot::bot(double x, double y, double z, int konto)
{
	inicjalizacja();
	sA = x;
	sB = y;
	sC = z;
	sKonta = konto;
}


// ------------------------------------- Funkcje prywatne -------------------------------- 
void bot::mutacja()
{
}

void bot::inicjalizacja()
{
	sKonta = sA = sB = sC = sPrzedmioty = 0;
}


// ------------------------------------- Funkcje publiczne -------------------------------

bool bot::wynik(arena* aren)
{
	return aren -> stala;
}

#endif
