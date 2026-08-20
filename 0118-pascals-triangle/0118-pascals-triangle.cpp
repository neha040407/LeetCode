class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        if (numRows >= 1)
            ans.push_back({1});

        if (numRows >= 2)
            ans.push_back({1, 1});

        int val;

        for(int i = 2 ; i < numRows ; i++){
            vector<int> row;
            row.push_back(1);
            for(int j = 1 ; j < i ; j++){
                val = ans[i-1][j-1] + ans[i-1][j];
                row.push_back(val);
            }
            row.push_back(1);
            ans.push_back(row);
        }

        return ans;
    }
};