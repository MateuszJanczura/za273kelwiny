#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>

class bot
{
	public:
		double sA, sB, sC; //parametry bota
		int sKonta, sPrzedmioty;
		bot();
		bot(double x, double y, double z, int konto);
		bool wynik(int cena, int wartoscPrzedmiotu);
		bool operator< (bot const &q) const {return sPrzedmioty > q.sPrzedmioty;}
};

bot::bot()
{
}

bot::bot(double x, double y, double z, int konto)
{
	sA = x;
	sB = y;
	sC = z;
	sKonta = konto;
}

bool bot::wynik(int cena, int wartoscPrzedmiotu)
{
	return rand() % 2;
}
