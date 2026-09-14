class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return 0;

        if (s.length() == 1)
            return 1;

        int maxlength = 0;
        bool visited[256] = {false};

        int left = 0, right = 0;
        while (right < s.length()) {
            if (visited[s[right]] == true) {
                while (visited[s[right]] == true) {
                    visited[s[left]] = false;
                    left++;
                }
            }
            visited[s[right]] = true;

            maxlength = max(maxlength, (right - left + 1));
            right++;

        }
        return maxlength;
    }
};
