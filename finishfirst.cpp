#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

//Function used to sort the pairs via the second value rather than the first
bool sortBySecond(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second < b.second);
}

//Function that returns a vector of indexes of optimal jobs as ints
//Parameters are int of amount of jobs, vector of ints for starting time, and vector of ints for ending time
vector<int> mostJobs(int n, vector<int> inicio, vector<int> final)
{
    //Create necessary vectors and add jobs as pairs
    vector<int> optimalJobsIdx;
    vector<pair<int,int>> jobs;
    vector<pair<int,int>> optimalJobs;
    for(int i = 0; i < inicio.size(); i++)
    {
        jobs.push_back(make_pair(inicio[i],final[i]));
    }
    //Create vector of original indexes and sort along with jobs by finish time first
    vector<int> idx(jobs.size());
    iota(idx.begin(), idx.end(), 0);
    sort( idx.begin(),idx.end(), [&](int i,int j){return jobs[i].second<jobs[j].second;} );
    sort(jobs.begin(), jobs.end(), sortBySecond);

    //First job will always be optimal so it and its idx is added to their vectors
    optimalJobs.push_back(jobs[0]);
    optimalJobsIdx.push_back(idx[0]);

    //Adds jobs deemed optimal to vector of pairs
    //Also adds indexes of optimal jobs to vector of ints
    for(int j = 0; j < jobs.size(); j++)
    {
        if(jobs[j].first >= optimalJobs.back().second)
        {
            optimalJobs.push_back(jobs[j]);
            optimalJobsIdx.push_back(idx[j]);
        }
    }
    
    return optimalJobsIdx;
}

int main()
{
    int n = 8;
    vector<int> inicio = {0,1,3,3,4,5,6,8};
    vector<int> final = {6,4,5,8,7,9,10,11};
    vector<int> optimalIdx = mostJobs(n, inicio, final);
    cout<<"\n";
    for(int i = 0; i < optimalIdx.size(); i++)
    {
        if(i < optimalIdx.size()-1)
            cout<<optimalIdx[i]<<" ";
        else
            cout<<optimalIdx[i];
    }
    return 0;
}