class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> cnt;

        for (int i = 0; i < s.length(); i++) {
            cnt[s[i]]++;
        }

        for (int i = 0; i < t.length(); i++) {
            cnt[t[i]]--;

            if (cnt[t[i]] < 0) {
                return false;
            }
        }

        return true;
    }
};