#include<bits/stdc++.h>

using namespace std;

struct route {
    int b,t,h;
};

int main() {
    int K,N,M;
    scanf("%d%d%d",&K,&N,&M);
    vector<route> adj[N+1];
    vector<int> dist(N+1,2e9),hull(N+1,2e9);
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    for(int i=0;i<M;i++) {
        int a;
        route r1,r2;
        scanf("%d%d%d%d",&a,&r1.b,&r1.t,&r1.h);
        r2.b = a;
        r2.h = r1.h;
        r2.t = r1.t;
        adj[a].push_back(r1);
        adj[r1.b].push_back(r2);
    }
    int A,B;
    scanf("%d%d",&A,&B);
    dist[A] = hull[A] = 0;
    pq.push({0,0,A});
    while(!pq.empty()) {
        int curr = pq.top()[2];
        pq.pop();
        for(route p : adj[curr]) {
            if(dist[p.b]>dist[curr]+p.t && hull[curr]+p.h<K) {
                hull[p.b] = hull[curr]+p.h;
                dist[p.b] = dist[curr]+p.t;
                pq.push({hull[p.b],dist[p.b],p.b});
            } else if(dist[p.b]==dist[curr]+p.t && (hull[p.b]>hull[curr]+p.h && hull[curr]+p.h<K)) {
                hull[p.b] = hull[curr]+p.h;
                pq.push({hull[p.b],dist[p.b],p.b});
            }
        }
    }
    int tempB = dist[B];
    fill(hull.begin(),hull.end(),2e9);
    fill(dist.begin(),dist.end(),2e9);
    hull[A] = dist[A] = 0;
    pq.push({0,0,A});
    while(!pq.empty()) {
        int curr = pq.top()[2];
        pq.pop();
        for(route p : adj[curr]) {
            if(hull[p.b]>hull[curr]+p.h) {
                hull[p.b] = hull[curr]+p.h;
                dist[p.b] = dist[curr]+p.t;
                pq.push({dist[p.b],hull[p.b],p.b});
            } else if(hull[p.b]==hull[curr]+p.h && dist[p.b]>dist[curr]+p.t) {
                dist[p.b] = dist[curr]+p.t;
                pq.push({dist[p.b],hull[p.b],p.b});
            }
        }
    }
    if(hull[B]<K) {
        tempB = min(tempB,dist[B]);
    }
    if(tempB==2e9) {
        printf("%d",-1);
    } else {
        printf("%d",tempB);
    }
    return 0;
}
