//Problem 34. Find First and Last Position of Element in Sorted Array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1,-1};
        result[0] = findfirst(nums,target);
        result[1] = findlast(nums,target);
        return(result);
    }
private:
    int findfirst(const vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        int firstpos = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] ==  target){
                firstpos = mid;
                right = mid -1;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return(firstpos);
    }
private:
    int findlast(const vector<int>& nums, int target){
        int left = 0, right = nums.size()-1;
        int lastpos = -1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                lastpos = mid;
                left = mid + 1;
            } else if(nums[mid] < target){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return(lastpos);
    }
};

//Time Complexity: O(log n) - The code uses binary search to find the first and last positions of the target element in the sorted array, which has a logarithmic time complexity.
//Space Complexity: O(1) -  the amount of auxiliary memory used remains identical whether the input array has 10 elements or 100,000 elements, it consumes constant space.