// My solution: Dynamic Programming
// Solution 2: BFS
// Sotution 3: DFS: To be checked.

class Solution {
public:
    int const MAX = 10000;
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,MAX);
        dp[0]=0;
        for (int i=1;i<=amount;i++){
            int temp = MAX;
            for (auto x:coins){
                if (i>=x){
                    temp = dp[i-x]+1;
                }
                if (temp<dp[i])
                    dp[i]=temp;
            }
        }
        cout << MAX;
        if (dp[amount]<MAX)
            return dp[amount];
        else return -1;
    }
};

