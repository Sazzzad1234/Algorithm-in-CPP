#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
int n, m;
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool valid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }
    if (grid[i][j] == '#') {
        return false;
    }
    if (vis[i][j]) {
        return false;
    }
    return true;
}
void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int ni = x+d[i].first;
            int nj = y+ d[i].second;
            if (valid(ni, nj)) {
                vis[ni][nj] = true;
                q.push({ni, nj});
        }
            
            }
        }
    }


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    memset(vis, 0, sizeof(vis));
    int apartments = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && vis[i][j]==false) {
                bfs(i, j);
                apartments++;
            }
        }
    }
    cout << apartments << endl;
    return 0;
}
