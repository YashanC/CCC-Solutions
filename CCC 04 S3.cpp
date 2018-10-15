#include<bits/stdc++.h>

using namespace std;

string grid[20][20];
bool visited[100];
map<char,int> row;

int val(int r,int c) {
    if(grid[r][c][0]<65 && grid[r][c][0]>=48) {
        int x;
        stringstream ss;
        ss << grid[r][c];
        ss >> x;
        return x;
    } else if(visited[r*10+c] || grid[r][c]=="*") {
        grid[r][c] = "*";
        return -1;
    } else {
        visited[10*r+c] = true;
        int tot = 0;
        for(int i=0;i<grid[r][c].length();i+=3) {
            int x = val(row[grid[r][c][i]],grid[r][c][i+1]-'0');
            if(x==-1) {
                grid[r][c] = "*";
                return -1;
            } else {
                tot += x;
            }
        }
        stringstream ss;
        ss << tot;
        grid[r][c] = ss.str();
        return tot;
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=1;i<=10;i++) {
        row[char(i+64)] = i;
        for(int j=1;j<=9;j++) {
            cin >> grid[i][j];
        }
    }
    for(int i=1;i<=10;i++) {
        for(int j=1;j<=9;j++) {
            memset(visited,false,sizeof(visited));
            int a = val(i,j);
            if(a==-1) {
                grid[i][j] = "*";
                cout << "* ";
            } else {
                cout << a << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}
