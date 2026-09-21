class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> need(26, 0);
        vector<int> window(26, 0);
        for (char c : s1) {
            need[c - 'a']++;
        }
        int l = 0;
        for (int r = 0; r < s2.size(); r++) {
            // 1. Add right
            window[s2[r] - 'a']++;
            // 2. Shrink if window too large
            if (r - l + 1 > s1.size()) {
                window[s2[l] - 'a']--;
                l++;
            }
            // 3. Check when window size == s1.size()
            if (r - l + 1 == s1.size() && window == need) {
                return true;
            }
        }
        return false;
    }
};