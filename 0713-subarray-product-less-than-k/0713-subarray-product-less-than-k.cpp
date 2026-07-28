class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int product = 1;
        int ans = 0;
        int start = 0;
        int len;

        if(k <= 1){
            return 0;
        }

        for(int end = 0 ; end < n ; end++){
            product *= nums[end];

            while(product >= k){
                product /= nums[start];
                start++;
            }

            ans += (end - start + 1);

        }

        return ans;
    }
};