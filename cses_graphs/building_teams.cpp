//basically it's code to check for bipartiteness in a graph

#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vb = vector<bool>;
using vbb = vector<vector<bool>>;
#define mp make_pair
#define pb push_back

bool bipartiteCheck(vii &adj_list, int src, vi &colors){
    for(auto u : adj_list[src]){
        if(colors[u] == -1){
            colors[u] = !colors[src];
            if (!bipartiteCheck(adj_list, u, colors)) return false;
        }
        else if(colors[u] == colors[src])
            return false;
    }
    return true;
}

int main(){
    int n, m;
    cin>>n>>m;
    //nodes range from 1...n
    vii adj_list(n+1);
    while(m--){
        int x, y; cin>>x>>y;
        adj_list[x].pb(y);
        adj_list[y].pb(x);
    }
    vi colors(n+1, -1);
    for(int i=1;i<=n;i++){
        if(colors[i]==-1){
            colors[i] = 1;
            if (!bipartiteCheck(adj_list, i, colors)){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(colors[i]) cout<<"1 ";
        else cout<<"2 ";
    }
    cout<<endl;
    return 0;
}
