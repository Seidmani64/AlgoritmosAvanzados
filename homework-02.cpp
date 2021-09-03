#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdlib.h>
#include <map>
#include "binarySearch.h"

using namespace std;

vector<int> m;
vector<int> p;

//Function used to sort the pairs via the second value rather than the first
bool sortBySecond(const Job &a, const Job &b)
{
    return (a.finishTimes < b.finishTimes);
}

int M_Compute_Opt(int j, vector<Job> jobs){
  if(j == 0)
    m[j] = jobs[j].weights;
  if(m[j] == 0)
  {
    m[j] = max(M_Compute_Opt(j-1, jobs),jobs[j].weights+M_Compute_Opt(p[j], jobs));
  }
    return m[j];
}

int Top_Down(vector<Job> jobs, vector<int> index){

    sort( index.begin(),index.end(), [&](int i,int j){return jobs[i].finishTimes<jobs[j].finishTimes;} );
    
    sort(jobs.begin(), jobs.end(), sortBySecond);

    for(int i = 0; i < jobs.size(); i++){
      p.push_back(index.at(binarySearch(jobs, jobs[i])));
      m.push_back(0);
    }

    return M_Compute_Opt(jobs.size()-1, jobs);
}


/*int main(int argc, char *argv[]){
  
  //code your solution here
  
  int n = stoi(argv[1]);
  counter = n;
  int datos = stoi(argv[1]) * 3;\
  
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
  }*/
  int main(){
  int n = 8;
  vector<int> inicio;
  vector<int> final;
  vector<int> pesos;
  vector<Job> jobs;
  vector<int> index(n);
  
  inicio = {1,3,0,4,3,5,6,4};
  final = {4,5,6,7,8,9,10,11};
  pesos = {5,1,10,6,4,8,2,1};

 
  for(int i = 0; i < n ; i++){
      Job jobI(inicio[i],final[i],pesos[i]);
      jobs.push_back(jobI);
  }

  iota(index.begin(),index.end(),0);


  Top_Down(jobs,index);

  for(int i = 0; i < m.size(); i++)
  {
    cout<<"The value of m at "<<i<<" is: "<<m[i]<<endl;
  }

  vector<int>::iterator it;
  it = max_element(m.begin(),m.end());
  int idx = distance(m.begin(), it);
  cout<<"The index of the largest combination is: "<<idx<<endl;
  cout<<idx<<" "<<p[idx]<<endl;
 
  return 0;
}
