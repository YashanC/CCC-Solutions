#include<bits/stdc++.h>

using namespace std;

int disjoint[200005];

struct road {
    int a,b,c,index;
};

int find(int x) {
    if(disjoint[x]<0) {
        return x;
    } else {
        return disjoint[x] = find(disjoint[x]);
    }
}

bool merge(int a,int b) {
    int p1 = find(a);
    int p2 = find(b);
    if(p1!=p2) {
        if(disjoint[p1]<disjoint[p2]) {
            disjoint[p1] += disjoint[p2];
            disjoint[p2] = p1;
        } else {
            disjoint[p2] += disjoint[p1];
            disjoint[p1] = p2;
        }
        return true;
    }
    return false;
}

bool comparePref(const road &x,const road &y) {
    return(x.c>y.c || (x.c==y.c && x.index<y.index));
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    memset(disjoint,-1,sizeof(disjoint));
    int N,M,curr,D,maxW=1e9;
    cin >> N >> M >> D;
    vector<vector<vector<int> > > adj(N+1);
    vector<road> paths(M);
    vector<int> dist(N+1),dest(D);
    queue<int> path;
    dist[1] = 0;
    for(int i=0;i<M;i++) {
        cin >> paths[i].a >> paths[i].b >> paths[i].c;
        paths[i].index = i;
    }
    for(int i=0;i<D;i++) {
        cin >> dest[i];
    }
    sort(paths.begin(),paths.end(),comparePref);
    for(int i=0;i<M;i++) {
        if(merge(paths[i].a,paths[i].b)) {
            adj[paths[i].a].push_back({paths[i].b,paths[i].c});
            adj[paths[i].b].push_back({paths[i].a,paths[i].c});
        }
    }
    path.push(1);
    while(!path.empty()) {
        curr = path.front();
        path.pop();
        for(int i=0;i<adj[curr].size();i++) {
            if(curr==1) {
                dist[adj[curr][i][0]] = adj[curr][i][1];
                path.push(adj[curr][i][0]);
            } else if(dist[adj[curr][i][0]] < min(dist[curr],adj[curr][i][1]) && adj[curr][i][0]!=1) {
                dist[adj[curr][i][0]] = min(dist[curr],adj[curr][i][1]);
                path.push(adj[curr][i][0]);
            }
        }
    }
    for(int i=0;i<D;i++) {
        maxW = min(maxW,dist[dest[i]]);
    }
    cout << maxW;
    return 0;
}
