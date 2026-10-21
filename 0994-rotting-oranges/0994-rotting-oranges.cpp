class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh = 0;
        int size;
        int minute = 0;

        int dr[4] = {-1 , 1 , 0 , 0};
        int dc[4] = {0 , 0 , -1 , 1};

        queue<vector<int>> q;

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        while(!q.empty() && fresh > 0){
            size = q.size();

            for(int i = 0 ; i < size ; i++){
                int r = q.front()[0];
                int c = q.front()[1];

                q.pop();

                for(int j = 0 ; j < 4 ; j++){
                    int nr = r + dr[j];
                    int nc = c + dc[j];

                    if(nr >= 0 && nr < rows && nc >= 0 && nc <cols && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;

                        q.push({nr,nc});
                    }
                }
            }

            minute++;
        }

        if(fresh != 0){
            return -1;
        }

        return minute;
    }
};