class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int minsum = INT_MAX;
        int sum = 0 , totalsum;
        int windowsize = n - k;

        for(int i = 0 ; i < windowsize ; i++){
            sum += cardPoints[i];
        }

        totalsum = sum;

        for(int i = 1 ; i <= n-windowsize ; i++){

            minsum = min(sum , minsum);

            sum -= cardPoints[i-1];
            sum += cardPoints[i+windowsize-1];

            totalsum += cardPoints[i+windowsize-1];            
        }

        minsum = min(sum , minsum);
        return totalsum - minsum;
    }
};