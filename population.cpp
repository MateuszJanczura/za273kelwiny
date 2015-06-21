#ifndef classPopulation
#define classPopulation

#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <random>
#include "bot.cpp"
using namespace std;



void Population::gameSettings(int rN=0)
{
	roundNumber = rN;
}

void Population::addBot(Bot a)
{
    bots.push_back(a);
}

void Population::print()
{
    for(int i=0; i<bots.size(); ++i)
    {
        bots[i]print();
        cout << endl;
    }
}


#endif
