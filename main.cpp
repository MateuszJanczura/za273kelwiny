#include <cstdio>
#include <cstdlib>
#include "bot.cpp"
#include "arena.cpp"
#include "gra.cpp"
using namespace std;

int main()
{
	arena* a;
	vector <bot> ranking;
	
/* ---------------------- UZYCIE ARENY ------------------------------------	
	// Arena dla 10 losowych botow, rywalizujacych o 10 przedmiotow
	a = new arena(10);
 	a -> ustawieniaLicytacji(10, 1);
	a -> licytacja();
	ranking = a -> ranking();
	delete(a);
	for(unsigned int i = 0; i < ranking.size(); i++) printf("#%d: Bot %d (%.2f, %.2f, %.2f) Przedmioty: %d, Konto: %d\n", i+1, ranking[i].nazwa, ranking[i].sA,ranking[i].sB,ranking[i].sC,ranking[i].sPrzedmioty, ranking[i].sKonta);
	
	printf("\n----------------------------\n\n");
	
	//Arena dla 5 botow o okreslonych cechach z listy, rywalizujacych o 3 przedmioty;	
	vector <bot> o;
	o.push_back(bot(0,0,0,100)); 	 // bot o wektorze [0,0,0] i stanie konta 100
	o.push_back(bot(0.7,0.3,0,100)); // bot o wektorze [0.7,0.3,0] i stanie konta 100
	o.push_back(bot(1,0,0,100));	 // bot o wektorze [1,0,0] i stanie konta 100
	o.push_back(bot(0,1,0,100));	 // bot o wektorze [0,1,0] i stanie konta 100
	o.push_back(bot(0,0,1,100)); 	 // bot o wektorze [0,0,1] i stanie konta 100
	a = new arena(o);
 	a -> ustawieniaLicytacji(3, 1);
	a -> licytacja();
	ranking = a -> ranking();
	delete(a);
	for(unsigned int i = 0; i < ranking.size(); i++) printf("#%d: Bot %d (%.2f, %.2f, %.2f) Przedmioty: %d, Konto: %d\n", i+1, ranking[i].nazwa, ranking[i].sA,ranking[i].sB,ranking[i].sC,ranking[i].sPrzedmioty, ranking[i].sKonta);
	
	printf("\n----------------------------\n\n");
	
	//Arena dla 3 botow o okreslonych cechach manualnie, rywalizujacych o 5 przedmiotyow	
	a = new arena;
	a -> dodajBota(bot(1,1,1,19));  // bot o wektorze [1,1,1] i stanie konta 19
	a -> dodajBota(bot(1,0,1,111)); // bot o wektorze [1,1,1] i stanie konta 111
	a -> dodajBota(bot(0,1,0,14));  // bot o wektorze [1,1,1] i stanie konta 14
 	a -> ustawieniaLicytacji(5, 1);
	a -> licytacja();
	ranking = a -> ranking();
	delete(a);
	for(unsigned int i = 0; i < ranking.size(); i++) printf("#%d: Bot %d (%.2f, %.2f, %.2f) Przedmioty: %d, Konto: %d\n", i+1, ranking[i].nazwa, ranking[i].sA,ranking[i].sB,ranking[i].sC,ranking[i].sPrzedmioty, ranking[i].sKonta);
	
	printf("\n----------------------------\n\n");
	
	//Arena dla 3 botow o okreslonych cechach manualnie, rywalizujacych o nieokreslona liczbe przedmiotow, prawdopodobienstwo nastepnego 0,81 ale nie wiecej niz 10 przedmiotow	
	a = new arena;
	a -> dodajBota(bot(1,1,1,19)); // bot o wektorze [1,1,1] i stanie konta 19
	a -> dodajBota(bot(1,0,1,111)); // bot o wektorze [1,1,1] i stanie konta 111
	a -> dodajBota(bot(0,1,0,14)); // bot o wektorze [1,1,1] i stanie konta 14
 	a -> ustawieniaLicytacji(10, 0.81);
	a -> licytacja();
	ranking = a -> ranking();
	delete(a);
	for(unsigned int i = 0; i < ranking.size(); i++) printf("#%d: Bot %d (%.2f, %.2f, %.2f) Przedmioty: %d, Konto: %d\n", i+1, ranking[i].nazwa, ranking[i].sA,ranking[i].sB,ranking[i].sC,ranking[i].sPrzedmioty, ranking[i].sKonta);
*/
	
	ranking.push_back(bot(1,1,1));
	
	return 0;
}
