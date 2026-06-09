// Author: Harshit_1809
#include<bits/stdc++.h>
using namespace std;

#define int long long

signed get(vector<int>& a, int i, vector<int>& b, vector<int>& c, int n, int last, vector<vector<int>>& dp){
    if(i>=n) return 0;

    if(dp[i][last] != -1) return dp[i][last];

    int chosea = 0, choseb = 0, chosec = 0;
    if(last != 0){
        chosea = a[i] + get(a, i+1, b, c, n, 0, dp);
    }
    if(last != 1){
        choseb = b[i] + get(a, i+1, b, c, n, 1, dp);
    }
    if(last != 2){
        chosec = c[i] + get(a, i+1, b, c, n, 2, dp);
    }
    dp[i][last] = max(chosea, max(choseb, chosec));
    return dp[i][last];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n), b(n), c(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        cin>>b[i];
        cin>>c[i];
    }
    // vector<vector<int>> dp(n+1, vector<int>(4, -1));
    // cout<<get(a,0, b, c, n, 3, dp);
    vector<vector<int>> dp(n+1, vector<int>(4, 0));

    for(int i=n-1; i>=0; i--){
        for(int j = 0; j<4; j++){
            int maxi = 0;
            if(j != 0){
                maxi = max(maxi, a[i] + dp[i+1][0]);
            }
            if(j != 1){
                maxi = max(maxi, b[i] + dp[i+1][1]);
            }
            if(j != 2){
                maxi = max(maxi, c[i] + dp[i+1][2]);
            }
            dp[i][j] = maxi;
        }
    }
    cout<<dp[0][3];
    return 0;
}