#include<iostream>
#include<vector>
using namespace std;

int partition(int arr[], int si, int ei){
    int i=si-1; //start i from one index before the valid si index
    int pivot=arr[ei];

    for(int j=si; j<ei; j++){
        if(arr[j]<=pivot){//j finds an ele less than pivot
            i++; //i reaches the first ele which is greater than pivot and was ignored by j
            swap(arr[i], arr[j]); //swapping of the smaller ele found by j, by greater ele on which i comes
        }
    }
    i++; //to get the pos just after the elements less than pivot
    swap(arr[i], arr[ei]);//placing pivot at that pos and plaing the prev ele ther to last since it too is 
                            //greater than pivot
    return i;
}

void quicksort(int arr[], int si, int ei){
    if(si>=ei){
        return;
    }

    int partitionidx=partition(arr, si, ei);

    quicksort(arr, si, partitionidx-1);
    quicksort(arr, partitionidx+1, ei);
}

void printarr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[6]={6, 3, 7, 2, 5, 4};
    int n=sizeof(arr)/sizeof(int);
    quicksort(arr, 0, n-1);
    printarr(arr, n);

    return 0;
}