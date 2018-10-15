#include<bits/stdc++.h>

using namespace std;

int n,t,result;
long long X[100005],Y[100005];

int search(int min,int max,long long val) {
    int mid = (max+min)/2;
    if(X[mid]<=val && X[mid-1]>val) {
        return mid;
    } else if(X[mid]<=val) {
        return search(min,mid-1,val);
    } else if(X[mid]>val) {
        return search(mid+1,max,val);
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int i=0;i<t;i++) {
        cin >> n;
        int dist = 0;
        for(int j=0;j<n;j++) cin >> X[j];
        for(int j=0;j<n;j++) {
            cin >> Y[j];
            if(Y[j]>=X[0]) {
                dist = max(dist,j-0);
            } else if(Y[j]>=X[n-1]) {
                result = search(0,n-1,Y[j]);
                dist = max(dist,j-result);
            }
        }
        printf("The maximum distance is %d\n",dist);
    }
    return 0;
}
