#include <bits/stdc++.h>
using namespace std;
bool vis[105];
vector<int>adj_list[105];
bool pathvis[105];
bool cycle;
void dfs(int src){
    vis[src] = true;
    pathvis[src] = true;
    for(int child : adj_list[src]){
        if(vis[child] && pathvis[child]==true)
        cycle = true;
        if(!vis[child]){
            dfs(child);
        }
    }
    pathvis[src]=false;
}
int main() {
    int n,e;
    cin>>n>>e;
    vector<int> ad_list[n];
    while(e--){
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
    }
    memset(vis,false,sizeof(false));
    memset(pathvis,false,sizeof(pathvis));
    cycle = false;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
        if(cycle){
            cout<<"Cycle detected\n";
        }
        else{
            cout<<"no cycle\n";
        }

    return 0;
}