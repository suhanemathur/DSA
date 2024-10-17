#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

bool valid_parethesis(string input){
    char a='(';
    char b='{';
    char c='[';
    char d=')';
    char e='}';
    char f=']';
    stack<char>s;
    for(int i=0; i<input.length(); i++){
        char curr=input[i];
        if(curr==a || curr==b || curr==c){
            s.push(curr);
        }
        else if(curr==d || curr==e || curr==f){
            if(curr==d){
                if(s.top()!=a){
                    return false;
                }
            }
            if(curr==e){
                if(s.top()!=b){
                    return false;
                }
            }
            if(curr==f){
                if(s.top()!=c){
                    return false;
                }
            }
            s.pop();
        }
    }
    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}

bool duplicate_parenthesis(string input1){
    stack<char>s;
    for(int i=0; i<input1.size(); i++){
        char curr=input1[i];
        if(curr=='(' || curr!=')'){
            s.push(curr);
        }
        else{
            int count=0;
            while(s.top()!='('){
                s.pop();
                count+=1;
            }
            if(count==0){
                cout<<"duplicate exists";
                return true;
            }
        }
    }
    return false;
}

int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>prevlow(n);
        vector<int>nextlow(n);
        stack<int>s;

        //prevlow;
        prevlow[0]=-1;
        s.push(0);
        for(int i=0; i<n; i++){
            while(!s.empty() && heights[i]<=heights[s.top()]){
                s.pop();
            }
            if(s.empty()){
                prevlow[i]=-1;
            }
            else{
                prevlow[i]=s.top();
            }
            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }
        
        //nextlow;
        nextlow[n-1]=n;  //last of the arr
        s.push(n-1);
        for(int i=n; i>=0; i--){
            while(!s.empty() && heights[i]<=heights[s.top()]){
                s.pop();
            }
            if(s.empty()){
                nextlow[i]=n; //no smaller ahead soo width will go till arr end
            }
            else{
                nextlow[i]=s.top();
            }
            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }

        int maxarea=0;
        for(int i=0; i<n; i++){
            int hi=heights[i];
            int width=nextlow[i]-prevlow[i]-1;
            int area=hi*width;
            maxarea=max(area, maxarea);
        }

        return maxarea;

        
    }

int main(){
    string input="([{}])";
    cout<<valid_parethesis(input)<<endl;
    vector<int>nums={2, 1, 5, 6, 2, 3};

    string input1="(a+b)+(c+d)";
    cout<<duplicate_parenthesis(input1)<<endl;

    // vector<int>res1=nextsmaller(nums);
    // for(int i=0; i<res1.size(); i++){
    //     cout<<res1[i]<<" ";
    // }
    // cout<<endl;

    // vector<int>res2=prevsmaller(nums);
    // for(int i=0; i<res2.size(); i++){
    //     cout<<res2[i]<<" ";
    // }
    // cout<<endl;

   


    return 0;
}