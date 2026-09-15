class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); ++i)
            cars.emplace_back(position[i], speed[i]);
        sort(cars.rbegin(), cars.rend());
        int fleets = 0;
        double prev = 0;
        for (auto [pos, spd] : cars) {
            double time = (double)(target - pos) / spd;
            if (time > prev) {
                ++fleets;
                prev = time;
            }
        }
        return fleets;
    }
};