#include <iostream>
#include <vector>
#include <climits>
using namespace std;

    int getauxarrays(int *arr, int n, int *rightmax, int *leftmax){
        int right_max=INT_MIN;
        int left_max=INT_MIN;
        int trappedwater[n]={0};

        //getting leftmax arr
        for(int i=0; i<n; i++){
            if(arr[i]>left_max){
                left_max=arr[i];
            }
            leftmax[i]=left_max;
        }

        //getting rightmax arr
        for(int i=n-1; i>=0; i--){
            if(arr[i]>right_max){
                right_max=arr[i];
            }
            rightmax[i]=right_max;
        }

        int totaltrap=0;
        for(int i=0; i<n; i++){
            trappedwater[i]=min(rightmax[i], leftmax[i])-arr[i];
            totaltrap+=trappedwater[i];
        }
        cout<<"The total trapped water is:"<<totaltrap<<" units";


    }

int main(){
    int rightmax[7];
    int leftmax[7];
    int water[7]={4, 2, 0, 6, 3, 2, 5};
    int n=sizeof(water)/sizeof(int);
    getauxarrays(water, n, rightmax, leftmax);
    cout<<endl;

    for(int i=0; i<n; i++){
        cout<<leftmax[i]<<",";
    }
    cout<<endl;

    for(int i=0; i<n; i++){
        cout<<rightmax[i]<<",";
    }

    


    return 0;
}
