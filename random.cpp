#include<iostream>
#include<vector>
using namespace std;

int pivot(vector<int>arr, int si, int ei){
        if(si>ei){
            return -1;
        }

        while(si<=ei){
            int mid=si+(ei-si)/2;
            if(mid<ei && arr[mid]>arr[mid+1]){
                return mid;
            }
            if(mid>si && arr[mid]<arr[mid-1]){
                return mid-1;
            }
            if(arr[si]<=arr[mid]){
                si=mid+1;
            }
            else{
                ei=mid-1;
            }
        }
        return -1;
    }


int main(){
    vector<int>arr={4,5,6,1,2,3};
    cout<<pivot(arr, 0, arr.size()-1);
    


    return 0;
}