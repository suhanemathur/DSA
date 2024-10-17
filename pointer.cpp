#include <iostream>
#include <vector>
using namespace std;

void printarr(int nums[]){
    // cout<<sizeof(nums)<<endl; //will output 4/8- which is size of int pointer (in 32 and 64 bit sys resp.)

    // //ERROR IN BELOW CODE- since sizeoff nums refers to the pointed location ie. 0th element of 
    // // the array since passed by reference 

    // // int size=sizeof(nums)/sizeof(int);
    // // for(int i=0; i<size; i++){
    // //     cout<<nums[i];
    // // }

    // for(int i=0; i<nums.size(); i++){
    //     cout<<nums[i];
    // }


}

void printarray(int nums[], int n){
    for(int i=0; i<n; i++){
        cout<<(nums+i)<<":"<<*(nums+i)<<endl;
    }
}

void printsubarrpos(int*arr, int n){
    int sum=0;
    for(int start=0; start<n; start++){
        for(int end=start; end<n; end++){
            // cout<<"("<<start<<","<<end<<")"; //to print all start and end points of subarrays

            //to print subarrays
            // for(int i=start; i<=end; i++){
            //     cout<<arr[i];
            // }
            // cout<<",";

            //to print sum of all subarrays
            int currsum=0;
            for(int i=start; i<=end; i++){
                currsum+=arr[i];
            }
            cout<<currsum<<",";

        }
        cout<<endl;
    }
    // cout<<sum;
}

int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);
    cout<<n<<endl;
    // printarr(arr);

    int x=10;
    int *ptr=&x;

    cout<<*ptr<<endl;
    cout<<ptr<<endl;
    ptr++;
    cout<<ptr<<endl;
    cout<<*ptr;

    printarray(arr, n);

    // int arr[]={1,2,3,4,5};
    printsubarrpos(arr,n);










    return 0;
}