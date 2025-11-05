class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
     vector<int> dp(amount+1,numeric_limits<int>::max()/2);
     int dim = coins.size();
     dp[0] = 0;
     for(int i = 0; i < dim ; i++){
        for(int j =0 ; j < amount + 1; j++){
            int curr = j-coins[i];
            if( curr < 0)
                continue;
            dp[j] = min(dp[j] , dp[curr]+1);
        }
     }
     if(dp[amount] == numeric_limits<int>::max()/2)
        return -1;
    return dp[amount];
    }
    
};