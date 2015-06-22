#ifndef classArena
#define classArena

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
	group.clear();
	srand(time(0));
}

void Arena::addBot(Bot a)
{
    group.push_back(a);
}

void Arena::newGroup(vector<Bot>* a)
{
    group.clear();
}

vector<Bot> Arena::play()
{
    for(int i=0; i<group.size(); ++i)
    {
        group[i].addResult(rand()%1000);
    }
    return group;
}

void Arena::play(vector<Bot>::iterator b, vector<Bot>::iterator e)
{
    group.assign(b,e);
    play();
    int x = 0;
    for(vector<Bot>::iterator i = b; i!=e; i++)
    {
        *i = group[x];
        ++x;
    }
}

#endif
