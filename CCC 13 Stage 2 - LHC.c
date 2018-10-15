#include<bits/stdc++.h>

using namespace std;

long long tot,maxdist=0;
vector<long long> dist(400005,0),ways(400005,1);
bool visited[400005];
vector<vector<int> > adj;

void dfs(int node)
{
    visited[node] = true;
    for(int i=0;i<adj[node].size();i++) {
        int x = adj[node][i];
        if(!visited[x]) {
            dfs(x);
            if(dist[x]+dist[node]+1>maxdist) {
                maxdist = dist[x]+dist[node]+1;
                tot = ways[x]*ways[node];
            } else if(dist[x]+dist[node]+1==maxdist) {
                tot += ways[x]*ways[node];
            }
            if(dist[x]+1>dist[node]) {
                dist[node] = dist[x]+1;
                ways[node] = ways[x];
            } else if(dist[x]+1==dist[node]) {
                ways[node] += ways[x];
            }
        }
    }
}

int main()
{
    int N;
    memset(visited,false,sizeof(visited));
    scanf("%d",&N);
    adj.resize(N+1);
    for(int i=0;i<N-1;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    printf("%lld %lld",maxdist+1,tot);
}
