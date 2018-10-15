#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<bool> > adj(55,vector<bool>(55,false));
    for(int i=1;i<=7;i++) if(i!=6) adj[i][6] = adj[6][i] = true;
    adj[3][4] = adj[4][3] = adj[15][3] = adj[3][15] = adj[3][5] = adj[5][3] = true;
    adj[4][5] = adj[5][4] = true;
    adj[7][8] = adj[8][7] = true;
    adj[8][9] = adj[9][8] = adj[9][10] = adj[10][9] = adj[9][12] = adj[12][9] = true;
    adj[10][11] = adj[11][10] = adj[11][12] = adj[12][11] = true;
    adj[13][12] = adj[12][13] = adj[13][15] = adj[15][13] = adj[13][14] = adj[14][13] = true;
    adj[16][17] = adj[17][16] = adj[16][18] = adj[18][16] = true;
    adj[17][18] = adj[18][17] = true;
    bool visited[55];
    int dist[55];
    char next;
    while(true) {
        cin >> next;
        int x,y;
        if(next=='q') {
            break;
        } else if(next=='n') {
            cin >> x;
            int tot=0;
            for(int i=0;i<adj[x].size();i++) {
                tot += (adj[x][i]);
            }
            cout << tot << endl;
        } else if(next=='i') {
            cin >> x >> y;
            adj[x][y] = adj[y][x] = true;
        } else if(next=='d') {
            cin >> x >> y;
            adj[x][y] = adj[y][x] = false;
        } else if(next=='f') {
            vector<int> fof;
            cin >> x;
            int tot=0;
            memset(visited,false,sizeof(visited));
            visited[x] = true;
            for(int i=0;i<55;i++) {
                if(adj[x][i]) {
                    fof.push_back(i);
                    visited[i] = true;
                }
            }
            for(int i=0;i<fof.size();i++) {
                for(int j=0;j<55;j++) {
                    if(!visited[j] && adj[fof[i]][j]) {
                        visited[j] = true;
                        tot++;
                    }
                }
            }
            cout << tot << endl;
        } else {
            cin >> x >> y;
            queue<int> path;
            memset(dist,1e9,sizeof(dist));
            memset(visited,false,sizeof(visited));
            dist[x] = 0;
            path.push(x);
            while(!path.empty()) {
                int curr = path.front();
                if(curr==y) break;
                path.pop();
                for(int i=0;i<55;i++) {
                    if(!visited[i] && adj[curr][i]) {
                        dist[i] = dist[curr]+1;
                        visited[i] = true;
                        path.push(i);
                    }
                }
            }
            while(!path.empty()) path.pop();
            if(visited[y]) {
                cout << dist[y] << endl;
            } else {
                cout << "Not connected" << endl;
            }
        }
    }
}
