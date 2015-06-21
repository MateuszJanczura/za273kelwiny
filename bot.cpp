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

class Bot
{
	private:
        //parameters of the bot
        double pA;
        double pB;
        double pC;
        int balance;
		void mutate();

	public:

		Bot(Bot* a);
		Bot(Bot* a, Bot* b);
		Bot(double a=0, double b=0, double c=0, int bal=0) : pA(a), pB(b), pC(c), balance(bal) {};
		void print();
};

Bot::Bot(Bot* a)
{
	pA = a -> pA;
	pB = a -> pB;
	pC = a -> pC;
	balance = a -> balance;
}

Bot::Bot(Bot* a, Bot* b)
{
	pA = (a->pA + b->pA)/2;
	pB = (a->pB + b->pB)/2;
	pC = (a->pC + b->pC)/2;
	balance = (a->balance + b->balance)/2;
	mutate();
}

void Bot::mutate()
{
    pA = pA *(1 + ((rand()%200)-100)/10000.0);
    pB = pB *(1 + ((rand()%200)-100)/10000.0);
    pC = pC *(1 + ((rand()%200)-100)/10000.0);
}

void Bot::print()
{
    cout << "bot's parameters: " << pA << " " << pB << " " << pC << " balance: " << balance;
}
#endif
