//Problem 485. Max Consecutive Ones

auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return(0);
}();
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_streak = 0;
        int current_streak = 0;
        for(int num : nums) {
            if (num == 1) {
                current_streak++;
                max_streak = max(max_streak,current_streak);
            } else {
                current_streak =0;
            }
        }
        return max_streak;
    }
};

//Time Complexity: O(n) - The code iterates through the input array once, performing constant-time operations for each element, resulting in linear time complexity.
//Space Complexity: O(1) - The code uses a fixed number of integer variables to keep track of the current and maximum streaks, which requires constant space regardless of the input size.