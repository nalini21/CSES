//basically it's code to check for cycles in a directed graph using dfs

#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vb = vector<bool>;
using vbb = vector<vector<bool>>;
using sti = stack<int>;
#define mp make_pair
#define pb push_back

int nm = 1e5+10;
int n, m;
vb visited(nm, false);
vii adj_list(nm);
sti recursionStack;
vb rsFlag(nm, false); //recurison stack flag

bool dfsCycleCheck(int node)
{
	visited[node] = true;
	rsFlag[node] = true;
    recursionStack.push(node);
	for(auto u: adj_list[node])
	{
		if(!visited[u])
			if(dfsCycleCheck(u))
				return true;
 
		if(rsFlag[u])
		{
			recursionStack.push(u);
			return true;
		}
	}
	recursionStack.pop();
	rsFlag[node] = false;
	return false;
}

void visit_all()
{
	for(int i = 1; i <= n; ++i)
		if(!visited[i]){
			if(dfsCycleCheck(i))
				break;
		}
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>n>>m;
    visited.resize(n+1);
    adj_list.resize(n+1);
    rsFlag.resize(n+1);
    while(m--){
        int x, y;
        cin>>x>>y;
        adj_list[x].pb(y);
    }
    visit_all();
	if(recursionStack.empty())
	{		
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
    vi ans;
	int temp = recursionStack.top();
	while(!recursionStack.empty())
	{
		ans.push_back(recursionStack.top());
		recursionStack.pop();
		if(ans.back() == temp and ans.size() != 1)
			break;
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(auto t: ans) cout <<t<< " ";
    cout<<endl;
    return 0;
}