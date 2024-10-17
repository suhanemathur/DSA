#include<iostream>
#include <vector>
#include<stack>
using namespace std;

int main(){
    vector<int>nums={6, 8, 0, 1, 3};
    stack<int>s;
    vector<int>res(nums.size());
    res[res.size()-1]=-1;
    s.push(nums[nums.size()-1]);
    for(int i=nums.size()-2; i>=0; i--){
        while(!s.empty() && nums[i]>=s.top()){
            s.pop();
        }
        if(s.empty()){
            res[i]=-1;
        }
        else{
            int nexthigh=s.top();
            res[i]=nexthigh;
        }
        s.push(nums[i]);
    }

    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }

    //valid parenthesis
    //'(', ')', '{', '}', '[' and ']'
    
    


    return 0;
}