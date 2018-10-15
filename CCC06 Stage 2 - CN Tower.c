#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    double minT;
    string place;
    cin >> N;
    vector<double> A(N);
    for(int i=0;i<N;i++) {
        cin >> place >> A[i];
    }
    sort(A.begin(),A.end());
    minT = (A[A.size()-1]-A[0])*12.0;
    for(int i=1;i<A.size();i++) {
        minT = min(minT,(360.0+A[i-1]-A[i])*12.0);
    }
    cout << ceil(minT);
    return 0;
}
