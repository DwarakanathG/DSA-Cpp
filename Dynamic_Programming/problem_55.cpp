//Problem 1477: Find Two Non-overlapping Sub-arrays Each With Target Sum

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n,INT_MAX);
        int start = 0;
        int ans = INT_MAX;
        int best = INT_MAX;
        int current_sum = 0;
        for(int last=0; last<n; ++last){
            current_sum += arr[last];
            while(current_sum > target){
                current_sum -= arr[start];
                start++;
            }
            if(current_sum == target){
                int length = last - start + 1;
                if(start > 0 && min_len[start-1] != INT_MAX){
                    ans = min(ans, length + min_len[start-1]);
                }
                best = min(best,length);
            }
            if(last > 0){
                min_len[last] = min(min_len[last-1], best);
            } else {
                min_len[last] = best;
            }            
        }
        return(ans == INT_MAX ? -1 : ans);
    }
};

//Time Complexity: O(n) for iterating through the array
//Space Complexity: O(n) for storing the minimum lengths