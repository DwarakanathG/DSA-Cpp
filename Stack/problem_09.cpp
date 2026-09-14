//Problem 150. Evaluate Reverse Polish Notation

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        st.reserve(tokens.size());

        for (const string& token : tokens) {
            if (token.size() == 1 && !isdigit(token[0])) {
                int b = st.back(); st.pop_back();
                int a = st.back(); st.pop_back();

                switch (token[0]) {
                    case '+': st.push_back(a + b); break;
                    case '-': st.push_back(a - b); break;
                    case '*': st.push_back(a * b); break;
                    case '/': st.push_back(a / b); break;
                }
            } else {
                st.push_back(stoi(token));
            }
        }

        return(st.back());
    }
};

//Time Complexity: O(n) - The code iterates through the input tokens once, performing constant-time operations for each token, resulting in linear time complexity.
//Space Complexity: O(n) - The code uses a stack to store intermediate results, which can potentially store all n tokens in the worst case, leading to linear space complexity.