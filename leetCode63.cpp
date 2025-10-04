class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        if(rows ==1 || cols == 1){
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols ;j++)
                    if(obstacleGrid[i][j] == 1)
                        return 0;
            }
            return 1;
        }
        if(obstacleGrid[rows-1][cols-1] == 1)
            return 0;
        vector<vector<long long int>> dp(rows,vector<long long int>(cols,0));
        for(int i = cols-2; i >=0 ; i--){
            if(obstacleGrid[rows-1][i] != 1){
                dp[rows-1][i] = 1;
            }  
            else{
                break;
            }
        }
        for(int i = rows-2; i >= 0 ; i--){
            if(obstacleGrid[i][cols-1] != 1){
                dp[i][cols-1] = 1;
            }
            else{
                break;
            }

        }
        for(int i = rows-2; i >= 0; i--){
            for(int j = cols-2; j>=0; j--){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
        }
        return dp[0][0];
    }
};