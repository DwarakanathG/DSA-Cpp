//problem 1. Two Sum

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};

//time complexity: O(n) - The code iterates through the input array once, performing constant-time operations for each element, resulting in linear time complexity.
//space complexity: O(n) - The code uses an unordered_map to store the elements of the input array, which can potentially store all n elements in the worst case, leading to linear space complexity.