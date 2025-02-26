#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
pair<int, int> parent[1005][1005];
int n, m;
vector<pair<int,int>>d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int i, int j) {
    if (i<0 || i>=n || j<0 || j>=m) {
        return false;
    }
    if (grid[i][j] =='#') {
        return false;
    }
    if (vis[i][j] == true) {
        return false;
    }
    return true;
}
void bfs(int si, int sj, int di, int dj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while (!q.empty()) {
        pair<int,int>par =q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;
        if (par_i == di && par_j == dj){
            break;
        }
        for (int i = 0; i < d.size();i++){
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if (valid(ci, cj)) {
                q.push({ci, cj});
                vis[ci][cj] = true;
                parent[ci][cj] = {par_i, par_j};
            }
        }
    }
}
void Path(int di, int dj, int si, int sj) {
    int x = di, y = dj;
    while (parent[x][y].first != -1 || parent[x][y].second != -1) {
        if (grid[x][y] != 'D') grid[x][y] = 'X';
        pair<int, int> p = parent[x][y];
        x = p.first;
        y = p.second;
    }
}

int main() {
    cin >> n >> m;
    int si, sj, di, dj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'R') {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'D') {
                di = i;
                dj = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    bfs(si, sj, di, dj);
    if (vis[di][dj]) {
        Path(di, dj, si, sj);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}
