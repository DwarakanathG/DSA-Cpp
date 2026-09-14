//Problem 1441. Build an Array With Stack Operations

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int current_target_idx = 0;
        int max_stream_val = target.back(); // Stopping exactly at the last required number

        for (int i = 1; i <= max_stream_val; ++i) {
            // emplace_back avoids temporary string copies in memory
            result.emplace_back("Push");

            if (i == target[current_target_idx]) {
                current_target_idx++; 
            } else {
                result.emplace_back("Pop"); 
            }
        }

        return(result);
    }
};

//Time Complexity: O(m) - The code iterates through the stream of numbers from 1 to the last number in the target array, performing constant-time operations for each number, resulting in linear time complexity relative to the size of the target array.
//Space Complexity: O(m) - The code creates a result vector that stores the operations performed