#include <iostream>
#include<vector>
using namespace std;

void printsubsets(string str, string subset){
    if(str.size()==0){
        cout<<subset<<"\n";
        return;
    }
    char ch=str[0];
    printsubsets(str.substr(1, str.size()-1), subset+ch);
    printsubsets(str.substr(1, str.size()-1), subset);
}

void printarr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i];
    }
}

void manipulatearray(int arr[], int n, int i){
    if(i==n){
        printarr(arr, n);
    }
    manipulatearray(arr, n, i+1);
    manipulatearray(arr,)
}


int main(){
    string str="abc";
    string subset="";
    printsubsets(str, subset);


    return 0;
}