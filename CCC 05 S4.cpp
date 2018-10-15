#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int l,goodtime,n;
    cin >> l;
    unordered_map<string,int> level;
    for(int i=0;i<l;i++) {
        cin >> n;
        goodtime = 0;
        level.clear();
        vector<string> in(n);
        cin.get();
        for(int j=0;j<n;j++) {
            getline(cin,in[j]);
        }
        level[in[0]] = 1;
        level[in[n-1]] = 0;
        for(int j=1;j<n-1;j++) {
            if(level.find(in[j])==level.end()) level[in[j]] = level[in[j-1]]+1;
        }
        for(auto it=level.begin();it!=level.end();++it) {
            goodtime = max(goodtime,it->second);
        }
        printf("%d\n",n*10-goodtime*20);
    }
    return 0;
}
