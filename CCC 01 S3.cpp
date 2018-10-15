#include <bits/stdc++.h>

using namespace std;

bool pts[30][30];

void warshall() {
    for(int i=0;i<26;i++) {
        for(int j=0;j<26;j++) {
            if(pts[j][i]) {
                for(int k=0;k<26;k++) {
                    if(pts[i][k]) {
                        pts[j][k] = true;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string road;
    vector<string> R;
    int bomb = 0;
    while(true) {
        cin >> road;
        if(road=="**") {
            break;
        }
        R.push_back(road);
    }
    for(int i=0;i<R.size();i++) {
        for(int j=0;j<26;j++) {
            for(int k=0;k<26;k++) {
                if(j!=k) {
                    pts[j][k] = false;
                } else {
                    pts[j][k] = true;
                }
            }
        }
        for(int j=0;j<R.size();j++) {
            if(i!=j) {
                pts[int(R[j][0])-65][int(R[j][1])-65] = true;
                pts[int(R[j][1])-65][int(R[j][0])-65] = true;
            }
        }
        warshall();
        if(!pts[0][1]) {
            cout << R[i] << "\n";
            bomb++;
        }
    }
    cout << "There are " << bomb << " disconnecting roads." << endl;
    return 0;
}
