//Problem 2472: Maximum Number of Non-Overlapping Palindrome Substrings

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int ans = 0;
        int lastEnd = -1;
        for(int centre = 0; centre < 2*n-1; ++centre){
            int left = centre/2;
            int right = left + (centre % 2);
            while(left >= 0 && right < n && s[left] == s[right]){
                if(right - left + 1 >= k){
                    if(left > lastEnd){
                        ans++;
                        lastEnd = right;
                    }
                    break;
                }
                left--;
                right++;
            }
        }
        return(ans);
    }
};

//Time Complexity: O(n * k) since expansion breaks early at length k
//Space Complexity: O(1) constant auxiliary space.
