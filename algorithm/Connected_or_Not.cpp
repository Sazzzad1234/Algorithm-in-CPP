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
    }
    int q;
    cin >> q;
    while (q--) {
        int src, dst;
        cin >>src>>dst;
        if (src == dst) {
            cout <<"YES"<< endl;
            continue;
        }
        bool found = false;
        for (int child : adj_list[src]) {
            if (child == dst) {
                found = true;
                break;
            }
        }
        if (found) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}