#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int si, int mid, int ei){
    vector<int>temp;
    // int mid=si+(ei-si)/2;
    int i=si;
    int j=mid+1;

    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=ei){
        temp.push_back(arr[j]);
        j++;
    }

    int index=0;
    for(int i=si; i<=ei; i++){
        arr[i]=temp[index];
        index++;
    }
}

void mergesort(int arr[], int si, int ei){
    if(si>=ei){
        return;
    }

    int mid=si+(ei-si)/2;
    mergesort(arr, si, mid);
    mergesort(arr, mid+1, ei);

    merge(arr, si, mid, ei);
}

void printarr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[6]={6, 3, 7, 5, 2, 4};
    int n=sizeof(arr)/sizeof(int);
    mergesort(arr, 0, n-1);
    printarr(arr, n);



    return 0;
}