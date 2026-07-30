class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        unordered_set<int> st(nums.begin(), nums.end());

        int maxlength = 1;

        for (int num : st) {

            // Only start counting if this is the first number of a sequence
            if (st.find(num - 1) == st.end()) {

                int curr = num;
                int length = 1;

                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    length++;
                }

                maxlength = max(maxlength, length);
            }
        }

        return maxlength;
    }
};