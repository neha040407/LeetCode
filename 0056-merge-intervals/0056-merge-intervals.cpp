class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int noofint = intervals.size();

        sort(intervals.begin(), intervals.end());

        int lower = intervals[0][0] , upper = intervals[0][1];

        for(int i = 1 ; i < noofint ; i++){
            if(intervals[i][0] <= upper){
                upper = max(upper , intervals[i][1]);
            }
            else{
                ans.push_back({lower,upper});
                lower = intervals[i][0];
                upper = intervals[i][1];
                i--;
            }
        }

        ans.push_back({lower,upper});

        return ans;
    }
};