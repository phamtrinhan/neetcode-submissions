class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;

        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];

            vector<int> count(26, 0);

            for (int j = 0; j < s.size(); j++) {
                char c = s[j];
                count[c - 'a']++;
            }

            string key = "";

            for (int j = 0; j < 26; j++) {
                key += to_string(count[j]);
                key += ",";
            }

            res[key].push_back(s);
        }

        vector<vector<string>> result;

        for (auto it = res.begin(); it != res.end(); it++) {
            result.push_back(it->second);
        }

        return result;
    }
};