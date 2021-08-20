#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<int> optimalJobsIdx;
    vector<pair<int,int>> jobs;
    vector<pair<int,int>> optimalJobs;
    for(int i = 0; i < inicio.size(); i++)
    {
        jobs.push_back(make_pair(inicio[i],final[i]));
    } 
    sort(jobs.begin(), jobs.end(), sortBySecond);
    //Prints sorted jobs for testing
    for(int i = 0; i < jobs.size(); i++)
    {
        cout<<"\nJob Start: "<<jobs[i].first<<" Job End: "<<jobs[i].second;
    }
    optimalJobs.push_back(jobs[0]);
    //Adds jobs deemed optimal to vector of pairs
    //Also adds indexes of optimal jobs to vector of ints
    //ISSUE: ADDING INDEX OF SORTED JOBS, MUST ADD INDEX OF ORIGINAL UNSORTED JOBS
    for(int j = 1; j < n; j++)
    {
        if(jobs[j].first >= optimalJobs.back().second)
        {
            optimalJobs.push_back(jobs[j]);
            optimalJobsIdx.push_back(j+=1);
        }
    }
    //Prints optimal jobs for testing
    cout<<"\nOptimal Jobs";
    for(int i = 0; i < optimalJobs.size(); i++)
    {
        cout<<"\nJob Start: "<<optimalJobs[i].first<<" Job End: "<<optimalJobs[i].second;
    }
    
    return optimalJobsIdx;
}

int main()
{
    int n = 8;
    vector<int> inicio = {0,1,3,3,4,5,6,8};
    vector<int> final = {6,4,5,8,7,9,10,11};
    vector<int> optimalIdx = mostJobs(n, inicio, final);
    for(int i = 0; i < optimalIdx.size(); i++)
    {
        if(i < optimalIdx.size()-1)
            cout<<optimalIdx[i]<<", ";
        else
            cout<<optimalIdx[i];
    }
    return 0;
}