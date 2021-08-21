#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0;
bool vis[1010][1010];
char matrix[1010][1010];

void dfs(int i, int j){
   if(i<0 || j<0 || i>=n || j >=m || vis[i][j] || matrix[i][j]=='#') return;
   vis[i][j] = true;
   dfs(i+1, j);
   dfs(i, j+1);
   dfs(i-1, j);
   dfs(i, j-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;   
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
             vis[i][j] = false;
             cin>>matrix[i][j];
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(matrix[i][j]=='.' && !vis[i][j]){
                dfs(i,j);
                cnt++;
            }
    cout<<cnt<<endl;
    return 0;
}