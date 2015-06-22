#ifndef classDef
#define classDef

#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <random>
using namespace std;

class Bot;
class Arena;
class Population;


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
		Bot(double a=0, double b=0, double c=0, int bal=0): pA(a), pB(b), pC(c), balance(bal) {};

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

class Arena
{
	private:
		vector <Bot> group;

	public:
		Arena();

		void addBot(Bot a);
		void newGroup(vector<Bot>* a);
		vector <Bot> play();
		void play(vector<Bot>* a);
};

class Population
{
	private:
		int roundNumber;
		int playersPerRound;
		vector<Bot> bots;

	public:
		Population(int rN=0): roundNumber(rN) {};

		void gameSettings(int rN);
		void addBot(Bot a);
		void print();

		void repopulate();
		void newGeneration();
};

#endif
