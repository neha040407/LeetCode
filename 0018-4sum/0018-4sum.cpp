class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int k , l;
        long sum;

        vector<vector<int>> ans;

        for(int i = 0 ; i <= n - 4 ; i++){
            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }

            for(int j = i+1 ; j <= n - 3 ; j++){

                if(j != i+1 && nums[j] == nums[j-1]){
                    continue;
                }

                k = j+1;
                l = n-1;

                while(k < l){
                    sum = (long)nums[i] + (long)nums[j] + (long)nums[k] + (long)nums[l];
                    if(sum == target){
                        ans.push_back({nums[i] , nums[j] , nums[k] , nums[l]});
                        k++;
                        l--;
                        while(k<l && nums[k-1] == nums[k]){
                            k++;
                        }
                        while(k<l && nums[l+1] == nums[l]){
                            l--;
                        }
                    }

                    else if(sum < target){
                        k++;
                        while(k<l && nums[k-1] == nums[k]){
                            k++;
                        }
                    }

                    else{
                        l--;
                        while(k<l && nums[l+1] == nums[l]){
                            l--;
                        }
                    }


                }

            }
        } 

        return ans;
    }
};