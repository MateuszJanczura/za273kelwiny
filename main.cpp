#include <cstdio>
#include <cstdlib>
#include "class.cpp"
#include "bot.cpp"
#include "arena.cpp"
#include "population.cpp"
using namespace std;

int main()
{
    Bot X01(1,1,1,10);
    Bot X02(3,3,5,100);
    Bot X03(5,3,2,1);

    cout << X01.toString() << endl;
    cout << X02.toString() << endl;
    cout << X03.toString() << endl;

    Arena playground;
    vector<Bot> populi;
    populi.push_back(X01);
    populi.push_back(X02);
    playground.play(&populi);

    cout << populi[0].toString() << endl;
    cout << populi[1].toString() << endl;

    return 0;
}

