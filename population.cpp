#ifndef classPopulation
#define classPopulation

#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <random>
#include "data.cpp"
#include "bot.cpp"
using namespace std;

class Population
{
	private:
		int roundNumber;
		vector<pair<Data,Bot> > bots;

	public:
		Population(int rN=0): roundNumber(rN) {};

		void gameSettings(int rN=0);
		void addBot(Bot a);
		void print();
};

void Population::gameSettings(int rN)
{
	roundNumber = rN;
}

void Population::addBot(Bot a)
{
    Data x;
    bots.push_back(make_pair(x,a));
}

void Population::print()
{
    for(int i=0; i<bots.size(); ++i)
    {
        bots[i].first.printCompressed();
        cout << " ";
        bots[i].second.print();
        cout << endl;
    }
}

int main()
{

}

#endif
