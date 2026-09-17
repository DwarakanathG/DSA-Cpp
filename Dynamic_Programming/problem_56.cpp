//Problem 45: Jump Game II

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return(0);

        int current = 0;
        int farthest = 0;
        int jumps = 0;
        for(int i=0; i < n-1; ++i){
            farthest = max(farthest, i + nums[i]);
            if(i == current){
                jumps++;
                current = farthest;
                if(current >= n-1){
                    break;
                }
            }
        }
        return(jumps);
    }
};

//Time Complexity: O(n) for iterating through the array
//Space Complexity: O(1) for using constant space