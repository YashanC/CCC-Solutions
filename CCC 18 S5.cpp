#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct edge {
    int beg,fin;
    ll wt;
};

bool cmp(const edge &a,const edge &b) {
    return(a.wt<b.wt);
}

int disjoint[100005];
vector<ll> usedportal;

int find(int x) {
    if(disjoint[x]<0) return x;
    return disjoint[x] = find(disjoint[x]);
}

/*int search(int min,int max,ll val) {
    int mid = (max+min)/2;
    if(min==max) {
        return mid;
    } else if(usedportal[mid].wt<val) {
        return search(mid+1,max,val);
    } else if(usedportal[mid].wt>=val) {
        return search(min,mid-1,val);
    }
}*/

bool merge(int x,int y) {
    int p1 = find(x);
    int p2 = find(y);
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

int main() {
    memset(disjoint,-1,sizeof(disjoint));
    int n,p,m,q;
    ll take = 0;
    scanf("%d%d%d%d",&n,&m,&p,&q);
    vector<edge> graph(p);
    vector<ll> usedplane;
    for(int i=0;i<p;i++) {
        scanf("%d%d%lld",&graph[i].beg,&graph[i].fin,&graph[i].wt);
        take += graph[i].wt*n;
    }
    sort(graph.begin(),graph.end(),cmp);
    for(int i=0;i<p;i++) {
        if(merge(graph[i].beg,graph[i].fin)) {
            take -= graph[i].wt*n;
            usedplane.push_back(graph[i].wt);
        }
    }
    memset(disjoint,-1,sizeof(disjoint));
    graph.resize(q);
    for(int i=0;i<q;i++) {
        scanf("%d%d%lld",&graph[i].beg,&graph[i].fin,&graph[i].wt);
        take += graph[i].wt*m;
    }
    vector<ll> sum(1,0);
    sort(graph.begin(),graph.end(),cmp);
    for(int i=0;i<q;i++) {
        if(merge(graph[i].beg,graph[i].fin)) {
            take -= graph[i].wt;
            usedportal.push_back(graph[i].wt);
            sum.push_back(graph[i].wt);
            sum[sum.size()-1] += sum[sum.size()-2];
        }
    }
    for(int i=0;i<usedplane.size();i++) {
        int y = distance(usedportal.begin(),lower_bound(usedportal.begin(),usedportal.end(),usedplane[i]));
        take += usedplane[i]*y - sum[y];
    }
    printf("%lld",take);
    return 0;
}
