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



void Populatioon::newGeneration()
{
    calibrate();
    int x;
    for(int k=0; k<rounndNumber; k++)
    {
        for(int i=multiplier * playersPerRound-1; i>=0; i--)
        {
            x = rand()%(i+1);
            swap(bots[i], bots[x]);
            if(i%playersPerRound==0)
                connectedArena->play(bots.begin()+i, bots.begin()+(i+playersPerRound));
        }
    }
    vector<int> probability(bots.size());
    for(int i=0; i<bots.size(); ++i)
    {
        probability[i] = probability[i-1] + bots[i-1].value().floor();
    }

    vector<Bot> newGen;
    int prev, a, b;
    for(int i=0; i<2* multiplier * playersPerRound - 1; ++i)
    {
        x = rand()%probability[bots.size()-1];
        a = 0;
        b = bots.size()-1;
        while(a!=b)
        {
            if(x>probability[(a+b)/2]) a = (a+b)/2 + 1;
            else b = (a+b)/2;
        }
        if(i%2==0) prev = a;
        else
        {
            newGen.push_back(Bot(&bots[prev], &bots[a]));
        }
    }
    bots.clear();
    bots = newGen;
}

#endif
