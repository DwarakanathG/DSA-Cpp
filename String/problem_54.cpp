//Problem: 5. Longest Palindromic Substring

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return(s);
        int start = 0, maxLength = 0;
        auto expand = [&](int left, int right){
            while(left >= 0 && right < s.length() && s[left] == s[right]){
                left--;
                right++;
            }
            return(right - left - 1);
        };
        for(int i=0; i<s.length(); i++){
            int len1 = expand(i, i);
            int len2 = expand(i, i+1);
            int len = max(len1,len2);
            if(len > maxLength){
                maxLength = len;
                start = i - (len-1)/2;
            }
        }
        return(s.substr(start,maxLength));
    }
};

//Time Complexity: O(n^2) for expanding around each character
//Space Complexity: O(1) for using constant space