#ifndef classDef
#define classDef

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

class Arena
{
	private:
		vector <Bot> group;
		int unikalnyNumer;
		int pozostalePrzedmiotyMax;
		double prawdopodobienstwoNastepnego;

		int nadajNazwe(int a);
		void tura();
		void inicjalizacja();
		void licytujPrzedmiot(int wartosc);

	public:
		Arena();

		bool czyNastepny();
		void dodajBota(bot a, int b = 0);
		vector <bot> ranking();
		void ustawieniaLicytacji(int a, double b);
		void licytacja();
};

class Population
{
	private:
		int roundNumber;
		vector<Bot> bots;

	public:
		Population(int rN=0): roundNumber(rN) {};

		void gameSettings(int rN);
		void addBot(Bot a);
		void print();
};

#endif
