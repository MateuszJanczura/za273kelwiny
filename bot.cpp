#ifndef classBot
#define classBot

#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>


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
		
		bool wynik(int cena, int wartoscPrzedmiotu);
		bool operator< (bot const &q) const {return sPrzedmioty > q.sPrzedmioty;} // bot jest mniejszy od innego jesli posiada gorsze przedmioty
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

bool bot::wynik(int cena, int wartoscPrzedmiotu)
{
	return rand() % 2;
}

#endif
