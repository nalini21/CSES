#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
	int n, x;
    cin>>n>>x;
    int weight[n];
    for(int i=0;i<n;i++) cin>>weight[i];
    pair<int, int> best[1<<n];
    //contains for each subset S, a pair (rides(S), last(S))
    //rides(S): minimum no. of rides for a subset S, last(S): min weight of the last ride.
    //our final goal is to calculate the value of rides({0,1,....,n-1})
    best[0] = {1, 0}; // for an empty group 
    for(int s = 1; s < (1<<n); s++){
        //initial value: n+1 rides are needed
        best[s] = {n+1, 0};
        for(int p = 0; p < n; p++){
            if(s & (1 << p)){
                auto options = best[s ^ (1 << p)];
                if(options.second + weight[p] <= x){
                    options.second += weight[p];
                    //adding p to the last ride
                }
                else{
                   options.first++;
                   options.second = weight[p];
                   //reserve a new ride that initially contain only p
                }
                 best[s] = min(best[s], options);
            }
        }
    }
    cout<<best[(1<<n)-1].first<<endl;
    return 0;
}