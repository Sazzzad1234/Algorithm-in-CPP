#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,E;
    cin >>N>>E;
    vector<vector<int>> adj_list(N);
    while (E--) {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--) {
        int src;
        cin >>src;
        vector<int>CN = adj_list[src];
        if(CN.empty()){
            cout<<-1<<endl;
            continue;;
        }
        sort(CN.begin(),CN.end(),greater<int>());
        for (int node : CN) {
        
        cout<<node<<" ";
        }
        cout<<endl;
    }
    return 0;
}