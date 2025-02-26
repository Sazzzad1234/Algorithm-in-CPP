#include<bits/stdc++.h>
using namespace std;
int vis[1005][1005];
vector<pair<int,int>> d ={{-2,-1},{-2,1},{2,-1},{2,1},
{-1,-2},{-1,2},{1,-2},{1,2}
};
int N,M;
bool valid(int ci,int cj,int N,int M ){
    if(ci<0 || cj<0 || ci>=N|| cj>=M){
        return false;
    }
    if(vis[ci][cj] != -1){
        return false;
    }
    return true;
}

int bfs(int N,int M,int kx,int ky,int qx,int qy){
    memset(vis,-1,sizeof(vis));
queue<pair<int,int>> q;
q.push({kx,ky});
vis[kx][ky]=0;
while(!q.empty()){
    pair<int,int>par = q.front();
    q.pop();
    int par_i = par.first;
    int par_j = par.second;

    if(par_i == qx && par_j == qy){
        return vis[par_i][par_j];
    }

    for(int i=0;i<8;i++){
        int ci = par_i + d[i].first;
        int cj = par_j + d[i].second;
        if(valid(ci,cj,N,M)){
            vis[ci][cj] = vis[par_i][par_j]+1;
            q.push({ci,cj});
        }
    }
}
return -1;
}
int main(){
    
    int T;
    cin>>T;
    while(T--){
        
        cin>>N>>M;
        int kx,ky,qx,qy;
        cin>>kx>>ky>>qx>>qy;
        int move = bfs(N,M,kx,ky,qx,qy);
        cout<<move<<endl;
    }
    
   }