#include<bits/stdc++.h>

using namespace std;

int disjoint[101];

struct edge {
    int wt,beg,fin;
};

bool compareCost(const edge &a,const edge &b) {
    return(a.wt<b.wt);
}

int find(int x) {
    if(disjoint[x]<0) return x;
    return disjoint[x] = find(disjoint[x]);
}

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
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    const int INF = 0x3f3f3f3f;
    int N,dist1=0,dist2=0;
    cin >> N;
    vector<edge> pen;
    vector<int> corners(8),weights(8);
    map<pair<int,int>,pair<int,int> > node;
    memset(disjoint,-1,sizeof(disjoint));
    for(int i=1;i<=N;i++) {
        int e;
        cin >> e;
        for(int j=0;j<e;j++) {
            cin >> corners[j];
        }
        for(int j=0;j<e;j++) {
            cin >> weights[j];
        }
        for(int j=0;j<e;j++) {
            edge x;
            int a = corners[j];
            int b = (j==e-1) ? corners[0] : corners[j+1];
            if(node.find({a,b})==node.end()) {
                node[{a,b}] = node[{b,a}] = {weights[j],i};
            } else {
                x.beg = i;
                x.fin = node[{a,b}].second;
                x.wt = node[{a,b}].first;
                node[{a,b}] = node[{b,a}] = {-1,-1};
                pen.push_back(x);
            }
        }
    }
    for(auto it=node.begin();it!=node.end();++it) {
        pair<int,int> p = it->second;
        pair<int,int> q = it->first;
        edge x;
        if(p.second!=-1) {
            x.beg = 0;
            x.fin = p.second;
            x.wt = p.first;
            node[{q.first,q.second}] = node[{q.second,q.first}] = {-1,-1};
            pen.push_back(x);
        }
    }
    sort(pen.begin(),pen.end(),compareCost);
    for(int i=0;i<pen.size();i++) {
        if((pen[i].beg!=0 && pen[i].fin!=0) && merge(pen[i].beg,pen[i].fin)) {
            dist1 += pen[i].wt;
        }
    }
    int minel = INF;
    for(int i=1;i<=N;i++) {
        minel = min(minel,disjoint[i]);
    }
    if(-minel<N) dist1 = INF;
    memset(disjoint,-1,sizeof(disjoint));
    for(int i=0;i<pen.size();i++) {
        if(merge(pen[i].beg,pen[i].fin)) {
            dist2 += pen[i].wt;
        }
    }
    cout << min(dist1,dist2);
    return 0;
}
