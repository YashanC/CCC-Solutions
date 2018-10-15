#include<bits/stdc++.h>

using namespace std;

#define gc getchar_unlocked

void scanint(int &x) {
    x = 0;
    register int c = gc();
    for(;(c<48 && c>57);c=gc());
    for(;(c>=48 && c<=57);c=gc()) x = (x<<3)+(x<<1)+(c-48);
}

int main() {
    int N,T,K,D,curr;
    scanint(N);
    scanint(T);
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    unordered_map<int,int> pencil;
    vector<pair<int,int>> adj[N+1];
    vector<int> dist(N+1,1e9);
    for(int i=0;i<T;i++) {
        int a,b,c;
        scanint(a);
        scanint(b);
        scanint(c);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    scanint(K);
    for(int i=0;i<K;i++) {
        int pi,ki;
        scanint(ki);
        scanint(pi);
        pencil[ki] = pi;
    }
    scanint(D);
    dist[D] = 0;
    pq.push({0,D});
    while(!pq.empty()) {
        curr = pq.top()[1];
        pq.pop();
        for(pair<int,int> p : adj[curr]) {
            if(dist[curr]+p.second<dist[p.first]) {
                dist[p.first] = dist[curr]+p.second;
                pq.push({dist[p.first],p.first});
            }
        }
    }
    int minPrice = 1e9;
    for(auto it=pencil.begin();it!=pencil.end();++it) {
        minPrice = min(minPrice,dist[it->first]+it->second);
    }
    printf("%d",minPrice);
    return 0;
}
