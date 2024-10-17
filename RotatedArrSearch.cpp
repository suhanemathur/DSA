#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums); // Find the pivot point
        if (pivot == -1) {
            // If no pivot, the array is not rotated
            return binarySearch(nums, target, 0, nums.size() - 1);
        }
        
        // If pivot is found, check in both subarrays
        if (nums[pivot] == target) {
            return pivot;
        }
        
        if (nums[0] <= target) {
            // If target is in the left sorted subarray
            return binarySearch(nums, target, 0, pivot - 1);
        } else {
            // If target is in the right sorted subarray
            return binarySearch(nums, target, pivot + 1, nums.size() - 1);
        }
    }

    int binarySearch(vector<int>& nums, int target, int s, int e) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1; // Return -1 if target is not found
    }

    int findPivot(vector<int>& nums) {
        int s =0;
        int e =nums.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (mid < e && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            if (mid > s && nums[mid] < nums[mid - 1]) {
                return mid - 1;
            }
            
            if (nums[mid] <= nums[s]) {
                e = mid - 1; //means right side is not sorted so pivot must be somewhere there
            } else {
                s = mid + 1;//means left side is sorted so pivot must be on right
            }
        }
        
        return -1; 
    }
};

int search(int arr[], int si, int ei, int target){
    if(si>ei){
        return -1;
    }
    int mid=si+(ei-si)/2;
    if(arr[mid]==target){
        return mid;
    }
    if(arr[si]<=arr[mid]){
        if(arr[si]<=target && target<=arr[mid]){
            return search(arr, si,mid-1, target);
        }
        else{
            return search(arr, mid+1, ei, target);
        }
    }
    else{
        if(arr[mid]<=target && target<=arr[ei]){
            return search(arr, mid+1, ei, target);
        }
        else{
            return search(arr, si, mid-1, target);
        }
    }
}