#include<iostream>
#include <vector>
using namespace std;

int binarysearch(vector<int>& nums, int target, int start, int end){
    while(start<=end){
        int mid=start+(end-start)/2;
        while(start<=end){
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>target){
                end=mid-1;
            }
            if(nums[mid]<target){
                start=mid+1;
            }
        }
    }
    return -1;
}

int findpivot(vector<int>& nums){
    int s=0; 
    int e=nums.size()-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(mid<e && nums[mid]>nums[mid+1]){
            return mid;
        }
        if(mid>s && nums[mid]<nums[mid-1]){
            return mid-1;
        }
        if(nums[mid]>=nums[s]){
            s=mid+1;
        }
        if(nums[mid]<=nums[s]){
            e=mid-1;
        }
    }
    return -1;
}

int searchtarget(vector<int>& nums, int target){
    int rotatedarr=findpivot(nums);
    if(rotatedarr==-1){
        binarysearch(nums, target, 0, nums.size()-1);
    }
    if(nums[0]>=target){
        
    }

}

// int binarysearch(vector<int>& nums, int target, int start, int end){
//     while(start<=end){
//         int mid=start+(end-start)/2;
//         while(start<=end){
//             if(nums[mid]==target){
//                 return mid;
//             }
//             if(nums[mid]>target){
//                 end=mid-1;
//             }
//             if(nums[mid]<target){
//                 start=mid+1;
//             }
//         }
//     }
//     return -1;
// }

// int findpivot(vector<int>& nums){
//     int s=0; 
//     int e=nums.size()-1;
//     while(s<=e){
//         int mid=s+(e-s)/2;
//         if(mid<e && nums[mid]>nums[mid+1]){
//             return mid;
//         }
//         if(mid>s && nums[mid]<nums[mid-1]){
//             return mid-1;
//         }
//         if(nums[mid]>=nums[s]){
//             s=mid+1;
//         }
//         if(nums[mid]<=nums[s]){
//             e=mid-1;
//         }
//     }
//     return -1;
// }

int main(){
    //for a sorted array that has been rotated, find target value index in O(logn)
    //O(logn) given-hint for binary sort
    //1. find the point from where the arr is rotated
    //2. craete a helping serach fn that will determine which of the 2 arrays to look in 
    //3. search in the desired arr using binary search

    vector<int>nums={4,5,6,7,0,1,2};
    int res=searchtarget(nums,0);
    cout<<res;


    return 0;
}