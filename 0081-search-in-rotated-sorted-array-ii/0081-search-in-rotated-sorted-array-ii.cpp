class Solution {
public:

    bool search(vector<int>& nums, int target) {
        int k = -1;
        int n = nums.size();
        int low,high;

        for(int i = 0 ; i < n-1 ; i++){
            if(nums[i] > nums[i + 1]){
                k = i;
            }
        }

        if(k == -1){
            low = 0;
            high = n - 1;
        }
        else{
            if(target <= nums[n - 1]){
                low = k+1;
                high = n-1;
            }
            else{
                low = 0;
                high = k;
            }
        }

        int mid;

        while(low <= high){
            mid = (low + high)/2;

            if(nums[mid] == target){
                return 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return 0;
    }
};