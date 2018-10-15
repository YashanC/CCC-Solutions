#include<bits/stdc++.h>

using namespace std;

char maps[50][50];
int dist[50][50],R,C;

bool valid(int r,int c) {
    if(r<0 || c<0 || r>=R || c>=C) return false;
    if(maps[r][c]=='*' || dist[r][c]<1e9) return false;
    return true;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    queue<pair<int,int> > path;
    cin >> t;
    for(int i=0;i<t;i++) {
        cin >> R >> C;
        for(int j=0;j<R;j++) {
            for(int k=0;k<C;k++) {
                cin >> maps[j][k];
                dist[j][k] = 1e9;
            }
        }
        path.push({0,0});
        dist[0][0] = 0;
        while(!path.empty()) {
            pair<int,int> curr = path.front();
            path.pop();
            if(curr.first==R-1 && curr.second==C-1) break;
            switch(maps[curr.first][curr.second]) {
                case '+':
                    if(valid(curr.first-1,curr.second)) { dist[curr.first-1][curr.second] = dist[curr.first][curr.second]+1; path.push({curr.first-1,curr.second}); }
                    if(valid(curr.first+1,curr.second)) { dist[curr.first+1][curr.second] = dist[curr.first][curr.second]+1; path.push({curr.first+1,curr.second}); }
                    if(valid(curr.first,curr.second-1)) { dist[curr.first][curr.second-1] = dist[curr.first][curr.second]+1; path.push({curr.first,curr.second-1}); }
                    if(valid(curr.first,curr.second+1)) { dist[curr.first][curr.second+1] = dist[curr.first][curr.second]+1; path.push({curr.first,curr.second+1}); }
                    break;
                case '-':
                    if(valid(curr.first,curr.second-1)) { dist[curr.first][curr.second-1] = dist[curr.first][curr.second]+1; path.push({curr.first,curr.second-1}); }
                    if(valid(curr.first,curr.second+1)) { dist[curr.first][curr.second+1] = dist[curr.first][curr.second]+1; path.push({curr.first,curr.second+1}); }
                    break;
                case '|':
                    if(valid(curr.first-1,curr.second)) { dist[curr.first-1][curr.second] = dist[curr.first][curr.second]+1; path.push({curr.first-1,curr.second}); }
                    if(valid(curr.first+1,curr.second)) { dist[curr.first+1][curr.second] = dist[curr.first][curr.second]+1; path.push({curr.first+1,curr.second}); }
                    break;
                default: break;
            }
        }
        while(!path.empty()) path.pop();
        printf("%d\n",(dist[R-1][C-1]==1e9) ? -1 : dist[R-1][C-1]+1);
    }
}
