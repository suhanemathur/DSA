#include <iostream>
#include <vector>
using namespace std;

    void merge(string arr[], int si, int mid, int ei){
        vector<string>temp;
        int i=si;
        int j=mid+1;

        while(i<=mid && j<=ei){
            if(arr[i]<arr[j]){
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

    void mergsesort(string arr[], int si, int ei){
        if(si>=ei){
            return;
        }
        int mid=si+(ei-si)/2;
        mergsesort(arr, si, mid);
        mergsesort(arr, mid+1, ei);
        merge(arr, si, mid, ei);
    }

    int partition(string arr[], int si, int ei){
        int i=si-1;
        string pivot=arr[ei];
        for(int j=si; j<ei; j++){
            if(arr[j]<=pivot){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        i++;
        swap(arr[i], arr[ei]);
        return i;
    }

    void quicksort(string arr[], int si, int ei){
        if(si>=ei){
            return;
        }

        int partitionidx=partition(arr, si, ei);
        quicksort(arr, si, partitionidx-1);
        quicksort(arr, partitionidx+1, ei);
    }

    void printarr(string arr[], int n){
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
    }

int main(){
    string arr[4]={"sun","earth","mars","mercury"};
    int n=sizeof(arr)/sizeof(string);
    printarr(arr, n);
    cout<<endl;
    // mergsesort(arr, 0, n-1);
    // cout<<endl;
    // printarr(arr, n);
    // cout<<endl;
    quicksort(arr, 0, n-1);
    printarr(arr, n);


    return 0;
}