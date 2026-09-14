class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int OFFSET = 10000;
        const int SIZE = 20001;  // vì -10000 ≤ nums[i] ≤ 10000
        vector<int> freq(SIZE, 0);

        // B1: Đếm tần suất, dịch chỉ số sang dương
        for (int num : nums) {
            freq[num + OFFSET]++;
        }

        // B2: Tạo danh sách các số đã xuất hiện
        vector<int> uniqueNums;
        for (int i = 0; i < SIZE; ++i) {
            if (freq[i] > 0) {
                uniqueNums.push_back(i - OFFSET);  // chuyển lại về số gốc
            }
        }

        // B3: Sắp xếp giảm dần theo tần suất
        sort(uniqueNums.begin(), uniqueNums.end(), [&](int a, int b) {
            return freq[a + OFFSET] > freq[b + OFFSET];
        });

        // B4: Trả về k phần tử có tần suất cao nhất
        return vector<int>(uniqueNums.begin(), uniqueNums.begin() + k);
    }
};