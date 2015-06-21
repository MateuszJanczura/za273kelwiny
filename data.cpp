#ifndef classData
#define classData

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Data
{
    private:
        vector<double> results;

    public:
        void clear();
        void push_back(double a);
        int size();
        void print();
        void printCompressed();
        double arithmeticMean();
        double standardDeviation();
        double value();
        bool operator<(Data a)
        {
            if(size()==a.size())
            {
                return value() < a.value();
            }
            else
            {
                return size() < a.size();
            }
        }
};

void Data::clear()
{
    results.clear();
}

void Data::push_back(double a)
{
    results.push_back(a);
}

int Data::size()
{
    return results.size();
}

void Data::print()
{
    if(results.empty()) cout << "empty";
    else
    {
        for(int i=0; i<results.size(); ++i)
        {
            cout << results[i] << " ";
        }
    }
}

void Data::printCompressed()
{
    cout << value();
}

double Data::arithmeticMean()
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

double Data::standardDeviation()
{
    if(size()==0)
    {
        return -1;
    }
    else
    {
        double a = arithmeticMean();
        double sum = 0;
        for(int i=0; i<size(); ++i)
        {
            sum += pow(results[i] - a,2);
        }
        sum /= results.size();
        return sqrt(sum);
    }
}

double Data::value()
{
    return arithmeticMean();
}

#endif
