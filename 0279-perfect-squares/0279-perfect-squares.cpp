class Solution {
public:
    
    int numSquares(int sum) {
        vector<int>arr;
            for(int i=1;i*i<=sum;i++)
            {
                    arr.push_back(i*i);
            }
           int n=arr.size();
            vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
             for(int i=0;i<=n;i++)
             {
                     for(int j=0;j<=sum;j++)
                     {
                             if(i==0)
                                     dp[i][j]=1e9;
                             if(j==0)
                                     dp[i][j]=0;
                     }
             }
            for(int i=1;i<=n;i++)
            {
                    for(int j=1;j<=sum;j++)
                    {
                            dp[i][j]=dp[i-1][j];
                            if(j>=arr[i-1])
                                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-arr[i-1]]);
                    }
            }
            return dp[n][sum]==1e9?1:dp[n][sum];
    }
};