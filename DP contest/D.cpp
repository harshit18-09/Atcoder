// Author: Harshit_1809
#include<bits/stdc++.h>
using namespace std;

#define int long long

signed get(vector<int> &weight, vector<int> &value, int i, int w, vector<vector<int>> &dp){
    if(i == weight.size()) return 0;
    if(dp[i][w] != -1) return dp[i][w];
    if(w < weight[i]) return dp[i][w] = get(weight, value, i+1, w, dp);
    return dp[i][w] = max((long long)get(weight, value, i+1, w, dp), (long long)(value[i] + get(weight, value, i+1, w - weight[i], dp)));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, w;
    cin>>n>>w;
    vector<int> weight(n), value(n);
    for(int i=0; i<n; i++){
        cin>>weight[i]>>value[i];
    }
    // vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
    // int ans = get(weight, value, 0, w, dp);
    vector<long long> dp(w + 1, 0);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int v = w; v >= weight[i]; v--) {
            dp[v] = max(dp[v], value[i] + dp[v-weight[i]]);
        }
    }

    cout<<dp[w]<<endl;
    return 0;
}