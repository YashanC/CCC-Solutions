#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int xa,ya,xb,yb;
    pair<int,int> p;
    cin >> xa >> ya >> xb >> yb;
    vector<vector<int> > board(8,vector<int>(8,1e9));
    queue<pair<int,int> > path;
    path.push({8-ya,xa-1});
    board[path.front().first][path.front().second] = 0;
    while(true) {
        p = path.front();
        if(p.first==8-yb && p.second==xb-1) {
            break;
        }
        path.pop();
        if(p.second>1 && p.second<6) {
            if(p.first>0 && p.first<7) {
                path.push({p.first-1,p.second-2});
                path.push({p.first-1,p.second+2});
                path.push({p.first+1,p.second-2});
                path.push({p.first+1,p.second+2});
                board[p.first-1][p.second-2] = min(board[p.first-1][p.second-2],board[p.first][p.second]+1);
                board[p.first-1][p.second+2] = min(board[p.first-1][p.second+2],board[p.first][p.second]+1);
                board[p.first+1][p.second-2] = min(board[p.first+1][p.second-2],board[p.first][p.second]+1);
                board[p.first+1][p.second+2] = min(board[p.first+1][p.second+2],board[p.first][p.second]+1);
            } else if(p.first==0) {
                path.push({p.first+1,p.second-2});
                path.push({p.first+1,p.second+2});
                board[p.first+1][p.second-2] = min(board[p.first+1][p.second-2],board[p.first][p.second]+1);
                board[p.first+1][p.second+2] = min(board[p.first+1][p.second+2],board[p.first][p.second]+1);
            } else {
                path.push({p.first-1,p.second-2});
                path.push({p.first-1,p.second+2});
                board[p.first-1][p.second-2] = min(board[p.first-1][p.second-2],board[p.first][p.second]+1);
                board[p.first-1][p.second+2] = min(board[p.first-1][p.second+2],board[p.first][p.second]+1);
            }
        } else if(p.second<=1) {
            if(p.first>0 && p.first<7) {
                path.push({p.first-1,p.second+2});
                path.push({p.first+1,p.second+2});
                board[p.first-1][p.second+2] = min(board[p.first-1][p.second+2],board[p.first][p.second]+1);
                board[p.first+1][p.second+2] = min(board[p.first+1][p.second+2],board[p.first][p.second]+1);
            } else if(p.first==0) {
                path.push({p.first+1,p.second+2});
                board[p.first+1][p.second+2] = min(board[p.first+1][p.second+2],board[p.first][p.second]+1);
            } else {
                path.push({p.first-1,p.second+2});
                board[p.first-1][p.second+2] = min(board[p.first-1][p.second+2],board[p.first][p.second]+1);
            }
        } else {
            if(p.first>0 && p.first<7) {
                path.push({p.first-1,p.second-2});
                path.push({p.first+1,p.second-2});
                board[p.first-1][p.second-2] = min(board[p.first-1][p.second-2],board[p.first][p.second]+1);
                board[p.first+1][p.second-2] = min(board[p.first+1][p.second-2],board[p.first][p.second]+1);
            } else if(p.first==0) {
                path.push({p.first+1,p.second-2});
                board[p.first+1][p.second-2] = min(board[p.first+1][p.second-2],board[p.first][p.second]+1);;
            } else {
                path.push({p.first-1,p.second-2});
                board[p.first-1][p.second-2] = min(board[p.first-1][p.second-2],board[p.first][p.second]+1);
            }
        }
        if(p.first>1 && p.first<6) {
            if(p.second>0 && p.second<7) {
                path.push({p.first-2,p.second-1});
                path.push({p.first+2,p.second-1});
                path.push({p.first-2,p.second+1});
                path.push({p.first+2,p.second+1});
                board[p.first-2][p.second-1] = min(board[p.first-2][p.second-1],board[p.first][p.second]+1);
                board[p.first+2][p.second-1] = min(board[p.first+2][p.second-1],board[p.first][p.second]+1);
                board[p.first-2][p.second+1] = min(board[p.first-2][p.second+1],board[p.first][p.second]+1);
                board[p.first+2][p.second+1] = min(board[p.first+2][p.second+1],board[p.first][p.second]+1);
            } else if(p.second==0) {
                path.push({p.first-2,p.second+1});
                path.push({p.first+2,p.second+1});
                board[p.first-2][p.second+1] = min(board[p.first-2][p.second+1],board[p.first][p.second]+1);
                board[p.first+2][p.second+1] = min(board[p.first+2][p.second+1],board[p.first][p.second]+1);
            } else {
                path.push({p.first-2,p.second-1});
                path.push({p.first+2,p.second-1});
                board[p.first-2][p.second-1] = min(board[p.first-2][p.second-1],board[p.first][p.second]+1);
                board[p.first+2][p.second-1] = min(board[p.first+2][p.second-1],board[p.first][p.second]+1);
            }
        } else if(p.first<=1) {
            if(p.second>0 && p.second<7) {
                path.push({p.first+2,p.second-1});
                path.push({p.first+2,p.second+1});
                board[p.first+2][p.second-1] = min(board[p.first+2][p.second-1],board[p.first][p.second]+1);
                board[p.first+2][p.second+1] = min(board[p.first+2][p.second+1],board[p.first][p.second]+1);
            } else if(p.second==0) {
                path.push({p.first+2,p.second+1});
                board[p.first+2][p.second+1] = min(board[p.first+2][p.second+1],board[p.first][p.second]+1);
            } else {
                path.push({p.first+2,p.second-1});
                board[p.first+2][p.second-1] = min(board[p.first+2][p.second-1],board[p.first][p.second]+1);
            }
        } else {
            if(p.second>0 && p.second<7) {
                path.push({p.first-2,p.second-1});
                path.push({p.first-2,p.second+1});
                board[p.first-2][p.second-1] = min(board[p.first-2][p.second-1],board[p.first][p.second]+1);
                board[p.first-2][p.second+1] = min(board[p.first-2][p.second+1],board[p.first][p.second]+1);
            } else if(p.second==0) {
                path.push({p.first-2,p.second+1});
                board[p.first-2][p.second+1] = min(board[p.first-2][p.second+1],board[p.first][p.second]+1);;
            } else {
                path.push({p.first-2,p.second-1});
                board[p.first-2][p.second-1] = min(board[p.first-2][p.second-1],board[p.first][p.second]+1);
            }
        }
    }
    cout << board[p.first][p.second];
    return 0;
}
