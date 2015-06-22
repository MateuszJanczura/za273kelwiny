#ifndef classBot
#define classBot

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>
#include "class.cpp"
using namespace std;


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

void Bot::addResult(int a)
{
    results.push_back(a);
}

void Bot::clearResults()
{
    results.clear();
}

double Bot::averageResult()
{
    if(results.size()==0)
    {
        return -1;
    }
    else
    {
        double sum = 0;
        for(unsigned int i=0; i<results.size(); ++i)
        {
            sum += results[i];
        }
        return sum / results.size();
    }
}

double Bot::standardDeviation()
{
    if(results.size()==0)
    {
        double a = averageResult();
        double sum = 0;
        for(unsigned int i=0; i<results.size(); ++i)
        {
            sum += pow(results[i] - a,2);
        }
        sum /= results.size();
        return sqrt(sum);
    }
    return 0;
}

double Bot::value()
{
    return averageResult();
}

void Bot::print()
{
    cout << "bot [" << pA << "," << pB << "," << pC << "] with balance: " << balance << " value: " << value();
}

string Bot::toString()
{
    stringstream s;
    s << "bot [" << pA << "," << pB << "," << pC << "] with balance: " << balance << " value: " << value();
    return s.str();
}
#endif
