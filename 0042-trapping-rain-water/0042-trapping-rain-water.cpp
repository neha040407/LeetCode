class Solution {
public:
    int trap(vector<int>& height) {
        int totalw = 0;
        int nextg;
        int addon;
        int currmax = 0;
        int n = height.size();
        vector<int> prevg(n);

        for(int i = 0 ; i < n ; i++){
            prevg[i] = currmax;
            currmax = max(currmax , height[i]);
        }

        currmax = 0;

        for(int i = n - 1 ; i >= 0 ; i--){
            nextg = currmax;
            currmax = max(currmax , height[i]);
            addon = (min(prevg[i],nextg) - height[i]);
            if(addon < 0){
                addon = 0;
            }
            totalw += addon;
        }

        return totalw;
    }
};