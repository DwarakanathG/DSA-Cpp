//Problem 14. Longest Common Prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return("");
        }
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[strs.size() - 1];
        string result = "";
        for(int i = 0; i < min(first.length(), last.length()); i++){
            if(first[i] != last[i]){
                break;
            }
            result += first[i];
        }
        return(result);
    }
};

//Time Complexity: O(n log n) -because sorting strings takes O(m n log n) operations due to string comparisons of length m, which completely dominates the final linear scan.
//Space Complexity: O(1) - extracting the first and last strings of maximum length M requires a small amount of extra memory to store them for character comparison.