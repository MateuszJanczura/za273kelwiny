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
    group.assign(a->begin(),a->end());
}

vector<Bot> Arena::play()
{
    for(int i=0; i<group.size(); ++i)
    {
        group[i].addResult(rand()%1000);
    }
    return group;
}

void Arena::play(vector<Bot>* a)
{
    newGroup(a);
    play();
    *a = assign(group.begin(),group.end());
}

#endif
