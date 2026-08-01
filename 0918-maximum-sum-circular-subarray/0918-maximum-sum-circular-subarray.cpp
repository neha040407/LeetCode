class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int totalsum = 0;
        int minsum = INT_MAX;
        int maxsum = INT_MIN;
        int currmax = 0;
        int currmin = 0;

        for(int i = 0 ; i < n ; i++){
            totalsum += nums[i];

            currmax += nums[i];
            maxsum = max(currmax , maxsum);
            currmax = max(0 , currmax);

            currmin += nums[i];
            minsum = min(currmin , minsum);
            currmin = min(0 , currmin);
        }

        if(maxsum < 0){
            return maxsum;
        }
        return max(maxsum , totalsum - minsum);
    }
};