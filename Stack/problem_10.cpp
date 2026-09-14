//Problem 636. Exclusive Time of Functions

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> exclusive_times(n, 0);
        
        vector<int> st; 
        st.reserve(logs.size() / 2); 
        
        int prev_time = 0;

        for (const string& log : logs) {
            int id = 0;
            int i = 0;
            
            while (log[i] != ':') {
                id = id * 10 + (log[i] - '0');
                i++;
            }
            i++; 
            bool is_start = (log[i] == 's');
            while (log[i] != ':') {
                i++;
            }
            i++; 
            int timestamp = 0;
            int len = log.size();
            while (i < len) {
                timestamp = timestamp * 10 + (log[i] - '0');
                i++;
            }
            if (is_start) {
                if (!st.empty()) {
                    exclusive_times[st.back()] += (timestamp - prev_time);
                }
                st.push_back(id);
                prev_time = timestamp;
            } else {
                exclusive_times[st.back()] += (timestamp - prev_time + 1);
                st.pop_back();
                prev_time = timestamp + 1;
            }
        }

        return exclusive_times;
    }
};

//Time Complexity: O(m) - The code iterates through the input logs once, performing constant-time operations for each log, resulting in linear time complexity relative to the number of logs.
//Space Complexity: O(m) - The code uses a stack to keep track of the function calls, which can potentially store all m logs in the worst case, leading to linear space complexity. The exclusive_times vector also requires O(n) space, but since n <= m, the overall space complexity is O(m).