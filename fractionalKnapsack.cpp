#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<double, int>p1, pair<double, int>p2){
    return p1.first>p2.first;
}

int main(){

    //FRACTIONAL KNAPSACK- O(nlogn)

    vector<int>val={100, 60, 120};
    vector<int> wt={20, 10, 30};

    vector<pair<double, int>> ratio(val.size(), make_pair(0.0, 0));
    for(int i=0; i<val.size(); i++){
        double r=val[i]/double(wt[i]);
        ratio[i]=make_pair(r, i);
    }

    sort(ratio.begin(), ratio.end(), compare);  //O(nlogn)

    for(int i=0; i<val.size(); i++){
        cout<<ratio[i].first<<", "<<ratio[i].second<<endl;
    }

    double res=0.0;
    int W=50;

    for(int i=0; i<ratio.size(); i++){
        int idx=ratio[i].second; //index to easy access wt and val
        if(wt[idx]<=W){
            res+=val[idx];
            W-=wt[idx];
        }
        else{
            res+=ratio[i].first*W;
            W=0;
            break;
        }
    }

    cout<<res;



    return 0;
}