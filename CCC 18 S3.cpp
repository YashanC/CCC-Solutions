#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pairii;

int grid[105][105];
char things[105][105];
bool visited[105][105];
int n,m;
const int INF = 0x3f3f3f3f;

bool chk(int row,int col) {
    return(row<n && col<m && row>=0 && col>=0);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    queue<pairii> q;
    pairii start;
    vector<pairii> esc;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> things[i][j];
            visited[i][j] = false;
            grid[i][j] = INF;
            if(things[i][j]=='W') {
                grid[i][j] = -1;
            } else if(things[i][j]=='S') {
                start = make_pair(i,j);
                q.push(make_pair(i,j));
                visited[i][j] = true;
                grid[i][j]= 0;
            } else if(things[i][j]=='.') {
                esc.push_back(make_pair(i,j));
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            switch(things[i][j]) {
                case 'C':
                    grid[i][j] = -1;
                    for(int k=j;k>=0;k--) {
                        if(things[i][k]=='.' || things[i][k]=='S') {
                            grid[i][k] = -1;
                        } else if(things[i][k]=='W') {
                            break;
                        }
                    }
                    for(int k=j;k<m;k++) {
                        if(things[i][k]=='.' || things[i][k]=='S') {
                            grid[i][k] = -1;
                        } else if(things[i][k]=='W') {
                            break;
                        }
                    }
                    for(int k=i;k>=0;k--) {
                        if(things[k][j]=='.' || things[k][j]=='S') {
                            grid[k][j] = -1;
                        } else if(things[k][j]=='W') {
                            break;
                        }
                    }
                    for(int k=i;k<n;k++) {
                        if(things[k][j]=='.' || things[k][j]=='S') {
                            grid[k][j] = -1;
                        } else if(things[k][j]=='W') {
                            break;
                        }
                    }
                    break;
                default: break;
            }
        }
    }
    if(grid[start.first][start.second]==-1) {
        for(int i=0;i<esc.size();i++) {
            cout << -1 << endl;
        }
        return 0;
    }
    while(!q.empty()) {
        pairii curr = q.front();
        q.pop();
        switch(things[curr.first][curr.second]) {
            case 'L':
                if(chk(curr.first,curr.second-1)) {
                    visited[curr.first][curr.second-1] = true;
                    if(grid[curr.first][curr.second-1]>grid[curr.first][curr.second]) {
                        q.push(make_pair(curr.first,curr.second-1));
                        grid[curr.first][curr.second-1] = grid[curr.first][curr.second];
                    }
                }
                break;
            case 'R':
                if(chk(curr.first,curr.second+1)) {
                    visited[curr.first][curr.second+1] = true;
                    if(grid[curr.first][curr.second+1]>grid[curr.first][curr.second]) {
                        q.push(make_pair(curr.first,curr.second+1));
                        grid[curr.first][curr.second+1] = grid[curr.first][curr.second];
                    }
                }
                break;
            case 'U':
                if(chk(curr.first-1,curr.second)) {
                    visited[curr.first-1][curr.second] = true;
                    if(grid[curr.first-1][curr.second]>grid[curr.first][curr.second]) {
                        q.push(make_pair(curr.first-1,curr.second));
                        grid[curr.first-1][curr.second] = grid[curr.first][curr.second];
                    }
                }
                break;
            case 'D':
                if(chk(curr.first+1,curr.second)) {
                    visited[curr.first+1][curr.second] = true;
                    if(grid[curr.first+1][curr.second]>grid[curr.first][curr.second]) {
                        q.push(make_pair(curr.first+1,curr.second));
                        grid[curr.first+1][curr.second] = grid[curr.first][curr.second];
                    }
                }
                break;
            case '.':
                if(chk(curr.first+1,curr.second)) {
                    visited[curr.first+1][curr.second] = true;
                    if(grid[curr.first+1][curr.second]>grid[curr.first][curr.second]+1) {
                        q.push(make_pair(curr.first+1,curr.second));
                        grid[curr.first+1][curr.second] = grid[curr.first][curr.second]+1;
                    }
                }
                if(chk(curr.first-1,curr.second)) {
                    visited[curr.first-1][curr.second] = true;
                    if(grid[curr.first-1][curr.second]>grid[curr.first][curr.second]+1) {
                        q.push(make_pair(curr.first-1,curr.second));
                        grid[curr.first-1][curr.second] = grid[curr.first][curr.second]+1;
                    }
                }
                if(chk(curr.first,curr.second+1)) {
                    visited[curr.first][curr.second+1] = true;
                    if(grid[curr.first][curr.second+1]>grid[curr.first][curr.second]+1) {
                        q.push(make_pair(curr.first,curr.second+1));
                        grid[curr.first][curr.second+1] = grid[curr.first][curr.second]+1;
                    }
                }
                if(chk(curr.first,curr.second-1)) {
                    visited[curr.first][curr.second-1] = true;
                    if(grid[curr.first][curr.second-1]>grid[curr.first][curr.second]+1) {
                        q.push(make_pair(curr.first,curr.second-1));
                        grid[curr.first][curr.second-1] = grid[curr.first][curr.second]+1;
                    }
                }
                break;
            case 'S':
                if(chk(curr.first+1,curr.second)) {
                    visited[curr.first+1][curr.second] = true;
                    if(grid[curr.first+1][curr.second]>grid[curr.first][curr.second]+1) {
                        q.push(make_pair(curr.first+1,curr.second));
                        grid[curr.first+1][curr.second] = grid[curr.first][curr.second]+1;
                    }
                }
                if(chk(curr.first-1,curr.second)) {
                    visited[curr.first-1][curr.second] = true;
                    if(grid[curr.first-1][curr.second]>grid[curr.first][curr.second]+1) {
                        q.push(make_pair(curr.first-1,curr.second));
                        grid[curr.first-1][curr.second] = grid[curr.first][curr.second]+1;
                    }
                }
                if(chk(curr.first,curr.second+1)) {
                    visited[curr.first][curr.second+1] = true;
                    if(grid[curr.first][curr.second+1]>grid[curr.first][curr.second]+1) {
                        q.push(make_pair(curr.first,curr.second+1));
                        grid[curr.first][curr.second+1] = grid[curr.first][curr.second]+1;
                    }
                }
                if(chk(curr.first,curr.second-1)) {
                    visited[curr.first][curr.second-1] = true;
                    if(grid[curr.first][curr.second-1]>grid[curr.first][curr.second]+1) {
                        q.push(make_pair(curr.first,curr.second-1));
                        grid[curr.first][curr.second-1] = grid[curr.first][curr.second]+1;
                    }
                }
                break;
            default: break;
        }
    }
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(grid[i][j]==INF) grid[i][j] = -1;
        for(int i=0;i<esc.size();i++) {
            cout << grid[esc[i].first][esc[i].second] << endl;
        }
    return 0;
}
