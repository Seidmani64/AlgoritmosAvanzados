#include <iostream>
#include <vector>
using namespace std;

class Job
{
    public:
    int startTimes;
    int finishTimes;
    int weights;

    Job(int start, int finish, int weight)
    {
        startTimes = start;
        finishTimes = finish;
        weights = weight;
    }
};