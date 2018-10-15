#include<bits/stdc++.h>

using namespace std;

int main() {
    int t,N,K,W,pin[30005];
    pin[0] = 0;
    cin >> t;
    for(int i=0;i<t;i++) {
        scanf("%d %d %d",&N,&K,&W);
        vector<vector<int> > dp(K,vector<int>(N+1,0));
        for(int j=1;j<=N;j++) {
            scanf("%d",&pin[j]);
            pin[j] += pin[j-1];
        }
        if(K*W>=N) {
            printf("%d\n",pin[N]);
        } else {
            for(int m=1;m<=N;m++) {
                dp[0][m] = (m<W) ? pin[m] : pin[m]-pin[m-W];
                dp[0][m] = max(dp[0][m-1],dp[0][m]);
            }
            for(int m=1;m<K;m++) {
                for(int p=1;p<=N;p++) {
                    dp[m][p] = (p<=m*W) ? dp[m-1][p] : dp[m-1][p-W]+pin[p]-pin[p-W];
                    dp[m][p] = max(dp[m][p],dp[m][p-1]);
                }
            }
            printf("%d\n",dp[K-1][N]);
        }
    }
    return 0;
}
