#ifndef classBot
#define classBot

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

class Bot
{
	private:
        //parameters of the bot
        double pA;
        double pB;
        double pC;
        int balance;

        //results of the arena
        vector<int> results;

		void mutate();

	public:
        //constructors
		Bot(Bot* a);
		Bot(Bot* a, Bot* b);
		Bot(double a=0, double b=0, double c=0, int bal=0) : pA(a), pB(b), pC(c), balance(bal) {};

		//results management
		void addResult(int a);
		void clearResults();
		double averageResult();
		double standardDeviation();
		double value();

        bool operator<(Bot a)
        {
            if(results.size()==a.results.size())
            {
                return value() < a.value();
            }
            else
                return results.size() < a.results.size();
        }

        //printing
		void print();
		void printCompressed();
		string toString();
		string toStringCompressed();
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
        for(int i=0; i<results.size(); ++i)
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
        for(int i=0; i<results.size(); ++i)
        {
            sum += pow(results[i] - a,2);
        }
        sum /= results.size();
        return sqrt(sum);
    }
}

double Bot::value()
{
    return averageResult();
}

void Bot::print()
{
    cout << "bot [" << pA << "," << pB << "," << pC << "] with balance: " << balance << " value: " << value();
}

int main()
{
    Bot adam(1,1,1,1);
    adam.addResult(5);
    adam.addResult(10);
    adam.print();
}
#endif
