class Solution {
public:
    inline static unordered_map<int, int> hash;

    static bool myCompare(const int& a, const int& b) {
        return (hash[a] != hash[b])
            ? hash[a] < hash[b]
            : a > b;
    }

    vector<int> frequencySort(vector<int>& nums) {
        hash.clear();

        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }

        sort(nums.begin(), nums.end(), myCompare);

        return nums;
    }
};