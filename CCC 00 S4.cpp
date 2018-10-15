#include <bits/stdc++.h>

using namespace std;

int main() {
    int d,n,club;
    bool stroke;
    cin >> d >> club;
    vector<int> c(club),S(d+1,0);
    for(int i=0;i<club;i++) {
        cin >> c[i];
    }
    for(int i=1;i<=d;i++) {
        n = 100000000;
        stroke = false;
        for(int j=0;j<club;j++) {
            if(c[j]<=i) {
                if(S[i-c[j]]!=-1) {
                    n = min(n,S[i-c[j]]+1);
                    stroke = true;
                }
            }
        }
        if(!stroke) {
            S[i] = -1;
        } else {
            S[i] = n;
        }
    }
    if(S[d]!=-1) {
        cout << "Roberta wins in " << S[d] << " strokes." << endl;
    } else {
        cout << "Roberta acknowledges defeat." << endl;
    }
}
