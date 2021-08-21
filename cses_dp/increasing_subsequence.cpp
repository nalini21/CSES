#include<bits/stdc++.h>
using namespace std;
#define ll long long
using vi = vector<int>;
const int MOD = (int) 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    vi a(n); 
    vi lis(n, 0);
    lis[0] = 1;
    for(int i=1;i<n;i++){
        lis[i] = 1;
        for(int j=0;j<i;j++){
            if(a[j]<a[i]) lis[i] = max(lis[i], 1 + lis[j]);
        }
    }
    cout<<lis[n-1]<<endl;
    return 0;
}