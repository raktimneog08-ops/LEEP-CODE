#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        
        for (char c : s) {
            // Push opening brackets onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                // If a closing bracket appears and the stack is empty, it's invalid
                if (st.empty()) {
                    return false;
                }
                
                char top = st.top();
                // Verify if the closing bracket matches the top of the stack
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        
        // Valid only if all opening brackets have been matched and popped
        return st.empty();
    }
};