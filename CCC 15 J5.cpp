#include<bits/stdc++.h>

using namespace std;

int dp[255][255];

int main() {
    int N,K;
    scanf("%d%d",&N,&K);
    for(int i=1;i<=K;i++) {
        for(int j=1;j<=N;j++) {
            if(j==i) {
                dp[i][j] = 1;
            } else if(i==1) {
                dp[i][j] = 1;
            } else if(j>i) {
                dp[i][j] = dp[i-1][j-1]+dp[i][j-i];
            }
        }
    }
    printf("%d",dp[K][N]);
}
