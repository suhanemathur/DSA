#include<iostream>
#include<vector>
using namespace std;

class Job{
    int idx;
    int deadline;
    int profit;

    Job(int idx, int deadline, int profit){
        this->idx=idx;
        this->deadline=deadline;
        this->profit=profit;
    }
};

int maxprofit(vector<pair<int, int>> pairs){
    int n=pairs.size();
    vector<Job> jobs;

    for(int i=0; i<n; i++){
        //we are not using push_back here since with it we will have to make objects and then pass values, and then insert
        //that variable in the vector, emplace_back will directly insert values after making a new object internally,
        //since compiler knows that the vector is of objects of class Job
        jobs.emplace_back(i, pairs[i].first, pairs[i].second); //idx, deadline, profit
        //IMP-emplace back helps whenerver we are making a vector of objects this way
    }

}

int main(){



    return 0;
}