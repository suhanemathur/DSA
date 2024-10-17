#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void printarr(int *arr, int n){
    for(int i=0; i<n; i++){
        cout<<(arr+i)<<":"<<*(arr+i)<<endl;
    }
}

//fn to print start and end pos of subarrays
void printsubarrpos(int*arr, int n){
    for(int start=0; start<n; start++){
        for(int end=start; end<n; end++){
            cout<<"("<<start<<","<<end<<")";
        }
        cout<<endl;
    }

}

//fn to print indivisual sum of all subarrays
void printsubarrsums(int *arr, int n){
    for(int start=0; start<n; start++){
        for(int end=start; end<n; end++){
            int sum=0; 
            for(int i=start; i<=end; i++){
                sum+=arr[i];
            }
            cout<<sum<<",";
        }
        cout<<endl;
    }
}

//fn to print max subarray sum
void printmaxsubarrsum(int *arr, int n){ //O(n^3) TC
    int maxsum=INT_MIN;
    for(int start=0; start<n; start++){
        for(int end=start; end<n; end++){
            int currsum=0;
            for(int i=start; i<=end; i++){
                currsum+=arr[i];
                if(currsum>maxsum){
                    maxsum=currsum;
                }
            }
        }
    }
    cout<<maxsum;
}

void printmaxsubarrsum2(int *arr, int n){ //O(n^2) tc 
    int maxsum=INT_MIN;

    for(int start=0; start<n; start++){
        int currsum=0;
        for(int end=start; end<n; end++){
            currsum+=arr[end];
            maxsum=max(currsum, maxsum);
        }
    }
    cout<<maxsum;
}

void kadanealgo(int *arr, int n){ //O(n) tc
    int maxsum=INT_MIN;
    int currsum=0;
    for(int start=0; start<n; start++){
        currsum+=arr[start];
        maxsum=max(currsum, maxsum);
        if(currsum<0){
            currsum=0;
        }
    }
    cout<<"max subarray sum is:"<<maxsum;
}

void buysellstock(int*arr, int n){
    int maxprofit=INT_MIN;
    int buyday=INT_MAX;
    int currprofit=0;

    for(int i=0; i<n; i++){
        if(arr[i]<buyday){
            buyday=arr[i];
        }
        currprofit=arr[i]-buyday;
        maxprofit=max(currprofit,maxprofit);
    }
    cout<<"Max profit is:"<<maxprofit;

}

vector<int> buysellstocksday(int *arr, int n){
    vector<int>buyday;
    int temp=-1;
    int maxprofit=INT_MIN;
    int currprofit=0;
    int minprice=INT_MAX;
    for(int i=0; i<n; i++){
        if(arr[i]<minprice){
            minprice=arr[i];
        } 
        buyday.push_back(minprice);
    }
    return buyday;
}

int findpivot(vector<int>& nums){
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2; //to avoid overflow
            if(mid<e && nums[mid]>nums[mid+1]){
                return mid; //
            }
            if(mid>s && nums[mid]<nums[mid-1]){
                return mid-1;
            }
            if(nums[mid]<=nums[s]){
                mid=mid+1;
            }
            if(nums[mid]>=nums[s]){
                mid=mid-1;
            }
        }
    return -1;
}


int main(){

    // INT_MAX:  +infinity
    // INT_MIN:  -infinity

    int arr[6]={2, -3, 6, -5, 4, 2};
    int n=sizeof(arr)/sizeof(int);
    printarr(arr, n);
    printsubarrpos(arr, n);
    printsubarrsums(arr, n);

    cout<<"max subarray sum:";
    printmaxsubarrsum(arr, n);
    cout<<endl;

    cout<<"maxsubarray sum:";
    printmaxsubarrsum2(arr,n);
    cout<<endl;

    int arr1[9]={-2,1,-3,4,-1,2,1,-5,4};
    int n1=sizeof(arr1)/sizeof(int);
    kadanealgo(arr1, n1);

    int prices[6]={7, 1, 5, 3, 6, 4};
    int n2=sizeof(prices)/sizeof(int);
    vector<int>result=buysellstocksday(prices, n2);
    cout<<"The best buy days for each dy is:"<<endl;
    for(auto it:result){
        cout<<it<<",";
    }

    cout<<endl;

    vector<int>nums={4,5,6,7,0,1,2};
    cout<<"The array is rotated from the point:";
    cout<<findpivot(nums);





    return 0;
}