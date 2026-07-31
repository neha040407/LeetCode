class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxsofar = values[0];
        int ans = INT_MIN;
        int sum;

        for(int i = 1 ; i < n ; i++){
            sum = values[i] - i + maxsofar;
            ans = max(sum,ans);
            maxsofar = max(maxsofar , values[i] + i);
        }

        return ans;
    }
};