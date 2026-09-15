class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int i = 0;
        while (i < tokens.size()) {
            const string& c = tokens[i];
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                if (c == "+") {
                    st.push(b + a);
                }
                else if (c == "-") {
                    st.push(b - a);
                }
                else if (c == "*") {
                    st.push(b * a);
                }
                else {
                    st.push(b / a);
                }
            }
            else {
                st.push(stoi(c));
            }
            i++;
        }
        return st.top();
    }
};