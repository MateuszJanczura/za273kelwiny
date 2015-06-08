#include <cstdio>
#include <cstdlib>
#include "arena.cpp"
using namespace std;

int main()
{
	arena* a;
	vector <bot> ranking;
	
	
	// Arena dla 100 losowych botow, rywalizujacych o 10 przedmiotow
	a = new arena(100);
	a -> pozostalePrzedmioty = 10;
	a -> licytacja();
	ranking = a -> ranking();
	delete(a);
	for(unsigned int i = 0; i < ranking.size(); i++) printf("#%d: Bot %d (%f, %f, %f) Przedmioty: %d, Konto: %d\n", i+1, ranking[i].nazwa, ranking[i].sA,ranking[i].sB,ranking[i].sC,ranking[i].sPrzedmioty, ranking[i].sKonta);
	
	printf("\n----------------------------\n\n");
	
	//Arena dla 5 botow o okreslonych cechach, rywalizujacych o 3 przedmioty;	
	vector <bot> o;
	o.push_back(bot(0,0,0,100)); // bot o wektorze [0,0,0] i stanie konta 100
	o.push_back(bot(0.7,0.3,0,100)); // bot o wektorze [0.7,0.3,0] i stanie konta 100
	o.push_back(bot(1,0,0,100)); // bot o wektorze [1,0,0] i stanie konta 100
	o.push_back(bot(0,1,0,100)); // bot o wektorze [0,1,0] i stanie konta 100
	o.push_back(bot(0,0,1,100)); // bot o wektorze [0,0,1] i stanie konta 100
	a = new arena(o);
	a -> pozostalePrzedmioty = 3;
	a -> licytacja();
	ranking = a -> ranking();
	delete(a);
	for(unsigned int i = 0; i < ranking.size(); i++) printf("#%d: Bot %d (%f, %f, %f) Przedmioty: %d, Konto: %d\n", i+1, ranking[i].nazwa, ranking[i].sA,ranking[i].sB,ranking[i].sC,ranking[i].sPrzedmioty, ranking[i].sKonta);
	
	
	return 0;
}
