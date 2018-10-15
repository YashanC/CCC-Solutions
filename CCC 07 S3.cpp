#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<int> adj[10005];
    bool visited[10005];
    int dist[10005];
    stack<int> path;
    scanf("%d",&n);
    bool circle;
    for(int i=0;i<n;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
    }
    while(true) {
        int x,y;
        scanf("%d%d",&x,&y);
        memset(visited,false,sizeof(visited));
        memset(dist,0,sizeof(dist));
        if(x==0 && y==0) break;
        path.push(x);
        circle = false;
        visited[x] = true;
        while(!path.empty()) {
            int curr = path.top();
            path.pop();
            if(curr==y) {
                circle = true;
                break;
            }
            for(int i=0;i<adj[curr].size();i++) {
                if(!visited[adj[curr][i]]) {
                    dist[adj[curr][i]] = dist[curr]+1;
                    visited[adj[curr][i]] = true;
                    path.push(adj[curr][i]);
                }
            }
        }
        if(circle) {
            printf("Yes %d\n",dist[y]-1);
        } else {
            printf("No\n");
        }
        while(!path.empty()) path.pop();
    }
}
