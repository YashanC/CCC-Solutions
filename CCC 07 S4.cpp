#include <bits/stdc++.h>

using namespace std;

struct slide {
    int beg,fin;
};

int n;

int path(int start,const vector<slide> &paths,vector<int> &dp) {
    if(start==n) {
        return 1;
    } else {
        int tot = 0;
        for(int i=0;i<paths.size();i++) {
            if(paths[i].beg==start) {
                if(dp[paths[i].fin-1]==-1) {
                    int x = path(paths[i].fin,paths,dp);
                    dp[paths[i].fin-1] = x;
                    tot += x;
                } else {
                    tot += dp[paths[i].fin-1];
                }
            }
        }
        return tot;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    slide s;
    cin >> n;
    vector<int> dp(n,-1);
    vector<slide> paths;
    while(true) {
        cin >> s.beg >> s.fin;
        if((s.beg==0)&&(s.fin==0)) {
            break;
        }
        paths.push_back(s);
    }
    cout << path(1,paths,dp);
    return 0;
}
