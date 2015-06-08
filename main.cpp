#include <cstdio>
#include <cstdlib>
#include "arena.cpp"
using namespace std;

int main()
{
	arena* a;
	a = new arena(6);
	a -> pozostaleTury = 5;
	a -> licytacja();
	vector <bot> ranking = a -> ranking();
	delete(a);
	for(unsigned int i = 0; i < ranking.size(); i++) printf("#%d: %f, %f, %f (%d)\n", i+1, ranking[i].sA,ranking[i].sB,ranking[i].sC,ranking[i].sPrzedmioty);
	return 0;
}
