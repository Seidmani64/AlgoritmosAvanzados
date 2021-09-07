#include "job.h"
#include <vector>

bool isCompatible(const Job &a, const Job &b){
    if((b.startTimes >= a.finishTimes) && (b.finishTimes != a.finishTimes)){

        return true;
    }
    else{
        return false;
    }

}

int binarySearch(vector<Job> jobs, const Job &x )
{

    int lo = 1, hi = jobs.size(), mid = 0 ;

    while(lo < hi){
       mid = (lo + hi)/2;
       if(mid == 0){
        hi = -1;
       }
       else if(isCompatible(jobs.at(mid),x))
        lo = mid + 1;  
       else
        hi = mid;
    }

    if(lo == 1){
        return 0;
    }

    if(isCompatible(jobs.at(lo),x)){
      return lo;
    }
    else{
      return lo - 1;
    }
}
