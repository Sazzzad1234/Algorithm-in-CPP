#include<bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> d ={{-1,0},{1,0},{0,-1},{0,1}};
int n,m;
bool valid(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    } 
        if(grid[i][j]=='-'){
             return false;
        }
        if(vis[i][j]==true){
            return false;
        } 
    return true;
}
int bfs(int si,int sj){
queue<pair<int,int>> q;
q.push({si,sj});
vis[si][sj] = true;
int area = 0;

while(!q.empty()){
    pair<int,int>par = q.front();
    q.pop();
    int par_i = par.first;
    int par_j = par.second;
    area++;

    for(int i=0;i<4;i++){
        int ci = par_i + d[i].first;
        int cj = par_j + d[i].second;
        if(valid(ci,cj)){
            q.push({ci,cj});
            vis[ci][cj] = true;
        }
    }
}
return area;
}
int main(){
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
int mini = INT_MAX;
bool found = false;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j] =='.'&& vis[i][j] == false){
            int area = bfs(i,j);
            mini=min(mini,area);
            found = true;
        }
    }
}
if(found == true){
    cout<<mini<<endl;
}
else{
    cout<<-1<<endl;
}
   }