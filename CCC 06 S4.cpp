#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    while(true) {
        int identity;
        bool group = true;
        cin >> N;
        if(N==0) break;
        vector<vector<int> > grp(N+1,vector<int>(N+1));
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                cin >> grp[i][j];
            }
        }
        for(int i=1;i<=N;i++) {
            if(grp[1][i]==1 && grp[i][1]==1) {
                identity = i;
            }
        }
        for(int i=2;i<=N;i++) {
            if(!(grp[identity][i]==i && grp[i][identity]==i)) group = false;
        }
        if(!group) {
            cout << "no" << endl;
        } else {
            for(int i=1;i<=N;i++) {
                bool inversed = false;
                for(int j=1;j<=N;j++) {
                    if(grp[i][j]==identity && grp[j][i]==identity) inversed = true;
                }
                if(!inversed) group = false;
            }
            if(!group) {
                cout << "no" << endl;
            } else {
                for(int i=1;i<=N;i++) {
                    for(int j=1;j<=N;j++) {
                        for(int k=1;k<=N;k++) {
                            if(grp[grp[i][j]][k]!=grp[i][grp[j][k]]) {
                                group = false;
                                break;
                            }
                        }
                        if(!group) break;
                    }
                    if(!group) break;
                }
                if(!group) {
                    cout << "no" << endl;
                } else {
                    cout << "yes" << endl;
                }
            }
        }
    }
    return 0;
}
