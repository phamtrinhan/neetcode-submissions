class Solution {
    struct ArrayHash {
        size_t operator()(const array<int, 26>& arr) const {
            size_t hash = 0;

            for (int x : arr) {
                hash = hash * 31 + x;
            }

            return hash;
        }
    };

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, vector<string>, ArrayHash> groups;

        for (const string& s : strs) {
            array<int, 26> count{};

            for (char c : s) {
                ++count[c - 'a'];
            }

            groups[count].push_back(s);
        }

        vector<vector<string>> result;
        result.reserve(groups.size());

        for (auto& [count, group] : groups) {
            result.push_back(move(group));
        }

        return result;
    }
};