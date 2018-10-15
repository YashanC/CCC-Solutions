#include<bits/stdc++.h>

using namespace std;

long long BIT[100005],t;

void updateBIT(int index,long long val) {
    while(index<=t) {
        BIT[index] += val;
        index = index + (index & -index);
    }
}

int getSum(int index) {
    int sum = 0;
    while(index>0) {
        sum += BIT[index];
        index = index - (index & -index);
    }
    return sum;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<long long,int> rank;
    memset(BIT,0,sizeof(BIT));
    double tot=0;
    cin >> t;
    vector<long long> s(t),temp;
    for(int i=0;i<t;i++) {
        cin >> s[i];
    }
    temp = s;
    sort(s.begin(),s.end());
    for(int i=0;i<t;i++) {
        rank[s[i]] = i+1;
    }
    for(int i=0;i<t;i++) {
        updateBIT(rank[temp[i]],1);
        tot += double(getSum(t)-getSum(rank[temp[i]])+1)/t;
    }
    printf("%.2f",tot);
    return 0;
}
