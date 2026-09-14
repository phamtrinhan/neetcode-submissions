class Solution {
public:
    string encode(const vector<string>& strs) {
        string res;
        for (const string& s : strs) {
            res += to_string(s.size());
            res += '#';
            res += s;
        }
        return res;
    }
    vector<string> decode(const string& s) {
        vector<string> res;
        size_t i = 0;
        while (i < s.size()) {
            size_t j = i;
            while (s[j] != '#') {
                ++j;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            res.push_back(s.substr(i, length));
            i += length;
        }
        return res;
    }
};