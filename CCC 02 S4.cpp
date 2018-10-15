#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int M,Q,grp,counter=0;
    cin >> M >> Q;
    cin.get();
    vector<string> name(Q+1);
    vector<int> T(Q+1),dp(Q+1,1e9),grps(Q+1,0),bounds;
    dp[0] = 0;
    for(int i=1;i<=Q;i++) {
        getline(cin,name[i]);
        cin >> T[i];
        cin.get();
        for(int j=1;j<=M && i-j>=0;j++) {
            if(dp[i]>*max_element(T.begin()+i-j+1,T.begin()+i+1)+dp[i-j]) {
                dp[i] = *max_element(T.begin()+i-j+1,T.begin()+i+1)+dp[i-j];
                grps[i] = j;
            }
        }
    }
    grp = Q;
    while(grps[grp]!=0) {
        bounds.push_back(grps[grp]);
        grp -= grps[grp];
    }
    counter = 1;
    cout << "Total Time: " << dp[Q] << "\n";
    for(int i=bounds.size()-1;i>=0;i--) {
        for(int j=0;j<bounds[i];j++) {
            cout << name[counter++] << " ";
        }
        cout << "\n";
    }
    return 0;
}
