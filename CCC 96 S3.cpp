#include<bits/stdc++.h>

using namespace std;

int N,K;

string Pattern(int n,int k,string prevstr) {
    string str = "";
    if(n==k) {
        for(int i=0;i<n;i++) str += "1";
        if(str.length()==N) cout << str << "\n";
        return str;
    } else if(n==0) {
        return "";
    } else if(k==0) {
        for(int i=0;i<n;i++) str += "0";
        if(str.length()==N) cout << str << "\n";
        return str;
    }
    str = prevstr+"1"+Pattern(n-1,k-1,prevstr+"1");
    if(str.length()==N) cout << str << "\n";
    str = prevstr+"0"+Pattern(n-1,k,prevstr+"0");
    if(str.length()==N) cout << str << "\n";
    return "";
}

int main() {
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++) {
        scanf("%d %d",&N,&K);
        printf("The bit patterns are\n");
        Pattern(N,K,"");
        printf("\n");
    }
}
