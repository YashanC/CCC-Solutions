#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    while(true) {
        cin >> n >> m;
        vector<vector<int> > grid(n,vector<int>(m,0)),dp(n,vector<int>(m,-1));
        if(n==0 && m==0) break;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                char thing;
                cin >> thing;
                grid[i][j] = (thing=='*') ? -1 : (thing=='.') ? 0 : thing-'0';
            }
        }
        dp[n-1][0] = grid[n-1][0];
        for(int i=n-2;i>=0;i--) {
            if(grid[i][0]!=-1) {
                dp[i][0] = dp[i+1][0]+grid[i][0];
            } else {
                break;
            }
        }
        for(int i=1;i<m;i++) {
            for(int j=n-1;j>=0;j--) {
                if(dp[j][i-1]!=-1 && grid[j][i]!=-1) {
                    int subtotal = grid[j][i]+dp[j][i-1];
                    dp[j][i] = max(dp[j][i],dp[j][i-1]+grid[j][i]);
                    for(int k=j-1;k>=0;k--) {
                        if(grid[k][i]!=-1) {
                            subtotal += grid[k][i];
                            dp[k][i] = max(subtotal,dp[k][i]);
                        } else {
                            break;
                        }
                    }
                }
            }
            for(int j=0;j<n;j++) {
                if(dp[j][i-1]!=-1 && grid[j][i]!=-1) {
                    int subtotal = grid[j][i]+dp[j][i-1];
                    dp[j][i] = max(dp[j][i],dp[j][i-1]+grid[j][i]);
                    for(int k=j+1;k<n;k++) {
                        if(grid[k][i]!=-1) {
                            subtotal += grid[k][i];
                            dp[k][i] = max(subtotal,dp[k][i]);
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        cout << dp[n-1][m-1] << '\n';
    }
}
