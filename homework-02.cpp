#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdlib.h>
#include "binarySearch.h"

using namespace std;

vector<int> m;
vector<int> temp;

//Function used to sort the pairs via the second value rather than the first
bool sortBySecond(const Job &a, const Job &b)
{
    return (a.finishTimes < b.finishTimes);
}

int M_Compute_Opt(int j,vector<int> p, vector<Job> jobs){

    if( j == temp.size()){
        if(find(temp.begin(),temp.end(),j)){

        }
        m[j] = max(M_Compute_Opt(j-1, p, jobs),jobs[j].weights+M_Compute_Opt(p[j], p, jobs));
    }
    return m[j];
}

int Top_Down(vector<Job> jobs, vector<int> index){
    vector<int> p;
    

    sort( index.begin(),index.end(), [&](int i,int j){return jobs[i].finishTimes<jobs[j].finishTimes;} );
    
    sort(jobs.begin(), jobs.end(), sortBySecond);
    cout<<"aqui"<<endl;
    for(int i = 0; i < jobs.size(); i++){
      p.push_back(index.at(binarySearch(jobs, jobs[i])));
      temp.push_back(i);
    }
    cout<<"aqui"<<endl;
    cout<<jobs.size()<<endl;
    cout<<p[0]<<endl;

    return M_Compute_Opt(jobs.size()-1, p, jobs);
}


int main(int argc, char *argv[]){
  
  //code your solution here
  
  int n = stoi(argv[1]);
  int datos = stoi(argv[1]) * 3;
  vector<int> inicio;
  vector<int> final;
  vector<int> pesos;

  vector<Job> jobs;
  vector<int> index(n);
  
  for(int i = 1; i <= datos; i++){
      if(i <= datos/3){
        inicio.push_back(stoi(argv[i+1]));
      }
      else if(i <= ((datos*2)/3)){
        final.push_back(stoi(argv[i+1]));
      }
      else{
        pesos.push_back(stoi(argv[i+1]));
      }
  }

 
  for(int i = 0; i < n ; i++){
      Job jobI(inicio[i],final[i],pesos[i]);
      jobs.push_back(jobI);
  }

  iota(index.begin(),index.end(),0);


  Top_Down(jobs,index);

    /*
  for(int i = 0; i < m.size(); i++){
      cout<<m[i]<<" ";
  }*/
 
  //Use std::cout to output your solution
  //Example:
  //std::cout << yoursolutionhere;
  return 0;
}
