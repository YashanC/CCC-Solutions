#include<bits/stdc++.h>

using namespace std;

long long disjoint[100005];

struct pipe {
  long long a,b,c,index;
};

bool compareCost(const pipe &d,const pipe &e) {
    return(d.c<e.c || (d.c==e.c && d.index<e.index));
}

long long find(long long x) {
    if(disjoint[x]<0) {
        return x;
    } else {
        return disjoint[x] = find(disjoint[x]);
    }
}

bool merge(long long a,long long b) {
    long long p1 = find(a);
    long long p2 = find(b);
    if(p1!=p2) {
        if(disjoint[p1]<disjoint[p2]) {
            disjoint[p1] += disjoint[p2];
            disjoint[p2] = p1;
        } else {
            disjoint[p2] += disjoint[p1];
            disjoint[p1] = p2;
        }
        return true;
    } else {
        return false;
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    memset(disjoint,-1,sizeof(disjoint));
    long long N,M,D,days=0,maxW=0;
    cin >> N >> M >> D;
    vector<pipe> all(M);
    //vector<bool> used(M,false);
    for(int i=0;i<M;i++) {
        cin >> all[i].a >> all[i].b >> all[i].c;
        all[i].index = i;
    }
    sort(all.begin(),all.end(),compareCost);
    for(int i=0;i<all.size();i++) {
        if(merge(all[i].a,all[i].b)) {
            days = (all[i].index<N-1) ? days : ++days;
            maxW = all[i].c;
            //used[i] = true;
        }
    }
    if(D>0) {
        memset(disjoint,-1,sizeof(disjoint));
        for(int j=0;j<M;j++) {
            if(find(all[j].a)!=find(all[j].b)) {
                if(all[j].c<maxW || (all[j].index<N-1 && all[j].c==maxW)) {
                    merge(all[j].a,all[j].b);
                } else if(all[j].index<N-1 && all[j].c<=D) {
                    cout << days-1;
                    return 0;
                }
            }
        }
    }
    cout << days;
}
