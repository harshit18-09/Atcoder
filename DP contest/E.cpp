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

int INF = 1e18;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, w;
    cin>>n>>w;
    vector<int> weight(n), value(n);
    int totalv = 0;
    for(int i=0; i<n; i++){
        cin>>weight[i]>>value[i];
        totalv += value[i];
    }
    // vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
    // int ans = get(weight, value, 0, w, dp);
    vector<long long> dp(totalv + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int v = totalv; v >= value[i]; v--) {
            if(dp[v - value[i]] != INF) {
                dp[v] = min(dp[v], weight[i] + dp[v - value[i]]);
            }
        }
    }

    int ans = 0;
    for (int v = 0; v <= totalv; v++) {
        if (dp[v] <= w) {
            ans = v;
        }
    }

    cout << ans << endl;
    return 0;
}