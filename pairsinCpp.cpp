#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int>p1, pair<int, int>p2){
    return p1.second<p2.second; //sort in ascending order based on second value
}

int main(){
    
    vector<int>start={0, 1, 2};
    vector<int>end={9, 2, 4};
    //we want to sort these based on end values

    vector<pair<int,int>>act(3, make_pair(0, 0));
    for(int i=0; i<3; i++){
        act[i]=make_pair(start[i], end[i]);
    }

    for(int i=0; i<3; i++){
        cout<<"activity "<< i<<" : "<<"("<<act[i].first<<","<<act[i].second<<")\n";
    }

    cout<<"---------after sorting based on second val-----------\n";

    sort(act.begin(), act.end(), compare);

    for(int i=0; i<3; i++){
        cout<<"activity "<< i<<" : "<<"("<<act[i].first<<","<<act[i].second<<")\n";
    }
    




    return 0;
}