#include <cstdio>
#include <cstdlib>
#include "class.cpp"
#include "bot.cpp"
#include "arena.cpp"
#include "population.cpp"
using namespace std;

int main()
{
    Bot X01(1,1,1,1), X02(3,4,5,10), X03(100,100,100,0);
    /*vector<Bot> P;
    P.push_back(X01);
    cout << P[0].toString() << endl;
    P.push_back(X02);
    cout << P[1].toString() << endl;
    P.push_back(X03);
    cout << P[2].toString() << endl << endl;

    Arena A;
    A.play(P.begin()+1, P.end());
    cout << P[0].toString() << endl;
    cout << P[1].toString() << endl;
    cout << P[2].toString() << endl;*/

    Population populi(1,3,1);
    populi.addBot(X01);
    populi.addBot(X02);
    populi.addBot(X03);
    populi.print();
    populi.newGeneration();
    populi.print();
}

