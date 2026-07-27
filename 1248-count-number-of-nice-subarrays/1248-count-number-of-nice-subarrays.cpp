class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0 , scopy = 0;
        int oddcount = 0;
        int ans=0;

        for(int end = 0 ; end < n ; end++){
            if(nums[end]%2 != 0){
                oddcount++;
            }

            while(oddcount > k){
                if(nums[start]%2 != 0){
                    oddcount--;
                }
                start++;
            }

            if(oddcount == k){
                scopy = start;
                while(nums[scopy]%2 == 0){
                    ans++;
                    scopy++;
                }
                ans++;
            }
        }
        return ans;

    }
};