class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int currow = 0;
        int curcol = n-1;

        while(currow != m && curcol != -1){
            if(matrix[currow][curcol] == target){
                return true;
            }
            else if(matrix[currow][curcol] > target){
                curcol--;
            }
            else{
                currow++;
            }
        }

        return false;
    }
};