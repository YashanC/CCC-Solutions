#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int N,totr,totc;
    totr = totc = 1;
    cin >> N;
    vector<vector<int> > tensor(1024,vector<int>(1024)),lasttensor(1024,vector<int>(1024)),inputs(1024,vector<int>(1024));
    lasttensor[0][0] = 1;
    for(int i=0;i<N;i++) {
        int r,c;
        cin >> r >> c;
        for(int j=0;j<r;j++) {
            for(int k=0;k<c;k++) {
                cin >> inputs[j][k];
            }
        }
        for(int j=0;j<totr*r;j++) {
            for(int k=0;k<totc*c;k++) {
                tensor[j][k] = lasttensor[j%totr][k%totc]*inputs[j/totr][k/totc];
            }
        }
        totr *= r;
        totc *= c;
        for(int j=0;j<totr;j++) {
            for(int k=0;k<totc;k++) {
                lasttensor[j][k] = tensor[j][k];
            }
        }
    }
    int maxrow,maxcol,minrow,mincol,maxel,minel;
    minrow = mincol = minel = INF;
    maxrow = maxcol = maxel = -INF;
    for(int i=0;i<totr;i++) {
        int rowsum = 0;
        for(int j=0;j<totc;j++) {
            minel = min(minel,tensor[i][j]);
            maxel = max(maxel,tensor[i][j]);
            rowsum += tensor[i][j];
        }
        maxrow = max(maxrow,rowsum);
        minrow = min(minrow,rowsum);
    }
    for(int i=0;i<totc;i++) {
        int colsum = 0;
        for(int j=0;j<totr;j++) {
            colsum += tensor[j][i];
        }
        maxcol = max(maxcol,colsum);
        mincol = min(mincol,colsum);
    }
    cout << maxel << endl << minel << endl << maxrow << endl << minrow << endl << maxcol << endl << mincol << endl;
    return 0;
}
