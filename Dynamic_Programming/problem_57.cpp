//Problem 22: Generate Parentheses

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current = "";
        backtrack(result, current , 0 ,0 ,n);
        return(result);
    }
private:
    void backtrack(vector<string>& result, string& current, int open, int close, int max_pairs){
        if (current.length() == 2 * max_pairs) {
            result.push_back(current);
            return;
        }
        if (open < max_pairs) {
            current.push_back('(');
            backtrack(result, current, open + 1, close, max_pairs);
            current.pop_back();
        }

        if (close < open) {
            current.push_back(')');
            backtrack(result, current, open, close + 1, max_pairs);
            current.pop_back();
        }
    }
};

//Time Complexity: O(4^n / sqrt(n)) for generating all combinations
//Space Complexity: O(4^n / sqrt(n)) for storing the result