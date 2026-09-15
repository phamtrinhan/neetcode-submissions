class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        st.reserve(tokens.size());
        int i = 0;
        while (i < tokens.size()) {
            string& s = tokens[i++];
            if (s.size() > 1 || isdigit(s[0])) {
                st.push_back(stoi(s));
                continue;
            }
            int a = st.back(); st.pop_back();
            int b = st.back(); st.pop_back();
            if (s[0] == '+') st.push_back(b + a);
            else if (s[0] == '-') st.push_back(b - a);
            else if (s[0] == '*') st.push_back(b * a);
            else st.push_back(b / a);
        }
        return st.back();
    }
};