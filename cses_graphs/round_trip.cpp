//basically it's code to check for cycles in an undirected graph using dfs

#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vb = vector<bool>;
using vbb = vector<vector<bool>>;
#define mp make_pair
#define pb push_back

int nm = 1e5+10;
vb visited(nm, false);
vii adj_list(nm);
vi parents(nm);
int n, m, sn, en;//sn: starting node, en:ending node

bool dfsCycleCheck(int node, int parent){
    visited[node] = true;
    parents[node] = parent;
    for(int u: adj_list[node]){
        if(u==parent) continue;
        if(visited[u]){
            sn = u;
            en = node;
            return true;
        }
        else if(!visited[u]){
            if(dfsCycleCheck(u, node)) return true;
        }
    }
    return false;
}

bool visit_all(){
    for(int i=1;i<=n;i++){
        if(!visited[i])
            if(dfsCycleCheck(i, -1)) return true;
    }
    return false;
}

int main(){
    cin>>n>>m;
    while(m--){
        int x, y;
        cin>>x>>y;
        adj_list[x].pb(y);
        adj_list[y].pb(x);
    }
    if(visit_all()){
        int tn = en;//tn:temp node
        vi ans;
        ans.pb(sn);
        while(tn!=sn){
            ans.pb(tn);
            tn = parents[tn];
        }
        ans.pb(sn);
        cout<<ans.size()<<endl;
        for(int t: ans) cout<<t<<" ";
        cout<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}