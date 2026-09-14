class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int OFFSET = 10000;
        const int SIZE = 20001;  
        vector<int> freq(SIZE, 0);

        for (int num : nums) {
            freq[num + OFFSET]++;
        }

        vector<int> uniqueNums;
        for (int i = 0; i < SIZE; ++i) {
            if (freq[i] > 0) {
                uniqueNums.push_back(i - OFFSET);  
            }
        }

        sort(uniqueNums.begin(), uniqueNums.end(), [&](int a, int b) {
            return freq[a + OFFSET] > freq[b + OFFSET];
        });

        return vector<int>(uniqueNums.begin(), uniqueNums.begin() + k);
    }
};