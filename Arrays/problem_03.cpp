//Problem 1470. Shuffle the Array

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        ans.reserve(2*n);
        for(int i=0; i<n; i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[i+n]);
        }
        return ans;
    }
};

//Time Complexity: O(n) - The code iterates through the input array once, performing constant-time operations for each element, resulting in linear time complexity.
//Space Complexity: O(n) - The code creates a new vector of size 2n to store the shuffled result, which requires linear space relative to the input size.