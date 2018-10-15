#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int N,l,maxlen=0;
    vector<int> freq(2010,0),sum(4010,0);
    unordered_map<int,int> len;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> l;
        freq[l]++;
    }
    for(int i=1;i<2000;i++) {
        for(int j=i;j<=2000;j++) {
            if(freq[i]>0 && freq[j]>0) {
                if(i==j) {
                    sum[i+j] += freq[i]/2;
                } else {
                    sum[i+j] += min(freq[i],freq[j]);
                }
                if(sum[i+j]>maxlen) {
                    maxlen = sum[i+j];
                    len[maxlen] = 1;
                } else if(sum[i+j]==maxlen) {
                    len[maxlen]++;
                }
            }
        }
    }
    printf("%d %d",maxlen,len[maxlen]);
}
