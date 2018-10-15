#include <bits/stdc++.h>

using namespace std;

int disjoint[100005];

int find(int x) {
    if(x!=disjoint[x]) {
        disjoint[x] = find(disjoint[x]);
    }
    return disjoint[x];
}

void merge(int x,int y) {
    disjoint[find(x)] = find(y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int G,P,planes=0,gate;
    bool available = true;
    cin >> G >> P;
    for(int i=0;i<=G;i++) {
        disjoint[i] = i;
    }
    while(available && planes<P) {
        cin >> gate;
        if(find(gate)==0) {
            available = false;
            cout << planes;
        }
        merge(find(gate),find(gate)-1);
        planes++;
    }
    if(available) {
        cout << planes;
    }
    return 0;
}
