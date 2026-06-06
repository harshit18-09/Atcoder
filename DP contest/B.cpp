// Author: Harshit_1809
#include<bits/stdc++.h>
using namespace std;

#define int long long

signed get(vector<int>& arr, int i,int k, vector<int>& dp){
    if(i == arr.size()-1) return 0;
    if(dp[i] != -1) return dp[i];

    int mini = INT_MAX;
    for(int j=1;j<=k;j++){
        if(i+j < arr.size()){
            int c = abs(arr[i]-arr[i+j]) + get(arr, i+j, k, dp);
            mini = min(mini, c);
        }
    }
    return dp[i] = mini;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> dp(n+1, -1);
    cout<<get(arr, 0, k, dp);
    return 0;
}