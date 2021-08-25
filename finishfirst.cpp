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
    for(int i = 0; i < n; i++)
    {
        jobs.push_back(make_pair(inicio[i],final[i]));
    }
    //Create vector of original indexes and sort along with jobs by finish time first
    vector<int> idx(n);
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
        if(jobs[j].first >= optimalJobs.back().second && jobs[j].second != optimalJobs.back().second)
        {
            optimalJobs.push_back(jobs[j]);
            optimalJobsIdx.push_back(idx[j]);
        }
    }
    
    return optimalJobsIdx;
}

int main()
{
    //Primera prueba
    int n1 = 8;
    vector<int> inicio1 = {0,1,3,3,4,5,6,8};
    vector<int> final1 = {6,4,5,8,7,9,10,11};
    vector<int> optimalIdx1 = mostJobs(n1, inicio1, final1);
    cout<<"\n";
    for(int i = 0; i < optimalIdx1.size(); i++)
    {
        if(i < optimalIdx1.size()-1)
            cout<<optimalIdx1[i]<<" ";
        else
            cout<<optimalIdx1[i];
    }

    //Segunda prueba
    int n2 = 1;
    vector<int> inicio2 = {0};
    vector<int> final2 = {20};
    vector<int> optimalIdx2 = mostJobs(n2, inicio2, final2);
    cout<<"\n";
    for(int i = 0; i < optimalIdx2.size(); i++)
    {
        if(i < optimalIdx2.size()-1)
            cout<<optimalIdx2[i]<<" ";
        else
            cout<<optimalIdx2[i];
    }

    //Tercera prueba
    int n3 = 5;
    vector<int> inicio3 = {0,0,0,0,0};
    vector<int> final3 = {5,3,1,2,2};
    vector<int> optimalIdx3 = mostJobs(n3, inicio3, final3);
    cout<<"\n";
    for(int i = 0; i < optimalIdx3.size(); i++)
    {
        if(i < optimalIdx3.size()-1)
            cout<<optimalIdx3[i]<<" ";
        else
            cout<<optimalIdx3[i];
    }

    //Cuarta prueba
    int n4 = 5;
    vector<int> inicio4 = {0,2,4,6,8};
    vector<int> final4 = {5,5,5,5,5};
    vector<int> optimalIdx4 = mostJobs(n4, inicio4, final4);
    cout<<"\n";
    for(int i = 0; i < optimalIdx4.size(); i++)
    {
        if(i < optimalIdx4.size()-1)
            cout<<optimalIdx4[i]<<" ";
        else
            cout<<optimalIdx4[i];
    }
    return 0;
}