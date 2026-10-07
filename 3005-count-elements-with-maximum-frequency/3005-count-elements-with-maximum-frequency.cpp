class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> hash;
        int maxfreq = INT_MIN;
        int sum = 0;

        for(int i : nums){
            hash[i]++;

            maxfreq = max(maxfreq, hash[i]);
        }

        for(auto i : hash){
            if(i.second == maxfreq){
                sum += maxfreq;
            }
        }

        return sum;
    }
};