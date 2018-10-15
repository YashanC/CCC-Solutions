#include<bits/stdc++.h>

using namespace std;

vector<int> soln;
vector<string> A,B;
int M,N;

bool append(int x,string ai,string bi) {
    if(x>=M) {
        return false;
    } else if(bi.find(ai)!=0 && ai.find(bi)!=0) {
        return false;
    } else {
        for(int i=0;i<N;i++) {
            if(ai+A[i]==bi+B[i]) {
                soln[x] = i;
                printf("%d\n",x+1);
                for(int j=0;j<=x;j++) printf("%d\n",soln[j]+1);
                return true;
            } else {
                soln[x] = i;
                if(append(x+1,ai+A[i],bi+B[i])) {
                    return true;
                }
            }
        }
        return false;
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;
    soln.resize(M,-1);
    for(int i=0;i<N;i++) {
        string str;
        cin >> str;
        A.push_back(str);
    }
    for(int i=0;i<N;i++) {
        string str;
        cin >> str;
        B.push_back(str);
    }
    if(!append(0,"","")) {
        printf("No solution.");
    }
    return 0;
}
