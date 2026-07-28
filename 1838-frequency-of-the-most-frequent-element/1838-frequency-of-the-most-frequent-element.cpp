class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long cost;
        int start = 0;
        int maxlength = 0;
        long sum = 0;

        for(int end = 0 ; end < n ; end++){
            sum += (long)nums[end] ;
            cost = ((long)nums[end] * (end-start+1)) - sum;  //total increments we have to do to make the end element the most frequent

            while(cost>k){
                sum -= (long)nums[start];
                start++;
                cost = ((long)nums[end] * (end-start+1)) - sum;
            }
            
            maxlength = max(maxlength , end-start+1);
        }

        return maxlength;
    }
};