#ifndef classPopulation
#define classPopulation

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
    for(unsigned int i=0; i<bots.size(); ++i)
    {
        bots[i].print();
        cout << endl;
    }
}


void Population::calibrate()
{
    while(bots.size() < playersPerRound * multiplier)
        bots.push_back(bots[rand()%bots.size()]);
}



void Population::newGeneration()
{
    calibrate();
    int x;
    for(int i=multiplier * playersPerRound-1; i>=0; i--)
    {
        x = rand()%(i+1);
        swap(bots[i], bots[x]);
        if(i%playersPerRound==0)
            connectedArena->play(bots.begin()+i, bots.begin()+(i+playersPerRound));
    }
}

#endif
