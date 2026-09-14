//Problem 448. Find All Numbers Disappeared in an Array

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int val = (nums[i] < 0) ? -nums[i] : nums[i]; 
            int target_index = val - 1; 
            
            if (target_index >= 0 && target_index < n) {
                if (nums[target_index] > 0) {
                    nums[target_index] = -nums[target_index];
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};

//Time Complexity: O(n) - The code iterates through the input array twice, performing constant-time operations for each element, resulting in linear time complexity.
//Space Complexity: O(1) - The code modifies the input array in place and uses a fixed number of integer variables, which requires constant space regardless of the input size. The result vector is also of size n, but since it is the output, it does not count towards the space complexity.