#include <iostream>
#include <vector>
using namespace std;

class Job
{
    public:
    int startTimes;
    int finishTimes;
    int weights;
    int ids;

    Job(int start, int finish, int weight, int id)
    {
        startTimes = start;
        finishTimes = finish;
        weights = weight;
        ids = id;
    }
};