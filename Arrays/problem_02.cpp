//Problem 1929. Concatenation of Array

class Solution
{
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);
        for(int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }
        return ans;
    }
};

//Time Complexity: O(n) - The code iterates through the input array once, performing constant-time operations for each element, resulting in linear time complexity.
//Space Complexity: O(n) - The code creates a new vector of size 2n to store the concatenated result, which requires linear space relative to the input size.