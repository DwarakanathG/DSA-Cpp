//Problem 645. Set Mismatch

auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int count[10001] = {0}; 
        int duplicate = -1;
        int missing = -1;
        for (int i = 0; i < n; ++i) {
            count[nums[i]]++;
        }
        for (int i = 1; i <= n; ++i) {
            if (count[i] == 2) {
                duplicate = i;
            } else if (count[i] == 0) {
                missing = i;
            }
            if (duplicate != -1 && missing != -1) {
                break;
            }
        }
        return {duplicate, missing};
    }   
};

//Time Complexity: O(n) - The code iterates through the input array once to count the occurrences of each number, and then iterates through the count array to find the duplicate and missing numbers, resulting in linear time complexity.
//Space Complexity: O(n) - The code uses a fixed-size count array of size  10001 to store the occurrences of each number, which requires linear space relative to the input size.