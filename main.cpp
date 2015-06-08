#include <cstdio>
#include <cstdlib>
#include "arena.cpp"
using namespace std;

int main()
{
	arena* a;
	a = new arena(6);
	a -> pozostalePrzedmioty = 50;
	a -> licytacja();
	vector <bot> ranking = a -> ranking();
	delete(a);
	for(unsigned int i = 0; i < ranking.size(); i++) printf("#%d: %f, %f, %f (Przedmioty: %d, Konto: %d)\n", i+1, ranking[i].sA,ranking[i].sB,ranking[i].sC,ranking[i].sPrzedmioty, ranking[i].sKonta);
	return 0;
}
