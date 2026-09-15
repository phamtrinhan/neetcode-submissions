class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();

        vector<int> res(n);
        vector<int> st(n);
        int top = 0;

        for (int i = 0; i < n; ++i) {
            while (top > 0 && t[i] > t[st[top - 1]]) {
                int j = st[--top];
                res[j] = i - j;
            }

            st[top++] = i;
        }

        return res;
    }
};