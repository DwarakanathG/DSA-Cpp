//Problem 1365. How Many Numbers Are Smaller Than the Current Number

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(102,0);
        for(int num : nums){
            count[num]++;
        }
        int running_sum = 0;
        for (int i = 0; i <= 100; ++i) {
            int temp = count[i];
            count[i] = running_sum;
            running_sum += temp;
        }
        vector<int> result;
        result.reserve(nums.size());
        for (int num : nums) {
            result.push_back(count[num]);
        }
        return(result);
    }
};

//Time Complexity: O(n) - The code iterates through the input array once to count the occurrences of each number, and then iterates through the count array to compute the running sum, resulting in linear time complexity.
//Space Complexity: O(1) - The code uses a fixed-size count array of size 102 to store the occurrences of each number, which requires constant space regardless of the input size. The result vector is also of size n, but since it is the output, it does not count towards the space complexity.