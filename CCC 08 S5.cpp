#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    bool state[35][35][35][35];
    for(int i=0;i<31;i++) {
        for(int j=0;j<31;j++) {
            for(int k=0;k<31;k++) {
                for(int l=0;l<31;l++) {
                    state[i][j][k][l] = false;
                    if(i>=2 && j>=1 && l>=2) {
                        if(!state[i-2][j-1][k][l-2]) {
                            state[i][j][k][l] = !state[i-2][j-1][k][l-2];
                        }
                    }
                    if(i>=1 && l>=1) {
                        if(!state[i-1][j][k][l-1]) {
                            state[i][j][k][l] = !state[i-1][j][k][l-1];
                        }
                    }
                    if(i>=1 && j>=1 && k>=1 && l>=1) {
                        if(!state[i-1][j-1][k-1][l-1]) {
                            state[i][j][k][l] = !state[i-1][j-1][k-1][l-1];
                        }
                    }
                    if(j>=3) {
                        if(!state[i][j-3][k][l]) {
                            state[i][j][k][l] = !state[i][j-3][k][l];
                        }
                    }
                    if(k>=2 && l>=1) {
                        if(!state[i][j][k-2][l-1]) {
                            state[i][j][k][l] = !state[i][j][k-2][l-1];
                        }
                    }
                }
            }
        }
    }
    scanf("%d",&t);
    for(int i=0;i<t;i++) {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(state[a][b][c][d]) {
            printf("Patrick\n");
        } else {
            printf("Roland\n");
        }
    }
    return 0;
}
