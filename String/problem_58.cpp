//Problem 1520: Maximum Number of Non-Overlapping Substrings

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> left(26, n);
        vector<int> right(26, -1);
        
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            left[idx] = min(left[idx], i);
            right[idx] = max(right[idx], i);
        }
        
        auto get_valid_end = [&](int i) -> int {
            int r = right[s[i] - 'a'];
            for (int j = i; j <= r; ++j) {
                int char_idx = s[j] - 'a';
                
                if (left[char_idx] < i) {
                    return(-1);
                }
                r = max(r, right[char_idx]);
            }
            return(r);
        };
        
        vector<pair<int, int>> intervals;
        
        for (int i = 0; i < n; ++i) {
            if (i == left[s[i] - 'a']) {
                int end = get_valid_end(i);
                if (end != -1) {
                    intervals.push_back({end, i}); 
                }
            }
        }
        
        sort(intervals.begin(), intervals.end());
        
        vector<string> res;
        int last_end = -1;
        for (const auto& interval : intervals) {
            int end = interval.first;
            int start = interval.second;
            if (start > last_end) {
                res.push_back(s.substr(start, end - start + 1));
                last_end = end;
            }
        }
        return(res);
    }
};

//Time Complexity: O(n) for traversing the string and finding intervals
//Space Complexity: O(n) for storing the intervals and result